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

#ifdef MC2_HEADER_H

#error File mc2_header.h included 2nd time

#else
#define MC2_HEADER_H

/* Functions returning a variable */

extern bool_t get_bool ( void );
extern char_t get_char ( void );
extern int8_t get_int8 ( void );
extern int16_t get_int16 ( void );
extern int32_t get_int32 ( void );
extern int64_t get_int64 ( void );
extern uint8_t get_uint8 ( void );
extern uint16_t get_uint16 ( void );
extern uint32_t get_uint32 ( void );
extern uint64_t get_uint64 ( void );
extern float32_t get_float32 ( void );
extern float64_t get_float64 ( void );
extern float128_t get_float128 ( void );

extern bool_t *get_bool_ptr ( void );
extern char_t *get_char_ptr ( void );
extern int8_t *get_int8_ptr ( void );
extern int16_t *get_int16_ptr ( void );
extern int32_t *get_int32_ptr ( void );
extern int64_t *get_int64_ptr ( void );
extern uint8_t *get_uint8_ptr ( void );
extern uint16_t *get_uint16_ptr ( void );
extern uint32_t *get_uint32_ptr ( void );
extern uint64_t *get_uint64_ptr ( void );
extern float32_t *get_float32_ptr ( void );
extern float64_t *get_float64_ptr ( void );
extern float128_t *get_float128_ptr ( void );

/* Functions that use a variable */

extern void use_bool ( bool_t use_bool_param );
extern void use_char ( char_t use_char_param );
extern void use_int8 ( int8_t use_int8_param );
extern void use_int16 ( int16_t use_int16_param );
extern void use_int32 ( int32_t use_int32_param );
extern void use_int64 ( int64_t use_int64_param );
extern void use_uint8 ( uint8_t use_uint8_param );
extern void use_uint16 ( uint16_t use_uint16_param );
extern void use_uint32 ( uint32_t use_uint32_param );
extern void use_uint64 ( uint64_t use_uint64_param );
extern void use_float32 ( float32_t use_float32_param );
extern void use_float64 ( float64_t use_float64_param );
extern void use_float128 ( float128_t use_float128_param );

extern void use_bool_ptr ( bool_t *use_bool_ptr_param );
extern void use_char_ptr ( char_t *use_char_ptr_param );
extern void use_int8_ptr ( int8_t *use_int8_ptr_param );
extern void use_int16_ptr ( int16_t *use_int16_ptr_param );
extern void use_int32_ptr ( int32_t *use_int32_ptr_param );
extern void use_int64_ptr ( int64_t *use_int64_ptr_param );
extern void use_uint8_ptr ( uint8_t *use_uint8_ptr_param );
extern void use_uint16_ptr ( uint16_t *use_uint16_ptr_param );
extern void use_uint32_ptr ( uint32_t *use_uint32_ptr_param );
extern void use_uint64_ptr ( uint64_t *use_uint64_ptr_param );
extern void use_float32_ptr ( float32_t *use_float32_ptr_param );
extern void use_float64_ptr ( float64_t *use_float64_ptr_param );
extern void use_float128_ptr ( float128_t *use_float128_ptr_param );


/* Examples */

/* Section 1 */

extern void mc2_0104 ( void );
extern void mc2_0105 ( void );

/* Section 2 */

extern void mc2_0201 ( void );
extern void mc2_0202 ( void );
extern void mc2_0203 ( void );
extern void mc2_0204 ( void );

/* Section 4 */

extern void mc2_0401 ( void );
extern void mc2_0402 ( void );

/* Section 5 */

extern void mc2_0501 ( void );
extern void mc2_0502 ( void );
extern void mc2_0503 ( void );
extern void mc2_0504 ( void );
extern void mc2_0505 ( void );
extern void mc2_0506 ( void );
extern void mc2_0507 ( void );

/* Section 6 */

extern void mc2_0601 ( void );
extern void mc2_0602 ( void );
extern void mc2_0603 ( void );
extern void mc2_0604 ( void );
extern void mc2_0605 ( void );

/* Section 7 */

extern void mc2_0701 ( void );

/* Section 8 */

