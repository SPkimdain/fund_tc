//@checker CONSTEXPR_IN_SWITCH
constexpr unsigned int HashCode(const char* str)
{
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

void foo(const char* lastname) 
{
    switch (HashCode(lastname)) //@violation CONSTEXPR_IN_SWITCH
    {
    case HashCode("Kim"):
        // Do something...
        break;

    case HashCode("Lee"):
        // Do something...
        break;

    case HashCode("Park"):
        // Do something...
        break;
    }
} 

