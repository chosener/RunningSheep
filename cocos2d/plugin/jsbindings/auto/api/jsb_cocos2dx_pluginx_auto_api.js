/**
 * @module pluginx_protocols
 */
var plugin = plugin || {};

/**
 * @class PluginProtocol
 */
plugin.PluginProtocol = {

/**
 * @method getPluginName
 * @return {char}
 */
getPluginName : function (
)
{
    return 0;
},

/**
 * @method getPluginVersion
 * @return {String}
 */
getPluginVersion : function (
)
{
    return ;
},

/**
 * @method getSDKVersion
 * @return {String}
 */
getSDKVersion : function (
)
{
    return ;
},

/**
 * @method setDebugMode
 * @param {bool} arg0
 */
setDebugMode : function (
bool 
)
{
},

};

/**
 * @class PluginManager
 */
plugin.PluginManager = {

/**
 * @method unloadPlugin
 * @param {char} arg0
 */
unloadPlugin : function (
char 
)
{
},

/**
 * @method loadPlugin
 * @param {char} arg0
 * @return {cc.plugin::PluginProtocol}
 */
loadPlugin : function (
char 
)
{
    return cc.plugin::PluginProtocol;
},

/**
 * @method end
 */
end : function (
)
{
},

/**
 * @method getInstance
 * @return {cc.plugin::PluginManager}
 */
getInstance : function (
)
{
    return cc.plugin::PluginManager;
},

};

/**
 * @class ProtocolAnalytics
 */
plugin.ProtocolAnalytics = {

/**
 * @method logTimedEventBegin
 * @param {char} arg0
 */
logTimedEventBegin : function (
char 
)
{
},

/**
 * @method logError
 * @param {char} arg0
 * @param {char} arg1
 */
logError : function (
char, 
char 
)
{
},

/**
 * @method setCaptureUncaughtException
 * @param {bool} arg0
 */
setCaptureUncaughtException : function (
bool 
)
{
},

/**
 * @method setSessionContinueMillis
 * @param {long} arg0
 */
setSessionContinueMillis : function (
long 
)
{
},

/**
 * @method logEvent
 * @param {char} arg0
<<<<<<< HEAD
 * @param {map_object} arg1
=======
 * @param {MapObject} arg1
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
logEvent : function (
char, 
map 
)
{
},

/**
 * @method startSession
 * @param {char} arg0
 */
startSession : function (
char 
)
{
},

/**
 * @method stopSession
 */
stopSession : function (
)
{
},

/**
 * @method logTimedEventEnd
 * @param {char} arg0
 */
logTimedEventEnd : function (
char 
)
{
},

};

/**
 * @class ProtocolIAP
 */
