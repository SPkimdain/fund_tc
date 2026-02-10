using System;

namespace ConsoleApplication
{
    class PracticeObjectInitializationNotUsedInitializer
    {
        public static void BadCase1()
        {
            var instance4 = new ExampleClass(); // @violation
            instance4.Name = "TabletPC";
            instance4.ID = 40182;
            instance4.Location = "Seoul";
            instance4.Age = 0.7;
            instance4.Score = 3.9;
            instance4.Marry = true;

            instance4.print();
        }

        public static void GoodCase1()
        {
            var instance3 = new ExampleClass
            {
                Name = "Desktop",
                ID = 37414,
                Location = "RedMond",
                Age = 2.3,
                Score = 4.2,
                Marry = false
            };

            instance3.print();
        }

        public static void GoodCase2()
        {
            var instance4 = new ExampleClass(); // good
            instance4.Name = "TabletPC";
            instance4.ID = 40182;

            instance4.print();
        }

        public static void GoodCase3()
        {
            var instance5 = new ExampleClass();
            instance5.Name += "TabletPC";
            instance5.ID += 40182;
            instance5.Location += "Seoul";
            instance5.Age += 0.7;
            instance5.Score += 3.9;
            instance5.Marry += true;

            instance5.print();
        }
        public static void Main(string[] args)
        {
            BadCase1();
            GoodCase1();
        }
    }

    class ExampleClass
    {
        private string name;
        private int id;
        private string location;
        private double age;
        private float fScore;
        private bool isMarried;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        public int ID
        {
            get
            {
                return id;
            }
            set
            {
                id = value;
            }
        }

        public string Location
        {
            get
            {
                return location;
            }
            set
            {
                location = value;
            }
        }

        public double Age
        {
            get
            {
                return age;
            }
            set
            {
                age = value;
            }
        }

        public float Score
        {
            get
            {
                return fScore;
            }
            set
            {
                fScore = value;
            }
        }

        public bool Marry
        {
            get
            {
                return isMarried;
            }
            set
            {
                isMarried = value;
            }
        }

        public void print()
        {
            Console.WriteLine("Name : " + name);
            Console.WriteLine("ID : " + id);
            Console.WriteLine("Location : " + location);
            Console.WriteLine("Age : " + age);
            Console.WriteLine("Score : " + fScore);
            if(isMarried)
            {
                Console.WriteLine(name + " is married");
            }
            else
            {
                Console.WriteLine(name + " is not married");
            }
        }
    }
}