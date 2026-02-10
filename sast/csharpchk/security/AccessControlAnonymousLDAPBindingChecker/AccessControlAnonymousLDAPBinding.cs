using System.DirectoryServices;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            DirectoryEntry oDE;
            string username = "user";
            string passwd = "passwd";
            oDE = new DirectoryEntry("LDAP://127.0.0.1"); // @violation
            oDE = new DirectoryEntry("LDAP://127.0.0.1", username, passwd);
        }
    }
}