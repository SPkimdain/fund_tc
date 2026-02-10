package security;

import com.opensymphony.xwork2.ActionSupport;

public class Cwe608_d extends ActionSupport {
    public String startDate; //@violation
    private String endDate;

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    public void setEndDate(String endDate) {
        this.endDate = endDate;
    }
}