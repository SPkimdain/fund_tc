package testcase.rule.security.AllowedXMLDTDChecker

import java.io.File
import java.io.FileReader
import javax.xml.parsers.DocumentBuilder
import javax.xml.parsers.DocumentBuilderFactory
import javax.xml.parsers.SAXParser
import javax.xml.parsers.SAXParserFactory
import javax.xml.stream.XMLInputFactory
import javax.xml.stream.XMLStreamReader
import org.dom4j.io.SAXReader
import org.jdom2.input.SAXBuilder
import org.xml.sax.helpers.DefaultHandler

object TestCase {
    fun violation1() {
        val dbf = DocumentBuilderFactory.newInstance()                          // @violation
        val db = dbf.newDocumentBuilder()
        db.parse(File("in.xml"))
    }

    fun violation2() {
        val spf = SAXParserFactory.newInstance()                                // @violation
        val sp = spf.newSAXParser()
        sp.parse(File("in.xml"), DefaultHandler())
    }

    fun violation3() {
        val fac = XMLInputFactory.newInstance()                                 // @violation
        val sr = fac.createXMLStreamReader(FileReader("in.xml"))
    }

    fun violation4() {
        val sr = SAXReader()                                                    // @violation
        val doc = sr.read(FileReader("in.xml"))
    }

    fun violation5() {
        val sb = SAXBuilder()                                                   // @violation
        val doc = sb.build(FileReader("in.xml"))
    }

    fun violation6() {
        val fac = XMLInputFactory.newInstance()                                 // bad (alarm line: setProperty)
        fac.setProperty("javax.xml.stream.supportDTD", true)                    // @violation
        val sr = fac.createXMLStreamReader(FileReader("in.xml"))
    }

    fun violation7() {
        val fac = XMLInputFactory.newInstance().apply {
            setProperty("javax.xml.stream.supportDTD", true)                    // @violation
        }
        val sr = fac.createXMLStreamReader(FileReader("in.xml"))
    }

    fun good1() {
        val dbf = DocumentBuilderFactory.newInstance()                          // good

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true)    // required setting
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false)
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false)

        val db = dbf.newDocumentBuilder()
        db.parse(File("in.xml"))
    }

    fun good2() {
        val fac = XMLInputFactory.newInstance()                                 // good
        fac.setProperty("javax.xml.stream.supportDTD", false)                   // required setting
        val sr = fac.createXMLStreamReader(FileReader("in.xml"))
    }

    fun good3() {
        val sb = SAXBuilder().apply {                                                   // good
            setFeature("http://apache.org/xml/features/disallow-doctype-decl", true)    // required setting
        }
        val doc = sb.build(FileReader("in.xml"))
    }
}