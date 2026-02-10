function violation1() {
    const https = require('https');

    let options = {
        hostname: 'www.example.com',
        port: 443,
        path: '/',
        method: 'GET',
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    };
        
    let req = https.request(options, (res) => {                             // @violation
        res.on('data', (d) => {
            process.stdout.write(d);
        });
    });
}

function violation2() {
    const https = require('https');
        
    let req = https.request({                                               // @violation
        hostname: 'www.example.com',
        port: 443,
        path: '/',
        method: 'GET',
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    }, (res) => {
        res.on('data', (d) => {
            process.stdout.write(d);
        });
    });
}

function violation3() {
    const tls = require('tls');

    let options = {
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    };
    
    let socket = tls.connect(443, "www.example.com", options, () => {       // @violation
        process.stdin.pipe(socket);
        process.stdin.resume();
    });
}

function violation4() {
    const tls = require('tls');
    
    let socket = tls.connect(443, "www.example.com", {                      // @violation
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    }, () => {
        process.stdin.pipe(socket);
        process.stdin.resume();
    });
}

function violation5() {
    const request = require('request');

    let option = {
        url: 'www.example.com',
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    };

    let socket = request.get(option);                                       // @violation
}

function violation6() {
    const request = require('request');

    let socket = request.get({                                              // @violation
        url: 'www.example.com',
        secureProtocol: 'TLSv1_2_method',
        rejectUnauthorized: false
    });
}

function good1() {
    const https = require('https');

    let options = {
        hostname: 'www.example.com',
        port: 443,
        path: '/',
        method: 'GET',
        secureProtocol: 'TLSv1_2_method'
    };
        
    let req = https.request(options, (res) => {                             // good
        res.on('data', (d) => {
            process.stdout.write(d);
        });
    });
}

function good2() {
    const https = require('https');
        
    let req = https.request({                                               // good
        hostname: 'www.example.com',
        port: 443,
        path: '/',
        method: 'GET',
        secureProtocol: 'TLSv1_2_method'
    }, (res) => {
        res.on('data', (d) => {
            process.stdout.write(d);
        });
    });
}

function good3() {
    const tls = require('tls');

    let options = {
        secureProtocol: 'TLSv1_2_method',
    };
    
    let socket = tls.connect(443, "www.example.com", options, () => {       // good
        process.stdin.pipe(socket);
        process.stdin.resume();
    });
}

function good4() {
    const tls = require('tls');
    
    let socket = tls.connect(443, "www.example.com", {                      // good
        secureProtocol: 'TLSv1_2_method',
    }, () => {
        process.stdin.pipe(socket);
        process.stdin.resume();
    });
}

function good5() {
    const request = require('request');

    let option = {
        url: 'www.example.com',
        secureProtocol: 'TLSv1_2_method',
    };

    let socket = request.get(option);                                       // good
}

function good6() {
    const request = require('request');

    let socket = request.get({                                              // good
        url: 'www.example.com',
        secureProtocol: 'TLSv1_2_method',
    });
}