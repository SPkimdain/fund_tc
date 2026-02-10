namespace
 {
 	class A
 	{
 		void f() = 0;   // @violation
 	};

 	class B
    {
        virtual void g() = 0;   //Not-violation
    };
 }