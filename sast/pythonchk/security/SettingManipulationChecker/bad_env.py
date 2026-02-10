import os

def index(request):
    name = request.GET['key']
    path = request.GET['value']
    os.putenv(name, path)       # @violation 2
