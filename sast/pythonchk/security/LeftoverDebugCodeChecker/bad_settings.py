from django.urls import reverse_lazy
from django.utils.text import format_lazy

DEBUG = True # @violation

ROOT_URLCONF = 'test.urls'
SITE_ID = 1

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': ':memory:',
    }
}