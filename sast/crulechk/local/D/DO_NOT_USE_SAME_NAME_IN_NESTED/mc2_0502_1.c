//@checker DO_NOT_USE_SAME_NAME_IN_NESTED

/*
 * Release Date: 17 JULY 2007
 *
 * MISRA-C:2004 Exemplar Suite
 *
 * Published by
 * MIRA Limited, Watling Street, Nuneaton, Warwickshire CV10 0TU UK
 * www.misra-c.com
 *
 * Copyright MIRA Limited, 2006, 2007.
 *
 * See file READ_ME.txt for full copyright, license and release information.
 */

/*
 * 5.2 Identifiers in an inner scope shall not use the same name as an
 *     identifier in an outer scope, and therefore hide that identifier.
 */

/*
 * All instances involving tags will be caught by rule 5.4 also.
 * All instances involving typedefs will be caught by rule 5.3 also.
 * This file also contains violations of other 5.* rules
 */

#include "DNUSNIN_mc2_types.h"
#include "DNUSNIN_mc2_header.h"
#include "mc2_0502.h"

static void mc2_0502a ( void );
static void mc2_0502b ( void );
static void mc2_0502c ( void );
static void enum_func_hide (void);

static void mc2_0502a ( void ) //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
   use_int32 ( local_hide_extern );
}

static void mc2_0502b ( void ) //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
   use_int32 ( 0 ); /* Do Something */
}

static void mc2_0502c ( void ) //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
   use_int32 ( 0 ); /* Do Something */
}

static void enum_func_hide (void) //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
{
	use_int32 ( 0 ); /* Do Something */
}

void mc2_0502 ( void )
{
   struct tag_hide { int32_t memb; } t_hide = { 0 }; //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED          
   int32_t var_hide = get_int32 ( ); //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   int32_t var_enum_hide = get_int32 ( ); //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   enum
   {
      hidden_enumerated //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   } enum_var_hide, enum_hide, enum_type_hide; //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   typedef int32_t typedef_hide;
   typedef int32_t type_enum_hide; //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   typedef int32_t type_var_hide; //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED
   int32_t var_type_hide  = get_int32 ( ); //@b-violation DO_NOT_USE_SAME_NAME_IN_NESTED


   static struct
   {
      int32_t no_hiding;
      struct
      {
         int32_t no_hiding;    /* Compliant  as outer.no_hiding and */
      } inner;                 /* outer.inner.no_hiding cannot be confused */
   } outer;                    /* Although, Not Compliant 5.7 */

   typedef_hide   mc2_0502_v1 = get_int32 ( );
   type_enum_hide mc2_0502_v2 = get_int32 ( );
   type_var_hide  mc2_0502_v3 = get_int32 ( );

   if ( t_hide.memb == get_int32 ( ) )
   {
	  /* Not Compliant - Tag hidden by Tag */
      struct tag_hide t_hide; //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Int hides Int */
      int32_t var_hide;  //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Int hides Enum */
      int32_t enum_var_hide; //@violation DO_NOT_USE_SAME_NAME_IN_NESTED                    
      enum
      {
         hidden_enumerated //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
      }    
	  /* Not Compliant - Enum hides Int */
      var_enum_hide,                   //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Enum hides Enum */
      enum_hide,                       //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Enum hides Typedef */
      type_enum_hide;                  //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Int hides Typedef */
      int32_t type_var_hide;           //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Int hides Function */
      int32_t mc2_0502a;               //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
      enum
      {
         mc2_0502b //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
      }                  
	  /* Not Compliant - Enum hides Function */	  
      enum_func_hide;                  //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Local var hides extern from header */
      int32_t local_hide_extern;       //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Typedef hides Enum */
      typedef int32_t enum_type_hide;  //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Typedef hides Int */
      typedef int32_t var_type_hide;   //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          
	  /* Not Compliant - Typedef hides Function */
      typedef int32_t mc2_0502c;       //@violation DO_NOT_USE_SAME_NAME_IN_NESTED          

      /* Usage */

      enum_type_hide mc2_0502_v4 = get_int32 ( );
      var_type_hide mc2_0502_v5  = get_int32 ( );
      mc2_0502c mc2_0502_v6      = get_int32 ( );

      t_hide.memb = get_int32 ( );
      var_hide = get_int32 ( );
      enum_var_hide = get_int32 ( );
      var_enum_hide = hidden_enumerated;
      enum_hide = hidden_enumerated;
      type_enum_hide = hidden_enumerated;
      type_var_hide = get_int32 ( );
      mc2_0502a = get_int32 ( );
      enum_func_hide = mc2_0502b;
      local_hide_extern = get_int32 ( );


      use_int32 ( t_hide.memb );
      use_int32 ( var_hide );
      use_int32 ( enum_var_hide );
      /* use_enum ( var_enum_hide );  some tools may flag var_enum_hide as
       *                              unused */
      /* use_enum ( enum_hide );      some tools may flag enum_hide as unused */
      /* use_enum ( type_enum_hide ); some tools may flag type_enum_hide as
       *                              unused */
      use_int32 ( type_var_hide );
      use_int32 ( mc2_0502a );
      /* use_enum ( enum_func_hide ); some tools may flag enum_func_hide as
       *                              unused */
      use_int32 ( local_hide_extern );
      use_int32 ( mc2_0502_v4 );
      use_int32 ( mc2_0502_v5 );
      use_int32 ( mc2_0502_v6 );
   }

   /* Usage */

   use_int32 ( mc2_0502_v1 );
   use_int32 ( mc2_0502_v2 );
   use_int32 ( mc2_0502_v3 );
   enum_var_hide  = hidden_enumerated;
   enum_hide      = hidden_enumerated;
   enum_type_hide = hidden_enumerated;
   /* use_enum ( enum_var_hide ); some tools may flag enum_var_hide as unused */
   /* use_enum ( enum_hide );     some tools may flag enum_hide as unused */
   /* use_enum ( enum_type_hide );some tools may flag enum_type_hide as unused */
   use_int32 ( var_hide );
   /* use_enum ( var_enum_hide ); some tools may flag var_enum_hide as unused */
   outer.no_hiding = get_int32 ( );
   outer.inner.no_hiding = get_int32 ( );
   use_int32 ( outer.no_hiding );
   use_int32 ( outer.inner.no_hiding );
   use_int32 ( var_type_hide );

   /* Calling functions with internal linkage */

   mc2_0502a ( );
   mc2_0502b ( );
   mc2_0502c ( );

   /* Calling functions with external linkage */

   mc2_0502_2 ( );
}

/* end of mc2_0502_1.c */
