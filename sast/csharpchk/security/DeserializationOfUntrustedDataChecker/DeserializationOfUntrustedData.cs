using System;
using System.Collections;
using System.IO;
using System.Net;
using System.Reflection;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Web.Script.Serialization;
using System.Web.UI;

namespace CSharp
{
	public class TestCase
	{
		public void violation1()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				BinaryFormatter formatter = new BinaryFormatter();
				var addresses = (Hashtable) formatter.Deserialize(stream);				// @violation
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public void violation2()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				NetDataContractSerializer serializer = new NetDataContractSerializer();
				var addresses = (Hashtable) serializer.Deserialize(stream);				// @violation
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public void violation3()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				SoapFormatter formatter = new SoapFormatter();
				var addresses = (Hashtable) formatter.Deserialize(stream);				// @violation
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public void violation4()
		{
			try
			{
				WebClient client = new WebClient();
				string json = client.DownloadString("http://example.com/api/json?id=1312837218");

				JavaScriptSerializer serializer = new JavaScriptSerializer(new SimpleTypeResolver());
				var instance = serializer.Deserialize<dynamic>(json);					// @violation
				Console.WriteLine(instance);
			}
			catch (SerializationException e)
			{
				throw;
			}
		}

		public void violation5()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				LosFormatter formatter = new LosFormatter();
				var addresses = (Hashtable) formatter.Deserialize(stream);				// @violation
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		sealed class CustomBinder : SerializationBinder
		{
			public override Type BindToType(string assemblyName, string typeName)
			{
				if (!(typeName == "type1" || typeName == "type2" || typeName == "type3"))
				{
					throw new SerializationException("Only type1, type2 and type3 are allowed");
				}
				return Assembly.Load(assemblyName).GetType(typeName);
			}
		}

		public void good1()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				BinaryFormatter formatter = new BinaryFormatter();
				formatter.Binder = new CustomBinder();									// good
				var addresses = (Hashtable) formatter.Deserialize(stream);
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public void good2()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				NetDataContractSerializer serializer = new NetDataContractSerializer();
				serializer.Binder = new CustomBinder();									// good
				var addresses = (Hashtable) serializer.Deserialize(stream);
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public void good3()
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				SoapFormatter formatter = new SoapFormatter();
				formatter.Binder = new CustomBinder();									// good
				var addresses = (Hashtable) formatter.Deserialize(stream);
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}

		public class CustomSafeTypeResolver : JavaScriptTypeResolver
		{
			public override Type ResolveType(string id)
			{
				if (id != "ExpectedType")
				{
					throw new ArgumentNullException("Only ExpectedType is allowed during deserialization");
				}
				return Type.GetType(id);
			}

			public override string ResolveTypeId(Type type)
			{
				throw new NotImplementedException();
			}
		}

		public void good4()
		{
			try
			{
				WebClient client = new WebClient();
				string json = client.DownloadString("http://example.com/api/json?id=1312837218");

				JavaScriptSerializer serializer = new JavaScriptSerializer(new CustomSafeTypeResolver());
				var instance = serializer.Deserialize<dynamic>(json);					// good
				Console.WriteLine(instance);
			}
			catch (SerializationException e)
			{
				throw;
			}
		}

		public void good5(string macKeyModifier)
		{
			FileStream stream = new FileStream("DataFile.dat", FileMode.Open);
			try
			{
				LosFormatter formatter = new LosFormatter(true, macKeyModifier);
				var addresses = (Hashtable) formatter.Deserialize(stream);				// good
				Console.WriteLine(addresses);
			}
			catch (SerializationException e)
			{
				throw;
			}
			finally
			{
				stream.Close();
			}
		}
	}
}