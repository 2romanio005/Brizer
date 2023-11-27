export class dataField{
    constructor(field_id){
            //this.#field = document.getElementById(field_id);
            this.#field_id = field_id;
            this.data = "null";
    }

    set data(data){
        //console.log("dataField_old", this.#data);       // LOG
        this.#data = data;
        document.getElementById(this.#field_id).innerHTML = this.#data;
        //console.log("dataField", this.#data);       // LOG
    }

    get data(){
        return this.#data;
    }

    #data;      // значение в поле
    #field_id;     // HTMLElement объект
}