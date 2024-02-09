export class dataField {
    constructor(allFieldId) {
        //this.#field = document.getElementById(field_id);
        this.#allFieldId = allFieldId;
        //this.data = "null";       // FIXME
        this.#data = "null"

        // console.log("Created dataField", this.#allFieldId);
    }

    set data(data) {
        //console.log("dataField_old", this.#data);       // LOG
        if (data === undefined) {
            this.#data = "null";
        } else {
            this.#data = data;
        }
        for (const fieldId of this.#allFieldId) {
            document.getElementById(fieldId).innerHTML = this.#data;
        }
        // console.log("New data in dataField", this.#allFieldId, this.#data);       // LOG
    }

    get data() {
        return this.#data;
    }

    #data;      // значение в поле
    #allFieldId;     // HTMLElement объект
}