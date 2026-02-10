//@checker IMPROPER_RESTRICTION_OF_XML_ENTITY

//dummy
class XercesDOMParser {
public:
  void setCreateEntityReferenceNodes(bool flag);
  void setDisableDefaultEntityResolution(bool flag);
  void parse(const char* xmlFile);
};

class SAX2XMLReader {
public:
  void setFeature(const unsigned short* entity, bool flag);
  void parse(const char* xmlFile);
};

class XMLReaderFactory {
public:
  static SAX2XMLReader* createXMLReader();  
    
};

class XMLUni {
public:
  static const unsigned short fgXercesDisableDefaultEntityResolution[];
};

class SAXParser {
public:
  void setDisableDefaultEntityResolution(bool flag);
};

struct xmlDoc {};

typedef xmlDoc* xmlDocPtr;

extern xmlDocPtr xmlReadFile(const char* xmlFile, const char* encoding, int options);

enum xmlParserOption {
  XML_PARSE_RECOVER = 1, // recover on errors
  XML_PARSE_NOENT = 2, // substitute entities
  XML_PARSE_DTDLOAD = 4, // load the external subset
  XML_PARSE_DTDATTR = 8, // default DTD attributes
  XML_PARSE_DTDVALID = 16, // validate with the DTD
  XML_PARSE_NOERROR = 32, // suppress error reports
  XML_PARSE_NOWARNING = 64, // suppress warning reports
  XML_PARSE_PEDANTIC = 128, // pedantic error reporting
  XML_PARSE_NOBLANKS = 256, // remove blank nodes
  XML_PARSE_SAX1 = 512, // use the SAX1 interface internally
  XML_PARSE_XINCLUDE = 1024, // Implement XInclude substitition
  XML_PARSE_NONET = 2048, // Forbid network access
  XML_PARSE_NODICT = 4096, // Do not reuse the context dictionary
  XML_PARSE_NSCLEAN = 8192, // remove redundant namespaces declarations
  XML_PARSE_NOCDATA = 16384, // merge CDATA as text nodes
  XML_PARSE_NOXINCNODE = 32768, // do not generate XINCLUDE START / END nodes
  XML_PARSE_COMPACT = 65536, // compact small text nodes; no modification of the tree allowed afterwards(will possibly crash if you try to modify the tree)
  XML_PARSE_OLD10 = 131072, // parse using XML - 1.0 before update 5
  XML_PARSE_NOBASEFIX = 262144, // do not fixup XINCLUDE xml, // base uris
  XML_PARSE_HUGE = 524288, // relax any hardcoded limit from the parser
  XML_PARSE_OLDSAX = 1048576, // parse using SAX2 interface before 2.7.0
  XML_PARSE_IGNORE_ENC = 2097152, // ignore internal document encoding hint
  XML_PARSE_BIG_LINES = 4194304 // Store big lines numbers in text PSVI field
};

void IMPROROXE_001_function(const char* xmlFile) {
  XercesDOMParser* parser = new XercesDOMParser();
  parser->setCreateEntityReferenceNodes(false); //@violation  IMPROPER_RESTRICTION_OF_XML_ENTITY
  parser->setDisableDefaultEntityResolution(false); //@violation  IMPROPER_RESTRICTION_OF_XML_ENTITY

  parser->parse(xmlFile);
}


void IMPROROXE_001_function2(const char* xmlFile) {
  SAX2XMLReader* reader = XMLReaderFactory::createXMLReader();
  reader->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, false); //@violation IMPROPER_RESTRICTION_OF_XML_ENTITY

  reader->parse(xmlFile);
}



void IMPROROXE_001_function3(const char* xmlFile) {
  xmlDocPtr doc = xmlReadFile(xmlFile, 0, XML_PARSE_DTDLOAD | XML_PARSE_NOENT); //@violation IMPROPER_RESTRICTION_OF_XML_ENTITY
}


void IMPROROXE_001_function4() {
  SAXParser* parser = new SAXParser();
  parser->setDisableDefaultEntityResolution(false); //@violation IMPROPER_RESTRICTION_OF_XML_ENTITY
}

