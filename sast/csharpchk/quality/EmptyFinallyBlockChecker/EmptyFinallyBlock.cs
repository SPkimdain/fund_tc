using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Quality
{
    class EmptyFinallyBlock
    {
        public List<string> ReadFile(string path)
        {
            FileInfo file = new FileInfo(path);
            StreamReader reader = file.OpenText();
            List<string> text = new List<string>();

            try
            {
                while (!reader.EndOfStream)
                {
                    text.Add(reader.ReadLine());
                }
                return text;
            }
            catch (IOException e)
            {
                Console.WriteLine(e.ToString());
                return text;
            }
            finally // @violation
            {
            }
        }
    }
}
