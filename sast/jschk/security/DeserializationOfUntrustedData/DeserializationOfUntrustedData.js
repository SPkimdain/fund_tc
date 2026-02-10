function violation() {
    const app = require("express")(),
      jsyaml = require("js-yaml");

    app.get("load", function(req, res) {
      let data = jsyaml.load(req.params.data);        // @violation
      // ...
    });
}

function good() {
    const app = require("express")(),
      jsyaml = require("js-yaml");

    app.get("load", function(req, res) {
      let data = jsyaml.safeLoad(req.params.data);    // good
      // ...
    });
}