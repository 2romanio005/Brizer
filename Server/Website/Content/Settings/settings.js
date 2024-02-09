// загрузка остальных JS необходимых в settings
import { dataField } from "../dataField.js";
import { inputField } from "./inputField.js";

{
    const headerDataField = new dataField(["header", "title"]);         // Поле с названием

    const allMainInputField = [                                         // Изменяемые поля с оновными данными
        new inputField("CO2Threshold", /\D+/),
        new inputField("airingTime", /\D+/),
        new inputField("activeAiringTime", /\D+/),
        new inputField("requiredTemp", /\.+(?=\.)|[^0-9\.]/),
        new inputField("heaterCheckTime", /\D+/),
        new inputField("requiredTempUpdateTime", /\D+/),
        new inputField("CO2HumanAbsence", /\D+/),
        new inputField("humanAbsenceCheckingTime", /\D+/),
        new inputField("beginNightTime", /\D+/),
        new inputField("endNightTime", /\D+/),
        new inputField("activeDisplayTime", /\D+/),
    ];
    const passwordMainInputField = new inputField("mainPassword", /[а-яёА-ЯЁ]+/, "var(--font_color)");  // Изменяемое поле с паролем для оснонвых данных

    const allMemoryInputField = [                                       // Изменяемое поле данными для измнения графиков
        new inputField("changeableChart"),
        new inputField("changeableLine"),
        new inputField("changeableElem"),
        new inputField("newValueForChartElem", /[^nul\d]/),
    ];
    const passwordMemoryInputField = new inputField("memoryPassword", /[а-яёА-ЯЁ]+/, "var(--font_color)");  // Изменяемое поле с паролем для изменения графиков


    function rebindAtHTMLObjects() {
        for (const field of allMainInputField) {
            field.rebind();
        }
        passwordMainInputField.rebind();

        for (const field of allMemoryInputField) {
            field.rebind();
        }
        passwordMemoryInputField.rebind();

        main_settings_submit.onclick = sendMainData;        // при нжатии на кнопку сохранить изменение настроек
        memory_settings_submit.onclick = sendMemoryData;    // при нжатии на кнопку сохранить изменение графиков
    }

    function updateSettingsData() {
        // загрузка полей с данными
        uploadDataGET("http://" + activeHost + AllDataPaths[nameDataSettings])
            .then(successUpdateData)
            .catch(error);
        function successUpdateData(responseText) {
            let splittedResponseText = responseText.split(';');
            console.log("splittedResponseText", splittedResponseText);

            headerDataField.data = splittedResponseText[0];

            for (let i = 0; i < allMainInputField.length; i++) {
                allMainInputField[i].data = (i + 1 < splittedResponseText.length) ? splittedResponseText[i + 1] : "null";
            }

            // for (const inputField of mainInputField) {
            // }

            // const MemoryInputField = [
            // new inputField("CO2Threshold", /\D+/),
            // new inputField("airingTime", /\D+/),
            // new inputField("activeAiringTime", /\D+/),
            // ];
        }

        function error(error) {
            console.warn("In updateSettingsData(): " + error);
        }
    }

    function firstSettingsUpload() {
        rebindAtHTMLObjects();
        updateSettingsData();
    }


    function sendMainData() {
        let dataToSend = passwordMainInputField.generateDataToSend();
        for (const inputField of allMainInputField) {
            dataToSend += inputField.generateDataToSend();
        }
        dataToSend = dataToSend.slice(1);
        // console.log("sendMainData: " + dataToSend);

        passwordMainInputField.setColorBackground("var(--waitingColor)");               // включить цвет ожиданий
        sendDataPOST("http://" + activeHost + AllSavePaths[nameSaveMainSettings], dataToSend)
            .then(successSendData)
            .catch(error);
        function successSendData(responseText) {
            let result = (responseText === "1");
            let resultColor = (result ? "var(--successColor)" : "var(--errorColor)");
            passwordMainInputField.setColorBackground(resultColor);       // изменения приняты/отклонены
            for (const inputField of allMainInputField) {
                inputField.setColorIfChanged(resultColor);
                if (result) {
                    inputField.resetOldData();
                }
            }
        }

        function error(error) {
            console.warn("In sendMainData(): " + error); successSendData("0");
        }
    }

    function sendMemoryData() {
        let dataToSend = passwordMemoryInputField.generateDataToSend();
        for (const inputField of allMemoryInputField) {
            dataToSend += inputField.generateDataToSend();
        }
        dataToSend = dataToSend.slice(1);
        // console.log("sendMemoryData: " + dataToSend);

        passwordMemoryInputField.setColorBackground("var(--waitingColor)");               // включить цвет ожиданий
        sendDataPOST("http://" + activeHost + AllSavePaths[nameSaveMemorySettings], dataToSend)
            .then(successSendData)
            .catch(error);
        function successSendData(responseText) {
            let result = (responseText === "1");
            let resultColor = (result ? "var(--successColor)" : "var(--errorColor)");
            passwordMemoryInputField.setColorBackground(resultColor);                     // изменения приняты/откланены
            allMemoryInputField[3].setColor(resultColor);                                 // раскрасить только поле со значением элемента
            if (result) {
                allMemoryInputField[3].resetOldData();
            }
        }

        function error(error) {
            console.warn("In sendMemoryData(): " + error); successSendData("0");
        }
    }



    if (!flagInPageLoading) {         // загрузка данных при первой подгрузке этого js, если остальные файлы страницы уже загружены
        firstSettingsUpload();
    }



    window.addEventListener(
        "updateData",
        (e) => {
            let MainUrl = new URL(window.location.href);
            if (MainUrl.searchParams.get(paramNameContent) === nameContentSettings) {     // если сейчас загружена страница Settings
                console.log("used updateData Settings");   // LOG
                for (const inputField of allMainInputField) {
                    inputField.oldData = "null";
                }
                firstSettingsUpload();
            }
        },
        false,
    );
}

