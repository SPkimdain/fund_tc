using System;
using System.Threading;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Foo
    {
        int f;
        double d;
        public Foo(int i, double d)
        {
            this.f = i;
            this.d = d;
        }
        public int getInt()
        {
            return this.f;
        }
        public double getDouble()
        {
            return this.d;
        }
    }
    class Program
    {
        public static int TestMethod(int a, int b, int c)
        {
            return a+b+c;
        }
        static void Main(string[] args)
        {
            int a = 1;
            int b = 2;
            int c = 3;
            int d = 4; // @violation
            int i = TestMethod(a,b,c);// @violation
        }
    }
    public class Class1
    {
        public Class1()
        {
        }

        public void Test()
        {
            XmlInterlock doc = new XmlInterlock();
            YesCoreEntities entities = new YesCoreEntities();

            Dictionary<string, TImeSubscription> response;

            foreach (TimeSubscription subscription in response.Values)
                doc.Time.AddTimeRow(performanceKey, subscription.TermTarget,
                    subscription.OrganizationId);

            List<Time> times = entities.GetTime(doc.GetXml()).ToList();

            foreach (Time time in times)
            {
                if (reponse.ContainsKey(time.IntegerlockId))
                {
                    TimeSubscription subscription = response[time.InterlockId];

                    subscription.TermSource = Convert.ToString(time.Id);
                    subscrption.SubscrptionTime = time.OperTime;
                }
            }

            return response.Values.ToList();
        }
    }
}
