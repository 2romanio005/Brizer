
let flagInPageLoading = false;  // флаг поднимающийся во время загрузки новой страницы, чтобы отловить окончание полной загрузки внутри загружаемых файлов js


// активный host с данными
let activeHost = "";
function updateActiveHost() {   // проверить что активный хост не изменился и изменить если да
    let mainUrl = new URL(window.location.href);
    let hostData = mainUrl.searchParams.get(paramHost);

    console.log("Active hostData:", activeHost);
    if (activeHost != hostData) {
        activeHost = hostData;
        console.log("New hostData:", activeHost);
    }
}



// создание Request(ajax) объекта  
function createRequestObject() {
    return new Promise(function (resolve, reject) {
        let http;
        try { http = new XMLHttpRequest(); }
        catch (e1) {
            try { http = new ActiveXObject('Msxml2.XMLHTTP'); }
            catch (e2) {
                try { http = new ActiveXObject('Microsoft.XMLHTTP'); }
                catch (e3) {
                    //console.warn(e1, e2, e3);
                    reject("Failed createRequestObject(): this browser is not supported." + e1 + e2 + e3);
                }
            }
        }

        if (!http) {
            reject("Failed createRequestObject(): object has not been created");
        }
        resolve(http);
    });
}

// возвращает подгруженный текст, который может быть как просто данными так и HTML
const uploadDataGET = function (url) {
    return new Promise(function (resolve, reject) {
        createRequestObject()
            .then(success)
            .catch(error);

        function success(http) {
            try {
                http.open("GET", url, true);
                http.onreadystatechange = function () {
                    if (http.readyState == 4) {
                        if (http.status == 200) {
                            resolve(http.responseText);      // вернуть контент загруженой страницы
                        }
                        reject("Failed uploadDataGET() or uploadHTML(): http.status = " + http.status + ", url = " + url);
                    }
                };
                http.send(null);
            } catch (error) {
                reject("Failed uploadDataGET() or uploadHTML():" + error + ", url = " + url);
            }
        }

        function error(error) {
            reject(error);
        }
    });
}
const uploadHTML = uploadDataGET;

// отправляет данные в POST запросе
function sendDataPOST(url, dataToSend, contentType = "application/x-www-form-urlencoded") {
    return new Promise(function (resolve, reject) {
        createRequestObject()
            .then(success)
            .catch(error);

        function success(http) {
            try {
                http.open("POST", url, true);
                http.setRequestHeader("Content-type", contentType);
                http.onload = () => {
                    if (http.status == 200) {
                        resolve(http.responseText);         // вернуть ответ сервера
                    }
                    reject("Failed sendDataPOST(): http.status = " + http.status + ", url = " + url);
                };
                http.send(dataToSend);
            } catch (error) {
                reject("Failed sendDataPOST():" + error + ", url = " + url);
            }
        }

        function error(error) {
            reject(error);
        }
    });
}

// подгрузка JS кода в дети к father
function uploadJS(url, type) {
    return new Promise(function (resolve, reject) {
        try {
            let script = document.createElement('script');
            script.src = url;
            //script.async = false;
            script.defer = true;
            script.type = type;
            document.head.appendChild(script);
            resolve();
        } catch (error) {
            reject("Failed uploadJS(): " + error);
        }
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

    flagInPageLoading = true; // помеяаем что началась загрузка страницы
    
    console.log("uploadPage:", allUrls);    
    let nam = 0;
    function everythingIsLoaded() {
        if (++nam == allUrls.length) {
            console.log("eventUpdateData in uploadPage()");
            flagInPageLoading = false;    // помеяаем что загрузка страницы завершена
            window.dispatchEvent(eventUpdateData);
        }
    }
    for (const url of allUrls) {
        // utl = MainURL.origin + utl;
        if (url[url.length - 1] == 's') {     // TODO нормальная проверка на js или html
            // загрузка JS 
            console.log("Start loading JS form", url);          // LOG
            uploadJS(url, "module")
                .then(() => {
                    console.log(nam, "uploadJS from", url, "- OK");
                    everythingIsLoaded();
                })
                .catch((error) => {
                    console.warn(nam, "uploadJS from", url, "- ER", error);
                    everythingIsLoaded();
                });
        } else {
            // загрузка нового HTML в качестве content
            console.log("Start loading HTML form", url);        // LOG
            uploadHTML(url)
                .then((responseText) => {
                    contentBody.innerHTML = responseText;
                    console.log(nam, "uploadHTML from", url, "- OK");
                    everythingIsLoaded();
                })     // LOG
                .catch((error) => {
                    console.warn(nam, "uploadHTML from", url, "- ER", error);
                    everythingIsLoaded();
                });
        }
    }

}
