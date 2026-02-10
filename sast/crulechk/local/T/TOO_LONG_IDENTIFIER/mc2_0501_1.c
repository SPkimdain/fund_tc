//@checker TOO_LONG_IDENTIFIER
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
 * 5.1 Identifiers (internal and external) shall not rely on the significance of
 *     more than 31 characters.
 */

/* Identifier Naming:
 *
 * All identifiers that are distinct in the first 31 characters are distinct in
 * the first 7 for readability, ie name_nn.
 * The next letters indicate the clash with the following key:
 *
 * f - function
 * v - variable
 * e - enumeration constant
 * l - label
 * m - macro
 * t - tag
 * y - typedef
 * c - component
 *
 * x is prefixed to indicate external linkage.
 *
 * 31 indicates the 31st character, so in ...31a a is the 32nd character.
 */

/* variables and functions with external linkage */

#include "TLID_mc2_types.h"
#include "TLID_mc2_header.h"
#include "mc2_0501_1.h"
#include "mc2_0501_2.h"

static void mc2_0501_s1 ( void );
static void name_67_xff_xxxxxxxxxxxxxxxxx31b ( void ); /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
static void name_71_xvf_xxxxxxxxxxxxxxxxx31b ( void ); /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
static void mc2_0501_x1 ( void );

void name_65_xfxf_xxxxxxxxxxxxxxxx31a ( void )         /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

void name_65_xfxf_xxxxxxxxxxxxxxxx31b ( void )         /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

void name_66_xfxv_xxxxxxxxxxxxxxxx31a ( void )         /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

void name_67_xff_xxxxxxxxxxxxxxxxx31a ( void )         /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

static void name_67_xff_xxxxxxxxxxxxxxxxx31b ( void )  /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

void name_69_xfv_xxxxxxxxxxxxxxxxx31a ( void )         /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

static void name_71_xvf_xxxxxxxxxxxxxxxxx31b ( void )  /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
{
   use_int32 ( 0 ); /* Do Something */
}

int32_t name_66_xfxv_xxxxxxxxxxxxxxxx31b = 0;          /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

int32_t name_68_xvxv_xxxxxxxxxxxxxxxx31a = 0;          /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

int32_t name_68_xvxv_xxxxxxxxxxxxxxxx31b = 0;          /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

int32_t name_70_xvv_xxxxxxxxxxxxxxxxx31a = 0;          /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

static int32_t name_70_xvv_xxxxxxxxxxxxxxxxx31b = 0;   /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

int32_t name_71_xvf_xxxxxxxxxxxxxxxxx31a = 0;          /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

static int32_t name_69_xfv_xxxxxxxxxxxxxxxxx31b = 0;   /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

static void mc2_0501_x1 ( void )
{
   /* sets variables and calls functions */
   name_66_xfxv_xxxxxxxxxxxxxxxx31b = get_int32 ( );
   name_68_xvxv_xxxxxxxxxxxxxxxx31a = get_int32 ( );
   name_68_xvxv_xxxxxxxxxxxxxxxx31b = get_int32 ( );
   name_70_xvv_xxxxxxxxxxxxxxxxx31a = get_int32 ( );
   name_70_xvv_xxxxxxxxxxxxxxxxx31b = get_int32 ( );
   name_71_xvf_xxxxxxxxxxxxxxxxx31a = get_int32 ( );
   name_69_xfv_xxxxxxxxxxxxxxxxx31b = get_int32 ( );

   name_65_xfxf_xxxxxxxxxxxxxxxx31a ( );
   name_65_xfxf_xxxxxxxxxxxxxxxx31b ( );
   name_66_xfxv_xxxxxxxxxxxxxxxx31a ( );
   name_67_xff_xxxxxxxxxxxxxxxxx31a ( );
   name_67_xff_xxxxxxxxxxxxxxxxx31b ( );
   name_69_xfv_xxxxxxxxxxxxxxxxx31a ( );
   name_71_xvf_xxxxxxxxxxxxxxxxx31b ( );
}

static void mc2_0501_s1 ( void )
{
   /* uses static variables and calls static functions */
   use_int32 ( name_70_xvv_xxxxxxxxxxxxxxxxx31b );
   use_int32 ( name_69_xfv_xxxxxxxxxxxxxxxxx31b );

   name_67_xff_xxxxxxxxxxxxxxxxx31b ( );
   name_71_xvf_xxxxxxxxxxxxxxxxx31b ( );
}

void mc2_0501 ( void )
{
   mc2_0501_x2  ( );
   mc2_0501_ct  ( );
   mc2_0501_y   ( );
   mc2_0501_fm  ( );
   mc2_0501_vel ( );

   mc2_0501_x1  ( );
   mc2_0501_s1  ( );
}

/* end of mc2_0501_1.c */
