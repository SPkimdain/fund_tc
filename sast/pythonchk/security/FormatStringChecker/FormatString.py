from django.shortcuts import render

CONFIG = {
    "API_KEY": "771df488714111d39138eb60df756e6b"
    # some program secrets that users should not be able to read
}
class Person(object):
    def __init__(self, name):
        self.name = name

def print_nametag(format_string, person):
    return format_string.format(Person=person)

def format_string(request):
    attack = request.GET["test"]                # if attack = {Person.__init__.__globals__[CONFIG][API_KEY]}

    person = Person("Vickie")

    print(attack.format(Person=person))         # @violation
    print(print_nametag(attack, person))        # @violation
    print("%s" % attack)                        # good
    print(f"{attack}")                          # good
    print(attack + "Hello")                     # good
    print(attack, "Hello")                      # good
    print(attack)                               # good


AUTHENTICATE_KEY = 'Passw0rd'

def make_user_message_1(request):
    user_info = get_user_info(request.POST.get('user_id', ''))

    format_string = request.POST.get('msg_format', '')
    # 내부의 민감한 정보가 외부로 노출될 수 있다.
    # 사용자가 입력한 문자열을 포맷 문자열로 사용하고 있어 안전하지 않다
    message = format_string.format(user=user_info)  # @violation

    return render(request, '/user_page', {'message':message})


def make_user_message_2(request):
    user_info = get_user_info(request.POST.get('user_id', ''))

    # 사용자가 입력한 문자열을 포맷 문자열로 사용하지 않아 안전하다
    message = 'user name is {}'.format(user_info.name) # good

    return render(request, '/user_page', {'message':message})