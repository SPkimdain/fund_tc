from django.http import HttpResponse
import logging

def index(request):
    userId = request.GET['id']
    result = eval('100 + ' + userId)
    logger = logging.getLogger(__name__)
    logger.error(userId)        # @violation
    logger.debug(userId)        # @violation
    return HttpResponse('result = ' + result)