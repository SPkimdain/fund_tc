namespace
 {
 	class A
 	{
 		virtual void f() = 1;   // @violation
 	};

 	class B
    {
        virtual void g() = 0;   //Not-violation
    };
 }