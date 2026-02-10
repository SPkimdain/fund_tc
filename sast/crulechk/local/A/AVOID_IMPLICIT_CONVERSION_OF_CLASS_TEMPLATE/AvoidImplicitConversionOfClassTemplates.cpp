// @checker AVOID_IMPLICIT_CONVERSION_OF_CLASS_TEMPLATE

// Example with smart pointers:
template< typename T >
class SmartPointer
{
  public:
    SmartPointer( T* );
    operator void const*();
};


class AA {
    int a;
};

class BB {
    int b;
};

// Here the designer added conversion to void
// const* to help comparison to the null pointer.
// However a bad side effect to this feature
// is that it is possible to generate equality
// comparison between two smart pointers on
// different types:
void doIt( AA* pa, BB* pb )
{
    SmartPointer<AA> spa( pa );
    SmartPointer<BB> spb( pb );
    // problem! comparing different pointer types
    if (spa == spb)   // @violation AVOID_IMPLICIT_CONVERSION_OF_CLASS_TEMPLATE
    {}

    bool b;
    b = spa == spb; // @violation AVOID_IMPLICIT_CONVERSION_OF_CLASS_TEMPLATE

    // int a = 1;
    // float b = a;
}
