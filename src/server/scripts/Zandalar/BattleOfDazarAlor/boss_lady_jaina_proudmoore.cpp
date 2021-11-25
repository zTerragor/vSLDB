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
//||

enum Texts
{
    SAY_AGGRO = 0,
    SAY_RING_OF_ICE,
    SAY_AVALANCHE,
    SAY_KILL,
    SAY_SIEGEBREAKER_BLAST,
    SAY_DEATH
};

enum Spells
{
    SPELL_ICE_SHARD = 290621,
    SPELL_ICE_SHARD_DEBUFF = 285253,
    SPELL_AVALANCHE_TRIGGER = 285254,

    SPELL_GRASP_OF_FROST = 287626,
    SPELL_CHILLING_TOUCH_AURA = 287993,
    SPELL_FREEZING_BLAST = 285177,
    SPELL_RING_OF_ICE = 285459,
    SPELL_RING_OF_ICE_ROOT_DAMAGE_AURA = 287199,

    SPELL_HOWLING_WINDS = 289861,
    SPELL_HOWLING_WINDS_AURA = 290535,

    SPELL_BLISTERING_TORNADO_AT_VISUAL = 288526,
    SPELL_BLISTERING_TORNADO_DAMAGE_KNOCK = 288534,
    SPELL_ARTIC_GROUND = 288297,
    SPELL_BROADSIDE_MISSILE = 288214,
    SPELL_REFRACTIVE_ICE = 288219,
    SPELL_SIEGEBREAKER_BLAST_MISSILE = 288379,
    SPELL_SIEGEBREEAKER_BLAST_EXP = 288380,
    SPELL_FROZEN_SOLID = 287490,
    SPELL_HAND_OF_FROST = 288434,
    SPELL_GLACIAL_RAY = 288345,
    SPELL_GLACIAL_RAY_DAMAGE = 288363,
    SPELL_ICEFALL = 288475,
    SPELL_ICEFALL_AT_MISSILE = 288507,
    SPELL_FLASH_FREEZE = 288719,
    //Jaina's Tide Elemental, 149558
    SPELL_WATER_BOLT_VOLLEY = 290084, //hc?
    SPELL_HEART_OF_FROST = 289220,
    SPELL_FROST_NOVA = 289219,

    SPELL_ARCANE_BARRAGE_MISSILE = 289984,
    SPELL_SHATTERING_LANCE = 288671,
    SPELL_CRYSTALLINE_DUST_CONE = 289940,
    SPELL_SUMMON_PRISMATIC_IMAGE_MISSILE = 288747,
    SPELL_SUMMON_PRISMATIC_IMAGE = 288715, //148907

    SPELL_TIME_WARP = 287925,
    SPELL_SUMMON_ORB_OF_FROST = 288617, //148859
    SPELL_ORB_OF_FROST_EXP = 288647,
    SPELL_ORB_OF_FROST_AT = 288629,

    SPELL_GATHERING_BLIZZARD_BAR = 289379,
    SPELL_FREEZING_BLOOD = 289387,

    SPELL_FROZEN_SIEGE_SUMMON_BALLISTA = 289853,
    SPELL_FROZEN_SIEGE_BALLISTA_VISUAL = 289855, //149441

    SPELL_ARTIC_ARMOR = 282841,
};

enum Events
{

};

//162208
struct boss_lady_jaina_proudmoore : public BossAI
{
    boss_lady_jaina_proudmoore(Creature* creature) : BossAI(creature, DATA_LADY_JAINA_PROUDMOORE) { }
};

void AddSC_boss_lady_jaina_proudmoore()
{
    RegisterCreatureAI(boss_lady_jaina_proudmoore);
}
