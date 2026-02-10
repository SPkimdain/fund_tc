//@checker CLASS_MEMBER_SHOULD_NOT_BE_PUBLIC

class CRange {    
 public:        // ¡¦        
  void SetLimits(int lowerLimit, int upperLimit);

 private:        
  int m_lowerLimit;    // m_lowerLimit <= m_upperLimit        
  int m_upperLimit; 
};

void CRange::SetLimits(    int lowerLimit, int upperLimit ) {    
  // assert(lowerLimit <= upperLimit);

  if (lowerLimit <= upperLimit)    {        
    m_lowerLimit = lowerLimit;        
    m_upperLimit = upperLimit;    
  } else    {       
    m_lowerLimit = upperLimit;       
    m_upperLimit = lowerLimit;   
  } 
}


class noncompliant {
 public:
  int a;  //@violation CLASS_MEMBER_SHOULD_NOT_BE_PUBLIC
  int b;  //@violation CLASS_MEMBER_SHOULD_NOT_BE_PUBLIC
};
