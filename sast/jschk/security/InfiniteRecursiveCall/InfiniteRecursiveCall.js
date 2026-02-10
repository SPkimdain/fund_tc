
function bad1(n) { // @violation
    bad1(n)
}

function bad2(n) {  // @violation
    if (1) {
        bad2(n)
    } else if (2) {
        bad2(n)
    } else if (3) {
        bad2(n)
    } else {
        bad2(n)
    }
}

function bad3(n) { //@violation
    if (true) {
        bad3(n);
    } else if (true) {
        bad3(n);
    }
}

function bad4(n) {  // @violation
    if (true) {
        bad4(n);
    } else if (true) {
        bad4(n);
    } else {
        bad4(n);
    }
}

function good1(n) {
    return;
    good1(n);
}

function good3(n) {
    if (true) {
        return good2(n);
        good3(n);
    } else {
        good3(n);
    }
}

function good4(n) {
    if (true) {
        return 1;
        good4(n);
    } else if (true) {
        good4(n);
    } else {
        good4(n);
    }
}

function good5(n) {
    if (true) {
        good5(n);
    } else if (true) {
        return;
        good5(n);
    } else {
        good5(n);
    }
}

function good6(n) {
    if (true) {
        good6(n);
    } else if (true) {
        good6(n);
    } else {
        return;
        good6(n);
    }
}

function dan_facto(num) {   // @violation
    return num * dan_facto(num - 1);
}

function safe_facto(num) {
    if (num === 0) {
        return 1;
    } else {
        return num * safe_facto(num - 1);
    }
}

function safe_fib(num) {
    if (num === 0) {
        return 0;
    }

    if (num === 1) {
        return 1;
    }
    return safe_fib(num - 1) + safe_fib(num - 2);
}