plugin.ProtocolIAP = {

/**
<<<<<<< HEAD
 * @method onPayResult
 * @param {cc.plugin::PayResultCode} arg0
 * @param {char} arg1
 */
onPayResult : function (
payresultcode, 
char 
=======
 * @method payForProduct
 * @param {MapObject} arg0
 */
payForProduct : function (
map 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
)
{
},

/**
<<<<<<< HEAD
 * @method getCallback
 * @return {function}
 */
getCallback : function (
)
{
    return std::function<void (int, std::basic_string<char> &)>;
=======
 * @method onPayResult
 * @param {cc.plugin::PayResultCode} arg0
 * @param {char} arg1
 */
onPayResult : function (
payresultcode, 
char 
)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
},

/**
 * @method configDeveloperInfo
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
configDeveloperInfo : function (
map 
)
{
},

};

/**
 * @class ProtocolAds
 */
plugin.ProtocolAds = {

/**
 * @method showAds
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 * @param {cc.plugin::ProtocolAds::AdsPos} arg1
 */
showAds : function (
map, 
adspos 
)
{
},

/**
 * @method hideAds
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
hideAds : function (
map 
)
{
},

/**
 * @method queryPoints
 */
queryPoints : function (
)
{
},

/**
<<<<<<< HEAD
 * @method getCallback
 * @return {function}
 */
getCallback : function (
)
{
    return std::function<void (int, std::basic_string<char> &)>;
},

/**
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 * @method spendPoints
 * @param {int} arg0
 */
spendPoints : function (
int 
)
{
},

/**
 * @method configDeveloperInfo
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
configDeveloperInfo : function (
map 
)
{
},

<<<<<<< HEAD
=======
/**
 * @method getAdsListener
 * @return {cc.plugin::AdsListener}
 */
getAdsListener : function (
)
{
    return cc.plugin::AdsListener;
},

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
};

/**
 * @class ProtocolShare
 */
plugin.ProtocolShare = {

/**
 * @method onShareResult
 * @param {cc.plugin::ShareResultCode} arg0
 * @param {char} arg1
 */
onShareResult : function (
shareresultcode, 
char 
)
{
},

/**
<<<<<<< HEAD
 * @method getCallback
 * @return {function}
 */
getCallback : function (
)
{
    return std::function<void (int, std::basic_string<char> &)>;
=======
 * @method share
 * @param {MapObject} arg0
 */
share : function (
map 
)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
},

/**
 * @method configDeveloperInfo
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
configDeveloperInfo : function (
map 
)
{
},

};

/**
 * @class ProtocolSocial
 */
plugin.ProtocolSocial = {

/**
 * @method showLeaderboard
 * @param {char} arg0
 */
showLeaderboard : function (
char 
)
{
},

/**
 * @method showAchievements
 */
showAchievements : function (
)
{
},

/**
<<<<<<< HEAD
 * @method getCallback
 * @return {function}
 */
getCallback : function (
)
{
    return std::function<void (int, std::basic_string<char> &)>;
=======
 * @method submitScore
 * @param {char} arg0
 * @param {long} arg1
 */
submitScore : function (
char, 
long 
)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
},

/**
 * @method configDeveloperInfo
<<<<<<< HEAD
 * @param {map_object} arg0
=======
 * @param {MapObject} arg0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
configDeveloperInfo : function (
map 
)
{
},

<<<<<<< HEAD
};

/**
 * @class ProtocolUser
 */
plugin.ProtocolUser = {

/**
 * @method getCallback
 * @return {function}
 */
getCallback : function (
)
{
    return std::function<void (int, std::basic_string<char> &)>;
},

/**
 * @method configDeveloperInfo
 * @param {map_object} arg0
 */
configDeveloperInfo : function (
=======
/**
 * @method unlockAchievement
 * @param {MapObject} arg0
 */
unlockAchievement : function (
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
map 
)
{
},

<<<<<<< HEAD
/**
 * @method isLoggedIn
 * @return {bool}
 */
isLoggedIn : function (
)
{
    return false;
},

/**
 * @method getSessionID
 * @return {String}
 */
getSessionID : function (
)
{
    return ;
},

/**
 * @method getAccessToken
 * @return {String}
 */
getAccessToken : function (
)
{
    return ;
},

};

/**
 * @class AgentManager
 */
plugin.AgentManager = {

/**
 * @method getSocialPlugin
 * @return {cc.plugin::ProtocolSocial}
 */
getSocialPlugin : function (
)
{
    return cc.plugin::ProtocolSocial;
},

/**
 * @method getAdsPlugin
 * @return {cc.plugin::ProtocolAds}
 */
getAdsPlugin : function (
)
{
    return cc.plugin::ProtocolAds;
},

/**
 * @method purge
 */
purge : function (
)
{
},

/**
 * @method getUserPlugin
 * @return {cc.plugin::ProtocolUser}
 */
getUserPlugin : function (
)
{
    return cc.plugin::ProtocolUser;
},

/**
 * @method getIAPPlugin
 * @return {cc.plugin::ProtocolIAP}
 */
getIAPPlugin : function (
)
{
    return cc.plugin::ProtocolIAP;
},

/**
 * @method getSharePlugin
 * @return {cc.plugin::ProtocolShare}
 */
getSharePlugin : function (
)
{
    return cc.plugin::ProtocolShare;
},

/**
 * @method getAnalyticsPlugin
 * @return {cc.plugin::ProtocolAnalytics}
 */
getAnalyticsPlugin : function (
)
{
    return cc.plugin::ProtocolAnalytics;
},

/**
 * @method destroyInstance
 */
destroyInstance : function (
)
{
},

/**
 * @method getInstance
 * @return {cc.plugin::AgentManager}
 */
getInstance : function (
)
{
    return cc.plugin::AgentManager;
},

};

/**
 * @class FacebookAgent
 */
plugin.FacebookAgent = {

/**
 * @method activateApp
 */
activateApp : function (
)
{
},

/**
 * @method getUserID
 * @return {String}
 */
getUserID : function (
)
{
    return ;
},

/**
 * @method logEvent
* @param {String|String|String|String} str
* @param {float|map_object|float} float
* @param {map_object} map
*/
logEvent : function(
str,
float,
map 
)
{
=======
};

/**
 * @class ProtocolUser
 */
plugin.ProtocolUser = {

/**
 * @method isLogined
 * @return {bool}
 */
isLogined : function (
)
{
    return false;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
},

/**
 * @method logout
 */
logout : function (
)
{
},

/**
<<<<<<< HEAD
 * @method getSDKVersion
 * @return {String}
 */
getSDKVersion : function (
)
{
    return ;
},

/**
 * @method logPurchase
* @param {float|float} float
* @param {String|String} str
* @param {map_object} map
*/
logPurchase : function(
float,
str,
=======
 * @method configDeveloperInfo
 * @param {MapObject} arg0
 */
configDeveloperInfo : function (
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
map 
)
{
},

/**
<<<<<<< HEAD
 * @method isLoggedIn
 * @return {bool}
 */
isLoggedIn : function (
)
{
    return false;
},

/**
 * @method canPresentDialogWithParams
 * @param {map_object} arg0
 * @return {bool}
 */
canPresentDialogWithParams : function (
map 
)
{
    return false;
},

/**
 * @method getAccessToken
 * @return {String}
 */
getAccessToken : function (
=======
 * @method login
 */
login : function (
)
{
},

/**
 * @method getSessionID
 * @return {String}
 */
getSessionID : function (
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
)
{
    return ;
},

<<<<<<< HEAD
/**
 * @method destroyInstance
 */
destroyInstance : function (
)
{
},

/**
 * @method getInstanceJs
 * @return {cc.plugin::FacebookAgent}
 */
getInstanceJs : function (
)
{
    return cc.plugin::FacebookAgent;
},

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
};
