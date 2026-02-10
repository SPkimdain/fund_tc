import MySQLdb
import mysql.connector
import pymysql
import cx_Oracle
import json
from dbConnect import DBConnect

mydb = MySQLdb.connect(host='localhost',  # @violation
                     user='sparrow',
                     passwd='hardcoded',
                     db='testdb')

mydb2 = None
try:
    mydb2 = mysql.connector.connect(host='localhost',  # @violation
                                    database='testdb',
                                    user='root',
                                    password='hardcoded')
except mysql.connector.Error as e:
    print(e)
finally:
    if mydb2 is not None:
        mydb2.close()

pymydb = pymysql.connect(host='localhost', user='tester', password='hi', db='testdb', charset='utf8')  # @violation 2

oradb = cx_Oracle.connect('username/password@127.0.0.1/dbname')  # @violation


def query_execute(query):
    # usre, passwd가 소스코드에 평문으로 하드코딩되어 있음
    dbconn = pymysql.connect(host='127.0.0.1', port='1234', user='root', passwd='1234', db='mydb', charset='utf8')  # @violation 2
    curs = dbconn.cursor()
    curs.execute(query)
    dbconn.commit()
    dbconn.close()

def query_execute(query, config_path):

    with open(config_path, 'r') as config:
        # 설정파일에서 user, passwd를 가져와 사용
        dbconf = json.load(fp=config)
        #암호화되어 있는 블록암호화 키를 복호화 해서 가져오는
        #사용자 정의 함수
        blockKey = get_decrypt_key('blockKey')
        # 설정파일에 암호화되어 있는 값을 가져와 복호화한 후에 사용
        dbUser = decrypt(blockKey, dbconf['user'])
        dbPasswd = decrypt(blockKey, dbconf['passwd'])

        dbconn = pymysql.connect(host='127.0.0.1', port=dbconf['port'], user=dbUser, passwd=dbPasswd, db=dbconf['db_name'], charset='utf8')     # @violation
        dbconn = pymysql.connect(host=dbconf['host'], port=dbconf['port'], user=dbUser, passwd='1234', db=dbconf['db_name'], charset='utf8')    # @violation
        dbconn = pymysql.connect(host=dbconf['host'], port=dbconf['port'], user=dbUser, passwd=dbPasswd, db=dbconf['db_name'], charset='utf8')  # good
        curs = dbconn.cursor()
        curs.execute(query)
        dbconn.commit()
        dbconn.close()
        
def variable():
    password = "1234567890ab!@"     # @violation
    PassWord = "1234567890ab!@"     # @violation
    passw0rd = "1234567890ab!@"     # @violation
    passwd = "1234567890ab!@"       # @violation
    xPasswd = getSomething()        # good
    pwd = "1234567890ab!@"          # @violation
    pw = "1234567890ab!@"           # @violation
    ip = "127.0.0.1"                # @violation
    iP = "127.0.0.1"                # @violation
    iPaaa = "dddddd"                # good
    host = "127.0.0.1"              # @violation
    Host = "127.0.0.1"              # @violation
    last_password = "fwefewfewf"    # @violation
    last2_password = getSomething() # good
    EMAIL_HOST_PASSWORD = "cvr23sdfdf" # @violation
    DATABASE = {
        'default': {
            'ENGINE': 'fpojqpoj',
            'USER': 'abmin',
            'PASSWORD': 'testdlkajfoj', # @violation
            'ALTER_PASSWORD': getSomething(), # good
            'ALTER2_PASSWORD': 'tailcheck' # @violation
        }
    }


def getSomething():
    return input("Enter something: ")


