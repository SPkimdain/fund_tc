import os

def bad_os(request):
    name = request.GET['name']
    file = os.open(name)        # @violation

def bad_builtin(request):
    name = request.field('name')
    file = open(name)           # @violation