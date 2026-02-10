from xml.etree import parse
from lxml import etree


def index(request):
    tree = parse('test.xml')
    xpath = "./students/[@userId=" + request.GET["test"] + "]/phone/text()"
    r = tree.findall(xpath)  # @violation


def safe_index(request):
    tree = parse('test.xml')
    arg = request.GET["test"]
    if not True in [badchar in arg for badchar in "\n'\""]:
        xpath = "./students/[@userId=" + arg + "]/phone/text()"
        r = tree.findall(xpath)  # safe


def parse_xml(request):
    user_name = request.POST.get('user_name', '')

    parser = etree.XMLParser(resolve_entities=False)
    tree = etree.parse('user.xml', parser)
    root = tree.getroot()

    # 검증되지 않은 외부 입력값 user_name를 사용하여
    # 안전하지 않은 질의문이 작성되에 query변수에 저장
    query = "/collection/users/user[@name='" + user_name + "']/home/text()"
    elmts = root.xpath(query)  # @violation
    return render(request, 'parse_xml.html', {'xml_element': elmts})


def parse_xml(request):
    user_name = request.POST.get('user_name', '')

    parser = etree.XMLParser(resolve_entities=False)
    tree = etree.parse('user.xml', parser)
    root = tree.getroot()

    query = '/collection/users/user[@name = $paramname]/home/text()'
    #외부 입력값을 paramname으로 매개변수화 해서 사용
    elmts = root.xpath(query, paramname=user_name)  # safe
    return render(request, 'parse_xml.html', {'xml_element':elmts})