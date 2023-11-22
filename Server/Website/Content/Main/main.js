// загрузка остальных JS необходимых в main
//uploadJS("/Content/Main/chartist/chartist.js", "module");//, document.getElementsByTagName("head")[0]);
//import {Chartist} from "./Content/Directing/chartist/chartist.min.js";

//import * as Chartist from "./chartist/chartist.js";
//import {Chartist} from "";

class myChartist {
    constructor(chart_id, labels_start, labels_len, path, divisor = 1) {
        this.#chart_id = chart_id;

        for (let i = 0; i < labels_len; i++) {
            this.#data.labels.push(String(labels_start + i));
        }

        this.path = path;

        this.#divisor = divisor;

        console.log("Created myChartist:",
            "\nid -", this.#chart_id,
            "\npath -", this.path,
            "\ndivisor -", this.#divisor,
            "\nlabels -", this.#data.labels,
        )
    }

    parseData(responseText) {
        this.#data.series = [];
        let line = responseText.split(';');
        for (let i = 0; i < line.length - 1; ++i) {
            this.#data.series.push([]);
            for (let point of line[i].split(',')) {
                this.#data.series[i].push(parseInt(point, 10) / this.#divisor);
            }
        }
        console.log(this.#data);        // LOG
    }

    updateSignature() {
        let visible_number = this.#data.series.length;
        while (visible_number > 0 && this.#data.series[visible_number - 1].length === 0) {
            --visible_number;
        }
        console.log(visible_number);// LOG
        for (let visible = 0; visible < visible_number; ++visible) {
            document.getElementById(this.#chart_id + '_' + String.fromCharCode('a'.charCodeAt() + visible)).style.display = "none";
        }
        for (let hidden = visible_number; hidden < this.#data.series.length; ++hidden) {
            document.getElementById(this.#chart_id + '_' + String.fromCharCode('a'.charCodeAt() + hidden)).style.display = "block";
        }

        new Chartist.Line('#' + this.#chart_id, this.#data, this.#options);
    }

    set path(path) {
        this.#path = path;
    }
    get path() {
        return this.#path;
    }

    #data = {
        labels: [],
        series: []
        //[null], [null], [null], [null], [null], [null], [null]
    };

    #options = {
        height: 350,
        showPoint: true,
        fullWidth: true,
    };

    #divisor;
    #chart_id;

    #path;
}


// const date_CO2 = {
//     labels: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23'],
//     series: [[null], [null], [null], [null], [null], [null], [null]]
// };
// const date_TEMP = {
//     labels: ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31'],
//     series: [[null], [null], [null], [null], [null], [null], [null]]
// };
// const date_RUB = {
//     labels: ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31'],
//     series: [[null], [null], [null], [null], [null], [null], [null]]
// };





// const street = document.getElementById("street");
// street.innerHTML = "null";
// const hot = document.getElementById("hot");
// hot.innerHTML = "null";
// const home = document.getElementById("home");
// home.innerHTML = "null";
// const ppm = document.getElementById("ppm");
// ppm.innerHTML = "null";
// const work_hot = document.getElementById("work_hot");
// work_hot.innerHTML = "null";
// const Wt_from_day = document.getElementById("Wt_from_day");
// Wt_from_day.innerHTML = "null";
// const RUB_naw_mon = document.getElementById("RUB_naw_mon");
// RUB_naw_mon.innerHTML = "null";
// const RUB_before_mon = document.getElementById("RUB_before_mon");
// RUB_before_mon.innerHTML = "null";
// const RUB_day = document.getElementById("RUB_day");
// RUB_day.innerHTML = "null";


// function parse_chart_data(massage, divisor, container) {
//     console.log(massage, container);
//     container = [];
//     console.log(massage, container);
//     let line = massage.responseText.split(';');
//     for (let i = 0; i < line.length - 1; ++i) {
//         container.push([]);
//         for (let point of line[i].split(',')) {
//             container[i].push(parseInt(point, 10) / divisor);
//         }
//     }
// }

// // прячет исчезнувшие и показывает новые графики
// function show_and_hide_chart_signature(chart_id, container) {
//     let visible_number = container.length;
//     while (visible_number > 0 && container[visible_number - 1].length === 0) {
//         --visible_number;
//     }
//     console.log(chart_id, visible_number, container);   // LOG
//     for (let visible = 0; visible < visible_number; ++visible) {
//         document.getElementById(chart_id + '_' + fromCharCode(charCodeAt('a') + visible)).style.display = "none";
//     }
//     for (let hiden = visible_number; hiden < 7; ++hiden) {
//         document.getElementById(chart_id + '_' + fromCharCode(charCodeAt('a') + hiden)).style.display = "block";
//     }
// }


const allChartists = [
    new myChartist("CO2_chart", 0, 24, "/Content/Main/LoadingData/CO2.txt"),
    // new myChartist("CO2_chart2", 0, 24, "2.txt"),
    // {chart: new myChartist("CO2_chart", 0, 24), path: "/Content/Main/LoadingData/CO2.txt"},
];

function load_all_data() {
    for (let chart of allChartists) {
        uploadHTML(chart.path)
            .then(updateChart)
            .catch((error) => console.error("FAILED:", chart.path));       // LOG
        
        function updateChart(responseText) {
            chart.parseData(responseText);
            chart.updateSignature();
            console.log("LOADED: ", responseText, "from", chart.path);     // LOG
        }
    }

    // function lol(responseText) {
    //     chart_CO2.parseData(responseText);
    //     chart_CO2.updateSignature();
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

// UNCOM
//window.setInterval(load_all_data, 60000);
// document.addEventListener('DOMContentLoaded', load_all_data);
load_all_data();