var queryString = getenv("QUERY")

var db: OpaquePointer?

var ret = sqlite3_exec(db, queryString, nil, nil, nil) //@violation

