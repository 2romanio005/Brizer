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
            document.getElementById("form_main_submit").action = MainUrl;
            document.getElementById("form_memory_submit").action = MainUrl;
            console.log("New hostData:", activeHost);
        }

        // загрузка полей с данными
        uploadHTML("http://" + activeHost + "/Content/Settings/LoadingData/data.txt")
            .then(successUpdateData)
            .catch((error) => console.warn("FAILED:", "http://" + activeHost + "/Content/Settings/LoadingData/data.txt", error));
        function successUpdateData(responseText) {
            let splittedResponseText = responseText.split(';');
            console.log("splittedResponseText", splittedResponseText);
            for (let i = 0; i < allInputField.length; i++) {
                allInputField[i].data = splittedResponseText[i];
            }
        }
    }


    // активный host с данными
    let activeHost = "";

    // Поля с данными
    const allInputField = [
        new dataField(["header", "title"]),
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


    updateData();

    window.addEventListener(
        "updateData",
        (e) => {
            let MainUrl = new URL(window.location.href);
            if (MainUrl.searchParams.get(paramNameContent) === nameContentSettings) {     // если сейчас загружена страница Settings
                console.log("used updateData Settings");   // LOG
                updateData();
            }
        },
        false,
    );

    //main_submit.onclick = main_submit
}

