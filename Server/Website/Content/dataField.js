export class dataField {
    constructor(allFieldId) {
        //this.#field = document.getElementById(field_id);
        this.#allFieldId = allFieldId;
        this.data = "null";
    }

    set data(data) {
        //console.log("dataField_old", this.#data);       // LOG
        this.#data = data;
        if(data === undefined){
            this.#data = "null";
        }
        for (const fieldId of this.#allFieldId) {
            document.getElementById(fieldId).innerHTML = this.#data;
        }
        //console.log("dataField", this.#data);       // LOG
    }

    get data() {
        return this.#data;
    }

    #data;      // значение в поле
    #allFieldId;     // HTMLElement объект
}