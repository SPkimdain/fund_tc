// @checker BAD_WHITESPACE.COMMA

#define COMMA(a, b) a,b
#define X_END 10
extern void mapPoint(int, int);


void nh_2_4_2_10_4( )
{
    int xco;
    int yco;
    int z;

    for ( xco = 3, yco = 17; xco < X_END; xco++, yco++ ) {
	mapPoint( xco, yco );
    }

    z = xco ,yco;                 // @violation BAD_WHITESPACE.COMMA
    z = xco,yco;                  // @violation BAD_WHITESPACE.COMMA
    z = xco , yco;                  // @violation BAD_WHITESPACE.COMMA

    z = COMMA(xco, yco);
}
