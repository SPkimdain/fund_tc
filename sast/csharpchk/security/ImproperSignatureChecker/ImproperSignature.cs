using JWT;
using JWT.Algorithms;
using JWT.Builder;
using JWT.Serializers;
using System;

namespace CSharp
{
	class TestCase
	{
		const string token = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJjbGFpbTEiOjAsImNsYWltMiI6ImNsYWltMi12YWx1ZSJ9.8pwBI_HtXqI3UgQHQ_rDRnSQRxFL1SR8fbQoS-5kM5s";
		const string secret = "GQDstcKsx0NHjPOuXOYg5MbeJ1XT0uFiwDVvVBrk";

		public void violation1()
		{
			IJsonSerializer serializer = new JsonNetSerializer();
			var provider = new UtcDateTimeProvider();
			IJwtValidator validator = new JwtValidator(serializer, provider);
			IBase64UrlEncoder urlEncoder = new JwtBase64UrlEncoder();
			IJwtAlgorithm algorithm = new HMACSHA256Algorithm();
			IJwtDecoder decoder = new JwtDecoder(serializer, validator, urlEncoder, algorithm);

			var decodedToken1 = decoder.Decode(token, secret, verify: false);	// @violation
			Console.WriteLine(decodedToken1);

			var decodedToken2 = decoder.Decode(token, secret, false);			// @violation
			Console.WriteLine(decodedToken2);
		}

		public void violation2()
		{
			var decodedToken1 = new JwtBuilder()								// @violation
				.WithSecret(secret)
				.Decode(token);
			Console.WriteLine(decodedToken1);

			var decodedToken2 = new JwtBuilder();								// @violation
			decodedToken2.WithSecret(secret).Decode(token);
			Console.WriteLine(decodedToken2);

			var decodedToken3 = new JwtBuilder();								// @violation
			decodedToken3.WithSecret(secret);
			decodedToken3.Decode(token);
			Console.WriteLine(decodedToken3);
		}

		public void good1()
		{
			IJsonSerializer serializer = new JsonNetSerializer();
			var provider = new UtcDateTimeProvider();
			IJwtValidator validator = new JwtValidator(serializer, provider);
			IBase64UrlEncoder urlEncoder = new JwtBase64UrlEncoder();
			IJwtAlgorithm algorithm = new HMACSHA256Algorithm();
			IJwtDecoder decoder = new JwtDecoder(serializer, validator, urlEncoder, algorithm);

			var decodedToken1 = decoder.Decode(token, secret, verify: true);	// good
			Console.WriteLine(decodedToken1);

			var decodedToken2 = decoder.Decode(token, secret, true);			// good
			Console.WriteLine(decodedToken2);
		}

		public void good2()
		{
			var decodedToken1 = new JwtBuilder()								// good
				.WithSecret(secret)
				.MustVerifySignature()
				.Decode(token);
			Console.WriteLine(decodedToken1);

			var decodedToken2 = new JwtBuilder();								// good
			decodedToken2.WithSecret(secret).MustVerifySignature().Decode(token);
			Console.WriteLine(decodedToken2);

			var decodedToken3 = new JwtBuilder();								// good
			decodedToken3.WithSecret(secret);
			decodedToken3.MustVerifySignature();
			decodedToken3.Decode(token);
			Console.WriteLine(decodedToken3);
		}
	}
}