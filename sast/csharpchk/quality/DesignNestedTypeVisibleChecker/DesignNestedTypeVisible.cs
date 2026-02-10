using System;

namespace DesignLibrary
{
    public class ParentType
    {
        public class NestedType // @violation
        {
            public NestedType()
            {
            }
        }

        public ParentType()
        {
            NestedType nt = new NestedType();
        }
    }

    protected class ParentTypeSafe
    {
        public class NestedType
        {
            public NestedType()
            {
            }
        }

        public ParentType()
        {
            NestedType nt = new NestedType();
        }
    }
}