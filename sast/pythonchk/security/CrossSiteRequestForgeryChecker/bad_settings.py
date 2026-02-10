MIDDLEWARE = [ # @violation
    'django.contrib.sessions.middleware.SessionMiddleware',
    # MIDDLEWARE 목록에서 csrf 항목을 삭제 또는 주석처리 하면
    # Django 앱에서 csrf 유효성 검사가 전역적으로 제거 됨
    # 'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.locale.LocaleMiddleware',
]