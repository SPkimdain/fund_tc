// @checker ONLY_THROW_OBJECT_OF_CLASS_TYPE

class C {
    int a;
};

void foo()
{
    C c;

    throw 1;   // @violation ONLY_THROW_OBJECT_OF_CLASS_TYPE
    throw c;
}
