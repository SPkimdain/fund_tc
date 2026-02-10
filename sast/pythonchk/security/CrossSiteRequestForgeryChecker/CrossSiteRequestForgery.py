from uuid import uuid4
from flask import Flask
from flask_wtf.csrf import CSRFProtect

from django.template import RequestContext
from django.views.decorators.csrf import csrf_exempt, csrf_protect
from django.shortcuts import render


def cross_site_request_forgery_1(request):
    app = Flask(__name__)
    app.secret_key = str(uuid4())

    csrf = CSRFProtect(app)
    csrf.exempt("controllers.user.create")  # @violation

@csrf.exempt                                # @violation
def cross_site_request_forgery_2(request):
    return HttpResponse('Hello world')

@csrf_exempt                                # @violation
def cross_site_request_forgery_3(request):
    return HttpResponse('Hello world')

@csrf_protect                               # good
def cross_site_request_forgery_4(request):
    c = {}
    return render_to_response("a_template.html", c, context_instance=RequestContext(request))


# csrf.exempt 데코레이터로 미들웨어에서 보호되는 CSRF 기능을 해제한다.
@csrf.exempt    # @violation
def pay_to_point(request):
    user_id = request.POST.get('user_id', '')
    pay = request.POST.get('pay', '')
    product_info = request.POST.get('product_info', '')
    ret = pay(user_id, pay, product_info)
    return render(request, '/view_wallet.html', {'wallet':ret})


# csrf_exempt 데코레이터를 삭제하거나 주석처리한다.
# @csrf_exempt
def pay_to_point(request):
    user_id = request.POST.get('user_id', '')
    pay = request.POST.get('pay', '')
    product_info = request.POST.get('product_info', '')
    ret = pay(user_id, pay, product_info)
    return render(request, '/view_wallet.html', {'wallet':ret})
