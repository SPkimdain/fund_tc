// @checker BAD_TYPE_DECLARATION

#define TYPEDEF(a) struct a{ \
  int a; \
int b; \
}

typedef int dummy;
typedef dummy attribute_type_e;
typedef dummy format_attribute_e;
typedef dummy type_mode_e;

typedef struct attribute_s attribute_t;
typedef struct attribute_s *attribute_p;
struct attribute_s {
    attribute_type_e type;
    union {
        type_mode_e mode;
        char *selection;
        char *alias;
        struct {
            format_attribute_e type;
            int format_arg;
        }format;
    } variant;
    attribute_p next;
};


struct wrong_s{    // @violation BAD_TYPE_DECLARATION
    attribute_type_e type;
    union{    // @violation BAD_TYPE_DECLARATION
        type_mode_e mode;
        char *selection;
        char *alias;
        struct{        // @violation BAD_TYPE_DECLARATION
            format_attribute_e type;
            int format_arg;
        }format;
    } variant;
};

TYPEDEF(MACRO_ST1);	// @violation BAD_TYPE_DECLARATION

typedef int myint;
struct ST1 {
    int a;
    int b;
};


  typedef int myint2;   // @violation BAD_TYPE_DECLARATION
typedef int
myint3;


 struct ST2 {           // @violation BAD_TYPE_DECLARATION
    int a;
    int b; int c;
};


struct ST3 {
    int a;
      int b;  // @violation BAD_TYPE_DECLARATION
    struct ST_INNER {
        int c;
        int d;
    } st;
};


/* struct ST_INNER st_inner; */



struct ST4 {
    int a;
    int b; int c;         // @violation BAD_TYPE_DECLARATION
};
