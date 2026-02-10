using System.Net;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;

namespace CSharp
{
	class TestCase
	{
		public void violation1()
		{
			ServicePointManager.ServerCertificateValidationCallback +=
				(sender, certificate, chain, sslPolicyErrors) => {
					return true;																			// @violation
				};

		}

		public void violation2()
		{
			ServicePointManager.ServerCertificateValidationCallback += ViolationSelfSignedForLocalhost;
		}

		private static bool ViolationSelfSignedForLocalhost(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors)
		{
			return true;																					// @violation
		}

		public void good1()
		{
			ServicePointManager.ServerCertificateValidationCallback +=
				(sender, certificate, chain, sslPolicyErrors) =>
				{
					if (sslPolicyErrors == SslPolicyErrors.None)
					{
						return true;
					}

					// For HTTPS requests to this specific host, we expect this specific certificate.
					// In practice, you'd want this to be configurable and allow for multiple certificates per host, to enable
					// seamless certificate rotations.
					var httpWebRequest = sender as HttpWebRequest;
					var x509Certificate2 = certificate as X509Certificate2;

                    if(httpWebRequest != null && x509Certificate2 != null) {
                        return httpWebRequest.RequestUri.Host == "localhost"                                // good
                                && x509Certificate2.Thumbprint == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                    		    && sslPolicyErrors == SslPolicyErrors.RemoteCertificateChainErrors;
                    }
					return false;
				};
		}

		public void good2()
		{
			ServicePointManager.ServerCertificateValidationCallback += GoodSelfSignedForLocalhost;
		}

		private static bool GoodSelfSignedForLocalhost(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors)
		{
			if (sslPolicyErrors == SslPolicyErrors.None)
			{
				return true;
			}

			// For HTTPS requests to this specific host, we expect this specific certificate.
			// In practice, you'd want this to be configurable and allow for multiple certificates per host, to enable
			// seamless certificate rotations.
			var httpWebRequest = sender as HttpWebRequest;
			var x509Certificate2 = certificate as X509Certificate2;

            if(httpWebRequest != null && x509Certificate2 != null) {
                return httpWebRequest.RequestUri.Host == "localhost"											// good
                        && x509Certificate2.Thumbprint == "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                        && sslPolicyErrors == SslPolicyErrors.RemoteCertificateChainErrors;
            }
			return false;
		}
	}
}