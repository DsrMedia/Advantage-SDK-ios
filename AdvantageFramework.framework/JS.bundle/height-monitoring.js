var _ADvantageDynamicHeightMonitoring;
var _ADvantageCalculatedHeight;
(function() {
    var old = 0;
    _ADvantageDynamicHeightMonitoring = setInterval(function() {
        var newHeight = parseInt(window.getComputedStyle(document.getElementsByTagName('body')[0]).height);
        if(newHeight !== old) {
            old = newHeight;
            var command = {'function':'setAdHeight', 'data':{'height':newHeight, 'isInternalHeightMonitoring':'Y'}};
            window.webkit.messageHandlers.advantagejs.postMessage(command);
        }
    }, 100);
})();
