/* WITH_CHECKERS : UNRESTRICTED_UPLOAD_OF_FILE_ASPNET */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
namespace WebFormTest
{
    public partial class UnrestrictedUpload : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void UploadButton_Click(object sender, EventArgs e)
        {
            if (FileUpload1.HasFile)
            {
                SaveFile(FileUpload1.PostedFile);
            }
            else
            {
                UploadStatusLabel.Text = "You did not specify a file to upload";
            }
        }

        void SaveFile(HttpPostedFile file)
        {
            string savePath = "c:\\temp\\uploads\\";
            string fileName = FileUpload1.FileName;
            string pathAndName = savePath + fileName;

            FileUpload1.SaveAs(pathAndName); /* BUG: UNRESTRICTED_UPLOAD_OF_FILE_ASPNET */
        }

        protected void UploadButton_Click2(object sender, EventArgs e)
        {
            if (FileUpload1.HasFile)
            {
                SaveFile2(FileUpload1.PostedFile);
            }
            else
            {
                UploadStatusLabel.Text = "You did not specify a file to upload";
            }
        }

        void SaveFile2(HttpPostedFile file)
        {
            string savePath = "c:\\temp\\uploads\\";
            string fileName = FileUpload1.FileName;
            string pathAndName = savePath + fileName;

            if (pathAndName.EndsWith(".txt") || pathAndName.EndsWith(".png"))
            {
                FileUpload1.SaveAs(pathAndName); // SAFE
            }
        }
    }
}