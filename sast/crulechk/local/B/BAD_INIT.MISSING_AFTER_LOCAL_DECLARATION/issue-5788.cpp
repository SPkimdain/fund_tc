// @checker BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION

typedef int scbcn581140Context;

extern int strncmp ( const char * str1, const char * str2, unsigned num );

void pfmBizDayGetSlsDt(char *);
void pfmBizDayGetSlsDt2(char * str)
{
	str = 0;
	
}

static long b000_validation_input_proc(scbcn581140Context *context) 

{
	
	    long rc = 1;
        if(strncmp("A", "B", 1) == 0)
			{
				char  s_sls_dt[8+1] ;  //@violation BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION
				/* 영업일 */
				pfmBizDayGetSlsDt(s_sls_dt);
				pfmBizDayGetSlsDt2(s_sls_dt);
			}
    

            
			if(strncmp("A", "A", 1) == 0)
			{
				char  s_sls_dt[8+1] ;  //@violation BAD_INIT.MISSING_AFTER_LOCAL_DECLARATION
				/* 영업일 */
				pfmBizDayGetSlsDt(s_sls_dt);
				pfmBizDayGetSlsDt2(s_sls_dt);
			}
    
	
     
}