function delay(millis) {
    let t = (new Date()).getTime();
    while (((new Date()).getTime() - t) < millis) {
    }
}