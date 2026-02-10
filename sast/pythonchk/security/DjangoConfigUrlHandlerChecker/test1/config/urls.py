# config/urls.py
from django.conf.urls import handler400, handler403, handler404, handler500  # @violation

handler400 = "blog.views.error400"
handler403 = "blog.views.error403"
handler404 = "blog.views.error404"
