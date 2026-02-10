//@checker FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
#define NULL 0

class CallTarget
{
 char* m_sTargetName;
 char* m_sTargetPositionString;
 bool m_bIsConsiderParams;
 bool m_bIsTargetAllParams;
 void parseTargetPositionString();
 CallTarget(char* targetName, char* targetPositionString);

};

CallTarget::CallTarget(char* targetName, char* targetPositionString) {


  try{
    int a = 1;
    throw 20;
  }
  catch (int e)
  {
    m_sTargetName = targetName; //@violation FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
    m_sTargetPositionString = targetPositionString; //@violation FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
    m_bIsConsiderParams = true; //@violation FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
  }

  m_sTargetPositionString = targetPositionString;
  m_bIsTargetAllParams = false;
  if(targetPositionString != NULL) {
    parseTargetPositionString();
  } else {
    m_bIsConsiderParams = false;
  }
}
