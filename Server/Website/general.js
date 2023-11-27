
// создание Request(ajax) объекта  
function createRequestObject() {
    try { return new XMLHttpRequest(); }
    catch (e1) {
        try { return new ActiveXObject('Msxml2.XMLHTTP'); }
        catch (e2) {
            try { return new ActiveXObject('Microsoft.XMLHTTP'); }
            catch (e3) { console.warn(e1, e2, e3); return null; }
        }
    }

}

// возвращает подгруженный HTML файл
function uploadHTML(url) {
    return new Promise(function (resolve, reject) {
        let http = createRequestObject();

        if (!http) {
            console.log("failed createRequestObject() at uploadHTML from" + url)
        }

        http.open('GET', url, true);
        http.onreadystatechange = function () {
            if (http.readyState == 4) {
                if (http.status == 200) {
                    resolve(http.responseText);      // подставить контент загруженой страницы
                }
                reject(http.status);
            }
        }
        http.send(null);
        // } catch (err) {
        //     reject(err);
        // }
    });
}

// подгрузка JS кода в дети к father
function uploadJS(url, type) {
    return new Promise(function (resolve, reject) {
        let script = document.createElement('script');
        script.src = url;
        script.async = false;  // FIXME надо?
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

// загрузка HTML и JS из url
function uploadPage(allUrls) {
    const contentBody = document.getElementById('contentBody');
    contentBody.innerHTML = "loading...";

    console.log("uploadPage:", allUrls);
    let nam = 0;
    function everythingIsLoaded() {
        if (++nam == allUrls.length) {
            console.log("eventUpdateData in uploadPage()");
            window.dispatchEvent(eventUpdateData);
        }
    }
    for (const url of allUrls) {
        // utl = MainURL.origin + utl;
        if (url[url.length - 1] == 's') {     // FIXME нормальная проверка на js или html
            // загрузка JS 
            console.log("Start loading JS form", url);          // LOG
            uploadJS(url, "module")
                .then(() => {
                    console.log(nam, "uploadJS()", url, "- OK");
                    everythingIsLoaded();
                })
                .catch((error) => {
                    console.warn(nam, "uploadJS()", url, "- ER", error);
                    everythingIsLoaded();
                });
        } else {
            // загрузка нового HTML в качестве content
            console.log("Start loading HTML form", url);        // LOG
            uploadHTML(url)
                .then((responseText) => {
                    contentBody.innerHTML = responseText;
                    console.log(nam, "uploadHTML()", url, "- OK");
                    everythingIsLoaded();
                })     // LOG
                .catch((error) => {
                    console.warn(nam, "uploadHTML", url, "- ER", error);
                    everythingIsLoaded();
                });
        }
    }

}

// обновление страницы с изменением истории (при использовании меню)
function uploadPageWithHistoryPush(nameContent, hostData) {
    let MainURL = new URL(window.location.href);
    console.log("\n\n=============================================================================================\n\n\n")   // LOG
    console.log("Start updating page from", MainURL.href);          // LOG
    // проверка что изменился html 
    if (MainURL.searchParams.get(paramNameContent) != nameContent) {
        // поменять URL фдресс на новый с записью в историю
        MainURL.searchParams.set(paramNameContent, nameContent);
        MainURL.searchParams.set(paramHost, hostData);
        console.log("to", MainURL.href);         // LOG
        window.history.pushState({ page: "" }, "", MainURL.href);
        console.log("Added new history", window.history.length);    // LOG

        uploadPage(AllPagesPaths[nameContent]);

        // если не изменилась основа, но изменился источник данных
    } else if (MainURL.searchParams.get(paramHost) != hostData) {
        MainURL.searchParams.set(paramHost, hostData);
        console.log("to", MainURL.href);         // LOG
        window.history.pushState({ page: "" }, "", MainURL.href);
        console.log("Added new history", window.history.length);    // LOG
        console.log("eventUpdateData in uploadPageWithHistoryPush()");
        window.dispatchEvent(eventUpdateData);
        //updateData();       // переподгзить данные
        // FIXME
    }
}

// обновление страницы без изменения истории (при переходе на страницу стрелочкой, перезагрузке, и в самом начале)
function uploadPageWithHistoryReplace(nameContent, hostData) {
    let MainURL = new URL(window.location.href);
    console.log("\n\n=============================================================================================\n\n\n")   // LOG
    console.log("Start returned page from", MainURL.href);          // LOG
    MainURL.searchParams.set(paramNameContent, nameContent);
    MainURL.searchParams.set(paramHost, hostData);
    console.log("to", MainURL.href);                                // LOG
    window.history.replaceState({ page: "" }, "", MainURL.href);
    console.log("History replaced. Length =", window.history.length);         // LOG

    uploadPage(AllPagesPaths[nameContent]);
}




// // подгрузить основную часть страницы
// function uploadContent(nameContent, hostData, changeHistory) {
//     console.log("==============================================")
//     console.log('start uploadContent.');                        // LOG
//     console.log('active href', window.location.href);           // LOG
//     console.log('to href', nameContent, hostData);          // LOG

//     let MainURL = new URL(window.location.href);
//     // загрузка основного HTML
//     // проверка что изменился html 
//     if (MainURL.pathname != nameContent) {
//         const contentBody = document.getElementById('contentBody');
//         contentBody.innerHTML = "loading...";
//         uploadHTML(MainURL.origin + nameContent + ".html")
//             .then((responseText) => { contentBody.innerHTML = responseText; console.log("uploadHTML() - OK") })
//             .catch((error) => console.warn(error));
//     }

//     // изменение URL для правильной перезагрузки
//     let newMainURL = new URL(window.location.href);
//     newMainURL.searchParams.set(paramNameContent, nameContent);
//     newMainURL.searchParams.set(paramHost, hostData);
//     console.log(MainURL.href, "->", newMainURL.href);         // LOG
//     // проверка что URL изменился (тоесть станица)
//     if (newMainURL != MainURL) {
//         if (changeHistory) {
//             window.history.pushState({ page: "" }, "", newMainURL.href);
//             console.log("add new history", window.history.length);         // LOG
//         } else {
//             window.history.replaceState({ page: "" }, "", newMainURL.href);
//             console.log("history replaced", window.history.length);        // LOG
//         }

//         // загрузка JS (обязательно после изменения URL, так как в js на него смотрят)
//         uploadJS(nameContent + ".js", "module")
//             .then(() => { console.log("uploadJS() - OK") })
//             .catch((error) => console.warn(error));
//     }
// }


// загрузка содержимого при открытии или перезагрузке страницы
{
    let MainURL = new URL(window.location.href);
    let nameContent = MainURL.searchParams.get(paramNameContent);
    let hostData = MainURL.searchParams.get(paramHost);
    // добавление параметров по умолчанию, если их нет
    if (nameContent === null) {
        nameContent = nameContentDirecting;
        //MainURL.searchParams.append(paramNameContent, nameContent);
    }
    if (hostData === null) {
        hostData = "";
        //MainURL.searchParams.append(paramHost, hostData);
    }
    // загрузка той же подстраницы, что была до перезагрузки
    uploadPageWithHistoryReplace(nameContent, hostData);
}


window.addEventListener('popstate', (e) => {
    let MainURLParams = new URL(window.location.href).searchParams;
    uploadPageWithHistoryReplace(MainURLParams.get(paramNameContent), MainURLParams.get(paramHost));
}, false);
// FIXME









