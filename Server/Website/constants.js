const paramNameContent = "nameContent";   // имя параметра с путём к контенту страницы 
const paramHost = "host";                 // имя параметра с путём к данным


const eventUpdateData = new Event("updateData");  // обновление загруженой страницы


const hostRoman = "94.242.44.182:56567";
const hostBorey = "94.242.44.182:56568";
const hostTest = "127.0.0.1:3000";
const hostTestCORS = "192.168.1.144:80";

const nameContentDirecting = "Directing";
const nameContentMain = "Main";
const nameContentSettings = "Settings";

const AllPagesPaths =
{
    "": ["/Content/Directing/directing.html"],
    [nameContentDirecting]: ["/Content/Directing/directing.html"],
    [nameContentMain]: ["/Content/Main/main.html", "/Content/Main/myChartist.js", "/Content/dataField.js", "/Content/Main/main.js"],
    [nameContentSettings]: ["/Content/Settings/settings.html", "/Content/dataField.js", "/Content/Settings/inputField.js", "/Content/Settings/settings.js"],
}


const nameDataMain = "MainData";
const nameDataCO2 = "CO2";
const nameDataTempChart = "TempChart";
const nameDataRubChart = "RubChart";
const nameDataSettings = "SettingsData";

const AllDataPaths =
{
    [nameDataMain]: "/LoadingData/Main/MainData",
    [nameDataCO2]: "/LoadingData/Main/CO2",
    [nameDataTempChart]: "/LoadingData/Main/TempChart",
    [nameDataRubChart]: "/LoadingData/Main/RubChart",
    [nameDataSettings]: "/LoadingData/Settings/SettingsData",
}

const nameSaveMainSettings = "MainSettings";
const nameSaveMemorySettings = "MemorySettings";

const AllSavePaths =
{
    [nameSaveMainSettings]: "/SavingData/Settings/MainSettings",
    [nameSaveMemorySettings]: "/SavingData/Settings/MemorySettings",
}






