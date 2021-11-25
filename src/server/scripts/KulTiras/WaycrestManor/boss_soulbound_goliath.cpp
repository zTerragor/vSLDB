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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "waycrest_manor.h"


enum GoliathSpells
{
    //Goliathspells
    SPELL_SOUL_HARVEST = 260512,
    SPELL_BURNING_BRUSH = 260547,
    SPELL_CRUSH = 260508,
    SPELL_SOUL_THORNS = 260551,
    SPELL_BURNING_FISTS = 272668,
    SPELL_REMOVE_MUSHROOM_POWER = 57283,
   /*//Trash spells
    SPELL_SOUL_FETISH = 278551,
    SPELL_UPROOT = 264038,
    SPELL_INFECTED_THORN = 264050,
    SPELL_EFFIGY_RECONSTRUCTION = 278474,
    SPELL_TEARING_STRIKE = 264556,
    SPELL_ENRAGE = 257260,
    SPELL_SHATTER = 264150,
    SPELL_THORNED_CLAW = 264140,*/
};

enum GoliathEvents
{
    EVENT_RESPAWN_T1,
    EVENT_RESPAWN_T2,
    EVENT_RESPAWN_T3,
    EVENT_RESPAWN_T4,
};

struct boss_soulbound_goliath : public BossAI
{
    boss_soulbound_goliath(Creature* creature) : BossAI(creature, DATA_SOULBOUND_GOLIATH) { }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(SPELL_BURNING_FISTS, 5s);
        events.ScheduleEvent(SPELL_BURNING_BRUSH, 5s);
        events.ScheduleEvent(SPELL_CRUSH, 2s);
        events.ScheduleEvent(SPELL_SOUL_HARVEST, 2s);
        events.ScheduleEvent(EVENT_RESPAWN_T1, Seconds(15), Seconds(23));
        events.ScheduleEvent(EVENT_RESPAWN_T2, Seconds(21), Seconds(29));
        events.ScheduleEvent(EVENT_RESPAWN_T3, Seconds(15), Seconds(23));
        events.ScheduleEvent(EVENT_RESPAWN_T4, Seconds(21), Seconds(29));
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        DoCast(SPELL_CRUSH);
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void ExecuteEvent(uint32 eventId) override
    {
       switch (eventId)
       {
       case SPELL_BURNING_FISTS:
	        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                DoCast(target, SPELL_BURNING_FISTS, true);
            events.Repeat(Seconds(7), Seconds(12));
            break;
       case SPELL_SOUL_HARVEST:
            DoCast(SPELL_SOUL_HARVEST);
            events.Repeat(Seconds(2));
            break;
       case EVENT_RESPAWN_T1:     
            me->SummonCreature(NPC_THORNGUARD, Position(-422.661, -248.634f, 233.8585f, 4.4889f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(11s);
            break;
       case EVENT_RESPAWN_T2:            
            me->SummonCreature(NPC_JAGGED_HOUND, Position(-415.661, -253.634f, 233.8585f, 3.4889f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(15s);
            break;
       case EVENT_RESPAWN_T3:            
            me->SummonCreature(NPC_THORNGUARD, Position(-423.661, -270.634f, 233.8585f, 1.4889f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(19s);
            break;
       case EVENT_RESPAWN_T4:          
            me->SummonCreature(NPC_JAGGED_HOUND, Position(-431.661, -270.634f, 233.8585f, 1.2949f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(34s);
            break;      
       case SPELL_CRUSH:
       {
           std::list<Player*> playerList;
           GetPlayerListInGrid(playerList, me, 200.0f);
           if (!playerList.empty())
           {
               // Picking a random target
               std::list<Player*>::iterator itr, next;
               itr = playerList.begin();
               // Removing Heals, DPS & hunters
               for (itr = playerList.begin(); itr != playerList.end(); itr = next)
               {
                   next = itr;
                   ++next;
                   if ((*itr)->GetRoleForGroup() == Roles::ROLE_HEALER ||
                       (*itr)->GetRoleForGroup() == Roles::ROLE_DAMAGE ||
                       (*itr)->getClass() == CLASS_HUNTER)
                       playerList.remove(*itr);
               }
               if (playerList.empty())
                   break;
               Trinity::Containers::RandomResize(playerList, 1);
               DoCast(SPELL_CRUSH);        
           }
           events.Repeat(2s);
           break;
       }      
       case SPELL_SOUL_THORNS:
       {
           std::list<Player*> playerList;
           GetPlayerListInGrid(playerList, me, 200.0f);
           if (!playerList.empty())
           {
               // Picking a random target
               std::list<Player*>::iterator itr, next;
               itr = playerList.begin();
               // Removing Tanks
               for (itr = playerList.begin(); itr != playerList.end(); itr = next)
               {
                   next = itr;
                   ++next;

                   if ((*itr)->GetRoleForGroup() == Roles::ROLE_TANK)
                       playerList.remove(*itr);
               }
               if (playerList.empty())
                   break;
               Trinity::Containers::RandomResize(playerList, 1);
               DoCast(SPELL_SOUL_THORNS);
           }
           events.Repeat(2s);
           break;
       }
     }
   }
};

void AddSC_boss_soulbound_goliath()
{
    RegisterCreatureAI(boss_soulbound_goliath);
}