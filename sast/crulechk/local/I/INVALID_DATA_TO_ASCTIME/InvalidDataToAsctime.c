// @checker INVALID_DATA_TO_ASCTIME

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

extern char* asctime (const struct tm * timeptr);

void func(void) {
  struct tm time_tm;
  /* Initialize time_tm */
  char *time = asctime(&time_tm);	//@violation INVALID_DATA_TO_ASCTIME
}

int validate_tm(struct tm* time) {
  /* 
   * The range of valid values of the tm_sec member is [0, 60] 
   * inclusive (to allow for leap seconds).
   */
  if (time->tm_sec < 0 || time->tm_sec > 60) return 0;
  if (time->tm_min < 0 || time->tm_min >= 60) return 0;
  if (time->tm_hour < 0 || time->tm_hour >= 24) return 0;
  if (time->tm_mday <= 0 || time->tm_mday > 31) return 0;
  if (time->tm_mon < 0 || time->tm_mon >= 12) return 0;
  /* While other years are legit, they may overflow asctime()'s buffer */
  if (time->tm_year < -999 || time->tm_year > 9999) return 0;
  if (time->tm_wday < 0 || time->tm_wday >= 7) return 0;
  if (time->tm_yday < 0 || time->tm_yday >= 366) return 0;
  return 1;
}
 
void func1(void) {
  struct tm time_tm;
  /* Initialize time_tm */
  if (!validate_tm(&time_tm)) {	
    /* Handle error */
  }
  char *time = asctime(&time_tm);	//@violation INVALID_DATA_TO_ASCTIME
}