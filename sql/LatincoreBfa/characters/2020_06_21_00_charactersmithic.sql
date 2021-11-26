-- -- Volcando estructura para tabla legion_characters.challenge
-- CREATE TABLE IF NOT EXISTS `challenge` (
  -- `ID` int(11) NOT NULL,
  -- `GuildID` bigint(20) NOT NULL DEFAULT 0,
  -- `MapID` mediumint(9) NOT NULL DEFAULT 0,
  -- `ChallengeID` mediumint(6) NOT NULL DEFAULT 0,
  -- `RecordTime` int(11) NOT NULL DEFAULT 0,
  -- `Date` int(11) NOT NULL DEFAULT 0,
  -- `ChallengeLevel` smallint(6) NOT NULL DEFAULT 0,
  -- `TimerLevel` smallint(6) NOT NULL DEFAULT 0,
  -- `Affixes` longtext CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  -- `ChestID` int(10) NOT NULL DEFAULT 0,
  -- PRIMARY KEY (`ID`) USING BTREE,
  -- KEY `mapID` (`MapID`) USING BTREE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- -- Volcando datos para la tabla legion_characters.challenge: ~41 rows (aproximadamente)
-- /*!40000 ALTER TABLE `challenge` DISABLE KEYS */;
-- INSERT INTO `challenge` (`ID`, `GuildID`, `MapID`, `ChallengeID`, `RecordTime`, `Date`, `ChallengeLevel`, `TimerLevel`, `Affixes`, `ChestID`) VALUES
	-- (1, 0, 1466, 0, 273561, 1546792860, 10, 3, '', 252668),
	-- (2, 0, 1466, 0, 152150, 1546793630, 10, 3, '', 252668),
	-- (3, 0, 1501, 0, 2727878, 1558133724, 21, 0, '5 14 10 ', 252677),
	-- (4, 0, 1477, 0, 1984493, 1558136236, 20, 2, '5 14 10 ', 252056),
	-- (5, 0, 1477, 0, 2427970, 1558178561, 23, 1, '5 14 10 ', 252056),
	-- (6, 0, 1501, 0, 3157539, 1558199441, 24, 0, '5 14 10 ', 252677),
	-- (7, 0, 1456, 0, 2028229, 1558202188, 22, 1, '5 14 10 ', 252665),
	-- (8, 0, 1492, 0, 1610491, 1558204984, 20, 0, '5 14 10 ', 252680),
	-- (9, 0, 1477, 0, 1549741, 1558212257, 19, 3, '5 14 10 ', 252056),
	-- (10, 0, 1492, 0, 1672740, 1558213817, 22, 0, '5 14 10 ', 252680),
	-- (11, 0, 1493, 0, 3105862, 1558218007, 21, 0, '5 14 10 ', 252674),
	-- (12, 0, 1458, 0, 1800896, 1558219919, 20, 1, '5 14 10 ', 252671),
	-- (13, 0, 1466, 0, 1338187, 1558221863, 21, 2, '5 14 10 ', 252668),
	-- (14, 0, 1458, 0, 2032340, 1558224045, 23, 0, '5 14 10 ', 252671),
	-- (15, 0, 1651, 0, 1674529, 1558266353, 22, 2, '5 14 10 ', 269871),
	-- (16, 0, 1753, 0, 2131830, 1558907561, 22, 0, '6 4 9 ', 272689),
	-- (17, 0, 1492, 0, 1151400, 1558908867, 21, 2, '6 4 9 ', 252680),
	-- (18, 0, 1477, 0, 2254960, 1558911214, 23, 1, '6 4 9 ', 252056),
	-- (19, 1, 1458, 0, 2149442, 1559067354, 24, 0, '6 4 9 ', 252671),
	-- (20, 1, 1651, 0, 1844431, 1559070955, 19, 2, '6 4 9 ', 269852),
	-- (21, 1, 1571, 0, 2537718, 1559081724, 19, 0, '6 4 9 ', 252686),
	-- (22, 1, 1651, 0, 4331811, 1559219291, 23, 0, '6 4 9 ', 269852),
	-- (23, 1, 1477, 0, 2364143, 1559237729, 21, 1, '6 4 9 ', 252056),
	-- (24, 1, 1456, 0, 1616304, 1559239390, 20, 2, '6 4 9 ', 252665),
	-- (25, 1, 1466, 0, 1895417, 1559428751, 23, 0, '7 2 10 ', 252668),
	-- (26, 1, 1458, 0, 2000234, 1559430816, 22, 0, '7 2 10 ', 252671),
	-- (27, 1, 1477, 0, 1840601, 1559432979, 21, 2, '7 2 10 ', 252056),
	-- (28, 1, 1456, 0, 2762397, 1559435729, 23, 0, '7 2 10 ', 252665),
	-- (29, 1, 1651, 0, 3087125, 1559439102, 18, 0, '7 2 10 ', 269852),
	-- (30, 1, 1456, 0, 1096942, 1559440431, 17, 3, '7 2 10 ', 252665),
	-- (31, 1, 1458, 0, 1323940, 1559442257, 20, 2, '7 2 10 ', 252671),
	-- (32, 1, 1456, 0, 2240010, 1559480444, 22, 0, '7 2 10 ', 252665),
	-- (33, 1, 1477, 0, 1881686, 1559504677, 20, 2, '7 2 10 ', 252056),
	-- (34, 1, 1466, 0, 3214439, 1559941847, 22, 0, '7 2 10 ', 252668),
	-- (35, 1, 1456, 0, 3055663, 1560009878, 21, 0, '9 10 6 ', 252665),
	-- (36, 1, 1477, 0, 1608273, 1560011920, 20, 3, '9 10 6 ', 252056),
	-- (37, 1, 1458, 0, 1503774, 1560014126, 22, 2, '9 10 6 ', 252671),
	-- (38, 1, 1516, 0, 3296680, 1563044883, 22, 0, '9 10 6 ', 252683),
	-- (39, 1, 1458, 0, 1574050, 1563047670, 21, 2, '9 10 6 ', 252671),
	-- (40, 1, 1456, 0, 1744580, 1563059559, 20, 1, '9 10 6 ', 252665),
	-- (41, 1, 1458, 0, 1519230, 1563062458, 21, 2, '9 10 6 ', 252671);
-- /*!40000 ALTER TABLE `challenge` ENABLE KEYS */;

-- -- Volcando estructura para tabla legion_characters.challenge_key
-- CREATE TABLE IF NOT EXISTS `challenge_key` (
  -- `guid` int(10) NOT NULL DEFAULT 0,
  -- `ID` mediumint(6) unsigned NOT NULL DEFAULT 0,
  -- `Level` tinyint(3) unsigned NOT NULL DEFAULT 0,
  -- `Affix` tinyint(3) unsigned NOT NULL DEFAULT 0,
  -- `Affix1` tinyint(3) unsigned NOT NULL DEFAULT 0,
  -- `Affix2` tinyint(3) unsigned NOT NULL DEFAULT 0,
  -- `KeyIsCharded` tinyint(3) unsigned NOT NULL DEFAULT 0,
  -- `timeReset` int(10) unsigned NOT NULL DEFAULT 0,
  -- `InstanceID` int(10) unsigned NOT NULL DEFAULT 0,
  -- PRIMARY KEY (`guid`) USING BTREE,
  -- KEY `guid` (`guid`) USING BTREE,
  -- KEY `timeReset` (`timeReset`) USING BTREE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- -- Volcando datos para la tabla legion_characters.challenge_key: ~0 rows (aproximadamente)
-- /*!40000 ALTER TABLE `challenge_key` DISABLE KEYS */;
-- /*!40000 ALTER TABLE `challenge_key` ENABLE KEYS */;

-- -- Volcando estructura para tabla legion_characters.challenge_member
-- CREATE TABLE IF NOT EXISTS `challenge_member` (
  -- `id` int(11) NOT NULL,
  -- `member` bigint(20) NOT NULL DEFAULT 0,
  -- `specID` mediumint(6) NOT NULL DEFAULT 0,
  -- `ChallengeLevel` smallint(6) NOT NULL DEFAULT 0,
  -- `Date` int(10) NOT NULL DEFAULT 0,
  -- `ChestID` int(10) NOT NULL DEFAULT 0,
  -- KEY `id` (`id`,`member`) USING BTREE,
  -- KEY `member` (`member`) USING BTREE,
  -- KEY `Date` (`Date`) USING BTREE,
  -- KEY `ChallengeLevel` (`ChallengeLevel`) USING BTREE,
  -- KEY `ChestID` (`ChestID`) USING BTREE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci ROW_FORMAT=COMPACT;

-- -- Volcando datos para la tabla legion_characters.challenge_member: ~184 rows (aproximadamente)
-- /*!40000 ALTER TABLE `challenge_member` DISABLE KEYS */;
-- INSERT INTO `challenge_member` (`id`, `member`, `specID`, `ChallengeLevel`, `Date`, `ChestID`) VALUES
	-- (1, 2, 259, 10, 1546792860, 252668),
	-- (1, 1, 259, 10, 1546792860, 252668),
	-- (2, 2, 259, 10, 1546793630, 252668),
	-- (2, 1, 259, 10, 1546793630, 252668),
	-- (3, 1363267, 577, 21, 1558133724, 252677),
	-- (3, 1363263, 73, 21, 1558133724, 252677),
	-- (3, 1363250, 259, 21, 1558133724, 252677),
	-- (3, 1363249, 105, 21, 1558133724, 252677),
	-- (3, 1363248, 253, 21, 1558133724, 252677),
	-- (4, 1363267, 577, 20, 1558136236, 252056),
	-- (4, 1363263, 73, 20, 1558136236, 252056),
	-- (4, 1363250, 259, 20, 1558136236, 252056),
	-- (4, 1363248, 253, 20, 1558136236, 252056),
	-- (5, 1363267, 577, 23, 1558178561, 252056),
	-- (5, 1363263, 73, 23, 1558178561, 252056),
	-- (5, 1363250, 259, 23, 1558178561, 252056),
	-- (5, 1363248, 253, 23, 1558178561, 252056),
	-- (6, 1363267, 577, 24, 1558199441, 252677),
	-- (6, 1363263, 73, 24, 1558199441, 252677),
	-- (6, 1363250, 259, 24, 1558199441, 252677),
	-- (6, 1363248, 253, 24, 1558199441, 252677),
	-- (7, 1363267, 577, 22, 1558202188, 252665),
	-- (7, 1363263, 73, 22, 1558202188, 252665),
	-- (7, 1363250, 259, 22, 1558202188, 252665),
	-- (7, 1363248, 253, 22, 1558202188, 252665),
	-- (8, 1363267, 577, 20, 1558204984, 252680),
	-- (8, 1363263, 73, 20, 1558204984, 252680),
	-- (8, 1363250, 259, 20, 1558204984, 252680),
	-- (8, 1363249, 105, 20, 1558204984, 252680),
	-- (8, 1363248, 253, 20, 1558204984, 252680),
	-- (9, 1363267, 577, 19, 1558212257, 252056),
	-- (9, 1363263, 73, 19, 1558212257, 252056),
	-- (9, 1363250, 259, 19, 1558212257, 252056),
	-- (9, 1363249, 105, 19, 1558212257, 252056),
	-- (9, 1363248, 253, 19, 1558212257, 252056),
	-- (10, 1363267, 577, 22, 1558213817, 252680),
	-- (10, 1363263, 73, 22, 1558213817, 252680),
	-- (10, 1363250, 259, 22, 1558213817, 252680),
	-- (10, 1363249, 105, 22, 1558213817, 252680),
	-- (10, 1363248, 253, 22, 1558213817, 252680),
	-- (11, 1363267, 577, 21, 1558218007, 252674),
	-- (11, 1363263, 73, 21, 1558218007, 252674),
	-- (11, 1363250, 259, 21, 1558218007, 252674),
	-- (11, 1363249, 105, 21, 1558218007, 252674),
	-- (11, 1363248, 253, 21, 1558218007, 252674),
	-- (12, 1363267, 577, 20, 1558219919, 252671),
	-- (12, 1363263, 73, 20, 1558219919, 252671),
	-- (12, 1363250, 259, 20, 1558219919, 252671),
	-- (12, 1363249, 105, 20, 1558219919, 252671),
	-- (12, 1363248, 253, 20, 1558219919, 252671),
	-- (13, 1363267, 577, 21, 1558221863, 252668),
	-- (13, 1363263, 73, 21, 1558221863, 252668),
	-- (13, 1363250, 259, 21, 1558221863, 252668),
	-- (13, 1363249, 105, 21, 1558221863, 252668),
	-- (13, 1363248, 253, 21, 1558221863, 252668),
	-- (14, 1363267, 577, 23, 1558224045, 252671),
	-- (14, 1363263, 73, 23, 1558224045, 252671),
	-- (14, 1363250, 259, 23, 1558224045, 252671),
	-- (14, 1363249, 105, 23, 1558224045, 252671),
	-- (14, 1363248, 253, 23, 1558224045, 252671),
	-- (15, 1363267, 577, 22, 1558266353, 269871),
	-- (15, 1363263, 73, 22, 1558266353, 269871),
	-- (15, 1363250, 259, 22, 1558266353, 269871),
	-- (15, 1363249, 105, 22, 1558266353, 269871),
	-- (15, 1363248, 253, 22, 1558266353, 269871),
	-- (16, 1363267, 577, 22, 1558907561, 272689),
	-- (16, 1363263, 73, 22, 1558907561, 272689),
	-- (16, 1363250, 259, 22, 1558907561, 272689),
	-- (16, 1363249, 105, 22, 1558907561, 272689),
	-- (16, 1363248, 253, 22, 1558907561, 272689),
	-- (17, 1363267, 577, 21, 1558908867, 252680),
	-- (17, 1363263, 73, 21, 1558908867, 252680),
	-- (17, 1363250, 259, 21, 1558908867, 252680),
	-- (17, 1363249, 105, 21, 1558908867, 252680),
	-- (17, 1363248, 253, 21, 1558908867, 252680),
	-- (18, 1363267, 577, 23, 1558911214, 252056),
	-- (18, 1363263, 73, 23, 1558911214, 252056),
	-- (18, 1363250, 259, 23, 1558911214, 252056),
	-- (18, 1363249, 105, 23, 1558911214, 252056),
	-- (18, 1363248, 253, 23, 1558911214, 252056),
	-- (19, 1363267, 577, 24, 1559067354, 252671),
	-- (19, 1363263, 73, 24, 1559067354, 252671),
	-- (19, 1363250, 259, 24, 1559067354, 252671),
	-- (19, 1363249, 105, 24, 1559067354, 252671),
	-- (19, 1363248, 253, 24, 1559067354, 252671),
	-- (20, 1363267, 577, 19, 1559070955, 269852),
	-- (20, 1363263, 73, 19, 1559070955, 269852),
	-- (20, 1363250, 259, 19, 1559070955, 269852),
	-- (20, 1363249, 105, 19, 1559070955, 269852),
	-- (20, 1363248, 253, 19, 1559070955, 269852),
	-- (21, 1363267, 577, 19, 1559081724, 252686),
	-- (21, 1363263, 73, 19, 1559081724, 252686),
	-- (21, 1363250, 259, 19, 1559081724, 252686),
	-- (21, 1363249, 102, 19, 1559081724, 252686),
	-- (21, 1363248, 253, 19, 1559081724, 252686),
	-- (22, 1363267, 577, 23, 1559219291, 269852),
	-- (22, 1363263, 73, 23, 1559219291, 269852),
	-- (22, 1363250, 259, 23, 1559219291, 269852),
	-- (22, 1363249, 105, 23, 1559219291, 269852),
	-- (22, 1363248, 253, 23, 1559219291, 269852),
	-- (23, 1363267, 577, 21, 1559237729, 252056),
	-- (23, 1363263, 73, 21, 1559237729, 252056),
	-- (23, 1363250, 259, 21, 1559237729, 252056),
	-- (23, 1363248, 253, 21, 1559237729, 252056),
	-- (24, 1363267, 577, 20, 1559239390, 252665),
	-- (24, 1363263, 73, 20, 1559239390, 252665),
	-- (24, 1363250, 259, 20, 1559239390, 252665),
	-- (24, 1363248, 253, 20, 1559239390, 252665),
	-- (25, 1363267, 577, 23, 1559428751, 252668),
	-- (25, 1363263, 73, 23, 1559428751, 252668),
	-- (25, 1363250, 259, 23, 1559428751, 252668),
	-- (25, 1363248, 253, 23, 1559428751, 252668),
	-- (26, 1363267, 577, 22, 1559430816, 252671),
	-- (26, 1363263, 73, 22, 1559430816, 252671),
	-- (26, 1363250, 259, 22, 1559430816, 252671),
	-- (26, 1363248, 253, 22, 1559430816, 252671),
	-- (27, 1363267, 577, 21, 1559432979, 252056),
	-- (27, 1363263, 73, 21, 1559432979, 252056),
	-- (27, 1363250, 259, 21, 1559432979, 252056),
	-- (27, 1363248, 253, 21, 1559432979, 252056),
	-- (28, 1363267, 577, 23, 1559435729, 252665),
	-- (28, 1363263, 73, 23, 1559435729, 252665),
	-- (28, 1363250, 259, 23, 1559435729, 252665),
	-- (28, 1363248, 253, 23, 1559435729, 252665),
	-- (29, 1363267, 577, 18, 1559439102, 269852),
	-- (29, 1363263, 73, 18, 1559439102, 269852),
	-- (29, 1363251, 64, 18, 1559439102, 269852),
	-- (29, 1363250, 259, 18, 1559439102, 269852),
	-- (29, 1363248, 253, 18, 1559439102, 269852),
	-- (30, 1363267, 577, 17, 1559440431, 252665),
	-- (30, 1363263, 73, 17, 1559440431, 252665),
	-- (30, 1363251, 64, 17, 1559440431, 252665),
	-- (30, 1363250, 259, 17, 1559440431, 252665),
	-- (30, 1363248, 253, 17, 1559440431, 252665),
	-- (31, 1363267, 577, 20, 1559442257, 252671),
	-- (31, 1363263, 73, 20, 1559442257, 252671),
	-- (31, 1363251, 63, 20, 1559442257, 252671),
	-- (31, 1363250, 259, 20, 1559442257, 252671),
	-- (31, 1363248, 253, 20, 1559442257, 252671),
	-- (32, 1363267, 577, 22, 1559480444, 252665),
	-- (32, 1363263, 73, 22, 1559480444, 252665),
	-- (32, 1363250, 259, 22, 1559480444, 252665),
	-- (32, 1363249, 105, 22, 1559480444, 252665),
	-- (32, 1363248, 253, 22, 1559480444, 252665),
	-- (33, 1363267, 577, 20, 1559504677, 252056),
	-- (33, 1363263, 73, 20, 1559504677, 252056),
	-- (33, 1363250, 259, 20, 1559504677, 252056),
	-- (33, 1363249, 105, 20, 1559504677, 252056),
	-- (33, 1363248, 253, 20, 1559504677, 252056),
	-- (34, 1363267, 577, 22, 1559941847, 252668),
	-- (34, 1363263, 73, 22, 1559941847, 252668),
	-- (34, 1363250, 259, 22, 1559941847, 252668),
	-- (34, 1363249, 105, 22, 1559941847, 252668),
	-- (34, 1363248, 253, 22, 1559941847, 252668),
	-- (35, 1363267, 577, 21, 1560009878, 252665),
	-- (35, 1363263, 73, 21, 1560009878, 252665),
	-- (35, 1363250, 259, 21, 1560009878, 252665),
	-- (35, 1363249, 105, 21, 1560009878, 252665),
	-- (35, 1363248, 253, 21, 1560009878, 252665),
	-- (36, 1363267, 577, 20, 1560011920, 252056),
	-- (36, 1363263, 73, 20, 1560011920, 252056),
	-- (36, 1363250, 259, 20, 1560011920, 252056),
	-- (36, 1363249, 105, 20, 1560011920, 252056),
	-- (36, 1363248, 253, 20, 1560011920, 252056),
	-- (37, 1363267, 577, 22, 1560014126, 252671),
	-- (37, 1363263, 73, 22, 1560014126, 252671),
	-- (37, 1363250, 259, 22, 1560014126, 252671),
	-- (37, 1363248, 253, 22, 1560014126, 252671),
	-- (38, 1363267, 577, 22, 1563044883, 252683),
	-- (38, 1363263, 73, 22, 1563044883, 252683),
	-- (38, 1363250, 259, 22, 1563044883, 252683),
	-- (38, 1363248, 253, 22, 1563044883, 252683),
	-- (39, 1363267, 577, 21, 1563047670, 252671),
	-- (39, 1363263, 73, 21, 1563047670, 252671),
	-- (39, 1363250, 259, 21, 1563047670, 252671),
	-- (39, 1363248, 253, 21, 1563047670, 252671),
	-- (40, 1363267, 577, 20, 1563059559, 252665),
	-- (40, 1363263, 73, 20, 1563059559, 252665),
	-- (40, 1363250, 259, 20, 1563059559, 252665),
	-- (40, 1363248, 253, 20, 1563059559, 252665),
	-- (41, 1363267, 577, 21, 1563062458, 252671),
	-- (41, 1363263, 73, 21, 1563062458, 252671),
	-- (41, 1363250, 259, 21, 1563062458, 252671),
	-- (41, 1363248, 253, 21, 1563062458, 252671);
-- /*!40000 ALTER TABLE `challenge_member` ENABLE KEYS */;

-- -- Volcando estructura para tabla legion_characters.challenge_oplote_loot
-- CREATE TABLE IF NOT EXISTS `challenge_oplote_loot` (
  -- `guid` int(10) NOT NULL DEFAULT 0,
  -- `chestListID` varchar(150) NOT NULL DEFAULT '',
  -- `date` int(10) NOT NULL DEFAULT 0,
  -- `ChallengeLevel` int(10) NOT NULL DEFAULT 0,
  -- PRIMARY KEY (`guid`) USING BTREE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- -- Volcando datos para la tabla legion_characters.challenge_oplote_loot: ~0 rows (aproximadamente)
-- /*!40000 ALTER TABLE `challenge_oplote_loot` DISABLE KEYS */;
-- /*!40000 ALTER TABLE `challenge_oplote_loot` ENABLE KEYS */;

-- -- Volcando estructura para tabla legion_characters.guild_challenges
-- CREATE TABLE IF NOT EXISTS `guild_challenges` (
  -- `GuildId` int(10) unsigned NOT NULL,
  -- `ChallengeType` int(1) NOT NULL DEFAULT 0,
  -- `ChallengeCount` int(1) DEFAULT NULL,
  -- PRIMARY KEY (`GuildId`,`ChallengeType`) USING BTREE
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- -- Volcando datos para la tabla legion_characters.guild_challenges: ~0 rows (aproximadamente)
-- /*!40000 ALTER TABLE `guild_challenges` DISABLE KEYS */;
-- /*!40000 ALTER TABLE `guild_challenges` ENABLE KEYS */;
