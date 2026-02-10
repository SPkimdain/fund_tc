function violation1(req) {
    let username = req.query.username;
    query = { $where: function() { return this.username == username; } };
    db.user.find(query, function (err, users) {                                     // @violation
      if (err) {
        // Handle errors
      } else {
        res.render('userlookup', { title: 'User Lookup', users: users });
      }
    });
}

function violation2(req) {
  let User = db.user;
  let username = req.query.username;
  query = { $where: function() { return this.username == username; } };
  User.find(query, function (err, users) {                                           // @violation
    if (err) {
      // Handle errors
    } else {
      res.render('userlookup', { title: 'User Lookup', users: users });
    }
  });
}

function violation3() {
  db.players.find( { $where: function() {                                           // @violation
    return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
  }});
}

function good1(req) {
    let username = req.query.username;
    query = { username: username }
    db.user.find(query, function (err, users) {                                     // good
      if (err) {
        // Handle errors
      } else {
        res.render('userlookup', { title: 'User Lookup', users: users });
      }
    });
}

function good2() {
  let username = req.query.username;
  db.players.find({ username: username });                                          // good
}

function good3() {
  db.players.find( {$expr: { $function: {                                           // good
    body: function(name) { return hex_md5(name) == "9b53e667f30cd329dca1ec9e6a83e994"; },
    args: [ "$name" ],
    lang: "js"
  }}});
}