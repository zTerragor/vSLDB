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

const Position adds_pos = { -631.0f, 1089.0f, 321.0f, 0.77f };

//ScriptDev: Wave of Light cannot be scripted now, due to missing areatrigger_template data, same for Divine Mallet, Consecration

enum Texts
{
    SAY_AGGRO = 0,
    SAY_INTRO = 1,    
    SAY_WAVE_OF_LIGHT,
    SAY_PRAYER_FOR_THE_FALLEN,
    SAY_RETRIBUTION,
    SAY_RECKONING,
    SAY_CALL_TO_ARMS,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 295065, // 1:1
    SUMMON_DARKFORGE_RAM = 270562,
    SACRED_BLADE = 283572,
    WAVE_OF_LIGHT_CREATE_AT = 283598,
    WAVE_OF_LIGHT_PERIODIC = 283617,
    SEAL_OF_RETRIBUTION = 284469,
    RETRIBUTION_AOE_DAMAGE = 284488,
    ZEALOTRY = 284459,

    JUDGMENT_RIGHTEOUSNESS = 283933,
    SEAL_OF_RECKONING = 284436,
    JUDGMENT_RECKONING = 284474,

    AVENGING_WRATH = 282113,
    CALL_TO_ARMS = 283662,
    PRAYER_OF_THE_FALLEN = 287469,

    DIVINE_PROTECTION = 288292,
    DIVINE_PROCTECTION_REDUCTION = 288294,
};

enum Events
{
    EVENT_WAVE_OF_LIGHT = 1,
    EVENT_SEAL_OF_RETRIBUTION,
    EVENT_ZEALOTRY,
    EVENT_JUDGMENT_RIGHTEOUSNESS,
    EVENT_SEAL_OF_RECKONING,
    EVENT_AVENGING_WRATH,
    EVENT_PRAYER_FOR_THE_FALLEN,
    EVENT_JUDGMENT_OF_RECKONING,
    EVENT_CALL_TO_ARMS,
    EVENT_SWITCH_SEAL,
    EVENT_DIVINE_PROTECTION,
};

enum Disciple
{
    ANGELIC_RENEWAL = 287419,
    DIVINE_BURST = 283626,
    HEAL_SP = 283628,
    PENANCE_HEAL = 284593,
    PENANCE_DAMAGE = 284595,

    EVENT_DIVINE_BURST = 1,
    EVENT_HEAL,
    EVENT_PENANCE_HEAL,
    EVENT_PENANCE_DAMAGE
};

enum Crusader
{
    AURA_OF_RETRIBUTION = 284468,
    BLINDING_FAITH_DUMMY = 283650,
    BLINDING_FAITH_DISORIENT = 283651,
    CONSECRATION_AT = 283579,
    CRUSADER_STRIKE = 283637,
    DIVINE_MALLET = 287439,
    DIVINE_MALLET_AT = 282074,
    WAVE_OF_LIGHT_HEALING = 283619,

    EVENT_CRUSADER_STRIKE = 1,
    EVENT_CONSECRATION,
    EVENT_DIVINE_MALLET,
    EVENT_BLINDING_FAITH,
};

//144680
struct boss_frida_ironbellows : public BossAI
{
    boss_frida_ironbellows(Creature* creature) : BossAI(creature, DATA_FRIDA_IRONBELLOWS) { }

