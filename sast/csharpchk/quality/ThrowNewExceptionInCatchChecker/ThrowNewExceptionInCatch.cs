using System;
using System.Threading;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace Quality
{
    class Program
    {
        public void MakeMistake() {
            try {
                int i = 0;
                int j = 10;
                j / i;
            } catch {
                throw;
            }
        }
        public void DoWork1()
        {
            try {
                MakeMistake();
            } catch (Exception e) {
                throw; //@sound
            }
        }
        public void DoWork2()
        {
            try {
                MakeMistake();
            } catch {
                throw; //@sound
            }
        }
        public void DoWork3()
        {
            try {
                MakeMistake();
            } catch (Exception e) {
                throw new Exception("this new exception will override stack trace!"); // @violation
            }
        }
        public void DoWork4()
        {
            try {
                MakeMistake();
            } catch (Exception e) {
                throw new Exception("this exception will preserve the first stack trace", e); //@sound
            }
        }
        public void DoWork5()
        {
            try {
                MakeMistake();
            } catch (ArithmeticException e) {
                throw new ArithmeticException("this exception will preserve the first stack trace", e); //@sound
            }
        }
        public void DoWork6()
        {
            try {
                MakeMistake();
            } catch (ArithmeticException e) {
                throw new ArithmeticException("this exception will preserve the first stack trace"); // @violation
            }
        }

        static void Main(string[] args)
        {
            try
            {
                DoWork1();
                DoWork2();
                DoWork3();
                DoWork4();
                DoWork5();
                DoWork6();
            }
            catch
            {
                throw new Exception();// @violation
            }
        }
    }

}
