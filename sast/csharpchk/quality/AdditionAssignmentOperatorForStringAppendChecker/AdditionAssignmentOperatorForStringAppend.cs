using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class Program
    {
        string TestMethod1(String a)
        {
            String ret = a;
            ret += ret;                 // @safe
            return ret;
        }

        string AppendString(string[] a)
        {
            string ret = "";
            foreach(string s in a)
            {
                ret += s;               // @violation
            }
            return ret;
        }

        string AppendInNestedLoop(string[] a, string[] b)
        {
            string ret = "";
            ret += "append strings";    // @safe
            foreach(string s1 in a) {
                foreach(string s2 in b) {
                    ret+= s2;           // @violation
                }
                ret+= s1;               // @violation
            }
            ret += "\n";                // @safe
            return ret;
        }

        string AppendInNestedLoopSafe(string[] a, string[] b)
        {
            StringBuilder sb = new StringBuilder();
            foreach(string s1 in a) {
                foreach(string s2 in b) {
                    sb.Append(s2);      // @safe
                }
                sb.Append(s1);          // @safe
            }
            return sb.ToString();
        }

        string AppendString(string[] a)
        {
            StringBuilder sb = new StringBuilder();
            foreach(string s in a)
            {
                sb.Append(s);           // @safe
            }
            return sb.ToString();
        }
    }
}
