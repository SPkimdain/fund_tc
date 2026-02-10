try {
    sessionStorage.setItem("userCCV", currentCCV);
} catch (e) {
    if (e == QUOTA_EXCEEDED_ERR) {CrossSessionContaminationLocalToSession
        alert('Quota exceeded.');
    }
}

var retrieveObject = sessionStorage.getItem("userCCV");

try {
     localStorage.setItem("userCCV",retrieveObject); // @violation
} catch (e) {
     if (e == QUOTA_EXCEEDED_ERR) {
     alert('Quota exceeded.');
    }
    var userCCV = localStorage.getItem("userCCV");
}

