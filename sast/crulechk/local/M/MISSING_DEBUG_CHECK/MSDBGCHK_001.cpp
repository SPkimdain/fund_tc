//@checker MISSING_DEBUG_CHECK
extern void debug();

void MSDBGCHK_001_function() {
  debug(); //@violation MISSING_DEBUG_CHECK
}
