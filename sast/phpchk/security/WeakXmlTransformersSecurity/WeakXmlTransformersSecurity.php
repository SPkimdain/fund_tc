<?php
    function violation1() {
        $xml = file_get_contents("xxe.xml");
        $doc = simplexml_load_string($xml, "SimpleXMLElement", LIBXML_NOENT);   // @violation
    }

    function violation2() {
        $doc = new DOMDocument();
        $doc->load("xxe.xml", LIBXML_NOENT);                                    // @violation
    }

    function violation3() {
        $reader = new XMLReader();
        $reader->open("xxe.xml");
        $reader->setParserProperty(XMLReader::SUBST_ENTITIES, true);            // @violation
    }

    function good1() {
        $xml = file_get_contents("xxe.xml");
        $doc = simplexml_load_string($xml, "SimpleXMLElement");                 // good
    }

    function good2() {
        $doc = new DOMDocument();
        $doc->load("xxe.xml");                                                  // good
    }

    function good3() {
        $reader = new XMLReader();
        $reader->open("xxe.xml");
        $reader->setParserProperty(XMLReader::SUBST_ENTITIES, false);           // good
    }
?>