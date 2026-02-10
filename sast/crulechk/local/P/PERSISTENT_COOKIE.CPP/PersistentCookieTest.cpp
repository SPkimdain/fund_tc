//@checker PERSISTENT_COOKIE.CPP
typedef long long qint64;

class QDateTime {
public :
	QDateTime() {}
	QDateTime(const QDateTime &other){};
	QDateTime addDays(qint64 days) const{ QDateTime *qt = new QDateTime(); return *qt;}
    QDateTime addMonths(int months) const{ QDateTime *qt = new QDateTime(); return *qt;}
    QDateTime addYears(int years) const{ QDateTime *qt = new QDateTime(); return *qt;}
    QDateTime addSecs(qint64 secs) const{ QDateTime *qt = new QDateTime(); return *qt;}
    QDateTime addMSecs(qint64 msecs) const{  QDateTime *qt = new QDateTime(); return *qt;}
	static QDateTime currentDateTime(){ QDateTime *qt = new QDateTime(); return *qt;}
	
};

class QNetworkCookie {
public :
	void setExpirationDate(const QDateTime &date){}
};

void PCC_001() {
	QNetworkCookie cookie;
    cookie.setExpirationDate(QDateTime::currentDateTime().addYears(2));	//@violation PERSISTENT_COOKIE.CPP
	cookie.setExpirationDate(QDateTime::currentDateTime().addMonths(12));	//@violation PERSISTENT_COOKIE.CPP
	cookie.setExpirationDate(QDateTime::currentDateTime().addDays(22));	//@violation PERSISTENT_COOKIE.CPP
    
	cookie.setExpirationDate(QDateTime::currentDateTime().addSecs(3601));	//@violation PERSISTENT_COOKIE.CPP
	cookie.setExpirationDate(QDateTime::currentDateTime().addMSecs(360001));	//@violation PERSISTENT_COOKIE.CPP
	
	cookie.setExpirationDate(QDateTime::currentDateTime().addSecs(3600));
	cookie.setExpirationDate(QDateTime::currentDateTime().addMSecs(360000));
}
