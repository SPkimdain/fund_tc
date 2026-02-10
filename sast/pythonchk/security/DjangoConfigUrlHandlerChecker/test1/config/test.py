# config/test.py
from django.conf.urls import handler400, handler403, handler404, handler500

# 사용자 정의 오류 페이지를 지정하고
# views.py에 사용자 정의 오류 페이지에 대한 코드를 구현하여 사용한다.
handler400 = "blog.views.error400"
handler403 = "blog.views.error403"
handler404 = "blog.views.error404"
handler500 = "blog.views.error500"