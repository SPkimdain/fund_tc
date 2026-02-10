function violation1() {
    const libxmljs = require("libxmljs");
    var fs = require('fs');

    var xml = fs.readFileSync('xxe.xml', 'utf8');

    var option = { noblanks: true, noent: true, nocdata: true }
    var xmlDoc = libxmljs.parseXmlString(xml, option);                                              // @violation
}

function violation2() {
    const libxmljs = require("libxmljs");
    var fs = require('fs');

    var xml = fs.readFileSync('xxe.xml', 'utf8');

    var xmlDoc = libxmljs.parseXmlString(xml, { noblanks: true, noent: true, nocdata: true });      // @violation
}

function good1() {
    const libxmljs = require("libxmljs");
    var fs = require('fs');

    var xml = fs.readFileSync('xxe.xml', 'utf8');

    var xmlDoc = libxmljs.parseXmlString(xml);                                                      // good
}

function good2() {
    const libxmljs = require("libxmljs");
    var fs = require('fs');

    var xml = fs.readFileSync('xxe.xml', 'utf8');

    var xmlDoc = libxmljs.parseXmlString(xml, { noblanks: true, nocdata: true });                   // good
}

function good3() {
    const libxmljs = require("libxmljs");
    var fs = require('fs');

    var xml = fs.readFileSync('xxe.xml', 'utf8');

    var xmlDoc = libxmljs.parseXmlString(xml, { noblanks: true, noent: false, nocdata: true });     // good
}