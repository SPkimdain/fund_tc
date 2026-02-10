from django.http import HttpResponse

def index(request):
    userId = request.GET['id']
    result = eval('100 + ' + userId)                  # @violation
    return HttpResponse('result = ' + result)