
void doExchange();

void test( )
{
    @try {
        doExchange();
    } @catch (NSException *e) { // @violation
        NSLog(@"doExchange failed");
    }
}

