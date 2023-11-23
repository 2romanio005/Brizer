
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

// возвращает подгруженный HTML файл
function uploadHTML(url) {
    return new Promise(function (resolve, reject) {
        let http = createRequestObject();
        if (!http) {
            reject("failed createRequestObject() at upload HTML from" + url);
        }

        http.open('GET', url, true);
        http.onreadystatechange = function () {
            if (http.readyState == 4) {
                resolve(http.responseText);      // подставить контент загруженой страницы
            }
        }
        http.send(null);
    });
}

// подгрузка JS кода в дети к father
function uploadJS(url, type) {
    return new Promise(function (resolve, reject) {
        let script = document.createElement('script');
        script.src = url;
        script.type = type;
        document.head.appendChild(script);
        resolve();
        // old_script = document.getElementById(url);
        // if (old_script) {
        //     resolve(old_script);          // уже загружен
        // }

        // let http = createRequestObject();
        // if (!http) {
        //     reject("failed createRequestObject() at upload JS from" + url);
        // }

        // http.open('GET', url, true);
        // http.onreadystatechange = function () {
        //     if (http.readyState == 4) {
        //         if (http.status == 200) {
        //             let script = document.createElement("script");
        //             script.type = 'text/javascript';
        //             script.id = url;
        //             script.text = http.responseText;
        //             document.head.appendChild(script);
        //             //executeJS(father)
        //             resolve(script);
        //         } else {
        //             reject("failed: " + url);
        //         }
        //     }
        // }
        // http.send(null);
    });
}

// подгрузить основную часть страницы
function uploadContent(pathnameContent, originData) {
    console.log("==============================================")
    console.log('start uploadContent.', pathnameContent, originData);       // LOG

    const contentBody = document.getElementById('contentBody');
    contentBody.innerHTML = "loading...";

    let MainUrl = new URL(window.location.href);

    // загрузка основного HTML
    if (MainUrl.pathname != pathnameContent) {
        uploadHTML(MainUrl.origin + pathnameContent + ".html")
            .then((responseText) => { contentBody.innerHTML = responseText; console.log("uploadHTML() - OK") })
            .catch((error) => console.error(error));
    }

    // изменение URL для правильной перезагрузки
    MainUrl.searchParams.set(paramPathnameContent, pathnameContent);
    MainUrl.searchParams.set(paramHostData, originData);
    window.history.pushState({ page: "" }, "", MainUrl.href);

    // загрузка JS (обязательно после изменения URL)
    uploadJS(pathnameContent + ".js", "module")
        .then(() => { console.log("uploadJS() - OK") })
        .catch((error) => console.error(error));
}



// вспоминаем, что за подстраница была до перезагрузки
{
    let MainUrl = new URL(window.location.href);
    pathnameContent = MainUrl.searchParams.get(paramPathnameContent);
    if (pathnameContent === null) {
        pathnameContent = "/Content/Directing/index";
        MainUrl.searchParams.append(paramPathnameContent, pathnameContent);
        //window.history.replaceState({ page: "Главная" }, "Главная", MainUrl.href);
    }
    originData = MainUrl.searchParams.get(paramHostData);
    if (originData === null) {
        originData = "";
        MainUrl.searchParams.append(paramHostData, originData);
    }
}

// загрузка той же подстраницы, что была до перезагрузки
uploadContent(pathnameContent, originData);


