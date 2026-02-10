import traceback

def bad(url, useragent, referer=None, retries=1, dimension=False):
    try:
        pass
        # ...
    except IOError:
        # 오류 메시지를 통해 스택정보가 노출됨.
        traceback.print_exc()   # @violation


def good(url, useragent, referer=None, retries=1, dimension=False):
    try:
        pass
        # ...
    except:
        # 오류 코드와 정보를 별도로 정의하고 최소 정보만 로깅
        logger.info('ERROR-01:통신오류')
