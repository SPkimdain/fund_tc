//@checker BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE

int test_bossol()
{
    int index = 0;
    if(1)
    {
        return 1;
    }
    else if(2) 
        return 5;
    else
    {
        return 3;
    }

    if(-1) {} //@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE
    else if(-2) //@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE
    {}
    else
    {
    }

    if(0) 
        return 0;
    else if (2) 
        {

        return 5;}

    else //@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE
    { return 2;}

    if(2) //@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE
    { return 2; }


    while(1) 
    { break; }//@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE


    while(1)
    { 
        break; 
    }
    
    while(1) 
        break;

    for(index = 0 ; index < 10; index ++) 
    { break; }//@violation BRACE_OF_STATEMENT_SHOULD_OCCUPY_LINE



    for(index = 0 ; index < 10; index ++)
    { 
        break;
    }

    
    for(index = 0 ; index < 10; index ++) 
        break;

    

}