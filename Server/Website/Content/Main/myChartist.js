export class myChartist {
    constructor(chart_id, labels_start, labels_len, pathname, divisor = 1) {
        this.#chart_id = chart_id;

        for (let i = 0; i < labels_len; i++) {
            this.#data.labels.push(String(labels_start + i));
        }

        this.url = new URL("http://1.1.1.1:1");  // создание каконибудь URL он будет заменён на paramHost
        this.url.pathname = pathname;

        this.#divisor = divisor;

        console.log("Created myChartist:",          // LOG
            "\nid -", this.#chart_id,
            "\npath -", this.url.href,
            "\ndivisor -", this.#divisor,
            "\nlabels -", this.#data.labels,
        )
    }

    parseData(responseText) {
        this.#data.series = [];
        let line = responseText.split(';');
        for (let i = 0; i < line.length - 1; ++i) {
            this.#data.series.push([]);
            for (let point of line[i].split(',')) {
                this.#data.series[i].push(parseInt(point, 10) / this.#divisor);
            }
        }
        console.log("ParseData", this.#chart_id, this.#data);        // LOG
    }

    redraw() {
        console.log("Redrawing", this.#chart_id, this.#data);
        let visible_number = this.#data.series.length;
        while (visible_number > 0 && this.#data.series[visible_number - 1].length === 0) {
            --visible_number;
        }
        // console.log(visible_number);             // LOG


        // FIXME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ошибка была тут TypeError: Cannot read properties of null (reading 'style')
        // спрятать или показать лишние квадратики
        for (let visible = 0; visible < visible_number; ++visible) {
            document.getElementById(this.#chart_id + '_signature_' + String.fromCharCode('a'.charCodeAt() + visible)).style.display = "block";
        }
        for (let hidden = visible_number; hidden < 7; ++hidden) {
            document.getElementById(this.#chart_id + '_signature_' + String.fromCharCode('a'.charCodeAt() + hidden)).style.display = "none";
        }

        new Chartist.Line('#' + this.#chart_id, this.#data, this.#options);
    }

    #data = {
        labels: [],
        series: []
        //[null], [null], [null], [null], [null], [null], [null]
    };

    #options = {
        height: 350,
        showPoint: true,
        fullWidth: true,
    };

    #divisor;           // на что делить данные, приходящие с сервера
    #chart_id;          // id графика

    url;                // URL адрс с данными
}