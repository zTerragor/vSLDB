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
#include "waycrest_manor.h"

enum GluttonousSpells
{
    //GluttonousSpells
    SPELL_ROTTEN_EXPLUSION = 264694,
    SPELL_CONSUME_SERVANT = 265002,
    SPELL_CALL_SERVANT = 264931,
    SPELL_TENDERIZE = 264923,
    SPELL_BILE_EXPLOSION = 268234,
};

struct boss_raal_the_gluttonous : public BossAI
{
    boss_raal_the_gluttonous(Creature* creature) : BossAI(creature, DATA_RAAL_THE_GLUTTONOUS) { }
    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(SPELL_ROTTEN_EXPLUSION, 11s);
        events.ScheduleEvent(SPELL_CONSUME_SERVANT, 5s,9s);
        events.ScheduleEvent(SPELL_CALL_SERVANT, 2s,6s);
        events.ScheduleEvent(SPELL_TENDERIZE, 1s);
        events.ScheduleEvent(SPELL_BILE_EXPLOSION, 7s);
    }
    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
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
        case SPELL_ROTTEN_EXPLUSION:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                DoCast(target, SPELL_ROTTEN_EXPLUSION, true);
            events.Repeat(Seconds(7), Seconds(12));
            break;

        case SPELL_CONSUME_SERVANT:
            DoCast(SPELL_CONSUME_SERVANT);
            events.Repeat(Seconds(12));
            break;
        case SPELL_CALL_SERVANT:
            DoCast(SPELL_CALL_SERVANT);
            DoCast(SPELL_TENDERIZE);
            events.Repeat(Seconds(12));
            break;    

        case SPELL_TENDERIZE:
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

                DoCast(SPELL_TENDERIZE);
                events.Repeat(Seconds(1));
                break;
            }
        }
        case SPELL_BILE_EXPLOSION:
        
            DoCast(SPELL_BILE_EXPLOSION);
            events.Repeat(Seconds(2));
            break;
        
        }
    }
};
void AddSC_boss_raal_the_gluttonous()
{
    RegisterCreatureAI(boss_raal_the_gluttonous);
}
