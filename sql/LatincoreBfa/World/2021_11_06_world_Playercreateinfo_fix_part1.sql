/*
**************************
*    BfaCore Reforged    *
**************************
*/

ALTER TABLE `playercreateinfo`
  ADD `intro_movie_id` int(10) unsigned DEFAULT NULL AFTER `orientation`,
  ADD `intro_scene_id` int(10) unsigned DEFAULT NULL AFTER `intro_movie_id`,
  ADD `npe_intro_scene_id` int(10) unsigned DEFAULT NULL AFTER `intro_scene_id`;


DELETE FROM `playercreateinfo` WHERE `race` IN (27, 28, 29, 30, 31, 32, 34, 35, 36, 37);
INSERT INTO `playercreateinfo` (`race`,`class`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`intro_movie_id`,`intro_scene_id`) VALUES
-- Nightborne
(27,1,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,3,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,8,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,4,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,5,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,9,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,10,1220,288.381011962890625,3352.22998046875,145.444000244140625,2.3515344,NULL,1900),
(27,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Highmountain Tauren
(28,1,1220,4079.050048828125,4392.3798828125,670.60302734375,5.181551,NULL,1901),
(28,3,1220,4079.050048828125,4392.3798828125,670.60302734375,5.181551,NULL,1901),
(28,11,1220,4079.050048828125,4392.3798828125,670.60302734375,5.181551,NULL,1901),
(28,7,1220,4079.050048828125,4392.3798828125,670.60302734375,5.181551,NULL,1901),
(28,10,1220,4079.050048828125,4392.3798828125,670.60302734375,5.181551,NULL,1901),
(28,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Maghar Orc
(36,1,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,3,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,8,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,4,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,2,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,7,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,10,1,1968.949951171875,-4742.919921875,37.19570159912109375,1.2225107,NULL,2138),
(36,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Zandalari Troll
(31,1,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,3,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,8,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,4,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,5,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,2,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,11,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,7,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,10,1642,-1127.300048828125,805.42999267578125,500.22900390625,3.184004,NULL,2247),
(31,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Vulpera
(35,1,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,3,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,8,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,4,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,2,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,9,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,7,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,10,1,1945.5400390625,-4635.64013671875,33.23099899291992187,5.653418,NULL,2395),
(35,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Void Elf
(29,1,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,3,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,8,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,4,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,2,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,9,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,10,1865,2121,3318,54.7061004638671875,0.08726646,NULL,1903),
(29,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Lightforged Draenei
(30,1,1860,458.822998046875,1449.6099853515625,757.572998046875,0.46642527,NULL,1902),
(30,3,1860,458.822998046875,1449.6099853515625,757.572998046875,0.46642527,NULL,1902),
(30,8,1860,458.822998046875,1449.6099853515625,757.572998046875,0.46642527,NULL,1902),
(30,2,1860,458.822998046875,1449.6099853515625,757.572998046875,0.46642527,NULL,1902),
(30,5,1860,458.822998046875,1449.6099853515625,757.572998046875,0.46642527,NULL,1902),
(30,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Dark Iron Dwarf
(34,1,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,3,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,8,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,4,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,2,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,9,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,5,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,7,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,10,2081,1621.1300048828125,536.64898681640625,201.4799957275390625,5.497962,NULL,2137),
(34,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Kul Tiran
(32,1,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,3,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,8,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,4,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,2,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,11,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,7,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,10,1643,1072.030029296875,-484.800994873046875,9.700130462646484375,1.3448513,NULL,2239),
(32,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394),

-- Mechagnome
(37,1,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,3,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,8,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,4,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,2,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,9,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,10,2268,711.45001220703125,606.843994140625,-238.526992797851562,2.214142,NULL,2393),
(37,6,2297,481.803009033203125,-2124.659912109375,840.85699462890625,3.1104908,NULL,2394);