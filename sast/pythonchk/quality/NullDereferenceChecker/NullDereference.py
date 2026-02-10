from xml.sax import make_parser, handler
import os

def not_taint() :
    return 1

def no_call1():
    filename = not_taint()
    if filename.count('.'):
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def no_call2():
    filename = not_taint()
    if filename == 0:
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_param1(request):
    filename = request.POST.get('app_name', '')
    if check(filename):   # @violation
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_param2(request):
    filename = request.POST.get('app_name', '')
    if check(filename) == 0:   # @violation
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_call1(request):
    filename = request.POST.get('app_name', '')
    if filename.print('.'):   # @violation
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_comp1(request):
    filename = request.POST.get('app_name', '')
    if filename <= 0:
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_call_comp1(request):
    filename = request.POST.get('app_name', '')
    if filename.count('.') <= 1:   # @violation
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_null_check(request):
    filename = request.POST.get('app_name', '')
    if filename is None:
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_call1(request):
    filename = request.POST.get('app_name', '')
    if filename is None and filename.count('.'):
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_call2(request):
    filename = request.POST.get('app_name', '')
    if filename is None:
        tmp = 0
    if filename.count('.'):
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_comp1(request):
    filename = request.POST.get('app_name', '')
    if filename is None and filename >= 0:
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_comp2(request):
    filename = request.POST.get('app_name', '')
    if filename is None:
        tmp = 0
    if filename < 1:
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def good_call_comp1(request):
    filename = request.POST.get('app_name', '')
    if filename is None and filename.count('.') == "":
        name, ext = os.path.splitext(filename)
    else:
        ext = ''

def bad_call_comp2(request):
    filename = request.POST.get('app_name', '')
    if filename is None:
        tmp = 0
    if filename.count('.') == "":
        name, ext = os.path.splitext(filename)
    else:
        ext = ''