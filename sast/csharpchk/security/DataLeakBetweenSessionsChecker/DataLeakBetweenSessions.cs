using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace NewNonghyupCheckers
{
    class DataLeakBetweenSessions : IHttpHandler
    {
        private String id;  // @violation

        public void ProcessRequest(HttpContext ctx)
        {
            var json = new JSONResonse()
            {
                Success = ctx.Request.QueryString["name"] != null,
                Name = ctx.Request.QueryString["name"]
            };

            ctx.Response.ContentType = "application/json";
            ctx.Response.Write(JsonConvert.SerializeObject(json));
        }

        public bool IsReusable
        {
            get { return false; }
        }
    }
}
