export class dataField{
    constructor(field_id){
            this.#field = document.getElementById(field_id);
            this.data = "null";
    }

    set data(data){
        this.#data = data;
        this.#field.innerHTML = this.#data;
    }

    get data(){
        return this.#data;
    }

    #data;      // значение в поле
    #field;     // HTMLElement объект
}