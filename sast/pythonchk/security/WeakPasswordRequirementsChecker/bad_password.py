from django.contrib.auth.models import User
from django.http import HttpResponse
import string


def bad_django(request):
    user = request.GET['username']
    password = request.GET['password']
    email = request.GET['email']
    user = User.objects.create_user(user, email, password)  # @violation
    user.save()

    u = User.objects.get(username='sparrow')
    u.set_password(password)  # @violation
    u.save()

    return HttpResponse('OK')


def safe_django(request):
    user = request.GET['username']
    password = request.GET['password']

    if len(password) > 10 and all(any(c in password for c in charset) for charset in (string.digits, string.ascii_letters, string)):
        email = request.GET['email']
        user = User.objects.create_user(username=user, email=email, password=password)  # safe
        user.save()

        u = User.objects.get(username='sparrow')
        u.set_password(password)  # safe
        u.save()
        return HttpResponse('OK')
    else:
        return HttpResponse('BAD')

