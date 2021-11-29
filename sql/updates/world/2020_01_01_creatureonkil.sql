DROP TABLE IF EXISTS `creature_onkill_reputation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creature_onkill_reputation` (
  `creature_id` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Creature Identifier',
  `RewOnKillRepFaction1` smallint(6) NOT NULL DEFAULT 0,
  `RewOnKillRepFaction2` smallint(6) NOT NULL DEFAULT 0,
  `MaxStanding1` tinyint(4) NOT NULL DEFAULT 0,
  `IsTeamAward1` tinyint(4) NOT NULL DEFAULT 0,
  `RewOnKillRepValue1` mediumint(8) NOT NULL DEFAULT 0,
  `MaxStanding2` tinyint(4) NOT NULL DEFAULT 0,
  `IsTeamAward2` tinyint(4) NOT NULL DEFAULT 0,
  `RewOnKillRepValue2` mediumint(9) NOT NULL DEFAULT 0,
  `TeamDependent` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`creature_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature OnKill Reputation gain';
/*!40101 SET character_set_client = @saved_cs_client */;
