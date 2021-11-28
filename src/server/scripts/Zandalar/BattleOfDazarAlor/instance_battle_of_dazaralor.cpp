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
#include "Player.h"
#include "InstanceScript.h"
#include "battle_of_dazaralor.h"
#include "GameObject.h"
//INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`, `insideResurrection`) VALUES ('2070', '0', 'instance_battle_of_dazaralor', '0', '1');

enum Scenes
{
    SCENE_CORPSES = 2464,
    SCENE_ALLIANCE_LANDING = 2462,
    SCENE_ALLIANCE_LANDING_2 = 2458,
    SCENE_BATTLEFIELD_ACTION = 2454,
};

struct instance_battle_of_dazaralor : public InstanceScript
{
	instance_battle_of_dazaralor(InstanceMap* map) : InstanceScript(map), isHorde(false), isAlliance(false)
	{
		SetHeaders(DataHeader);
		SetBossNumber(EncounterCount);
	}

	ObjectGuid frida_guid;
	ObjectGuid rawani_guid;

    void OnPlayerExit(Player* player)
    {
        player->GetSceneMgr().CancelSceneByPackageId(SCENE_CORPSES);
        player->GetSceneMgr().CancelSceneByPackageId(SCENE_BATTLEFIELD_ACTION);
    }

	void OnPlayerEnter(Player* player)
	{			
		if (isHorde == true || isAlliance == true)
		{
			return;
		}
		else
		{
			if (player->GetTeam() == HORDE)
			{
				isHorde = true;
				player->SendMovieStart(876);
                player->GetSceneMgr().RecreateScene(SCENE_CORPSES, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                player->GetSceneMgr().RecreateScene(SCENE_BATTLEFIELD_ACTION, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
			}
			if (player->GetTeam() == ALLIANCE)
			{
				isAlliance = true;
				player->SendMovieStart(876);
                player->GetSceneMgr().RecreateScene(SCENE_CORPSES, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                player->GetSceneMgr().RecreateScene(SCENE_BATTLEFIELD_ACTION, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
			}
		}
		/**********************************************************************************************************************************************/
		if (isHorde == true)
		{
			if (Creature* frida = instance->GetCreature(frida_guid))			
				frida->DespawnOrUnsummon();
		}
		if (isAlliance == true)
		{
			if (Creature* rawani = instance->GetCreature(rawani_guid))
				rawani->DespawnOrUnsummon();
		}
	}

	void OnCreatureCreate(Creature* creature) override
	{
		switch (creature->GetEntry())
		{
		case NPC_FRIDA_IRONBELLOWS:
		case NPC_RAWANI_KANAE:
			 creature->GetGUID();
			 break;

		case NPC_HIGH_TINKER_MEKKATORQUE:
			 creature->GetGUID();
			 creature->SetVisible(false);
			 break;
		}
	}

private:
	bool isHorde;
	bool isAlliance;
};

void AddSC_instance_battle_of_dazaralor()
{
	RegisterInstanceScript(instance_battle_of_dazaralor, 2070);
}
