from django.http import FileResponse

def index(request):
    path = request.GET['returnURL']
    return FileResponse(open(path, 'rt'))       # @violation