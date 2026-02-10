/* WITH_CHECKERS : PERSISTENT_COOKIE_ASPNET */

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace WebFormTest
{
    public partial class PersistentCookie : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            StringBuilder sb = new StringBuilder();
            // Get cookie from the current request.
            HttpCookie cookie = Request.Cookies.Get("DateCookieExample");

            // Check if cookie exists in the current request.
            if (cookie == null)
            {
                sb.Append("Cookie was not received from the client. ");
                sb.Append("Creating cookie to add to the response. <br/>");
                // Create cookie.
                cookie = new HttpCookie("DateCookieExample");
                // Set value of cookie to current date time.
                cookie.Value = DateTime.Now.ToString();
                // Set cookie to expire in 10 minutes.
                int x = 5000;
                cookie.Expires = DateTime.Now.AddMinutes(x); /* BUG: PERSISTENT_COOKIE_ASPNET */
                // Insert the cookie in the current HttpResponse.
                Response.Cookies.Add(cookie);
            }
            else
            {
                sb.Append("Cookie retrieved from client. <br/>");
                sb.Append("Cookie Name: " + cookie.Name + "<br/>");
                sb.Append("Cookie Value: " + cookie.Value + "<br/>");
                sb.Append("Cookie Expiration Date: " +
                    cookie.Expires.ToString() + "<br/>");
            }
            Label1.Text = sb.ToString();
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox1.Text;
            StringBuilder sb = new StringBuilder();
            // Get cookie from the current request.
            HttpCookie cookie = Request.Cookies.Get("DateCookieExample");

            // Check if cookie exists in the current request.
            if (cookie == null)
            {
                sb.Append("Cookie was not received from the client. ");
                sb.Append("Creating cookie to add to the response. <br/>");
                // Create cookie.
                cookie = new HttpCookie("DateCookieExample");
                // Set value of cookie to current date time.
                cookie.Value = DateTime.Now.ToString();
                // Set cookie to expire in 10 minutes.
                int x = Int32.Parse(arg);
                cookie.Expires = DateTime.Now.AddMinutes(x); /* BUG: PERSISTENT_COOKIE_ASPNET */
                // Insert the cookie in the current HttpResponse.
                Response.Cookies.Add(cookie);
            }
            else
            {
                sb.Append("Cookie retrieved from client. <br/>");
                sb.Append("Cookie Name: " + cookie.Name + "<br/>");
                sb.Append("Cookie Value: " + cookie.Value + "<br/>");
                sb.Append("Cookie Expiration Date: " +
                    cookie.Expires.ToString() + "<br/>");
            }
            Label1.Text = sb.ToString();
        }

        protected void TextBox2_TextChanged(object sender, EventArgs e)
        {
            string arg = TextBox2.Text;
            StringBuilder sb = new StringBuilder();
            // Get cookie from the current request.
            HttpCookie cookie = Request.Cookies.Get("DateCookieExample");

            // Check if cookie exists in the current request.
            if (cookie == null)
            {
                sb.Append("Cookie was not received from the client. ");
                sb.Append("Creating cookie to add to the response. <br/>");
                // Create cookie.
                cookie = new HttpCookie("DateCookieExample");
                // Set value of cookie to current date time.
                cookie.Value = DateTime.Now.ToString();
                // Set cookie to expire in 10 minutes.
                int x = Int32.Parse(arg);
                if (x > 3600) x = 3600;
                cookie.Expires = DateTime.Now.AddMinutes(x); // not bug
                // Insert the cookie in the current HttpResponse.
                Response.Cookies.Add(cookie);
            }
            else
            {
                sb.Append("Cookie retrieved from client. <br/>");
                sb.Append("Cookie Name: " + cookie.Name + "<br/>");
                sb.Append("Cookie Value: " + cookie.Value + "<br/>");
                sb.Append("Cookie Expiration Date: " +
                    cookie.Expires.ToString() + "<br/>");
            }
            Label1.Text = sb.ToString();
        }
    }
}