function uploadContent(base_link, content_link) {
    console.log('start uploadContent');       // LOG
    console.log(base_link, content_link);     // LOG
    const contentBody = document.getElementById('contentBody');

    contentBody.innerHTML = "loading...";

    delay(3000);
    var http = createRequestObject();
    if (http) {
        http.open('GET', content_link);
        http.onreadystatechange = function () {
            if (http.readyState == 4) {
                //contentBody.innerHTML = http.responseText;
                console.log('history:', history);     // LOG
                window.location.hash = content_link;
                console.log("href:", window.location.href);    // LOG
                window.location.href = base_link
                //history.pushState('data to be passed', 'Title of the page', base_link);
                //history.pushState('data to be passed', 'Title of the page', base_link + '/?ContentLink=' + content_link);
                console.log('history:', history);     // LOG
                //history.;
            } else {
                //обработка процесса загрузки
            }
        }
        http.send(null);
    }
    else {
        document.location = base_link + content_link;
    }
    console.log('fin uploadContent');      // LOG
}

// создание Request(ajax) объекта  
function createRequestObject() {
    try { return new XMLHttpRequest() }
    catch (e) {
        try { return new ActiveXObject('Msxml2.XMLHTTP') }
        catch (e) {
            try { return new ActiveXObject('Microsoft.XMLHTTP') }
            catch (e) { return null; }
        }
    }
}

function parseURL(URL, key){
    let start_index = URL.indexOf('&' + key + '=') + key.length + 3;
    let fin_index = URL.indexOf('&', start_index);
    if(fin_index == -1){
        fin_index = URL.length;
    }
    return URL.slice(start_index, fin_index);
}

let MainUrl = "http://127.0.0.1:3000/General/general.html/?ContentLink=./Content/Main/main.html&lol=123";
let Qest = MainUrl.slice(MainUrl.indexOf('?'));
Qest[0] = '&';              // сделать у всех ключей '&' в начале для одинаковости

console.log("way:", parseURL(Qest, "ContentLink"));

//parseURL(window.location.href, ContentLink);


//uploadContent('./Content/Main/main.html');