// @checker DO_NOT_USE_SIZEOF_ON_PTR
extern void* malloc (int size);

#define SIZE_MAX	512

#define SIZEOF(p) sizeof(p)

double *allocate_array(int num_elems)
{
  double *d_array;

  if (num_elems > SIZE_MAX/sizeof(d_array)) {		//@violation DO_NOT_USE_SIZEOF_ON_PTR
    /* handle error condition */
  }
  d_array = (double *)malloc(sizeof(d_array) * num_elems);	//@violation DO_NOT_USE_SIZEOF_ON_PTR
  if (d_array == 0) {
    /* handle error condition */
  }
  return d_array;
}


double *allocate_array2(int num_elems)
{
  double *d_array;

  if (num_elems > SIZE_MAX/SIZEOF(d_array)) {	
    /* handle error condition */
  }
  d_array = (double *)malloc(SIZEOF(d_array) * num_elems);	
  if (d_array == 0) {
    /* handle error condition */
  }
  return d_array;
}
