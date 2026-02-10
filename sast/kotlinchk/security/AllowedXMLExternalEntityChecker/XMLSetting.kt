package testcase.rule.security.AllowedXMLExternalEntityChecker

import java.io.File
import java.io.FileReader
import javax.servlet.http.HttpServletRequest
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
    fun violation1(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val dbf = DocumentBuilderFactory.newInstance()

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true)    // required settings
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false)
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false)
        dbf.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false)
        dbf.setFeature(XMLConstants.FEATURE_SECURE_PROCESSING, false)                   // single unsafe setting
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "")
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

        val db = dbf.newDocumentBuilder()
        db.parse(File(p))                   // @violation
    }

    fun violation2(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val spf = SAXParserFactory.newInstance()
        val sp = spf.newSAXParser()
        sp.parse(File(p), DefaultHandler())     // @violation
    }

    fun violation3(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val fac = XMLInputFactory.newInstance()
        val sr = fac.createXMLStreamReader(FileReader(p))   // @violation
    }

    fun violation4(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val sr = SAXReader()
        val doc = sr.read(FileReader(p))                    // @violation
    }

    fun violation5(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val sb = SAXBuilder()
        val doc = sb.build(FileReader(p))                   // @violation
    }

    fun violation6(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val fac = XMLInputFactory.newInstance()
        fac.setProperty("javax.xml.stream.supportDTD", true)
        val sr = fac.createXMLStreamReader(FileReader(p))   // @violation
    }

    fun violation7(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val fac = XMLInputFactory.newInstance().apply {
            setProperty("javax.xml.stream.supportDTD", true)
        }
        val sr = fac.createXMLStreamReader(FileReader(p))    // @violation
    }

    fun good1(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val dbf = DocumentBuilderFactory.newInstance()

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true)    // all required settings
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false)
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false)
        dbf.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false)
        dbf.setFeature(XMLConstants.FEATURE_SECURE_PROCESSING, true)
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "")
        dbf.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

        val db = dbf.newDocumentBuilder()
        db.parse(File(p))                                   // safe
    }

    fun good2(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val fac = XMLInputFactory.newInstance()
        fac.setProperty("javax.xml.stream.supportDTD", false)                       // all required settings
        fac.setProperty("javax.xml.stream.isSupportingExternalEntities", false)
        fac.setProperty(XMLConstants.ACCESS_EXTERNAL_DTD, "")
        fac.setProperty(XMLConstants.ACCESS_EXTERNAL_SCHEMA, "")
        val sr = fac.createXMLStreamReader(FileReader(p))   // safe
    }

    fun good3(request: HttpServletRequest) {
        val p = request.getParameter("some_param")
        val sb = SAXBuilder().apply {
            setFeature("http://apache.org/xml/features/disallow-doctype-decl", true)    // all required settings
            setFeature("http://xml.org/sax/features/external-general-entities", false)
            setFeature("http://xml.org/sax/features/external-parameter-entities", false)
            setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false)
            setFeature(XMLConstants.FEATURE_SECURE_PROCESSING, true)
        }

        val doc = sb.build(FileReader(p))                   // safe
    }
}