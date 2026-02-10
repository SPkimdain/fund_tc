var express = require('express');
var app = express();
var url = require('url')

//Testcase 1
app.get('/ex1', function (req,res) {
    var queryObj = url.parse(req.url, true)
    var queueName = queryObj.name;
    var queueSvc = azureStorage.createQueueService();
    //    ...
    queueSvc.deleteQueue(queueName, option, function(error, response){ //@violation
        if(!error){
           // all the messages has been deleted
        }
    });
    return null;
});


//Testcase 2
app.get('/ex2', function (req,res) {
    var queryObj = url.parse(req.url, true)
    var containerName = queryObj.name;
    var blobSvc = azureStorage.createBlobService();
    //...
    blobSvc.deleteContainer(containerName, function (error, response) { //@violation
        if (!error) {
            // all the content in the given container has been deleted
        }
    });
    return null;
});