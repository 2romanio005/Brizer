#include "settings.h"


String sensors = String(brizerMainTitle) + ";-2.56;17.19;26.19;693;19;72;5;286;0";
String graf_CO2 = "null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null;810,764,720,674,694,695,694,597,473,401,540,746,516,550,581,494,648,640,698,701,752,709,541,672;788,767,761,751,736,740,735,667,533,581,548,465,404,434,442,435,458,546,689,869,813,808,765,667;";
String graf_TEMP = "171,-125;-1496,-2019,-2523,-2638,-2387,-1870,-1804,-863,-185,-246,-481,-1260,-1643,-1428,-1045,-1091,null,-1066,-568,-1427,-1389,-364,null,167,46,-271,-263,-100,237,104,1;-517,-545,-630,-546,-821,null,-1440,-1573,-1240,-1161,-923,-523,-260,-426,-550,-302,97,129,238,96,-9,21,null,-25,-210,-245,-379,-360,-308,-459,-870;709,294,148,420,603,577,595,680,615,649,603,526,198,51,53,-202,null,null,-542,null,-481,-559,-466,null,-904,null,-498,-270,-477,-484;1410,1305,1252,1268,1135,780,605,347,341,423,673,947,866,1063,839,605,506,399,251,193,132,111,260,202,50,-136,-160,-37,32,36,5;2252,2136,1963,1837,1861,1791,1723,1759,1774,1918,2036,2066,2116,1884,1582,1450,1392,null,1588,1752,1867,1911,2116,1833,1543,1430,1488,1750,1717,1722;2435,2524,2437,2333,2353,2472,2836,2564,2489,2419,2420,2353,2339,2385,2450,2471,2569,2325,1887,1976,2135,2054,1919,1730,1940,1938,1937,1925,1990,2018,2311;";
String graf_RUB = "544,707;933,1230,1429,1622,1566,1462,1369,1144,886,876,927,1050,1205,1161,1082,1113,null,1110,858,1103,950,616,null,661,582,561,803,752,483,615,401;743,926,893,513,809,null,1384,1074,674,1010,956,590,658,773,677,813,679,371,548,654,489,619,null,571,634,627,741,736,682,845,911;352,485,481,550,288,231,188,387,434,354,413,469,329,574,566,651,null,null,1245,null,487,797,753,null,1060,null,581,798,793,529;41,40,90,69,186,322,453,562,491,556,402,219,281,212,254,281,336,479,521,434,723,686,287,431,606,672,706,645,734,432,568;0,0,0,7,0,1,17,1,20,8,0,0,0,0,19,56,19,null,72,0,0,0,0,0,15,83,47,0,9,16;0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,6,0,0,3,0,0,0,0;";


#define numberMainSettingsArg 13
const char *const allNameMainSettingsArg[numberMainSettingsArg] = {
  "mainPassword",
  brizerSettingsTitle,
  "CO2Threshold",
  "airingTime",
  "activeAiringTime",
  "requiredTemp",
  "heaterCheckTime",
  "requiredTempUpdateTime",
  "CO2HumanAbsence",
  "humanAbsenceCheckingTime",
  "beginNightTime",
  "endNightTime",
  "activeDisplayTime"
};

#define numberMainSettingsMessage 12
String mainSettingsMessage[numberMainSettingsMessage] = {
  String(brizerSettingsTitle),
  "0",
  "0",
  "0",
  "0.0",
  "0",
  "0",
  "0",
  "0",
  "0",
  "0",
  "0",
};

#define numberMemorySettingsArg 5
const char *const allNameMemorySettingsArg[numberMemorySettingsArg] = {
  "memoryPassword",
  "changeableChart",
  "changeableLine",
  "changeableElem",
  "newValueForChartElem"
};
