function uploadContent(base_link, content_link) {
    console.log('start uploadContent from:', base_link, content_link);       // LOG
    const contentBody = document.getElementById('contentBody');

    contentBody.innerHTML = "loading...";

    //delay(3000);
    var http = createRequestObject();
    if (http) {
        http.open('GET', base_link + content_link);
        http.onreadystatechange = function () {
            if (http.readyState == 4) {
                contentBody.innerHTML = http.responseText;      // подставить контент загруженой страницы

                console.log('history:', history);     // LOG
                MainUrl.origin
                MainUrl.searchParams.set(paramContentLink, content_link)
                window.history.pushState({page: ""}, "", MainUrl.href);
                console.log("href:", window.location.href);    // LOG
                //window.location.href = base_link
                //history.pushState('data to be passed', 'Title of the page', base_link);
                //history.pushState('data to be passed', 'Title of the page', base_link + '/?ContentLink=' + content_link);
                console.log('history:', history);     // LOG
            } else {
                //обработка процесса загрузки
            }
        }
        http.send(null);
    }
    else {
        //window.location.href = base_link + content_link;
    }
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

let MainUrl = new URL(window.location.href);
ContentLink = MainUrl.searchParams.get(paramContentLink);
if(ContentLink === null){
    ContentLink = "/Content/Directing/index.html";
    MainUrl.searchParams.append(paramContentLink, "/Content/Directing/index.html");
    console.log("path: ", MainUrl.href);   // LOG
    //window.history.replaceState({page: "Главная"}, "Главная", MainUrl.href);
}
uploadContent('./', ContentLink);



