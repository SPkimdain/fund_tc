function tit_cllService(sParam, a, b,c,) {
    var sUrl = TEMP + ABC2 + "?mode=delete";
    sUrl = sUrl + "&file=" + Urlencode(TEMP1) +
    "&filedir=" + urlencode(FILEDIR);

    Transaction(a,sUrl,123); //@violation

}


function gfn_gpms_fileDelete(serverSaveDir, serverFileName, isNeedRtn) {
    var serverUrl = GF_GPMS_FILE_SERVER_URL + GF_GPMS_FILE_SERVICE_NAME + "?mode=delete";

    _FILE_PROC_RTN = "";
    _FILE_PROC_MSG = "";

    serverUrl = serverUrl + "&fileDir=" + UrlEncode(serverSaveDir)
        + "&fileName=" + UrlEncode(serverFileName);

    if ( isNeedRtn == true) {
        http.sync = true;
    }

    Transaction("", serverUrl, "", "", "", ""); //@violation

    if ( isNeedRtn == true ) {
        http.sync = false;
        // 결과 전송
        return _FILE_PROC_RTN;
    }
}