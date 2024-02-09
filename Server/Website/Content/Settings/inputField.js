export class inputField {
    constructor(fieldId, forbiddenExpressions = "", changedColor = "var(--waitingColor)") {
        this.#fieldId = fieldId;
        this.#oldData = "null";

        this.#forbiddenExpressions = forbiddenExpressions;
        this.#changedColor = changedColor;
    }

    rebind() {
        this.#oldData = "null";

        const HTML_field = eval(this.#fieldId);
        HTML_field.onkeyup = () => {
            HTML_field.value = HTML_field.value.replace(this.#forbiddenExpressions, '');
            this.setColorIfChanged(this.#changedColor);
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

    resetOldData() {
        this.#oldData = this.data;
    }
    resetData() {
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
    #fieldId;           // ID HTMLElement объекта


    #forbiddenExpressions;  // запрёшённая для ввода последовательность
    #changedColor;          // цвет полня если оно изменено
}


