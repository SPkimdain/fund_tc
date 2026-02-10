var cookieSession = require('cookie-session');

function violation1() {
//--cookie-session
    let session4 = cookieSession({//@violation
    });

    let session3 = cookieSession({//@violation
        httpOnly: true
    });

    let session2 = cookieSession({//@violation
        resave: false,
        saveUninitialized: true
    });

    let session = cookieSession({
        httpOnly: false, //@violation
        secure: false, //@violation
    });
}

function violation2() {
//--express-session
    const express = require('express');
    const session = require('express-session');
    let app = express();
    app.use(session({
        cookie:
        {
            secure: false,//@violation
            httpOnly: false//@violation
        }
    }));

    const express2 = require('express');
    const session2 = require('express-session');
    let app2 = express2();
    app2.use(session2({ //@violation
        cookie:
        {
            temp: false
        }
    }));
}

function violation3() {
//--cookies
    let cookies = new Cookies(req, res, {keys: keys});
    cookies.set('LastVisit', new Date().toISOString(), {
        httpOnly: false,//@violation
        secure: false //@violation
    });
}

function violation4() {
//--csurf
    const cookieParser = require('cookie-parser');
    const csrf = require('csurf');
    const express = require('express');
    let csrfProtection = csrf({
        cookie:
        {
            secure: false, //@violation
            httpOnly: false //@violation
        }
    });
}

function good() {
//--cookie-session
    let session = cookieSession({//good
        httpOnly: true,
        secure: true
    });
}

function good2() {
//--express-session
    const express = require('express');
    const session = require('express-session');
    let app = express();
    app.use(session({
        cookie:
        {
            secure: true,//good
            httpOnly: true//good
        }
    }));
}

function good3() {
//--cookies
    let cookies = new Cookies(req, res, { keys: keys });
    cookies.set('LastVisit', new Date().toISOString(), {//good
        httpOnly: true,//good
        secure: true //good
    });
}

function good4() {
//--csurf
    const cookieParser = require('cookie-parser');
    const csrf = require('csurf');
    const express = require('express');
    let csrfProtection = csrf({ cookie: { secure: true, httpOnly: true }});//good
}