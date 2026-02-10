import Foundation


import libxml2



var queryString = getenv("QUERY")
let ctxt = xmlXPathNewContext(docPtr)
if ctxt == nil {
    return XMLNodeSet()
}
ctxt.memory.node = nodePtr

if let nsDictionary = namespaces {
    for (ns, name) in nsDictionary {
        xmlXPathRegisterNs(ctxt, ns, name)
    }
}

let result = xmlXPathEvalExpression(queryString, ctxt) //@violation
