from smtplib import SMTP


def with_statement(request):
    user = request.GET['user']
    cmd = request.GET['cmd']

    with SMTP(smtp_server, smtp_tls_port) as session:
        session.ehlo()
        session.starttls()
        session.login(username, password)
        session.docmd(cmd, user)        # @violation 2


def simple_statement(request):
    user = request.GET['user']
    cmd = request.GET['cmd']

    session = SMTP(smtp_server, smtp_tls_port)
    session.ehlo()
    session.starttls()
    session.login(username, password)
    session.docmd(cmd, user)            # @violation 2
