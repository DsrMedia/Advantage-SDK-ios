<script type="text/javascript">
//advantage-ios.js
//Copyright (c) 2015,  Digitalsunray Media GbmH. All rights reserved.

//constructor

function ADvantageSDK(){
    this._SDK_PREFIX = "advantagejs";
    this._SDK_VERSION     = "%@"; // will be updated from the native SDK
    this._publisherApp     = "%@"; // publisher bundle ID
    this._adid = "%@"; // IDFA or AID
    this._trackingAdLimit= %@; //boolean
    // Constant. In miliseconds.
    this.DEFAULT_VISIBILITY_INTERVAL = 300;
    this._visibilityInterval = this.DEFAULT_VISIBILITY_INTERVAL;
}

//setVisibilityInterval
ADvantageSDK.prototype.setVisibilityInterval = function(newVisibilityInterval){
	if (!isNaN(newVisibilityInterval)){
		this._visibilityInterval = newVisibilityInterval;
		// notify sdk
		this._sendMessageToSDK("setVisibilityInterval?interval="+newVisibilityInterval);
	}
};
//getVisibilityInterval
ADvantageSDK.prototype.getVisibilityInterval = function(){
	return this._visibilityInterval;
};
//resetVisibilityInterval
ADvantageSDK.prototype.resetVisibilityInterval = function(){
	this.setVisibilityInterval(this.DEFAULT_VISIBILITY_INTERVAL);
};
//sendMessageToSDK
ADvantageSDK.prototype._sendMessageToSDK=function(msg) {
    var iframe = document.createElement("IFRAME");
    iframe.setAttribute("src", this._SDK_PREFIX + "://" + msg);
    document.documentElement.appendChild(iframe);
    iframe.parentNode.removeChild(iframe);
};
//fireEvent
ADvantageSDK.prototype.fireEvent=function(evtStatus,object) {
    
    try {
		var e = document.createEvent("Event"); // erzeuge ein event
		e.initEvent('ADvantage',true,false); // initialisiere das event
		// füge daten an das event
		e.status=evtStatus;
		e.data=(object!=undefined)?object:""; // not needed at the moment
		e.id='ADvantageSDK'; // event ID
		document.dispatchEvent(e); // sende das event ab
    } catch (event) {
        /*do something*/
    }
};

// Attention: Do not change the variable names here, as we rely on them in other places.
var _ADvantageSDK=new ADvantageSDK();
var ADvantage_fireEvent=_ADvantageSDK.fireEvent; // for compatibility reasons with old SDK Version

/*
some samples how to call the functions from SDK side
_ADvantageSDK.fireEvent('reset2Default');
_ADvantageSDK.fireEvent('visibilityEvent',{}); // Add the JSON OBJECT as second parameter
_ADvantageSDK.setVisibilityInterval(500);
_ADvantageSDK.resetVisibilityInterval();
_ADvantageSDK._SDK_VERSION='2.5.2.1';
*/








/*
ADvantageObjectSDK.getFakeVisibilityEvent = function(){
    return {
        "status":"success",
        "nativeCallbackName":"visibilityEvent",
        "timestamp":'[TIMESTAMP],
        "result":{
            "visible" : "[true/false]",
            "insideScrollview" : "[true/false]"
            "percentage" :[0-100 float],
            "relativePosition" : {
                "top"  : 10,
                "left" : 10
            },
            "maxDimensions"    : {
                "maxWidth"  : 200,
                "maxHeight" : 200
            }
        }
    }
}
*/
</script>
