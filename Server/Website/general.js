

// обновление страницы с изменением истории (при использовании меню)
function uploadPageWithHistoryPush(nameContent, hostData) {
    let MainURL = new URL(window.location.href);
    // console.log("\n\n=============================================================================================\n\n\n")   // LOG
    // console.log("Start updating page from", MainURL.href);          // LOG
    if (MainURL.searchParams.get(paramNameContent) != nameContent) {           // проверка что изменился html 
        // поменять URL адресс на новый с записью в историю
        MainURL.searchParams.set(paramNameContent, nameContent);
        MainURL.searchParams.set(paramHost, hostData);
        //console.log("to", MainURL.href);         // LOG
        window.history.pushState({ page: "" }, "", MainURL.href);
        //console.log("Added new history", window.history.length);    // LOG
        updateActiveHost();
        uploadPage(AllPagesPaths[nameContent]);
    } else if (MainURL.searchParams.get(paramHost) != hostData) {               // если не изменилась основа, но изменился источник данных
        // переподгрузить данные с нового источника
        MainURL.searchParams.set(paramHost, hostData);
        // console.log("to", MainURL.href);         // LOG
        window.history.pushState({ page: "" }, "", MainURL.href);
        // console.log("Added new history", window.history.length);    // LOG
        // console.log("eventUpdateData in uploadPageWithHistoryPush()");
        updateActiveHost();
        window.dispatchEvent(eventUpdateData);
    }
}

// обновление страницы без изменения истории (при переходе на страницу стрелочкой назад/вперёд, перезагрузке, и в самом начале)
function uploadPageWithHistoryReplace(nameContent, hostData) {
    let MainURL = new URL(window.location.href);
    // console.log("\n\n=============================================================================================\n\n\n")   // LOG
    // console.log("Start returned page from", MainURL.href);          // LOG
    // поменять URL адресс на новый с записью в историю
    MainURL.searchParams.set(paramNameContent, nameContent);
    MainURL.searchParams.set(paramHost, hostData);
    // console.log("to", MainURL.href);                                // LOG
    window.history.replaceState({ page: "" }, "", MainURL.href);
    // console.log("History replaced. Length =", window.history.length);         // LOG

    updateActiveHost();
    uploadPage(AllPagesPaths[nameContent]);
}


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









