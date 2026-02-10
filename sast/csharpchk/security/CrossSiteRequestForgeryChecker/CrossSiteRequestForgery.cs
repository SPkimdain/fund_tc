/*****************************************************/
/* Converted by ASPNETConv: ASP.NET Converter module */
/* Generated at: 2026-05-01 10:40:55                 */
/*****************************************************/
// Originated from D:\sparrow5\data\client\admin\analysis\1_checker_test\sparrow\sources\test.cshtml
namespace ASP {

  using System;
  using System.Collections.Generic;
  using System.IO;
  using System.Linq;
  using System.Net;
  using System.Web;
  using System.Web.Helpers;
  using System.Web.Security;
  using System.Web.UI;
  using System.Web.WebPages;
  using System.Web.Mvc;
  using System.Web.Mvc.Ajax;
  using System.Web.Mvc.Html;
  using System.Web.Routing;

  public class SPW_756_test_cshtml : System.Web.Mvc.WebViewPage<dynamic> {

    protected System.Web.HttpApplication ApplicationInstance {
      get {
        return ((System.Web.HttpApplication)(Context.ApplicationInstance));
      }
    }

    public SPW_756_test_cshtml() {
    }

    public override void Execute(dynamic Model) {
      WriteLiteral("");
      WriteLiteral("\r\n");
      if (Request.IsAuthenticated)
      {
          // -------------------------------------------------------------------------
          // [SAFE] 안전한 케이스
          // 설명: 토큰이 포함되어 있고, 입력값(Input)이 없어서 CSRF 대상이 아니거나 안전함
          // -------------------------------------------------------------------------
          using (Html.BeginForm("LogOff", "Account", FormMethod.Post, new { id = "logoutForm", @class = "navbar-right" }))
          {
                    Write(Html.AntiForgeryToken());


      WriteLiteral("        <ul");
      WriteLiteral(" class=\"");
      WriteLiteral("nav");
      WriteLiteral(" navbar-nav");
      WriteLiteral(" navbar-right");
      WriteLiteral("\"");
      WriteLiteral(">\r\n            <li>\r\n");
      Write(Html.ActionLink("안녕하세요 " + User.Identity.GetUserName() + "!", "Index", "Manage", routeValues: null, htmlAttributes: new { title = "Manage" }));
      WriteLiteral("\r\n            </li>\r\n            <li>\r\n                <a");
      WriteLiteral(" href=\"");
      WriteLiteral("javascript:document.getElementById('logoutForm').submit()");
      WriteLiteral("\"");
      WriteLiteral(">로그오프</a>\r\n            </li>\r\n        </ul>\r\n");
          }

      WriteLiteral("    <hr />\r\n");

          // -------------------------------------------------------------------------
          // [VULNERABLE] 위험한 케이스 (탐지 대상)
          // 조건 1: Html.BeginForm(FormMethod.Post) 사용
          // 조건 2: 내부 요소에 <input> 태그 존재 (사용자 입력 발생)
          // 조건 3: @Html.AntiForgeryToken() 누락됨 -> CSRF 공격 가능
          // -------------------------------------------------------------------------
          using (Html.BeginForm("UpdateStatus", "Profile", FormMethod.Post))  //@violation
          {


      WriteLiteral("        <div");
      WriteLiteral(" class=\"");
      WriteLiteral("form-group");
      WriteLiteral("\"");
      WriteLiteral(">\r\n            <label>오늘의 기분:</label>\r\n            <input");
      WriteLiteral(" type=\"");
      WriteLiteral("text");
      WriteLiteral("\"");
      WriteLiteral(" name=\"");
      WriteLiteral("statusMessage");
      WriteLiteral("\"");
      WriteLiteral(" class=\"");
      WriteLiteral("form-control");
      WriteLiteral("\"");
      WriteLiteral(" />\r\n            <input");
      WriteLiteral(" type=\"");
      WriteLiteral("submit");
      WriteLiteral("\"");
      WriteLiteral(" value=\"");
      WriteLiteral("상태");
      WriteLiteral(" 업데이트");
      WriteLiteral("\"");
      WriteLiteral(" class=\"");
      WriteLiteral("btn");
      WriteLiteral(" btn-default");
      WriteLiteral("\"");
      WriteLiteral(" />\r\n        </div>\r\n");
          }
      }
      else
      {
      WriteLiteral("    <ul");
      WriteLiteral(" class=\"");
      WriteLiteral("nav");
      WriteLiteral(" navbar-nav");
      WriteLiteral(" navbar-right");
      WriteLiteral("\"");
      WriteLiteral(">\r\n        <li>");
      Write(Html.ActionLink("등록", "Register", "Account", routeValues: null, htmlAttributes: new { id = "registerLink" }));
      WriteLiteral("</li>\r\n        <li>");
      Write(Html.ActionLink("로그인", "Login", "Account", routeValues: null, htmlAttributes: new { id = "loginLink" }));
      WriteLiteral("</li>\r\n    </ul>\r\n");
      }
      WriteLiteral("");
    }
  }
}
