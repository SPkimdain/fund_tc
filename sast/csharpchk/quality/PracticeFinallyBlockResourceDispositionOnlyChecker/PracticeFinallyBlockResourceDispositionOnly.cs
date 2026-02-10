using System.IO;

class PracticeFinallyBlockResourceDispositionOnly
{
    public static byte[] BadCase1(string filePath)
    {
        byte[] buffer;
        FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
        try
        {
            int length = (int)fileStream.Length;
            buffer = new byte[length];
            int count;
            int sum = 0;

            while ((count = fileStream.Read(buffer, sum, length - sum)) > 0)
                sum += count;
        }
        finally // @violation
        {
            fileStream.Dispose();
        }
        return buffer;
    }

    public static byte[] BadCase2(string filePath)
    {
        byte[] buffer;
        FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
        try
        {
            int length = (int)fileStream.Length;
            buffer = new byte[length];
            int count;
            int sum = 0;

            while ((count = fileStream.Read(buffer, sum, length - sum)) > 0)
                sum += count;
        }
        finally // @violation
        {
            if(fileStream != null)
            {
                fileStream.Dispose();
            }
        }
        return buffer;
    }

    public static byte[] BadCase3(string filePath1, string filePath2)
    {
        byte[] buffer1;
        byte[] buffer2;
        FileStream fileStream1 = new FileStream(filePath1, FileMode.Open, FileAccess.Read);
        FileStream fileStream2 = new FileStream(filePath2, FileMode.Open, FileAccess.Read);
        try
        {
            int length1 = (int)fileStream1.Length;
            int length2 = (int)fileStream2.Length;
            buffer1 = new byte[length1];
            buffer2 = new byte[length2];
            int count1;
            int count2;
            int sum1 = 0;
            int sum2 = 0;

            while ((count1 = fileStream1.Read(buffer1, sum1, length1 - sum1)) > 0)
                sum1 += count1;

            while((count2 = fileStream2.Read(buffer2, sum2, length2 - sum2)) > 0)
                sum2 += count2;
        }
        finally // @violation
        {
            if(fileStream1 != null)
            {
                if(fileStream2 != null)
                    fileStream1.Dispose();
            }
            fileStream2.Dispose();
        }
        return buffer1;
    }

    public static byte[] GoodCase1(string filePath)
    {
        byte[] buffer;
        using(FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read)) {
            int length = (int)fileStream.Length;
            buffer = new byte[length];
            int count;
            int sum = 0;

            while ((count = fileStream.Read(buffer, sum, length - sum)) > 0)
                sum += count;
        }
        return buffer;
    }

    public void TestTryFianlly()
    {
        try
        {
            var temp = obj;
        }
        finally
        {
            obj = null;
        }
    }
}