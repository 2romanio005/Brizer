
const options = {
    height: 350,
    showPoint: true,
    fullWidth: true,
};

const date_CO2 = {
    labels: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23'],
    series: [[null], [null], [null], [null], [null], [null], [null]]
};
const date_TEMP = {
    labels: ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31'],
    series: [[null], [null], [null], [null], [null], [null], [null]]
};
const date_RUB = {
    labels: ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31'],
    series: [[null], [null], [null], [null], [null], [null], [null]]
};





const street = document.getElementById("street");
street.innerHTML = "null";
const hot = document.getElementById("hot");
hot.innerHTML = "null";
const home = document.getElementById("home");
home.innerHTML = "null";
const ppm = document.getElementById("ppm");
ppm.innerHTML = "null";
const work_hot = document.getElementById("work_hot");
work_hot.innerHTML = "null";
const Wt_from_day = document.getElementById("Wt_from_day");
Wt_from_day.innerHTML = "null";
const RUB_naw_mon = document.getElementById("RUB_naw_mon");
RUB_naw_mon.innerHTML = "null";
const RUB_before_mon = document.getElementById("RUB_before_mon");
RUB_before_mon.innerHTML = "null";
const RUB_day = document.getElementById("RUB_day");
RUB_day.innerHTML = "null";


function parse_chart_data(massage, divisor, container) {
    console.log(massage, container);
    container = [];
    console.log(massage, container);
    let line = massage.responseText.split(';');
    for (let i = 0; i < line.length - 1; ++i) {
        container.push([]);
        for(let point of line[i].split(',')){
            container[i].push(parseInt(point, 10) / divisor);
        }
    }
}
function show_and_hide_chart_signature(chart_id, container){
    let visible_number = container.length;
    while(visible_number > 0 && container[visible_number - 1].length === 0){
        --visible_number;
    }
    console.log(chart_id, visible_number, container);
    for(let visible = 0; visible < visible_number; ++visible){
        document.getElementById(chart_id + '_' + fromCharCode(charCodeAt('a') + visible)).style.display = "none";
    }
    for(let hiden = visible_number; hiden < 7; ++hiden){
        document.getElementById(chart_id + '_' + fromCharCode(charCodeAt('a') + hiden)).style.display = "block";
    }
}

function load_all_data() {
    let massage = createRequestObject();
    massage.open('GET', '/load_data', true);
    massage.onload = function () {
        let ansver = massage.responseText.split(';');

        street.innerHTML = ansver[0];
        hot.innerHTML = ansver[1];
        home.innerHTML = ansver[2];
        ppm.innerHTML = ansver[3];
        work_hot.innerHTML = ansver[4];
        Wt_from_day.innerHTML = ansver[5];
        RUB_naw_mon.innerHTML = ansver[6];
        RUB_before_mon.innerHTML = ansver[7];
        RUB_day.innerHTML = ansver[8];
    }
    massage.send();

    let massage_CO2 = createRequestObject();
    massage_CO2.open('GET', '/load_data_CO2', true);
    massage_CO2.onload = function () {
        // let ansver = massage_CO2.responseText.split(';');
        // for (let i = 0; i < ansver.length - 1; ++i) {
        //     let parse = ansver[i].split(',');
        //     for (let j = 0; j < parse.length; ++j) {
        //         date_CO2.series[i][j] = parseInt(parse[j], 10);
        //     }
        // }
        parse_chart_data(massage_CO2, 1, date_CO2.series);
        show_and_hide_chart_signature("CO2_chart", date_CO2.series);
        new Chartist.Line('#CO2_chart', date_CO2, options);
    }
    massage_CO2.send();

    let massage_TEMP = createRequestObject();
    massage_TEMP.open('GET', '/load_data_TEMP', true);
    massage_TEMP.onload = function () {
        // let ansver = massage_TEMP.responseText.split(';');
        // for (let i = 0; i < ansver.length - 1; ++i) {
        //     let parse = ansver[i].split(',');
        //     for (let j = 0; j < parse.length; ++j) {
        //         date_TEMP.series[i][j] = parseInt(parse[j], 10) / 100.0;
        //     }
        // }
        parse_chart_data(massage_CO2, 100.0, date_TEMP.series);
        show_and_hide_chart_signature("TEMP_chart", date_CO2.series);
        new Chartist.Line('#TEMP_chart', date_TEMP, options);
    }
    massage_TEMP.send();

    let massage_RUB = createRequestObject();
    massage_RUB.open('GET', '/load_data_RUB', true);
    massage_RUB.onload = function () {
        // let ansver = massage_RUB.responseText.split(';');
        // for (let i = 0; i < ansver.length - 1; ++i) {
        //     let parse = ansver[i].split(',');
        //     for (let j = 0; j < parse.length; ++j) {
        //         date_RUB.series[i][j] = parseInt(parse[j], 10) / 100.0;
        //     }
        // }
        parse_chart_data(massage_CO2, 100.0, date_RUB.series);
        show_and_hide_chart_signature("RUB_chart", date_CO2.series);
        new Chartist.Line('#RUB_chart', date_RUB, options);
    }
    massage_RUB.send();

}

window.setInterval(load_all_data, 60000);
document.addEventListener('DOMContentLoaded', load_all_data);
