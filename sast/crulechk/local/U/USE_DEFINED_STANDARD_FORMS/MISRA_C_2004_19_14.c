// @checker USE_DEFINED_STANDARD_FORMS

/** Regex 
 * (#if|#elseif)\s*defined\s*([(][\w ]*[)]|\w*)\s*
*/


#if defined TEXT
#endif
#if defined 	TEXT2          
#endif
#if	 defined TEXT3			 
#endif
#if defined (TEXT6)				
#endif
#if 			 defined(TEXT7)		
#elseif 		defined(TEXT8 )
#elseif defined(TEXT9) h > 0 // @violation USE_DEFINED_STANDARD_FORMS 
#endif

int UDSTDF_001_function()
{
  int ret = 1;

  return ret++;
}

