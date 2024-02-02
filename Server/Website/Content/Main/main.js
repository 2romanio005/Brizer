// загрузка остальных JS необходимых в main
import { myChartist } from "./myChartist.js";
import { dataField } from "../dataField.js";

{
    function updateData() {
        let MainUrl = new URL(window.location.href);
        let hostData = MainUrl.searchParams.get(paramHost);

        console.log("Active hostData:", activeHost);
        if (activeHost != hostData) {
            activeHost = hostData;
            console.log("New hostData:", activeHost);

            for (let chart of allChartists) {
                chart.url.host = activeHost;
            }
        }
        // console.log("1111111111111111111111111111111111111111111111", allDataField);

        // загрузка полей с данными
        uploadHTML("http://" + activeHost + AllDataPaths[nameDataMain])
            .then(successUpdateData)
            .catch((error) => console.warn("FAILED:", "http://" + activeHost + AllDataPaths[nameDataMain], error));
        function successUpdateData(responseText) {
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


    // активный host с данными
    let activeHost = "";

    // Поля с данными
    const allDataField = [
        new dataField(["header", "title"]),
        new dataField(["street"]),
        new dataField(["hot"]),
        new dataField(["home"]),
        new dataField(["ppm"]),
        new dataField(["work_hot"]),
        new dataField(["Wt_from_day"]),
        new dataField(["RUB_naw_mon"]),
        new dataField(["RUB_before_mon"]),
        new dataField(["RUB_day"]),
    ];

    let displayedDays = [];
    let displayedMonths = [];
    {

        const allDaysOfWeek =
            [
                "воскресенье",
                "понедельник",
                "вторник",
                "среда",
                "четверг",
                "пятница",
                "суббота",
            ]

        const allMonth =
            [
                "Январь",
                "Февраль",
                "Март",
                "Апрель",
                "Май",
                "Июнь",
                "Июль",
                "Август",
                "Сентябрь",
                "Октябрь",
                "Ноябрь",
                "Декабрь",
            ]
        //new Date(Date.now() - 86400000); // that is: 24 * 60 * 60 * 1000
        //(new Date.setDate(date.getDate() - i)).getDate()
        let date = new Date();
        for (let i = 0; i < 7; ++i) {
            let iDaysAgo = new Date(date.valueOf() - i * 24 * 60 * 60 * 1000);
            displayedDays.push(String(iDaysAgo.getDate()) + ' ' + String(allDaysOfWeek[iDaysAgo.getDay()]));
            displayedMonths.push(allMonth[(date.getMonth() - i + 12) % 12]);
        }
        console.log(displayedDays);
    }
    // Графики
    const allChartists = [
        new myChartist("CO2_chart", 0, 24, AllDataPaths[nameDataCO2], displayedDays),
        new myChartist("TEMP_chart", 1, 31, AllDataPaths[nameDataTempChart], displayedMonths, 100),
        new myChartist("RUB_chart", 1, 31, AllDataPaths[nameDataRubChart], displayedMonths, 100),
    ];

    updateData(); // загрузка данных при первой подгрузке этого js

    window.addEventListener(     // загрузка данных при последующих обрашениях к этому js
        "updateData",
        (e) => {
            let MainUrl = new URL(window.location.href);
            if (MainUrl.searchParams.get(paramNameContent) === nameContentMain) {     // если сейчас загружена страница Main
                console.log("used event updateData Main");   // LOG
                updateData();
            }
        },
        false,
    );
}