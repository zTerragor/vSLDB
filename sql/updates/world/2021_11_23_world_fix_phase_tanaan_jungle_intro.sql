/*
**************************
*    BfaCore Reforged    *
**************************
*/

-- Warlords of Draenor : Tanaan Jungle (Intro)

DELETE FROM phase_area WHERE AreaId IN(7044,7037,7041);
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 169, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 170, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 172, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 173, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 175, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 176, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 177, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7037, 179, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 169, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 170, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 172, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 173, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 174, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 175, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 176, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 177, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 179, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 180, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 181, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7041, 182, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 169, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 170, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 172, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 173, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 175, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 176, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 177, 'TanaanJungleIntro');
REPLACE INTO phase_area (`AreaId`, `PhaseId`, `Comment`) VALUES (7044, 179, 'TanaanJungleIntro');

UPDATE gameobject SET PhaseId = 0 WHERE guid IN (1249910,1250112,1250120,1250124,1250125,1250126,1250129,1250175,1250178,1250179,1250180,1250182,1250184,1250186,1250188,1250190,1460376);
