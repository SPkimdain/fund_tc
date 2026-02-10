from django.contrib.auth.forms import SetPasswordForm, PasswordChangeForm
from django.http import HttpResponse
from some.pack import BankAccount


def access_danger(request):
    account = BankAccount()
    account.sendAccount()  # @violation
    response = HttpResponse('OK')
    return response


def access_safe(request):
    req_user_name = request.GET['username']
    user_name = request.session['username']

    if req_user_name == user_name:
        account = BankAccount()
        account.sendAccount()
        response = HttpResponse('OK')
        return response
    else:
        return HttpResponse('BAD')


def access_safe2(request):
    req_user_name = request.GET['username']
    user_name = request.session['username']

    if req_user_name != user_name:
        return HttpResponse('BAD')

    account = BankAccount()
    account.sendAccount()
    response = HttpResponse('OK')
    return response


def bad_change_password(request):
    can_change_password = request.user.has_usable_password()

    if can_change_password:
        if request.POST:
            form = SetPasswordForm(request.user, request.POST)  # @violation

            if form.is_valid():
                form.save()

                if django.VERSION >= (1, 7):
                    from django.contrib.auth import update_session_auth_hash
                    update_session_auth_hash(request, form.user)

                messages.success(request, _("Your password has been changed successfully!"))
                return redirect('admin_account')
        else:
            form = SetPasswordForm(request.user)                # @violation
    else:
        form = None

    return render(request, 'admin/account/change_password.html', {
        'form': form,
        'can_change_password': can_change_password,
    })


def good_change_password(request):
    if not password_management_enabled():
        raise Http404

    can_change_password = request.user.has_usable_password()

    if can_change_password:
        if request.method == 'POST':
            form = PasswordChangeForm(request.user, request.POST)   # good

            if form.is_valid():
                form.save()
                update_session_auth_hash(request, form.user)

                messages.success(request, _("Your password has been changed successfully!"))
                return redirect('admin_account')
        else:
            form = PasswordChangeForm(request.user)                 # good
    else:
        form = None

    return TemplateResponse(request, 'admin/account/change_password.html', {
        'form': form,
        'can_change_password': can_change_password,
    })