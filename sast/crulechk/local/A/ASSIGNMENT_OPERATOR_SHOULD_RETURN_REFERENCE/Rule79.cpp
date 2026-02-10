//@checker ASSIGNMENT_OPERATOR_SHOULD_RETURN_REFERENCE

class Noncomplaint {
  Noncomplaint operator=(const Noncomplaint&);  //@violation ASSIGNMENT_OPERATOR_SHOULD_RETURN_REFERENCE
};



class Complaint {
  Complaint& operator=(const Complaint&);
};


class N {
	N operator=(const N& rhs); 
};


N N::operator=(const N& rhs)	//@violation ASSIGNMENT_OPERATOR_SHOULD_RETURN_REFERENCE
{
  return *this;
}

