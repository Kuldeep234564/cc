open visual studio 2022
create new project - asp.net web application- give name foer the project- empty-creat
right click on  project- add- new item- web service(asmx)-
  
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace mtomdownloadimgWS
{
    /// <summary>
    /// Summary description for mtomdownloadimg
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class mtomdownloadimg : System.Web.Services.WebService {

        [WebMethod]
        public string HelloWorld() {
            return "Hello World";
        }
        [WebMethod, Description("Get Image Content")]
        public byte[] GetImageFile(string fileName)
        {
            if (System.IO.File.Exists(Server.MapPath("~/Images/") + fileName))
            {
                return System.IO.File.ReadAllBytes(Server.MapPath("~/Images/") + (fileName));
            }
            else
            {
                return new byte[] { 0 };
            }
        }

    }
}

right click on project - new item- generic handler - give name for the the handler-

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mtomdownloadimgWS
{
    /// <summary>
    /// Summary description for Handler1
    /// </summary>
    public class Handler1 : IHttpHandler 
    {

        public void ProcessRequest (HttpContext context)
        {
            mtomdownloadimg ws = new mtomdownloadimg();
            byte[] binImage = ws.GetImageFile(context.Request["fileName"]);
            if (binImage.Length == 1)
            {

            }
            else
            {
                context.Response.ContentType = "image/jpeg";
                context.Response.BinaryWrite(binImage);

            }
        }

    
     
        public bool IsReusable {
            get {
                return false;
            }
        }
    }
}

right click on project - new item - web form - design the web form with 1 lable, textbox, button, image
double click on button - 
  
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace mtomdownloadimgWS
{
	public partial class WebForm1 : System.Web.UI.Page
	{
		protected void Page_Load(object sender, EventArgs e)
		{

		}

        protected void Button1_Click(object sender, EventArgs e)
        {
            Image1.ImageUrl = "~/Handler1.ashx?fileName=" + TextBox1.Text;
            Response.Write("DOWNLOADING IMAGE IS DONE");

        }
    }
}

right click on project - add - new folder - give name for the folder as IMAGE- add some images in folder

on web form right click select view in browser.
     
