/* WITH_CHECKERS : DOWNLOAD_OF_CODE_WITHOUT_INTEGRITY_CHECK_CSHARP */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Net;
using System.IO;

//TODO: https://cwe.mitre.org/data/definitions/494.html 에 따르면 "실행될 코드" 다운로드에 적용되는 룰인데, 단순 파일 저장만으로도 검출됨
//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace MyVulnerableWebsite
{
    public partial class DownloadFromRemote : System.Web.UI.Page
    {
        public override bool DownloadFile()
        {
            var url = "https://www.somewhere.untrusted.com";
            var desDir = "D:/DestinationPath";
            string fileName = Path.GetFileName(url);
            string descFilePath = Path.Combine(desDir, fileName);
            try
            {
                WebRequest myre = WebRequest.Create(url);
            }
            catch (Exception ex)
            {
                throw new Exception(ex.Message);
            }
            try
            {
                byte[] fileData;
                using (WebClient client = new WebClient())
                {
                    fileData = client.DownloadData(url);
                }
                using (FileStream fs = new FileStream(descFilePath, FileMode.OpenOrCreate))
                {
                    fs.Write(fileData, 0, fileData.Length); /* BUG: DOWNLOAD_OF_CODE_WITHOUT_INTEGRITY_CHECK_CSHARP */
                }
                return true;
            }
            catch (Exception ex)
            {
                throw new Exception(ex.Message);
            }
        }
    }
}