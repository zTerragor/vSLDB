DROP TABLE IF EXISTS `item_instance`;
create table `item_instance` (
	`guid` bigint (20),
	`itemEntry` mediumint (8),
	`owner_guid` bigint (20),
	`creatorGuid` bigint (20),
	`giftCreatorGuid` bigint (20),
	`count` int (10),
	`duration` int (10),
	`charges` text ,
	`flags` mediumint (8),
	`enchantments` text ,
	`randomPropertyType` tinyint (3),
	`randomPropertyID` int (10),
	`randomBonusListId` int (10),
	`durability` smallint (5),
	`playedTime` int (10),
	`text` text ,
	`upgradeid` int (10),
	`transmogrification` int (10),
	`enchantIllusion` int (10),
	`battlePetSpeciesId` int (10),
	`battlePetBreedData` int (10),
	`battlePetLevel` smallint (5),
	`battlePetDisplayId` int (10),
	`bonusListIDs` text ,
	`itemlevel` mediumint (6),
	`dungeonEncounterID` mediumint (6),
	`context` tinyint (3),
	`createdTime` int (10),
	`challegeMapID` int (10),
	`challengeLevel` int (10),
	`challengeAffix` int (10),
	`challengeAffix1` int (10),
	`challengeAffix2` int (10),
	`challengeKeyIsCharded` int (10),
	`isdonateitem` tinyint (1),
PRIMARY KEY (`guid`,`owner_guid`,`itemEntry`,`randomPropertyId`,`context`,`dungeonEncounterID`,`createdTime`)
) ENGINE=INNODB DEFAULT CHARSET=utf8 COMMENT='';

