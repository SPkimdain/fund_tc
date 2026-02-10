using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpCheckerTest
{
    class NamingLINQNotUsedPascalCasing
    {
        public static void BadCase1()
        {
            var localDistributors = from customer in customers
                                    join distributor in distributors on customer.City equals distributor.City
                                    select new { Bad_customer = customer, Bad_distributor = distributor };  // @violation

            Console.WriteLine("BadCase1");
        }

        public static void GoodCase1()
        {
            var localDistributors = from customer in customers
                                    join distributor in distributors on customer.City equals distributor.City
                                    select new { GoodCustomer = customer, GoodDistributor = distributor };
            Console.WriteLine("GoodCase1");
        }


        public static void print()
        {
            Console.WriteLine("******************************************************************************");
            Console.WriteLine("* You should Use aliases to make sure that property names of anonymous types *");
            Console.WriteLine("*               are correctly capitalized, using Pascal casing               *");
            Console.WriteLine("******************************************************************************");
        }

        static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();

            print();
        }
    }
}