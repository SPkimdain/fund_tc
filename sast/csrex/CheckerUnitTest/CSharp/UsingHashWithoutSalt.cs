/* WITH_CHECKERS : USING_HASH_WITHOUT_SALT_CSHARP */

using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Security;
using System.Security.Cryptography;

namespace CSharp
{	
	public class TestCase
    {
		static void HashWithoutSalt()
		{
			var bytes = new byte[100];
			(new Random()).NextBytes(bytes);
			var source = bytes;            
			var sha256 = new SHA256CryptoServiceProvider();
			sha256.ComputeHash(source);							/* BUG: USING_HASH_WITHOUT_SALT_CSHARP */
		}

		static void HashSalt(byte[] salt)
		{     
			var bytes = new byte[100];
			(new Random()).NextBytes(bytes);
			var source = bytes;            
			var sha256 = new SHA256CryptoServiceProvider();
			var combined = salt.Concat(source).ToArray();
			sha256.ComputeHash(combined);						/* SAFE */
		}
	}
}