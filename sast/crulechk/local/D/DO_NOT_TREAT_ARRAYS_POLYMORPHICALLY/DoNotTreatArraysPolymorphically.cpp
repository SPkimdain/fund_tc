//@checker DO_NOT_TREAT_ARRAYS_POLYMORPHICALLY
struct DNTAP_Base {
  virtual ~DNTAP_Base() = default;
};
 
struct DNTAP_Derived final : DNTAP_Base {};

struct DNTAP_Base2 {
	virtual ~DNTAP_Base2() = default;
};

struct DNTAP_Derived2 : DNTAP_Base2 {
	
};
 
int doNotTreatArrayPolyMorphicallyTest() {
   
   DNTAP_Base *b = new DNTAP_Derived[10];	//@violation DO_NOT_TREAT_ARRAYS_POLYMORPHICALLY
   DNTAP_Base2 *b2 = new DNTAP_Base2[10];
   DNTAP_Base2 *a = new DNTAP_Derived2[10];	//@violation DO_NOT_TREAT_ARRAYS_POLYMORPHICALLY
   DNTAP_Base2 *a2 = new DNTAP_Derived2;
   
   delete [] b;
   delete [] b2;

   return 0;
}
