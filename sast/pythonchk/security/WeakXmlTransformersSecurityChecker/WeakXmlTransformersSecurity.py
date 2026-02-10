import xml.sax
from lxml import etree
from xml.sax import make_parser
from xml.sax.handler import feature_external_ges
from xml.dom.pulldom import parseString, START_ELEMENT
from django.shortcuts import render
from .model import comments


def violation1():
    parser = etree.XMLParser()  # @violation
    tree1 = etree.parse('ressources/xxe.xml', parser)
    root1 = tree1.getroot()


def violation2():
    parser = etree.XMLParser(resolve_entities=True)  # @violation
    tree1 = etree.parse('ressources/xxe.xml', parser)
    root1 = tree1.getroot()


def violation3():
    parser = etree.XMLParser(resolve_entities=True)  # @violation
    treexsd = etree.parse('ressources/xxe.xsd', parser)
    rootxsd = treexsd.getroot()
    schema = etree.XMLSchema(rootxsd)


def violation4():
    ac = etree.XSLTAccessControl(read_network=True, write_network=False)  # @violation
    transform = etree.XSLT(rootxsl, access_control=ac)


def violation5():
    parser = xml.sax.make_parser()
    myHandler = MyHandler()
    parser.setContentHandler(myHandler)

    parser.setFeature(feature_external_ges, True)  # @violation
    parser.parse("ressources/xxe.xml")


def good1():
    parser = etree.XMLParser(resolve_entities=False, no_network=True)
    tree1 = etree.parse('ressources/xxe.xml', parser)
    root1 = tree1.getroot()


def good2():
    parser = etree.XMLParser(resolve_entities=False)
    treexsd = etree.parse('ressources/xxe.xsd', parser)
    rootxsd = treexsd.getroot()
    schema = etree.XMLSchema(rootxsd)


def good3():
    parser = etree.XMLParser(resolve_entities=False)
    treexsl = etree.parse('ressources/xxe.xsl', parser)
    rootxsl = treexsl.getroot()

    ac = etree.XSLTAccessControl.DENY_ALL
    transform = etree.XSLT(rootxsl, access_control=ac)


def good4():
    parser = xml.sax.make_parser()
    myHandler = MyHandler()
    parser.setContentHandler(myHandler)
    parser.parse("ressources/xxe.xml")

    parser.setFeature(feature_external_ges, False)
    parser.parse("ressources/xxe.xml")


def get_xml(request):
    if request.method == "GET":
        data = comments.objects.all()
        com = data[0].comment
        return render(request, '/xml_view.html', {'com': com})

    elif request.method == "POST":
        parser = make_parser()
        parser.setFeature(feature_external_ges, True)  # @violation
        doc = parseString(request.body.decode('utf-8'), parser=parser)
        for event, node in doc:
            if event == START_ELEMENT and node.tagName == "foo":
                doc.expandNode(node)
                text = node.toxml()
        comments.objects.filter(id=1).update(comment=text);
        return render(request, '/xml_view.html')


def get_xml(request):
    if request.method == "GET":
        data = comments.objects.all()
        com = data[0].comment
        return render(request, '/xml_view.html', {'com': com})

    elif request.method == "POST":
        parser = make_parser()
        parser.setFeature(feature_external_ges, False)
        doc = parseString(request.body.decode('utf-8'), parser=parser)
        for event, node in doc:
            if event == START_ELEMENT and node.tagName == "foo":
                doc.expandNode(node)
                text = node.toxml()
        comments.objects.filter(id=1).update(comment=text);
        return render(request, '/xml_view.html')
