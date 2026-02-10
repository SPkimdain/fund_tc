func parseXML(xml: String) {
  xmlParser = NSXMLParser(data: rawXml.dataUsingEncoding(NSUTF8StringEncoding)!)

  xmlParser.delegate = self
  xmlParser.shouldResolveExternalEntities = true //@violation
  xmlParser.parse()
}
