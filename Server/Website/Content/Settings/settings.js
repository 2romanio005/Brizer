// загрузка остальных JS необходимых в settings
import { dataField } from "../dataField.js";
import { inputField } from "./inputField.js";

{
    function updateData() {
        let MainUrl = new URL(window.location.href);
        let hostData = MainUrl.searchParams.get(paramHost);

        console.log("Active hostData:", activeHost);
        if (activeHost != hostData) {
            activeHost = hostData;
            console.log("New hostData:", activeHost);
        }

        // загрузка полей с данными
        uploadHTML("http://" + activeHost + "/Content/Settings/LoadingData/data.txt")
            .then(successUpdateData)
            .catch((error) => console.warn("FAILED:", "http://" + activeHost + "/Content/Settings/LoadingData/data.txt", error));
        function successUpdateData(responseText) {
            let splittedResponseText = responseText.split(';');
            console.log("splittedResponseText", splittedResponseText);

            let i = 0;
            headerDataField.data = splittedResponseText[i++];

            for (const inputField of mainInputField) {
                inputField.data = splittedResponseText[i++];
            }

            // const MemoryInputField = [
            // new inputField("CO2_no_good", /\D+/),
            // new inputField("on_vent", /\D+/),
            // new inputField("vent", /\D+/),
            // ];
        }
    }

    function sendPostData(url, dataToSend) {
        return new Promise(function (resolve, reject) {
            let http = createRequestObject();

            if (!http) {
                console.log("failed createRequestObject() at sendPostData from" + url);     // FIXME
                reject("failed createRequestObject() at sendPostData from" + url);
            }

            http.open("POST", url, true);
            http.setRequestHeader("Content-Type", "text/plain");
            http.onload = () => {
                if (http.status == 200) {
                    resolve(http.responseText);         // вернуть ответ сервера
                } else {
                    reject(http.status);
                }
            };
            http.send(dataToSend);
        });
    }

    function sendDataMain() {
        let dataToSend = "password=" + document.getElementById("password").value;
        for (const inputField of mainInputField) {
            dataToSend += inputField.generateDataToSend();
        }
        //dataToSend = dataToSend.slice(1);

        document.getElementById("password").style.background = "var(--waitingColor)";               // включить цвет ожиданий
        sendPostData("http://" + activeHost + "/Content/Settings/SendedData/main.txt", dataToSend)
            .then(successSendData)
            .catch((error) => { console.warn("FAILED:", "http://" + activeHost + "/Content/Settings/SendedData/main.txt", error); successSendData("0"); });
        function successSendData(responseText) {
            let resultColor = (responseText === "1" ? "var(--successColor)" : "var(--errorColor)")
            document.getElementById("password").style.background = resultColor;       // изменения приняты/откланены
            for (const inputField of mainInputField) {
                inputField.updateData(resultColor);
            }
        }
    }

    function sendDataMemory() {

        sendPostData("http://" + activeHost + "/Content/Settings/SendedData/memory", dataToSend);
    }


    // активный host с данными
    let activeHost = "";

    // Поля с данными
    const headerDataField = new dataField(["header", "title"]);

    const mainInputField = [
        new inputField("CO2_no_good", /\D+/),
        new inputField("on_vent", /\D+/),
        new inputField("vent", /\D+/),
        new inputField("celsius_NORM", /\.+(?=\.)|[^0-9\.]/),
        new inputField("check_temp", /\D+/),
        new inputField("update_celsius_NORM", /\D+/),
        new inputField("CO2_out_people", /\D+/),
        new inputField("time_out_people", /\D+/),
        new inputField("time_nite", /\D+/),
        new inputField("time_no_nite", /\D+/),
        new inputField("on_display", /\D+/),
    ];
    //const passwordInputField = new inputField("password");

    const MemoryInputField = [
        // new inputField("CO2_no_good", /\D+/),
        // new inputField("on_vent", /\D+/),
        // new inputField("vent", /\D+/),
    ];
    //const memoryInputField = new inputField("memory_password");


    updateData();

    window.addEventListener(
        "updateData",
        (e) => {
            let MainUrl = new URL(window.location.href);
            if (MainUrl.searchParams.get(paramNameContent) === nameContentSettings) {     // если сейчас загружена страница Settings
                console.log("used updateData Settings");   // LOG
                for (const inputField of mainInputField){
                    inputField.oldData = "null";
                }
                updateData();
            }
        },
        false,
    );

    main_submit.onclick = sendDataMain;


    //main_submit.onclick = main_submit
}

