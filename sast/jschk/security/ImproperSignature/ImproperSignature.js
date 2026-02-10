function violation1() {
    const jwt = require('jsonwebtoken');

    var tokenAlgorithm = { algorithm: 'none' };
    let token = jwt.sign({ foo: 'bar' }, key, tokenAlgorithm);                                          // @violation

    var verifyOption = { expiresIn: 360000 * 5, algorithms: ['RS256', 'none'] };
    jwt.verify(token, key, verifyOption, callbackcheck);                                                // @violation
}

function violation2() {
    const jwt = require('jsonwebtoken');

    let token = jwt.sign({ foo: 'bar' }, key, { algorithm: 'none' });                                   // @violation

    jwt.verify(token, key, { expiresIn: 360000 * 5, algorithms: ['RS256', 'none'] }, callbackcheck);    // @violation
}

function good1() {
    const jwt = require('jsonwebtoken');

    var tokenAlgorithm = { algorithm: 'HS256' };
    let token = jwt.sign({ foo: 'bar' }, key, tokenAlgorithm);                                          // good

    var verifyOption = { expiresIn: 360000 * 5, algorithms: ['HS256'] };
    jwt.verify(token, key, verifyOption, callbackcheck);                                                // good
}

function good2() {
    const jwt = require('jsonwebtoken');

    let token = jwt.sign({ foo: 'bar' }, key, { algorithm: 'HS256' });                                  // good

    jwt.verify(token, key, { expiresIn: 360000 * 5, algorithms: ['HS256'] }, callbackcheck);            // good
}