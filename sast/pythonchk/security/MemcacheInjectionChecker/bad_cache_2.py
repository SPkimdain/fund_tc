from django.http import HttpResponse
from django.core.cache import caches, cache

def index(request):
    id = request.GET['id']                    # this line contains bad character
    response = HttpResponse()
    cache1 = caches['cache1']
    c = caches['outofanalysis']
    cache1.set("req-" % id, response, 600)      # @violation
    c.set("req-" % id, response, 600)           # cannot generate alarm for this case
    cache.set("req-" % id, response, 600)       # @violation
    return response
