using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace User_Login_CS
{
    public class MissingLoginControlBody : Login
    {
        override protected void OnLoginError(EventArgs e)  // @violation
        {
            // do something here!
        }

        protected void Page_Load(object sender, EventArgs e)
        {

        }
    }
}