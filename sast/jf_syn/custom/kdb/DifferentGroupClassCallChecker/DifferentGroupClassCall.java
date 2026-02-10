package com.kdb.gsb.xd.aaa.svc.impl;

import com.kdb.gsb.xl.BIO;

public class ComplexSVCImpl {
    public static void main(String[] args) {
        BIZ biz = new BIZ();  
        biz.Test();

        BIO bio = new BIO();
        bio.printMessage();
    }
}
