using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Quality
{
    class PortabilityFlawFileSeparator
    {
        public PortabilityFlawFileSeparator()
        {
        }

        public void FileSeparator(String path, String path1)
        {
            FileStream stream = File.Create(path + "\\" + path1); // @violation
        }

        public void FileSeparatorSound(String path, String path1)
        {
            FileStream stream = File.Open(path + Path.DirectorySeparatorChar + path1, FileMode.Open); //@safe
        }
    }
}