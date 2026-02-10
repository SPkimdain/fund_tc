//@checker INSTANTIATE_TEMPLATES

template <typename T>
void test(T a)
{
  T b = a;

}

template <typename T>
class Sample{
    public :
    T a;
    void inst_mem (T b)
    {
      a = b;

    }
    void uninst_mem () //@violation INSTANTIATE_TEMPLATES
    {

    }
};

int IT_func1()
{
  Sample<int> s;

  s.inst_mem (1);
  return 0;
}