extern void mc2_0801 ( void );
extern void mc2_0802 ( void );
extern void mc2_0803 ( void );
extern void mc2_0804 ( void );
extern void mc2_0805 ( void );
extern void mc2_0806 ( void );
extern void mc2_0807 ( void );
extern void mc2_0808 ( void );
extern void mc2_0809 ( void );
extern void mc2_0810 ( void );
extern void mc2_0811 ( void );
extern void mc2_0812 ( void );

/* Section 9 */

extern void mc2_0901 ( void );
extern void mc2_0902 ( void );
extern void mc2_0903 ( void );

/* Section 10 */

extern void mc2_1001 ( void );
extern void mc2_1002 ( void );
extern void mc2_1003 ( void );
extern void mc2_1004 ( void );
extern void mc2_1005 ( void );
extern void mc2_1006 ( void );

/* Section 11 */

extern void mc2_1101 ( void );
extern void mc2_1102 ( void );
extern void mc2_1103 ( void );
extern void mc2_1104 ( void );
extern void mc2_1105 ( void );

/* Section 12 */

extern void mc2_1201 ( void );
extern void mc2_1202 ( void );
extern void mc2_1203 ( void );
extern void mc2_1204 ( void );
extern void mc2_1205 ( void );
extern void mc2_1206 ( void );
extern void mc2_1207 ( void );
extern void mc2_1208 ( void );
extern void mc2_1209 ( void );
extern void mc2_1210 ( void );
extern void mc2_1211 ( void );
extern void mc2_1212 ( void );
extern void mc2_1213 ( void );

/* Section 13 */

extern void mc2_1301 ( void );
extern void mc2_1302 ( void );
extern void mc2_1303 ( void );
extern void mc2_1304 ( void );
extern void mc2_1305 ( void );
extern void mc2_1306 ( void );
extern void mc2_1307 ( void );

/* Section 14 */

extern void mc2_1401 ( void );
extern void mc2_1402 ( void );
extern void mc2_1403 ( void );
extern void mc2_1404 ( void );
extern void mc2_1405 ( void );
extern void mc2_1406 ( void );
extern void mc2_1407 ( void );
extern void mc2_1408 ( void );
extern void mc2_1409 ( void );
extern void mc2_1410 ( void );

/* Section 15 */

extern void mc2_1500 ( void );
extern void mc2_1501 ( void );
extern void mc2_1502 ( void );
extern void mc2_1503 ( void );
extern void mc2_1504 ( void );
extern void mc2_1505 ( void );

/* Section 16 */

extern void mc2_1601 ( void );
extern void mc2_1602 ( void );
extern void mc2_1603 ( void );
extern void mc2_1604 ( void );
extern void mc2_1605 ( void );
extern void mc2_1606 ( void );
extern void mc2_1607 ( void );
extern void mc2_1608 ( void );
extern void mc2_1609 ( void );
extern void mc2_1610 ( void );

/* Section 17 */

extern void mc2_1701 ( void );
extern void mc2_1702 ( void );
extern void mc2_1703 ( void );
extern void mc2_1704 ( void );
extern void mc2_1705 ( void );
extern void mc2_1706 ( void );

/* Section 18 */

extern void mc2_1801 ( void );
extern void mc2_1802 ( void );
extern void mc2_1803 ( void );
extern void mc2_1804 ( void );

/* Section 19 */

extern void mc2_1901 ( void );
extern void mc2_1902 ( void );
extern void mc2_1903 ( void );
extern void mc2_1904 ( void );
extern void mc2_1905 ( void );
extern void mc2_1906 ( void );
extern void mc2_1907 ( void );
extern void mc2_1908 ( void );
extern void mc2_1909 ( void );
extern void mc2_1910 ( void );
extern void mc2_1911 ( void );
extern void mc2_1912 ( void );
extern void mc2_1913 ( void );
extern void mc2_1914 ( void );
extern void mc2_1915 ( void );
extern void mc2_1916 ( void );
extern void mc2_1917 ( void );

/* Section 20 */

extern void mc2_2001 ( void );
extern void mc2_2002 ( void );
extern void mc2_2003 ( void );
extern void mc2_2004 ( void );
extern void mc2_2005 ( void );
extern void mc2_2006 ( void );
extern void mc2_2007 ( void );
extern void mc2_2008 ( void );
extern void mc2_2009 ( void );
extern void mc2_2010 ( void );
extern void mc2_2011 ( void );
extern void mc2_2012 ( void );


#endif

/* end of mc2_header.h */
