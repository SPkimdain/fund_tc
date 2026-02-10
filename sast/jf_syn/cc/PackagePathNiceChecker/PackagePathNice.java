package com.nice.app.css_cro.cs_admin.biz;

public class PackagePath {
    // Constructor
    public PackagePath() {
        Test test = new Test();
        test = tpSvr.tpConvertCall(test, "/css_cro/cs_admin/TR825_in", "/css_cro/cs_admin/TR825_out", log.service());   /* Safe */
        test = tpSvr.tpConvertCall(test, "/css_cro/TR825_in", "/css_cro/TR825_out", log.service());   // @violation
        test = tpSvr.tpConvertCall(test, "/css_cro", "/css_cro", log.service());   // @violation
        test = tpSvr.tpConvertCall(test, "/css_cro/cs_admin/TR825_in", "/css_cro/TR825_out", log.service());   // @violation
    }

    // Method
    public void testMethod() {
        Test test = new Test();
        test = tpSvr.tpConvertCall(test, "/css_cro/cs_admin/TR825_in", "/css_cro/cs_admin/TR825_out", log.service());   /* Safe */
        test = tpSvr.tpConvertCall(test, "/css_cro/TR825_in", "/css_cro/TR825_out", log.service());   // @violation
        test = tpSvr.tpConvertCall(test, "/css_cro", "/css_cro", log.service());   // @violation
        test = tpSvr.tpConvertCall(test, "/css_cro/cs_admin/TR825_in", "/css_cro/TR825_out", log.service());   // @violation
    }
}