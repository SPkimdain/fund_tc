from smtplib import SMTP


def with_statement(request):
    subject = request.GET['subject']
    body = request.GET['body']

    with SMTP(smtp_server, smtp_tls_port) as session:
        session.ehlo()
        session.starttls()
        session.login(username, password)
        headers = "\n".join(["from: sparrow@fasoo.com",
                             "subject: [TEST] Hello! " + subject,
                             "to: sast@fasoo.com",
                             "mime-version: 1.0",
                             "content-type: text/html"])
        session.sendmail("sparrow@fasoo.com", "sast@fasoo.com", headers + "\n\n" + body)  # @violation


def simple_statement(request):
    subject = request.GET['subject']
    body = request.GET['body']

    session = SMTP(smtp_server, smtp_tls_port)
    session.ehlo()
    session.starttls()
    session.login(username, password)
    headers = "\n".join(["from: sparrow@fasoo.com",
                         "subject: [TEST] Hello! " + subject,
                         "to: sast@fasoo.com",
                         "mime-version: 1.0",
                         "content-type: text/html"])
    session.sendmail("sparrow@fasoo.com", "sast@fasoo.com", headers + "\n\n" + body)  # @violation
