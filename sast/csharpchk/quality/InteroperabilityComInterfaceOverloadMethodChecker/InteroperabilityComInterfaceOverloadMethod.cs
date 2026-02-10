using System;
using System.Runtime.InteropServices;

[assembly: ComVisible(false)]
namespace InteroperabilityLibrary
{
    // This interface violates the rule.
    [ComVisible(true)]
    public interface IOverloadedInterface
    {
        void SomeMethod(int valueOne); // @violation
        void SomeMethod(int valueOne, int valueTwo); // @violation
    }

    // This interface satisfies the rule.
    [ComVisible(true)]
    public interface INotOverloadedInterface
    {
        void SomeMethod(int valueOne);
        void AnotherMethod(int valueOne, int valueTwo);
    }
}