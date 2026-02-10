/* WITH_CHECKERS : HARD_CODED_USER_NAME_AND_PASSWORD_CSHARP */

using System;
using System.Data.SqlClient;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class HardCodedConnTest {

    public HardCodedConnTest() {
    }

    void Bad(object sender)
    {
        string id = Request["ID"];
        string connect = "Integrated Security=false;UserId=MyTestId;Password=abcdefg!";
        string query = "Select * From Products Where ProductID = @ProductID";

        using (var conn = new SqlConnection(connect)) /* BUG: HARD_CODED_USER_NAME_AND_PASSWORD_CSHARP */
        {
            using (var cmd = new SqlCommand(query, conn))
            {
                int idInt = Convert.ToInt32(id);
                if (idInt > 0 && idInt < 10000) {
                    cmd.Parameters.AddWithValue("@ProductID", idInt);
                    conn.Open();
                    cmd.ExecuteReader();
                }
            }
        }
    }

    void Good(object sender, string connect)
    {
        string query = "Select * From Products Where ProductID = @ProductID";

        using (var conn = new SqlConnection(connect)) // NOT BUG
        {
            using (var cmd = new SqlCommand(query, conn))
            {
                int idInt = Convert.ToInt32(id);
                if (idInt > 0 && idInt < 10000) {
                    cmd.Parameters.AddWithValue("@ProductID", idInt);
                    conn.Open();
                    cmd.ExecuteReader();
                }
            }
        }
    }
}