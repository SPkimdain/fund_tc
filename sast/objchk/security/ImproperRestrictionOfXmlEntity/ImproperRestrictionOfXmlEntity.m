void parseSomeXML (NSString* xml) {

    NSData* xmlConvToData = [xml dataUsingEncoding:NSUTF8StringEncoding];
    NSXMLParser* parser = [[NSXMLParser alloc] initWithData:xmlConvToData];
    [xmlConvToData setShouldResolveExternalEntities:YES]; //@violation
    [xmlConvToData setDelegate:self];
}
