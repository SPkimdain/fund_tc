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

/* Included in mc2_0501_1.c and mc2_0501_2.c */

/* functions with external linkage */

#ifndef MC2_0501_1_H
#define MC2_0501_1_H

extern void name_65_xfxf_xxxxxxxxxxxxxxxx31a ( void );  /* Not Compliant */	//@violation TOO_LONG_IDENTIFIER
extern void name_65_xfxf_xxxxxxxxxxxxxxxx31b ( void );  /* Not Compliant */ //@violation TOO_LONG_IDENTIFIER

extern void name_66_xfxv_xxxxxxxxxxxxxxxx31a ( void );  /* Not Compliant */ //@violation TOO_LONG_IDENTIFIER

/* Clashes with static identifier in mc2_0501_1.c */
extern void name_67_xff_xxxxxxxxxxxxxxxxx31a ( void );  /* Not Compliant */ //@violation TOO_LONG_IDENTIFIER

/* Clashes with static identifier in mc2_0501_1.c */
extern void name_69_xfv_xxxxxxxxxxxxxxxxx31a ( void );  /* Not Compliant */ //@violation TOO_LONG_IDENTIFIER


/* variables with external linkage */

extern int32_t name_66_xfxv_xxxxxxxxxxxxxxxx31b;        /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

extern int32_t name_68_xvxv_xxxxxxxxxxxxxxxx31a;        /* Not Compliant *///@violation TOO_LONG_IDENTIFIER
extern int32_t name_68_xvxv_xxxxxxxxxxxxxxxx31b;        /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

/* Clashes with static identifier in mc2_0501_1.c */
extern int32_t name_70_xvv_xxxxxxxxxxxxxxxxx31a;        /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

/* Clashes with static identifier in mc2_0501_1.c */
extern int32_t name_71_xvf_xxxxxxxxxxxxxxxxx31a;        /* Not Compliant *///@violation TOO_LONG_IDENTIFIER

#endif

/* end of mc2_0501_1.h */
