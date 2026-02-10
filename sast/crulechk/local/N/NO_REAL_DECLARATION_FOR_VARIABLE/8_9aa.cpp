
//@checker NO_REAL_DECLARATION_FOR_VARIABLE
//#include <stdio.h>


/* 8_9ab.cpp에 중복 선언이 있으나 extern int 형태에 초기화를 시켜둠*/
extern int notComp1; //@violation NO_REAL_DECLARATION_FOR_VARIABLE

/* 실제 선언이 없음 */
extern int notComp2; //@violation NO_REAL_DECLARATION_FOR_VARIABLE

/* 8_9ab.cpp에 중복 선언이 있으나 실제 선언이 없음*/
extern int notComp3; //@violation NO_REAL_DECLARATION_FOR_VARIABLE

/* 일반 int 선언 */
int comp2; 

int NRDFV_func1()
{
	//printf("%d", comp1);

	return 0;
}

