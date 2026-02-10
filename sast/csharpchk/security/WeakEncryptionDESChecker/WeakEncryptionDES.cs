using System;
using System.IO;
using System.Security.Cryptography;
using System.Web;

public class CWE327TestCase : System.Web.UI.Page
{
    public static byte[] encryptString()
    {
        SymmetricAlgorithm serviceProvider = new DESCryptoServiceProvider(); // @violation
        byte[] key = { 16, 22, 240, 11, 18, 150, 192, 21 };
        serviceProvider.Key = key;
        ICryptoTransform encryptor = serviceProvider.CreateEncryptor();

        String message = "Hello World";
        byte[] messageB = System.Text.Encoding.ASCII.GetBytes(message);
        return encryptor.TransformFinalBlock(messageB, 0, messageB.Length);
    }
}