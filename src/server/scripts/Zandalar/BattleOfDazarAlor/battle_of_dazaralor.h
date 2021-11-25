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
#ifndef BOD
#define BOD

#define DataHeader "BOD"

uint32 const EncounterCount = 10;

enum EncounterData
{
	DATA_FRIDA_IRONBELLOWS = 1,
	DATA_RAWANI_KANAE,	
	DATA_GRONG,
	DATA_JADEFIRE_MASTERS,
	DATA_OPULENCE,
	DATA_CONCLAVE,
	DATA_KING_RASTAKHAN,
	DATA_HIGH_TINKER_MEKKATORQUE,
	DATA_STORMWALL_BLOCKADE,
	DATA_LADY_JAINA_PROUDMOORE,
};

enum Creatures
{
	//HORDE
	NPC_FRIDA_IRONBELLOWS = 144680,
	NPC_ANOINTED_DISCIPLE = 145898,
	NPC_DARKFORGED_CRUSADER = 145903,
	NPC_GRONG = 148117,
	NPC_APETAGONIZER_3000 = 149611,
	NPC_APETAGONIZE_CORE = 500501,
	NPC_MESTRAH = 144690,
	NPC_MANCEROY_FLAMEFIST = 146099,
	NPC_LIVING_BOMB_BOD = 146107,
	NPC_MAGMA_TRAP_BOD = 500502,
	NPC_SPIRIT_OF_XUEN = 147069,
	NPC_MAGMA_STALKER = 500505,
	NPC_BARRIER_BOD = 147374,
	NPC_OPULENCE = 145261,
	NPC_SPIRIT_OF_GOLD = 147218,

	NPC_HIGH_TINKER_MEKKATORQUE = 144838,
	//ALLIANCE
	NPC_RAWANI_KANAE = 144683,
	NPC_REZANI_DISCIPLE = 147895,
	NPC_ZANDALARI_CRUSADER = 147896,	
};

#endif // BOD
