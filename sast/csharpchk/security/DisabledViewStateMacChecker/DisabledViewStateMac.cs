using System;
using System.Configuration;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.ComponentModel;

namespace TestApplication
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Page.EnableViewStateMac = false; // @violation
            Page.EnableViewStateMac = true;
            Page.EnableViewStateMac = false; // @violation
            Page.EnableViewState = false;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            this.Debug1.Text = "This is dummy code";
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            this.Debug2.Text = "This is dummy code";
        }
    }
}