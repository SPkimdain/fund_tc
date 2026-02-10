try {
    localStorage.setItem("userCCV", currentCCV);
} catch (e) {
    if (e == QUOTA_EXCEEDED_ERR) {
        alert('Quota exceeded.');
    }
}

var retrieveObject = localStorage.getItem("userCCV");

try {
     sessionStorage.setItem("userCCV",retrieveObject); // @violation
} catch (e) {
     if (e == QUOTA_EXCEEDED_ERR) {
     alert('Quota exceeded.');
    }
    var userCCV = sessionStorage.getItem("userCCV");
}

