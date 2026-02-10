import MySQLdb
from django.shortcuts import render
from app.models import Member

def index(request):
    name = request.GET['name']
    score = request.GET['score']
    query = "SELECT * FROM table WHERE name = '" + name + "' AND score >= '" + score + "';"
    db = MySQLdb.connect("localhost", "user", "pass", "TEST")
    cursor = db.cursor()
    cursor.execute(query)           # @violation
    result = cursor.fetchall()

def index_safe(request):
    name = request.GET['name']
    score = request.GET['score']
    if not True in [badchar in name or badchar in score for badchar in "\n'\""]:
        query = "SELECT * FROM table WHERE name = '" + name + "' AND score >= '" + score + "';"
        db = MySQLdb.connect("localhost", "user", "pass", "TEST")
        cursor = db.cursor()
        cursor.execute(query)           # safe
        result = cursor.fetchall()


def update_board(request):
    dbconn = MySQLdb.connect("localhost", "user", "pass", "TEST")
    with dbconn.cursor() as curs:
        # 외부로부터 입력받은 값을 검증 없이 사용할 경우 안전하지 않다.
        name = request.POST.get('name', '')
        content_id = request.POST.get('content_id', '')

        # 사용자의 검증되지 않은 입력으로 부터 동적으로 쿼리문 생성
    sql_query = "update board set name='" + name + "' where content_id='" + content_id + "'"

    # 외부 입력값이 검증 없이 쿼리로 수행되어 안전하지 않다.
    curs.execute(sql_query)           # @violation
    curs.commit()
    return render(request, '/success.html')

def update_board(request):
    dbconn = MySQLdb.connect("localhost", "user", "pass", "TEST")
    with dbconn.cursor() as curs:
        name = request.POST.get('name', '')
        content_id = request.POST.get('content_id', '')

        # 외부 입력값으로 부터 안전한 매개변수 화된 쿼리를 생성 한다.
        sql_query = 'update board set name=%s where content_id=%s'

        # 사용자의 입력 값을 매개변수 화된 쿼리에 바인딩 하여 실행되므로 안전하다.
        curs.execute(sql_query, (name, content_id))           # safe
        curs.commit()
        return render(request, '/success.html')


def member_search(request):
    # 외부로부터 입력 값을 가져온다.
    name = request.POST.get('name', '')

    # 외부로부터 입력 받은 값을 검증 없이 쿼리문 생성에 사용하여
    # 안전하지 않다.
    query="select * from member where name='" + name + "'"
    # 외부 입력 값을 검증 없이 사용한 쿼리문을 raw()함수로 실행하면
    # 안전하지 않다.
    data = Member.objects.raw(query)           # @violation
    return render(request, '/member_list.html', {'member_list':data})

def member_search(request):
    # 외부로부터 입력 값을 가져온다.
    name = request.POST.get('name', '')

    # 외부 입력 값을 raw()함수 실행 시 바인딩 변수로 사용하여 쿼리 구조가
    # 변경되지 않도록 한다.(list 형은 %s, dictionary 형은 %(key)s를 사용)
    query='select * from member where name=%s'

    # 인자화된 쿼리문을 사용하여 raw()함수를 사용하여 안전하다.
    data = Member.objects.raw(query, [name])           # safe
    return render(request, '/member_list.html', {'member_list':data})