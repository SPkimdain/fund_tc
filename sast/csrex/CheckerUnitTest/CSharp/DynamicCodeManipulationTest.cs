/* WITH_CHECKERS : DYNAMIC_CODE_MANIPULATION_CSHARP */

using Microsoft.AspNetCore.Mvc;
using System.CodeDom.Compiler;
using System.Linq;

namespace WebApplicationDotNetCore.Controllers
{
	public class ViolationController : Controller
	{
		public static void Main(string[] args)
		{
			var code = args[0];

			var provider = CodeDomProvider.CreateProvider("CSharp");
			var compilerParameters = new CompilerParameters { ReferencedAssemblies = { "System.dll", "System.Runtime.dll" } };
			var compilerResults = provider.CompileAssemblyFromSource(compilerParameters, code);		/* BUG: DYNAMIC_CODE_MANIPULATION_CSHARP */
			object myInstance = compilerResults.CompiledAssembly.CreateInstance("MyClass");
			var result = (string)myInstance.GetType().GetMethod("MyMethod").Invoke(myInstance, new object[0]);
			return Content(result);
		}
	}

	public class GoodController : Controller
	{
		private string[] allowedInnerInvocations = { "method1", "method2" };

		public static void Main(string[] args)
		{
			var code = args[0];

			// Match the input against a whitelist
			if(allowedInnerInvocations.Contains(code)) {
				var provider = CodeDomProvider.CreateProvider("CSharp");
				var compilerParameters = new CompilerParameters { ReferencedAssemblies = { "System.dll", "System.Runtime.dll" } };
				var compilerResults = provider.CompileAssemblyFromSource(compilerParameters, code);		/* GOOD */
				object myInstance = compilerResults.CompiledAssembly.CreateInstance("MyClass");
				var result = (string)myInstance.GetType().GetMethod("MyMethod").Invoke(myInstance, new object[0]);
			}
		}
	}
}