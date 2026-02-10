using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Xml.Xsl;

namespace TypeCheckWithName
{
    class Program
    {
        private String[] colors;
        private List<String> secureName;
        public List<String> publicName;

        public String[] getColors()
        {
            return colors; // @violation
        }

        public List<String> returnSecureName()
        {
            return secureName; // @violation
        }

        private List<String> returnSecureNameInPrivate()
        {
            return secureName;
        }

        public List<String> returnPublicName()
        {
            return publicName;
        }

        private List<String> returnPublicNameInPrivate()
        {
            return publicName;
        }
    }
}
