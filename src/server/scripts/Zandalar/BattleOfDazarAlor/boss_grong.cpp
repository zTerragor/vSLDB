/*
 * Copyright (C) 2020 BfaCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedGossip.h"
#include "battle_of_dazaralor.h"

const Position apetagonizer_3000_pos = { -907.0f, 920.0f, 340.0f, 0.0f };

//Grong 148117

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956, // 1:1
    TANTRUM = 281936, // at 100 energy, -25 energy per secd
    REVERBERATING_SLAM = 282179,
    FEROCIOUS_ROAR = 290574, //heroic+ Players who are not within 5 yards of another player will be feared for 5 seconds when hit by the Ferocious Roar.
    FEROCIOUS_ROAR_FEAR = 290575,
    BESTIAL_COMBO = 282082,
    BESTIAL_SMASH = 283078,
    BESTIAL_IMPACT = 289412,
    BESTIAL_THROW = 289292,

    //Adds
    PARACHUTE = 55001,
    APETAGONIZE = 282243,
    APETAGONIZE_CORE_MISSILE = 285661,
    APETAGONIZE_CORE_BUFF = 285659,
    DISCHARGE_APETAGONIZE_CORE = 285660,
    LIGHTNING_DETONATION = 285654,
};

enum Events
{
    EVENT_TANTRUM = 1,
    EVENT_REVERBERATING_SLAM,
    EVENT_FEROCIOUS_ROAR,
    EVENT_BESTIAL_COMBO,
    EVENT_APETAGONIZER,

    EVENT_APETAGONIZE,
};

struct boss_grong : public BossAI
{
    boss_grong(Creature* creature) : BossAI(creature, DATA_GRONG) { }

    void Reset() override
    {
        BossAI::Reset();
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->DespawnCreaturesInArea(NPC_APETAGONIZER_3000);
        me->DespawnCreaturesInArea(NPC_APETAGONIZE_CORE);
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        _EnterCombat();    
        DoCast(PERIODIC_ENERGY_GAIN);

        events.ScheduleEvent(EVENT_REVERBERATING_SLAM, 3s);
        events.ScheduleEvent(EVENT_BESTIAL_COMBO, 11s);
        events.ScheduleEvent(EVENT_APETAGONIZER, 30s);
        if (IsHeroic() || IsMythic())
        {
            events.ScheduleEvent(FEROCIOUS_ROAR, 8s);
        }       
    }

    void JustDied(Unit* /*unit*/) override
    {
        _JustDied();
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == LIGHTNING_DETONATION)
        {
            //me->SetPower(POWER_ENERGY, +50);
        }
        if (spell->Id == DISCHARGE_APETAGONIZE_CORE)
        {
            DoCastAOE(TANTRUM);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 75);
            events.ScheduleEvent(EVENT_TANTRUM, 100ms);
            me->GetScheduler().Schedule(1s, [this] (TaskContext context)
            {
                me->SetPower(POWER_ENERGY, 50);
            });
            me->GetScheduler().Schedule(2s, [this] (TaskContext context)
            {
                me->SetPower(POWER_ENERGY, 25);
            });
            me->GetScheduler().Schedule(3s, [this] (TaskContext context)
            {
                me->SetPower(POWER_ENERGY, 0);
            });
        }
        switch (eventId)
        {
        case EVENT_TANTRUM:
        {
             me->StopMoving();
             DoCastAOE(TANTRUM);
             break;
        }
        case EVENT_REVERBERATING_SLAM:
        {
            me->StopMoving();
            DoCastAOE(REVERBERATING_SLAM);
            events.Repeat(20s);
            break;
        }
        case EVENT_BESTIAL_COMBO:
        {            
            //DoCast(BESTIAL_COMBO);
            DoCastVictim(BESTIAL_SMASH);
            DoCastVictim(BESTIAL_THROW);            
            events.Repeat(25s);
            break;
        }
        case EVENT_APETAGONIZER:
        {
            me->SummonCreature(NPC_APETAGONIZER_3000, me->GetRandomPoint(apetagonizer_3000_pos, 30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(45s);
            break;
        }
        case EVENT_FEROCIOUS_ROAR:
        {
            me->StopMoving();
            DoCastAOE(FEROCIOUS_ROAR);
            events.Repeat(35s);
            break;
        }

        }
    }
};

//149611
struct npc_apetagonizer_3000 : public ScriptedAI
{
    npc_apetagonizer_3000(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();       
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddAura(PARACHUTE);
        Talk(0);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_APETAGONIZE, 5s);
    }

    /*void EnterCombat(Unit* u) override
    {
    }*/

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->HasAura(PARACHUTE) && me->GetPositionZ() <= 341.0f)
        {
            me->RemoveAura(PARACHUTE);
        }

        switch (eventId)
        {
        case EVENT_APETAGONIZE:
            if (Creature* grong = me->FindNearestCreature(NPC_GRONG, 100.0f, true))
            {
                if (grong->IsAlive())
                {
                    std::list<Creature*> c_li;
                    me->GetCreatureListWithEntryInGrid(c_li, NPC_GRONG, 100.0f);
                    for (auto & grong : c_li)
                    {                        
                        me->AI()->DoCast(grong, APETAGONIZE);
                    }
                }
            }
            events.Repeat(5s);
            break;

        default:
            break;
        }
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        if (spell->Id == APETAGONIZE)
        {
            if (Creature* grong = me->FindNearestCreature(NPC_GRONG, 100.0f, true))
            {
                if (grong->IsAlive())
                {
                    //grong->SetPower(POWER_ENERGY, +10);
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        Talk(1);
        DoCastAOE(LIGHTNING_DETONATION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->SummonCreature(NPC_APETAGONIZE_CORE, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

//500501
struct npc_apetagonize_core : public ScriptedAI
{
    npc_apetagonize_core(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void sGossipHello(Player* player) override
    { 
        CloseGossipMenuFor(player);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        player->AddAura(APETAGONIZE_CORE_BUFF);
        me->DespawnOrUnsummon();
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, APETAGONIZE_CORE_MISSILE);
    }
};

void AddSC_boss_grong()
{
    RegisterCreatureAI(boss_grong);
    RegisterCreatureAI(npc_apetagonizer_3000);
    RegisterCreatureAI(npc_apetagonize_core);
}
