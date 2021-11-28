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
#include "battle_of_dazaralor.h"
// ||

enum Texts
{

};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    HOARD_POWER = 287070,
    COIN_SHOWER_AT = 285014,
    COIN_SHOWER_MISSILE = 285027,
    COIN_SHOWER_DAMAGE = 285046,
    COIN_SWEEP = 287037,
    FOCUSED_ANIMUS_AURA = 284614,
    GREED_AURA = 284943,
    LIQUID_GOLD_AURA = 287072,
    LIQUID_GOLD_AT = 287073,
    LIQUID_GOLD_AT_DAMAGE = 287074,
    SPIRITS_OF_GOLD = 285995,
    SURGING_GOLD = 289155,
    WAIL_OF_GREED = 284941,
    WAIL_OF_GREED_MOD_DAMAGE = 284942,
    //Add
    CHANNEL_OF_GOLD = 286026,
    GOLD_BURST_DAMAGE = 286040,
};

enum Events
{
    EVENT_HOARD_POWER = 1,
    EVENT_SPIRITS_OF_GOLD,
    EVENT_LIQUID_GOLD,
    EVENT_COIN_SHOWER,
    EVENT_WAIL_OF_GREED,
    EVENT_COIN_SWEEP,
};

//145261
struct boss_opulence : public BossAI
{
    boss_opulence(Creature* creature) : BossAI(creature, DATA_OPULENCE) { }

    void Reset() override
    {
        BossAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
        me->SetPowerType(POWER_ENERGY);
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPower(POWER_ENERGY, 0);
        me->DespawnCreaturesInArea(NPC_SPIRIT_OF_GOLD, 125.0f);        
        me->NearTeleportTo(me->GetHomePosition());
        _JustReachedHome();
        engaged = false;
    }

    void AttackStart(Unit* who) override
    {
        me->SetWalk(false);

        if (me->Attack(who, true))
        DoStartMovement(who);
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        _EnterCombat();
        engaged = true;
        DoCast(PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_HOARD_POWER, 1s);
        events.ScheduleEvent(EVENT_COIN_SWEEP, 7s);
        events.ScheduleEvent(EVENT_LIQUID_GOLD, 12s);
        events.ScheduleEvent(EVENT_SPIRITS_OF_GOLD, 17s);
        events.ScheduleEvent(EVENT_COIN_SHOWER, 20s);
        events.ScheduleEvent(EVENT_WAIL_OF_GREED, 23s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == HOARD_POWER)
        {
            return;
        }
        if (spellInfo->Id == SPIRITS_OF_GOLD)
        {
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SPIRIT_OF_GOLD:
             summon->AI()->DoZoneInCombat();
             break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override 
    { 
        if (instance->IsWipe() && engaged == true)
        {
            me->DespawnCreaturesInArea(NPC_SPIRIT_OF_GOLD, 125.0f);
            me->ForcedDespawn(100, 3s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_HOARD_POWER:
        {
            DoCast(HOARD_POWER);
            break;
        }
        case EVENT_COIN_SWEEP:
        {
            DoCastVictim(COIN_SWEEP);
            events.Repeat(10s);
            break;
        }
        case EVENT_LIQUID_GOLD:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* tar : tarlist)
            DoCast(tar, LIQUID_GOLD_AURA);
            events.Repeat(15s);
            break;
        }
        case EVENT_COIN_SHOWER:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 10, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* tar : tarlist)
            DoCast(tar, COIN_SHOWER_MISSILE);
            events.Repeat(20s);
            break;
        }
        case EVENT_SPIRITS_OF_GOLD:
        {
            DoCast(SPIRITS_OF_GOLD);
            events.Repeat(60s);
            break;
        }
        case EVENT_WAIL_OF_GREED:
        {
            DoCastAOE(WAIL_OF_GREED);
            me->AddAura(GREED_AURA);
            events.Repeat(35s);
            break;
        }
        
        default:
            break;
        }
    }
    private:
    bool engaged = true;
};

void AddSC_boss_opulence()
{
    RegisterCreatureAI(boss_opulence);
}
