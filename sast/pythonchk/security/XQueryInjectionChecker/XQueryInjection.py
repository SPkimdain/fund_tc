import zorba_api

def xquery_injection_1(request):
    test = request.GET["test"]

    store = zorba_api.InMemoryStore_getInstance()
    zorba = zorba_api.Zorba_getInstance(store)

    query = "for $i in (1,2," + test + ")"
    xquery = zorba.compileQuery(query)                  # @violation
    print(xquery.printPlanAsXML())
    print(xquery.execute())
    zorba.shutdown()
    zorba_api.InMemoryStore_shutdown(store)

def xquery_injection_2(request):
    test = request.GET["test"]

    store = zorba_api.InMemoryStore_getInstance()
    zorba = zorba_api.Zorba_getInstance(store)

    tmp = filter(test)

    query = "for $i in (1,2," + tmp + ")"
    xquery = zorba.compileQuery(query)                  # good
    print(xquery.printPlanAsXML())
    print(xquery.execute())
    zorba.shutdown()
    zorba_api.InMemoryStore_shutdown(store)