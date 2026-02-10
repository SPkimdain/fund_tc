from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login
from django.shortcuts import redirect


def bad_django(request):
    username = request.GET['username']
    password = request.GET['password']
    user = authenticate(request, username=username, password=password)  # @violation
    if user is not None:
        # success
        login(request, user)  # @violation
        return redirect('/main')
    else:
        return redirect('/login')


def bad_django_deep(request):
    username = request.GET['username']
    password = request.GET['password']

    if request.GET['needless_check'] is None:  # for complexity test
        if request.GET['needless_check2'] is None:  # for complexity test
            user = authenticate(request, username=username, password=password)  # @violation
            if user is not None:
                # success
                login(request, user)  # @violation
                return redirect('/main')
            else:
                return redirect('/login')


def safe_django(request):
    username = request.GET['username']
    password = request.GET['password']
    num_trial = request.session.get('num_trial', 0)
    if num_trial > 5:
        return redirect('/over_limit')
    else:
        num_trial += 1
        request.session['num_trial'] = num_trial

        user = authenticate(request, username=username, password=password)
        if user is not None:
            # success
            login(request, user)
            return redirect('/main')
        else:
            return redirect('/login')


def safe_django_deep(request):
    username = request.GET['username']
    password = request.GET['password']
    num_trial = request.session.get('num_trial', 0)

    if num_trial > 5:
        return redirect('/over_limit')
    else:
        num_trial += 1
        request.session['num_trial'] = num_trial

        if request.GET['needless_check'] is None:  # for complexity test
            if request.GET['needless_check2'] is None:  # for complexity test
                user = authenticate(request, username=username, password=password)
                if user is not None:
                    # success
                    login(request, user)
                    return redirect('/main')
                else:
                    return redirect('/login')


def safe_django2(request):
    username = request.GET['username']
    password = request.GET['password']
    num_trial = request.session.get('num_trial', 0)
    if num_trial > 5:
        return redirect('/over_limit')
    else:
        num_trial = 1 + num_trial
        request.session['num_trial'] = num_trial

        user = authenticate(request, username=username, password=password)
        if user is not None:
            # success
            login(request, user)
            return redirect('/main')
        else:
            return redirect('/login')


def old_style(request):
    username = request.GET['username']
    password = request.GET['password']

    num_trial = 0

    while num_trial < 5:
        num_trial = num_trial + 1
        request.session['num_trial'] = num_trial

        user = authenticate(request, username=username, password=password)
        if user is not None:
            # success
            login(request, user)
            return redirect('/main')
        else:
            return redirect('/login')


def safe_test_login(request):
    for count in range(5):
        try_login_action()


def deep_safe_test_login(request):
    if request.GET['needless_check'] is None:  # for complexity test
        for count in range(5):
            if request.GET['needless_check2'] is None:  # for complexity test
                try_login_action()


def deep_danger_test_login(request):  # @violation
    while True:
        if request.GET['needless_check'] is None:  # for complexity test
            if request.GET['needless_check2'] is None:  # for complexity test
                try_login_action()


def danger_test_login(request):  # @violation
    while True:
        try_login_action()
