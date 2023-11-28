export class inputField {
    constructor(FieldId, forbiddenExpressions = "") {
        this.#FieldId = FieldId;
        this.oldData = "null";
        this.data = "null";

        const this_FieldId = eval(FieldId);
        this_FieldId.onkeyup = () => {
            this_FieldId.value = this_FieldId.value.replace(forbiddenExpressions, '');
            if(this.isChanged){
                document.getElementById(this.#FieldId).style.color = "var(--waitingColor)";
            }else{
                document.getElementById(this.#FieldId).style.color = "var(--font_color)";
            }
        }
    }

    set oldData(oldData){
        this.#oldData = oldData;
    }

    updateData(resultColor){
        if(this.isChanged){
            this.#oldData = this.data;;
            document.getElementById(this.#FieldId).style.color = resultColor;
        }else{
            document.getElementById(this.#FieldId).style.color = "var(--font_color)";
        }
    }

    set data(data) {
        //console.log(this.#FieldId, this.#oldData, this.data);
        if (!this.isChanged) {     // значит данные не были изменены человеком, то можно их обновить с сервера
            document.getElementById(this.#FieldId).value = data;
        }
        this.#oldData = data;
    }

    get data() {
        return document.getElementById(this.#FieldId).value;
    }

    // get oldData() {
    //     return this.#oldData;       // FIXME
    // }

    get isChanged() {
        return this.#oldData != this.data;
    }

    generateDataToSend(){
        return '&' + this.#FieldId + '=' + this.data;
    }

    #oldData;           // данные, подгруженные с бризера
    #FieldId;           // HTMLElement объект
}


