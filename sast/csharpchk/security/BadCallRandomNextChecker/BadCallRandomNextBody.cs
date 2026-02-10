using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Random;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd1 = new Random();
            int maxValue = 1024;
            rnd1.Next(maxValue);                        // @violation
            new Random().Next();                        // @violation
        }

        string InsecureRandomNumber(string test)
        {
            Random rnd2 = new Random();
            return (test + rnd2.Next().ToString());     // @violation
        }

        static void InsecureParameter(Random rnd4)
        {
            rnd4.Next();                                // @violation
        }

        static void DoNotDetectBelow()
        {
            Random rnd3 = new Random();
            rnd3.GetType();
        }
    }
}

