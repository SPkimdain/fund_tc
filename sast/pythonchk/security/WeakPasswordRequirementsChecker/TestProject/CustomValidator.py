import re
from django.core.exceptions import ValidationError
from django.utils.translation import ugettext as _


class CustomValidator(object):

    def validate(self, password, user=None):
        if len(password) > 8:

            # 2종 이상 문자로 구성된 8자리 이상 비밀번호 검사 정규식
            PT1 = re.compile('^(?=.*[A-Z])(?=.*[a-z])[A-Za-z\d!@#$%^&*]{8,}$')
            PT2 = re.compile('^(?=.*[A-Z])(?=.*\d)[A-Za-z\d$@$!%*?&]{8,}$')
            PT3 = re.compile('^(?=.*[A-Z])(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$')
            PT4 = re.compile('^(?=.*[a-z])(?=.*\d)[A-Za-z\d!@#$%^&*]{8,}$')
            PT5 = re.compile('^(?=.*[a-z])(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$')
            PT6 = re.compile('^(?=.*\d)(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$')

            # 문자 구성 상관없이 10자리 이상 비밀번호 검사 정규식
            PT7 = re.compile('^[A-Za-z\d!@#$%^&*]{10,}$')

            for pattern in [PT1, PT2, PT3, PT4, PT5, PT6, PT7]:
                if pattern.match(password):
                    return None
                else:
                    raise ValidationError

    def get_help_text(self):
        return _("비밀번호는 영문 대문자, 소문자, 숫자, 특수문자 조합 중 2가지 이상 8자리이거나 문자 구성 상관없이 10자리 이상이어야 합니다.")