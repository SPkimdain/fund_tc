/* WITH_CHECKERS : INCORRECT_PERMISSION_ASSIGNMENT_FOR_CRITICAL_RESOURCE_CSHARP */

using System.Text;
using System.Diagnostics;
using System.IO;
using System.Security.AccessControl;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace ConsoleApplication13
{
    class Program
    {
        static void Main(string[] args)
        {

        }

        private bool GrantAccess(string fullPath)
        {
            DirectoryInfo dInfo = new DirectoryInfo(fullPath);
            DirectorySecurity dSecurity = dInfo.GetAccessControl();
            dSecurity.AddAccessRule(new FileSystemAccessRule("everyone", FileSystemRights.FullControl,
                                                             InheritanceFlags.ObjectInherit | InheritanceFlags.ContainerInherit,
                                                             PropagationFlags.NoPropagateInherit, AccessControlType.Allow));
            dInfo.SetAccessControl(dSecurity); /* BUG: INCORRECT_PERMISSION_ASSIGNMENT_FOR_CRITICAL_RESOURCE_CSHARP */
            return true;
        }
    }
}
