package testcase.rule.security.WeakXmlTransformersSecurityChecker

import java.io.File
import java.io.FileReader
import javax.xml.XMLConstants
import javax.xml.parsers.DocumentBuilder
import javax.xml.parsers.DocumentBuilderFactory
import javax.xml.parsers.SAXParser
import javax.xml.parsers.SAXParserFactory
import javax.xml.stream.XMLInputFactory
import javax.xml.stream.XMLStreamReader
import javax.xml.transform.Transformer
import javax.xml.transform.TransformerFactory
import org.dom4j.io.SAXReader
import org.jdom2.input.SAXBuilder
import org.xml.sax.helpers.DefaultHandler

object TestCase {
	fun violation1() {
		val transformer = TransformerFactory.newInstance().newTransformer()
		transformer.transform(input, result)			// @violation
	}

	fun violation2() {
		val factory1 = TransformerFactory.newInstance()
		factory1.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
		factory1.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

		val factory2 = TransformerFactory.newInstance()

		val transformer = factory2.newTransformer()
		transformer.transform(input, result)			// @violation
	}

	fun violation3() {
		val factory = TransformerFactory.newInstance()
		factory.setAttribute(XMLConstants.XML_NS_URI, "")

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// @violation
	}

    fun violation4() {
        val dbf = DocumentBuilderFactory.newInstance()
        val db = dbf.newDocumentBuilder()
        db.parse(File("in.xml"))                    // @violation
    }

    fun violation5() {
        val spf = SAXParserFactory.newInstance()
        val sp = spf.newSAXParser()
        sp.parse(File("in.xml"), DefaultHandler())  // @violation
    }

    fun violation6() {
        val fac = XMLInputFactory.newInstance()
        val sr = fac.createXMLStreamReader(FileReader("in.xml"))    // @violation
    }

    fun violation7() {
        val sr = SAXReader()
        val doc = sr.read(FileReader("in.xml"))                                     // @violation
    }

    fun violation7() {
        val sb = SAXBuilder()
        val doc = sb.build(FileReader("in.xml"))                                    // @violation
    }

	fun good1() {
		val factory = TransformerFactory.newInstance()
		factory.setAttribute(XMLConstants.ACCESS_EXTERNAL_DTD, "")
		factory.setAttribute(XMLConstants.ACCESS_EXTERNAL_STYLESHEET, "")

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// good
	}

	fun good2() {
		val factory = TransformerFactory.newInstance()
		factory.setFeature(XMLConstants.FEATURE_SECURE_PROCESSING, true)

		val transformer = factory.newTransformer()
		transformer.transform(input, result)			// good
	}

    fun good3() {
        val dbf = DocumentBuilderFactory.newInstance()

        dbf.setFeature("http://apache.org/xml/features/disallow-doctype-decl", true);
        dbf.setFeature("http://xml.org/sax/features/external-general-entities", false);
        dbf.setFeature("http://xml.org/sax/features/external-parameter-entities", false);

        val db = dbf.newDocumentBuilder()
        db.parse(File("in.xml"))                    // good
    }
}