    void Reset() override
    {        
        BossAI::Reset();
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);     
        me->AddAura(SACRED_BLADE);
        intro = false;
        hp60 = false;
        hp30 = false;
        me->DespawnCreaturesInArea(NPC_DARKFORGED_CRUSADER, 125.0f);
        me->DespawnCreaturesInArea(NPC_ANOINTED_DISCIPLE, 125.0f);
        if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 100.0f, true))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, crusader);
        }
        if (Creature* crusader = me->FindNearestCreature(NPC_ANOINTED_DISCIPLE, 100.0f, true))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, crusader);
        }
    }

    /*void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && intro == false)
        {
            intro = true;
            Talk(SAY_INTRO);
        }
    }*/

    void EnterCombat(Unit* /*unit*/) override
    {        
        _EnterCombat();
        Talk(SAY_AGGRO);
        DoCast(PERIODIC_ENERGY_GAIN);
        me->StopMoving();
        me->AddAura(SEAL_OF_RETRIBUTION);
        me->GetScheduler().Schedule(3s, [this] (TaskContext context)
        {
            Talk(SAY_RETRIBUTION);           
        });
        events.ScheduleEvent(EVENT_WAVE_OF_LIGHT, 12s);    
        events.ScheduleEvent(EVENT_JUDGMENT_RIGHTEOUSNESS, 50s);
        events.ScheduleEvent(EVENT_JUDGMENT_OF_RECKONING, 60s);
        events.ScheduleEvent(EVENT_CALL_TO_ARMS, 65s);
        if (IsHeroic() || IsMythic())
        {
            events.ScheduleEvent(EVENT_DIVINE_PROTECTION, 15s);
        }
        if (IsMythic())
        {
            events.ScheduleEvent(EVENT_PRAYER_FOR_THE_FALLEN, 25s);
        }
    }

    void DamageTaken(Unit* unit, uint32& damage) override
    {
        if (me->HealthBelowPct(60) && hp60 == false)
        {
            hp60 = true;
        }

        if (me->HealthBelowPct(30) && hp30 == false)
        {
            hp30 = true;
            DoCast(AVENGING_WRATH);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summon->AI()->DoZoneInCombat(nullptr, 250.0f);
    }

    void JustDied(Unit* /*unit*/) override
    {
       _JustDied();
       Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            Talk(SAY_KILL);
        }    
    }

   void SpellHit(Unit* caster, SpellInfo const* spell) override 
   {
       if (me->HasAura(SEAL_OF_RECKONING))
       {
           me->AddAura(ZEALOTRY);
       }
   }

   void JudgmentRighteousnessTargets()
   {
       uint32 Choose = urand(0, 1);

       switch (Choose)
       {
       case 0:
       {
           if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 500.0f, true))
           {
               me->CastSpell(crusader, JUDGMENT_RIGHTEOUSNESS);
           }
           break;
       }
       case 1:
       {
           if (Creature* disciple = me->FindNearestCreature(NPC_ANOINTED_DISCIPLE, 500.0f, true))
           {
               me->CastSpell(disciple, JUDGMENT_RIGHTEOUSNESS);
           }
           break;
       }
       default:
           break;
       }
   }

   
   void OnSpellFinished(SpellInfo const* spellInfo) 
   {
       if (spellInfo->Id == CALL_TO_ARMS)
       {
           me->SummonCreature(NPC_DARKFORGED_CRUSADER, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
           me->SummonCreature(NPC_ANOINTED_DISCIPLE, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
       }
   }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) >= 100)
        {
            events.ScheduleEvent(EVENT_SWITCH_SEAL, 100ms);
        }

        switch (eventId)
        {

        case EVENT_DIVINE_PROTECTION:
        {
            if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 100.0f, true))
            {
                if (crusader->HealthBelowPct(99) && !crusader->HasAura(DIVINE_PROCTECTION_REDUCTION))
                {
                    crusader->AddAura(DIVINE_PROCTECTION_REDUCTION);
                }
            }
            if (Creature* disciple = me->FindNearestCreature(NPC_ANOINTED_DISCIPLE, 100.0f, true))
            {
                if (disciple->HealthBelowPct(99) && !disciple->HasAura(DIVINE_PROCTECTION_REDUCTION))
                {
                    disciple->AddAura(DIVINE_PROCTECTION_REDUCTION);
                }
            }
            events.Repeat(15s);
            break;
        }

        case EVENT_WAVE_OF_LIGHT:
        {
             Talk(SAY_WAVE_OF_LIGHT);
             DoCast(WAVE_OF_LIGHT_CREATE_AT);
             events.Repeat(20s);
             break;
        }

        case EVENT_PRAYER_FOR_THE_FALLEN:
        {
             Talk(SAY_PRAYER_FOR_THE_FALLEN);
             DoCast(PRAYER_OF_THE_FALLEN);
             std::list<Creature*> c_li;
             me->GetCreatureListWithEntryInGrid(c_li, NPC_ANOINTED_DISCIPLE, 250.0f);
             for (auto& disciples : c_li)
             {             
                 disciples->StopMoving();
                 disciples->CastSpell(disciples, ANGELIC_RENEWAL, false);
             }
             std::list<Creature*> c_li_2;
             me->GetCreatureListWithEntryInGrid(c_li_2, NPC_DARKFORGED_CRUSADER, 250.0f);
             for (auto& crusaders : c_li_2)
             crusaders->CastSpell(nullptr, DIVINE_MALLET, false);
             events.Repeat(50s);
             break;
        }

        case EVENT_JUDGMENT_RIGHTEOUSNESS:
        {
             JudgmentRighteousnessTargets();
             events.Repeat(30s);
             break;
        }

        case EVENT_JUDGMENT_OF_RECKONING:
        {
            if (me->GetPower(POWER_ENERGY) >= 100)
            {
                me->StopMoving();
                me->CastStop();
                Talk(SAY_RECKONING);
                me->SetPower(POWER_ENERGY, 0);
                DoCastAOE(JUDGMENT_RECKONING);                
            }
            events.Repeat(60s);
            break;
        }

        case EVENT_SWITCH_SEAL:
        {
            if (me->GetPower(POWER_ENERGY) >= 100)
            {
                if (me->HasAura(SEAL_OF_RETRIBUTION))
                {
                    me->GetScheduler().Schedule(100ms, [this] (TaskContext context)
                    {
                        me->SetPower(POWER_ENERGY, 0);
                        me->RemoveAura(SEAL_OF_RETRIBUTION);
                        me->RemoveAura(PERIODIC_ENERGY_GAIN);                        

                        me->AddAura(SEAL_OF_RECKONING);                        
                    });
                }
                if (me->HasAura(SEAL_OF_RECKONING))
                {
                    me->GetScheduler().Schedule(100ms, [this] (TaskContext context)
                    {
                        me->SetPower(POWER_ENERGY, 0);
                        me->RemoveAura(SEAL_OF_RECKONING);
                        me->RemoveAura(PERIODIC_ENERGY_GAIN);                        

                        me->AddAura(SEAL_OF_RETRIBUTION);
                        me->AddAura(PERIODIC_ENERGY_GAIN);
                    });
                }
            }
            break;
        }
        case EVENT_CALL_TO_ARMS:       
        {
             Talk(SAY_CALL_TO_ARMS);
             me->StopMoving();
             DoCast(CALL_TO_ARMS);
             events.Repeat(35s);
             break;
        }
        }
    }

