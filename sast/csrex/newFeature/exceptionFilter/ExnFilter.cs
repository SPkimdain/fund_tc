using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.IO;

namespace newFeatures
{
    namespace ExceptionFilter
    {
        class ExnFilterTest : System.Web.UI.Page
        {
            protected void Page_Load(object sender, EventArgs e)
            {

            }

            public void test_tc(int c)
            {
                int x = 0;
                try
                {
                    x = 1;
                    Console.WriteLine(x);
                    x = 2;
                    Console.WriteLine(x);
                    if (c > 10) {
                        return;
                    }
                    Console.WriteLine("test");
                    Directory.SetCurrentDirectory("not_exists");

                    using (StreamReader reader = new StreamReader("not_exists.txt"))
                    {
                        reader.ReadToEnd();
                    }
                }
                catch (DirectoryNotFoundException dirEx)
                {
                    Console.WriteLine("Directory not found: " + dirEx.Message);
                }
                catch (FileNotFoundException fileEx)
                {
                    Console.WriteLine("File not found: " + file.Message);
                }
            }

            public void test_tf(int c)
            {
                int x = 0;
                Console.WriteLine(x);
                try
                {
                    x = 1;
                    Console.WriteLine(x);
                    x = 2;
                    Console.WriteLine(x);
                    if (c > 10) {
                        return;
                    }
                    Console.WriteLine("test");
                }
                finally
                {
                    Console.WriteLine("finally");
                }
            }

            public int test_tf_return_value(int c)
            {
                int x = 0;
                Console.WriteLine(x);
                try
                {
                    x = 1;
                    Console.WriteLine(x);
                    x = 2;
                    Console.WriteLine(x);
                    if (c > 10) {
                        return 10;
                    }
                    Console.WriteLine("test");
                }
                finally
                {
                    Console.WriteLine("finally");
                }
                return 20;
            }

            public void test_tcf(int c)
            {
                int x = 0;
                Console.WriteLine(x);
                try
                {
                    x = 1;
                    Console.WriteLine(x);
                    x = 2;
                    Console.WriteLine(x);
                    if (c > 10) {
                        return;
                    }
                    Console.WriteLine("test");
                    Directory.SetCurrentDirectory("not_exists");

                    using (StreamReader reader = new StreamReader("not_exists.txt"))
                    {
                        reader.ReadToEnd();
                    }
                    if (c < 20) {
                        return;
                    } else {
                        throw new FileLoadException();
                    }

                    Console.WriteLine("end of try block");
                }
                catch (DirectoryNotFoundException dirEx)
                {
                    Console.WriteLine("Directory not found: " + dirEx.Message);
                }
                catch (FileNotFoundException fileEx)
                {
                    Console.WriteLine("File not found: " + fileEx.Message);
                }
                finally
                {
                    Console.WriteLine("finally");
                }
            }

            public void test_tcf_filtered(int c)
            {
                int x = 0;
                Console.WriteLine(x);
                try
                {
                    x = 1;
                    Console.WriteLine(x);
                    x = 2;
                    Console.WriteLine(x);
                    if (c > 10) {
                        return;
                    }
                    Console.WriteLine("test");
                    Directory.SetCurrentDirectory("not_exists");

                    using (StreamReader reader = new StreamReader("not_exists.txt"))
                    {
                        reader.ReadToEnd();
                    }
                    if (c < 20) {
                        return;
                    } else {
                        throw new FileLoadException();
                    }

                    Console.WriteLine("end of try block");
                }
                catch (DirectoryNotFoundException dirEx) when (c > 10)
                {
                    Console.WriteLine("Filtered 1 Directory not found: " + dirEx.Message);
                }
                catch (DirectoryNotFoundException dirEx) when (dirEx.Message.Length > 10)
                {
                    Console.WriteLine("Filtered 2 Directory not found: " + dirEx.Message);
                }
                catch (FileNotFoundException fileEx) when (fileEx.ToString.Length > 10)
                {
                    Console.WriteLine("Filtered File not found: " + fileEx.Message);
                }
                catch (FileNotFoundException fileEx)
                {
                    Console.WriteLine("File not found: " + fileEx.Message);
                }
                catch (DirectoryNotFoundException dirEx)
                {
                    Console.WriteLine("Directory not found: " + dirEx.Message);
                }
                catch when (c > 100)
                {
                    Console.WriteLine("general catch 100");
                }
                catch when (c < 30)
                {
                    Console.WriteLine("general catch 30");
                }
                catch
                {
                    Console.WriteLine("general general");
                }
                finally
                {
                    Console.WriteLine("finally really");
                }
            }
        }
    }
}
