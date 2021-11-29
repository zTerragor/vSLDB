-- QUEST POI
DELETE FROM `quest_poi` WHERE `QuestID` = '26266'; 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26266, 0, 0, -1, 0, 0, 0, 52, 0, 1, 0, 0, 0, 0, 35662); 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26266, 0, 1, 0, 265062, 57988, 0, 52, 0, 1, 0, 0, 0, 0, 35662); 
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26266'; 
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26266, 1, 0, -10499, 1023, 35662);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26266, 0, 0, -10112, 1042, 35662);

-- Fix Quest: Feeding the Hungry and the Hopeless (QUEST ID 26271) Now it's blizzlike :P yeah bitches..
-- START QUEST FIX
-- Fix Homeless Stormwind Citizen
DELETE FROM `creature_template` WHERE `entry` IN (42386, 42384);
INSERT INTO `creature_template`(`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `FadeRegionRadius`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (42384, 0, 0, 0, 42625, 42414, 'Homeless Stormwind Citizen', '', '', NULL, '', 0, 9, 10, 0, 0, 0, 7, 0, 1, 1.14286, 1, 0, 0, 2000, 2000, 0, 0, 1, 33024, 2048, 0, 0, 0, 0, 0, 0, 7, 0, 0, 42384, 0, 0, 0, 0, 0, 0, 0, 0, 80383, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 'npc_hungry_hobo', 35662);
INSERT INTO `creature_template`(`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `FadeRegionRadius`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (42386, 0, 0, 0, 42625, 42617, 'Homeless Stormwind Citizen', '', '', NULL, '', 0, 9, 10, 0, 0, 0, 7, 0, 1, 1.14286, 1, 0, 0, 2000, 2000, 0, 0, 1, 33024, 2048, 0, 0, 0, 0, 0, 0, 7, 0, 0, 42386, 0, 0, 0, 0, 0, 0, 0, 0, 80382, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, '', 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 'npc_hungry_hobo', 35662);
DELETE FROM `creature_template_addon` WHERE `entry` IN (42386, 42384);
DELETE FROM `creature_addon` WHERE `guid` IN (214595, 214569, 214460, 214566, 214597, 214627, 214617, 214567, 214467, 214619, 214633, 214629, 214574, 214612, 214464, 214462, 214599, 214601, 214459, 214628, 214468, 214461, 214613, 214630);
-- spawn stew should not give kill credit when is spawned:P
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = '42617';
-- END QUEST FIX

-- added missing script to the right npc
UPDATE `creature_template` SET `ScriptName` = 'npc_westplains_drifter' WHERE `entry` = '42391';