function violation(arg1, arg2){
    const expr = require('express');
    const app = expr()
    //app.use(helmet()); <<---

    app.use((req, res, next) => { // @violation
      res.setHeader("X-XSS-Protection", "1; mode=block"); // @violation
      next();
    });

    app.use(function(req, res, next) { // @violation
        res.setHeader("X-XSS-Protection", "1; mode=block"); // @violation
        next();
    });
}

function violation2(){
    const expr = require('express');
    const app = expr()

    app.use((req, res, next) => { // @violation
        next();
    });
}

function good1(){
    const express = require('express');
    const helmet = require('helmet');
    const app = express()

    app.use(helmet());
    app.use((req, res, next) => { // safe
        next();
    });
}

function good2(){
    const express = require('express');
    const helmet = require('helmet');
    const app = express()

    //x-xss-protection(default)
    app.use(helmet.xssFilter());
    app.use((req, res, next) => { // safe
        next();
    });
}

function good2(){
    const express = require('express');
    const app = express()

    //x-powered-by
    app.disable("x-powered-by");
    app.use((req, res, next) => { // safe
        next();
    });
}
