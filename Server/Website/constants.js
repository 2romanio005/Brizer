const paramNameContent = "nameContent";   // имя параметра с путём к контенту страницы 
const paramHost = "host";                 // имя параметра с путём к данным


const eventUpdateData = new Event("updateData");


const hostRoman = "94.242.44.182:56567";
const hostBorey = "94.242.44.182:56568";
const hostTest = "127.0.0.1:3000";

const nameContentDirecting = "Directing";
const nameContentMain = "Main";
const nameContentSettings = "Settings";

const AllPagesPaths = 
{
    "":["/Content/Directing/index.html"],
    [nameContentDirecting]:["/Content/Directing/index.html"],
    [nameContentMain]:["/Content/Main/main.html","/Content/Main/main.js", "/Content/Main/myChartist.js", "/Content/Main/dataField.js"],
    [nameContentSettings]:["/Content/Settings/settings.html", "/Content/Settings/settings.js"],
}
console.log(AllPagesPaths);