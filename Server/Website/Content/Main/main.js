// загрузка остальных JS необходимых в main
import { myChartist } from "./myChartist.js";
import { dataField } from "./dataField.js";
//uploadJS("/Content/Main/myChartist.js", "module");//, document.getElementsByTagName("head")[0]);



function load_all_data() {
    // загрузка полей с данными
    uploadHTML("http://" + activeHostData + "/Content/Main/LoadingData/data.txt")
        .then(updateData)
        .catch((error) => console.error("FAILED:", "http://" + activeHostData + "/Content/Main/LoadingData/data.txt"));
    function updateData(responseText) {
        let splittedResponseText = responseText.split(';')
        for (let i = 0; i < allDataField.length; i++){
            allDataField[i].data = splittedResponseText[i];
        }
    }


    // загрузка графиков
    for (let chart of allChartists) {
        uploadHTML(chart.url.href)
            .then(updateChart)
            .catch((error) => console.error("FAILED:", chart.url.href));       // LOG

        function updateChart(responseText) {
            chart.parseData(responseText);
            chart.redraw();
            // console.log("LOADED: ", responseText, "from", chart.url.href);     // LOG
        }
    }

    // function lol(responseText) {
    //     chart_CO2.parseData(responseText);
    //     chart_CO2.redraw();
    //     console.log("LOADING CO2: ", responseText);
    // }

    // try {
    //     let a = new Chartist.Line('#CO2_chart', { labels: ["1", "2"], series: [[1, 4, 2]] }, { height: 350,
    //         showPoint: true,
    //         fullWidth: true,});
    // } catch (error) {
    //     console.error("error:", error);
    // }

    //uploadHTML("http://94.242.44.182:56567/load_data_RUB")
    // uploadHTML("/Content/Main/LoadingData/test.txt")
    //     .then((responseText) => { massage = responseText; console.log("LOADING DATA: ", responseText) })
    //     .catch((error) => console.error("failed:", "/Content/Main/LoadingData/test"));


    // createRequestObject();
    // massage.open('GET', '/Content/Main/LoadingData/test', true);
    // massage.onload = function () {
    //     let ansver = massage.responseText;
    //     console.log(ansver);
    // }
    // massage.send();






    // let massage = createRequestObject();
    // massage.open('GET', '/load_data', true);
    // massage.onload = function () {
    //     let ansver = massage.responseText.split(';');

    //     street.innerHTML = ansver[0];
    //     hot.innerHTML = ansver[1];
    //     home.innerHTML = ansver[2];
    //     ppm.innerHTML = ansver[3];
    //     work_hot.innerHTML = ansver[4];
    //     Wt_from_day.innerHTML = ansver[5];
    //     RUB_naw_mon.innerHTML = ansver[6];
    //     RUB_before_mon.innerHTML = ansver[7];
    //     RUB_day.innerHTML = ansver[8];
    // }
    // massage.send();

    // let massage_CO2 = createRequestObject();
    // massage_CO2.open('GET', '/load_data_CO2', true);
    // massage_CO2.onload = function () {
    //     // let ansver = massage_CO2.responseText.split(';');
    //     // for (let i = 0; i < ansver.length - 1; ++i) {
    //     //     let parse = ansver[i].split(',');
    //     //     for (let j = 0; j < parse.length; ++j) {
    //     //         date_CO2.series[i][j] = parseInt(parse[j], 10);
    //     //     }
    //     // }
    //     parse_chart_data(massage_CO2, 1, date_CO2.series);
    //     show_and_hide_chart_signature("CO2_chart", date_CO2.series);
    //     new Chartist.Line('#CO2_chart', date_CO2, options);
    // }
    // massage_CO2.send();

    // let massage_TEMP = createRequestObject();
    // massage_TEMP.open('GET', '/load_data_TEMP', true);
    // massage_TEMP.onload = function () {
    //     // let ansver = massage_TEMP.responseText.split(';');
    //     // for (let i = 0; i < ansver.length - 1; ++i) {
    //     //     let parse = ansver[i].split(',');
    //     //     for (let j = 0; j < parse.length; ++j) {
    //     //         date_TEMP.series[i][j] = parseInt(parse[j], 10) / 100.0;
    //     //     }
    //     // }
    //     parse_chart_data(massage_CO2, 100.0, date_TEMP.series);
    //     show_and_hide_chart_signature("TEMP_chart", date_CO2.series);
    //     new Chartist.Line('#TEMP_chart', date_TEMP, options);
    // }
    // massage_TEMP.send();

    // let massage_RUB = createRequestObject();
    // massage_RUB.open('GET', '/load_data_RUB', true);
    // massage_RUB.onload = function () {
    //     // let ansver = massage_RUB.responseText.split(';');
    //     // for (let i = 0; i < ansver.length - 1; ++i) {
    //     //     let parse = ansver[i].split(',');
    //     //     for (let j = 0; j < parse.length; ++j) {
    //     //         date_RUB.series[i][j] = parseInt(parse[j], 10) / 100.0;
    //     //     }
    //     // }
    //     parse_chart_data(massage_CO2, 100.0, date_RUB.series);
    //     show_and_hide_chart_signature("RUB_chart", date_CO2.series);
    //     new Chartist.Line('#RUB_chart', date_RUB, options);
    // }
    // massage_RUB.send();

}

function updateHostData() {
    let MainUrl = new URL(window.location.href);
    let hostData = MainUrl.searchParams.get(paramHostData);

    if (activeHostData != hostData) {
        activeHostData = hostData;
        console.log("New host:", activeHostData);

        for (let chart of allChartists) {
            chart.url.host = activeHostData;
            //console.log(chart);                     // LOG
        }
        load_all_data();
    }

}

// активный host с данными
let activeHostData = "";

// Поля с данными
const allDataField = [
    new dataField("ppm"),
    new dataField("street"),
    new dataField("hot"),
];

// Графики
const allChartists = [
    new myChartist("CO2_chart", 0, 24, "/Content/Main/LoadingData/CO2.txt"),
    // new myChartist("CO2_chart2", 0, 24, "2.txt"),
    // {chart: new myChartist("CO2_chart", 0, 24), path: "/Content/Main/LoadingData/CO2.txt"},
];


// TODO
//window.setInterval(load_all_data, 60000);
// document.addEventListener('DOMContentLoaded', load_all_data);
updateHostData();