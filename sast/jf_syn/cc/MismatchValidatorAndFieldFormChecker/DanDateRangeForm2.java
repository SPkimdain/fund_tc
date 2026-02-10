package org.example.cwe660_struts.forms;

import com.opensymphony.xwork2.ActionSupport;

public class DanDateRangeForm2 extends ActionSupport {
    private String startDate;
    private String endDate;
    private String scale;

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    public void setEndDate(String endDate) {
        this.endDate = endDate;
    }

    public void setScale(String scale) {
        this.scale = scale;
    }
}
