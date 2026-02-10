using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quality
{
    class HtmlInputHidden
    {
        public HtmlInputHIdden() {
            HtmlInputHidden hidden = new HtmlInputHidden(); // @violation
        }
    }
}