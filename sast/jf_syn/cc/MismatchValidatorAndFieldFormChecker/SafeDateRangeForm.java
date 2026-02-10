package org.example.cwe660_struts.forms;

import com.opensymphony.xwork2.ActionSupport;

import javax.ejb.Stateless;

public class SafeDateRangeForm extends ActionSupport {
    private String startDate;
    private String endDate;
    private String scale;  // 검증과 일치하도록 필드를 추가합니다.

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    public void setEndDate(String endDate) {
        this.endDate = endDate;
    }

    public void setScale(String scale) {
        this.scale = scale;
    }

    public String getStartDate() {
        return startDate;
    }

    public String getEndDate() {
        return endDate;
    }

    public String getScale() {
        return scale;
    }
    @Override
    public String execute() {
        return SUCCESS;
    }

    @Override
    public String input() {
        return INPUT;
    }

    @Override
    public void validate() {
        if (startDate == null || startDate.isEmpty()) {
            addFieldError("startDate", "Start date is required.");
        }
        if (endDate == null || endDate.isEmpty()) {
            addFieldError("endDate", "End date is required.");
        }
//        if (scale == null || scale.isEmpty()) {
//            addFieldError("scale", "Scale is required.");
//        }
    }
}