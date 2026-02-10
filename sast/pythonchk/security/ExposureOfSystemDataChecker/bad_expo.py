import traceback
from django.http import HttpResponse
import flask

# flask examples

app = flask.Flask(__name__)


@app.route('/test')
def index_flask():
    if flask.request.form['something_bad']:
        return flask.make_response(traceback.format_exc().strip().split('\n'))  # @violation
    else:
        return flask.make_response('OK')  # safe


@app.route('/test2')
def index_flask2():
    if flask.request.form['something_bad']:
        lines = traceback.format_exc().strip().split('\n')
        return flask.make_response('BAD')  # safe
    else:
        return flask.make_response('OK')  # safe


# django example

def index(request):
    if request.GET['something_bad']:
        response = HttpResponse('BAD')
        lines = traceback.format_exc().strip().split('\n')
        response.writelines(lines)  # @violation
    else:
        response = HttpResponse('OK')
    return response


def index2(request):
    if request.GET['something_bad']:
        response = HttpResponse('BAD')
        traceback.print_exc()  # @violation
    else:
        response = HttpResponse('OK')
    return response

def fetch_url(url, useragent, referer=None, retries=1, dimension=False):
    try:
        response = requests.get(url, stream=True, timeout=5, headers={
            'User-Agent': useragent,
            'Referer': referer,
        })
    except IOError:
        # 에러메시지를 통해 스택정보가 노출됨.
        traceback.print_exc()       # @violation

def fetch_url(url, useragent, referer=None, retries=1, dimension=False):
    try:
        response = requests.get(url, stream=True, timeout=5, headers={
            'User-Agent': useragent,
            'Referer': referer,
        })
    except IOError:
        # 에러 코드와 정보를 별도로 정의하고 최소 정보만 로깅
        logger.info('ERROR-01:통신에러')    # good
