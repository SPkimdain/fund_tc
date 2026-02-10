import html
from flask import render_template

# flask examples


@app.route('/search', methods=['POST'])
def search():
    search_keyword = request.form.get('search_keyword')
    # 사용자의 입력을 아무런 검증 또는 치환 없이 동적 웹 페이지에 사용하고 있어
    # 크로스사이트 스크립트가 발생할 수 있다
    return render_template('search.html', search_keyword=search_keyword)  # @violation

app = flask.Flask(__name__)


@app.route('/search', methods=['POST'])
def search():
    search_keyword = request.form.get('search_keyword')
    # 동적 웹 페이지 생성에 사용되는 데이터는
    # HTML 엔티티코드로 치환하여 표현해야한다
    escape_keyword = html.escape(search_keyword)
    return render_template('search.html', search_keyword=escape_keyword)  # safe


from django.http import HttpResponse
from django.shortcuts import render
from django.utils.safestring import mark_safe

# django example


def profile_link(request):
    # 외부 입력값을 검증 없이 HTML 태그 생성의 인자로 사용
    profile_url = request.POST.get('profile_url')
    profile_name = request.POST.get('profile_name')

    object_link = '<a href="{}">{}</a>'.format(profile_url, profile_name)
    # mark_safe함수는 Django의 XSS escape 정책을 따르지 않는다.
    object_link = mark_safe(object_link)  # @violation
    return render(request, 'my_profile.html',{'object_link':object_link})


def profile_link(request):
    # 외부 입력값을 검증 없이 HTML 태그 생성의 인자로 사용
    profile_url = request.POST.get('profile_url')
    profile_name = request.POST.get('profile_name')

    object_link = '<a href="{}">{}</a>'.format(profile_url, profile_name)
    # 신뢰 할 수 없는 데이터에 대해서는 mark_safe 함수를 사용하지 않는다
    # object_link = mark_safe(object_link)  # safe
    return render(request, 'my_profile.html',{'object_link':object_link})