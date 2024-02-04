export class inputField {
    constructor(fieldId, forbiddenExpressions = "", changedColor = "var(--waitingColor)", data = "null") {
        this.#fieldId = fieldId;
        this.oldData = "null";
        this.data = data;

        const HTML_field = eval(fieldId);
        HTML_field.onkeyup = () => {
            HTML_field.value = HTML_field.value.replace(forbiddenExpressions, '');
            this.setColorIfChanged(changedColor);
            // console.log("Changed: " + this.#fieldId);
        }
    }

    generateDataToSend() {
        return '&' + this.#fieldId + '=' + this.data;
    }

    setColorIfChanged(color) {
        if (this.isChanged) {
            this.setColor(color);
        } else {
            this.setColor("var(--font_color)");
        }
    }

    setColor(color) {
        document.getElementById(this.#fieldId).style.color = color;
    }
    setColorBackground(color) {
        document.getElementById(this.#fieldId).style.background = color;
    }

    resetOldData(){
        this.#oldData = this.data;
    }
    resetData(){
        document.getElementById(this.#fieldId).value = this.#oldData;
    }

    set data(data) {
        //console.log(this.#fieldId, this.#oldData, this.data);
        if (!this.isChanged) {     // значит данные не были изменены человеком, то можно их обновить с сервера
            document.getElementById(this.#fieldId).value = data;
        }
        this.resetOldData();
    }

    get data() {
        return document.getElementById(this.#fieldId).value;
    }

    get isChanged() {
        return this.#oldData != this.data;
    }

    #oldData;           // данные, подгруженные с бризера
    #fieldId;           // HTMLElement объект
}


