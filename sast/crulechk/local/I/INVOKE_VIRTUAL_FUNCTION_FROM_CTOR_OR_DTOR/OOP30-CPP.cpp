// @checker INVOKE_VIRTUAL_FUNCTION_FROM_CTOR_OR_DTOR

class IVFFCOD_non {
 public:
 int a;
 IVFFCOD_non() { seize(); }  //@violation INVOKE_VIRTUAL_FUNCTION_FROM_CTOR_OR_DTOR
  virtual ~IVFFCOD_non() { IVFFCOD_non::release(); } 
 protected:
  virtual void seize() {}
  void release() {}
  
};

class IVFFCOD_non_1 : public IVFFCOD_non {
 public:
 int b;
  IVFFCOD_non_1() { seize(); } //@violation INVOKE_VIRTUAL_FUNCTION_FROM_CTOR_OR_DTOR
  ~IVFFCOD_non_1() {}
 protected:
   void seize() {
     
     // get derived resources...
   }
   void release() {
     // release derived resources...
     
   }
};

class IVFFCOD_non_2 final : public IVFFCOD_non {
 public:
 int b;
  IVFFCOD_non_2() { seize(); } //Okay
  ~IVFFCOD_non_2() {}
 protected:
   virtual void seize() {
     
     // get derived resources...
   }
   void release() {
     // release derived resources...
     
   }
};

// class NoncompliantDD : public NoncompliantD {
 // public:
  // NoncompliantDD() {}
  // ~NoncompliantDD() {}
 // protected:
   // void seize() {
     // NoncompliantD::seize();
    // // // get derived resources...
   // }
   // void release() {
     // // release derived resources...
     // NoncompliantD::release();
   // }
// };


void IVFFCOD_noncompliant () {
//  NoncompliantD x;
}



class IVFFCOD {
 public:
  IVFFCOD() {
    // seize base resources...
	IVFFCOD_non * bb = new IVFFCOD_non();
	//bb->IVFFCOD_non::seize();
	//bb->IVFFCOD_non::seize();
  }
  virtual ~IVFFCOD() {
    // release base resources...
  }
};

class IVFFCOD_1 : public IVFFCOD {
 public:
  IVFFCOD_1() {
    // seize derived resources...
  }
  ~IVFFCOD_1() {
    // release derived resources...
  }
};

void IVFFCOD_compliant() {
  IVFFCOD_1 x;
}