private:
    bool hp30;
    bool hp60;
    bool intro;
};

//145903
struct npc_darkforged_crusader_145903 : public ScriptedAI
{
    npc_darkforged_crusader_145903(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }

    void EnterCombat(Unit * u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 3s);
        events.ScheduleEvent(EVENT_CONSECRATION, 8s);
        events.ScheduleEvent(EVENT_BLINDING_FAITH, 13s);
        events.ScheduleEvent(EVENT_DIVINE_MALLET, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (me->GetDistance2d(frida) <= 30.0f)
            {
                if (frida->IsAlive())
                {
                    if (frida->HasAura(AURA_OF_RETRIBUTION))
                    {
                        if (!me->HasAura(AURA_OF_RETRIBUTION))
                        {
                            me->AddAura(AURA_OF_RETRIBUTION);
                        }
                    }
                    else
                    {
                        if (me->HasAura(AURA_OF_RETRIBUTION))
                        {
                            me->RemoveAura(AURA_OF_RETRIBUTION);
                        }
                    }
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (frida->IsAlive())
            {
                frida->AddAura(ZEALOTRY);
            }
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    { 
        if (spellInfo->Id == BLINDING_FAITH_DUMMY)
        {
            DoCastVictim(BLINDING_FAITH_DISORIENT);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CRUSADER_STRIKE:
             me->StopMoving();
             DoCastVictim(CRUSADER_STRIKE);
             events.Repeat(15s);
             break;

        case EVENT_CONSECRATION:
             me->StopMoving();
             DoCastAOE(CONSECRATION_AT);
             events.Repeat(20s);
             break;

        case EVENT_BLINDING_FAITH:
             me->StopMoving();
             DoCastAOE(BLINDING_FAITH_DUMMY);
             events.Repeat(25s);
             break;

        case EVENT_DIVINE_MALLET:
             me->StopMoving();
             DoCastAOE(DIVINE_MALLET_AT);
             events.Repeat(30s);
             break;
        }
    }
};

//145898
struct npc_antoined_disciple_145898 : public ScriptedAI
{
    npc_antoined_disciple_145898(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterCombat(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_DIVINE_BURST, 3s);
        events.ScheduleEvent(EVENT_HEAL, 8s);
        events.ScheduleEvent(EVENT_PENANCE_HEAL, 13s);
        events.ScheduleEvent(EVENT_PENANCE_DAMAGE, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (me->GetDistance2d(frida) <= 30.0f)
            {
                if (frida->IsAlive())
                {
                    if (frida->HasAura(AURA_OF_RETRIBUTION))
                    {
                        if (!me->HasAura(AURA_OF_RETRIBUTION))
                        {
                            me->AddAura(AURA_OF_RETRIBUTION);
                        }
                    }
                    else
                    {
                        if (me->HasAura(AURA_OF_RETRIBUTION))
                        {
                            me->RemoveAura(AURA_OF_RETRIBUTION);
                        }
                    }
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (frida->IsAlive())
            {
                frida->AddAura(ZEALOTRY);
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_DIVINE_BURST:
             me->StopMoving();
             DoCastRandom(DIVINE_BURST, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_HEAL:
             me->StopMoving();
             DoCast(HEAL_SP);
             events.Repeat(20s);
             break;

        case EVENT_PENANCE_HEAL:
             me->StopMoving();
             if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 100.0f, true))
             {
                 if (crusader->HealthBelowPct(99))
                 {
                     me->CastSpell(crusader, PENANCE_HEAL);
                 }
             }
             events.Repeat(25s);
             break;

        case EVENT_PENANCE_DAMAGE:
             me->StopMoving();
             DoCastRandom(PENANCE_DAMAGE, 500.0f, true);
             events.Repeat(30s);
             break;
        }
    }
};

void AddSC_boss_frida_ironbellows()
{
    RegisterCreatureAI(boss_frida_ironbellows);
    RegisterCreatureAI(npc_darkforged_crusader_145903);
    RegisterCreatureAI(npc_antoined_disciple_145898);
}
