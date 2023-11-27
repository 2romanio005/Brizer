// загрузка остальных JS необходимых в main
import { myChartist } from "./myChartist.js";
import { dataField } from "./dataField.js";
//uploadJS("/Content/Main/myChartist.js", "module");//, document.getElementsByTagName("head")[0]);

{

function updateData() {
    console.log("22222222222222222222222222222222222222222222222", allDataField);
    // загрузка полей с данными
    uploadHTML("http://" + activeHost + "/Content/Main/LoadingData/data.txt")
        .then(updateData)
        .catch((error) => console.warn("FAILED:", "http://" + activeHost + "/Content/Main/LoadingData/data.txt", error));
    function updateData(responseText) {
        let splittedResponseText = responseText.split(';');
        console.log("splittedResponseText", splittedResponseText);
        for (let i = 0; i < allDataField.length; i++) {
            allDataField[i].data = splittedResponseText[i];
        }
    }

    // загрузка графиков
    for (let chart of allChartists) {
        uploadHTML(chart.url.href)
            .then(updateChart)
            .catch((error) => console.warn("FAILED:", chart.url.href, error));       // LOG

        function updateChart(responseText) {
            chart.parseData(responseText);
            chart.redraw();
            // console.log("LOADED: ", responseText, "from", chart.url.href);        // LOG
        }
    }
}

function updateHost() {
    let MainUrl = new URL(window.location.href);
    let hostData = MainUrl.searchParams.get(paramHost);

    console.log("Active hostData:", activeHost);
    if (activeHost != hostData) {
        activeHost = hostData;
        //activeHost = "94.242.44.182:56567";
        console.log("New hostData:", activeHost);

        for (let chart of allChartists) {
            chart.url.host = activeHost;
            //console.log(chart);                     // LOG
        }
        return true;
    }
    return false;
}





// активный host с данными
let activeHost = "";

// Поля с данными
const allDataField = [
    new dataField(["header", "title"]),
];
//Бризер Borey;-4.06;0.31;24.00;424;0;1546;111;127;4



// TODO
//window.setInterval(updateData, 60000);
// document.addEventListener('DOMContentLoaded', updateData);
updateHost();
updateData();

// ploadHTML("http://94.242.44.182:56567/load_data_TEMP"); // FIXME

window.addEventListener(
    "updateData",
    (e) => {
        let MainUrl = new URL(window.location.href);
        if (MainUrl.searchParams.get(paramNameContent) === nameContentMain) {     // если сейчас загружена страница Main
            console.log("used updateData");   // LOG
            updateHost();
            updateData();
        }
    },
    false,
);}