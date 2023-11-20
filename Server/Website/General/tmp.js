function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function delay(millis) {
    let t = (new Date()).getTime();
    while (((new Date()).getTime() - t) < millis) {
    }
}