using System;

namespace Samples
{
    // Violates this rule
    [FlagsAttribute]
    public enum Color
    {
        None    = 0,
        Red     = 1,
        Orange  = 3, // @violation
        Yellow  = 4
    }

    [FlagsAttribute]
    enum ColorInternal
    {
        None    = 0,
        Red     = 1,
        Orange  = 3,
        Yellow  = 4
    }

    [FlagsAttribute]
    public enum Days
    {
        None        = 0,
        Monday      = 1,
        Tuesday     = 2,
        Wednesday   = 4,
        Thursday    = 8,
        Friday      = 16,
        All         = Monday| Tuesday | Wednesday | Thursday | Friday
    }
}
