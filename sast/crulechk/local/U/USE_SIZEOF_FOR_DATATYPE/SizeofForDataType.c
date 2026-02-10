// @checker USE_SIZEOF_FOR_DATATYPE
typedef long size_t;
extern void * memset ( void * ptr, int value, size_t num );

int main(int argc, char** argv)
{
    int a[16];

    memset(a, 0, 64); // @violation USE_SIZEOF_FOR_DATATYPE
    memset(a, 0, sizeof(int));
    memset(a, 0, 16*sizeof(int));
    memset(a, 0, 32*16*sizeof(int));

    return 0;
}
