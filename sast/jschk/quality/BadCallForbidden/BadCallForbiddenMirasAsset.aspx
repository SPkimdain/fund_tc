<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="utf-8"%>
<%@ page import="m.config.SystemConfig"%>
<%@ include file="/openweb/common/common.jsp"%>
<%
             String path = SystemConfig.get("FILE_DOWNLOAD");
%>
<!DOCTYPE html>
<html lang='ko'>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" media="screen" type="text/css" href="/openweb/css/common/base.css" />
<!--[if lt IE 7]><link rel='stylesheet' media='screen' type='text/css' href='/openweb/css/common/ie7.css'><![endif]-->
<title>자산관리전문가 - 미래에셋증권</title>
<!--[if lt IE 9]><script src='/openweb/js/common/IE9.js'></script><![endif]-->
<script type="text/javascript" language="javascript" src="/common/jquery-1.7.1.min.js"></script>
<script type="text/javascript" language="javascript" src="/openweb/js/common/common.js"></script>
<script src="/common/BridgeCore.js" type="text/javascript"></script>
<script type="text/javascript" language="javascript" >
//<!--
             xecureInit();

             var brd_cd                         = "<%=targetId%>";                           //게시판코드
    //공통 변수 선언
    var page_cnt = 5;                    //페이지출력건수
    var row                       = 10;                   //한페이지당 출력건수
    var page                     = 0;                    //현재 페이지

    var category = "";
    var dtl_div_cd = "";
    //이벤트 등록 및 초기 설정
    $(document).ready(function(){
        $("#search_key").val(decodeURIComponent('${param.searchword}'));       //검색어
        //검색구분
        if( "${param.searchtype}" == "" ){
            $("#searchOption").val('title');
        }else{
            $("#searchOption").val('${param.searchtype}');
        }
        if (brd_cd == "F_NEWS") {
        $("#contents").html("새소식");
        setTitle("새소식");
        category = "G";
         $("#dataListCaption").html("새소식 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "F_GONG") {
        $("#contents").html("공시정보");
        setTitle("공시정보");
        category = "G";
        $("#dataListCaption").html("공시정보: 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "SYS_WEB") {
        $("#contents").html("시스템개선");
        setTitle("시스템개선");
        category = "G";
        $("#dataListCaption").html("시스템개선 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "EVENT") {
        $("#contents").html("이벤트");
        setTitle("이벤트");
        category = "G";
        $("#dataListCaption").html("이벤트 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "DAILY") {
        $("#contents").html("데일리시황");
        setTitle("데일리시황");
        category = "R";
        $("#dataListCaption").html("데일리시황 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "FOCUS") {
        $("#contents").html("투자전략");
        setTitle("투자전략");
        category = "R";
        $("#dataListCaption").html("투자전략 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "ECONOMIC") {
        $("#contents").html("경제분석");
        setTitle("경제분석");
        category = "R";
        $("#dataListCaption").html("경제분석 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "ANALYSIS" || brd_cd == "ANALYSIS_BUSINESS") {
        brd_cd = "ANALYSIS";
        $("#contents").html("기업분석");
        setTitle("기업분석");
         category = "R";
        dtl_div_cd = "30";
        $("#dataListCaption").html("기업분석 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "ANALYSIS_INDUSTRY") {
            brd_cd = "ANALYSIS";
        $("#contents").html("산업분석");
         setTitle("새소식");
        category = "R";
        dtl_div_cd = "40";
        $("#dataListCaption").html("산업분석 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "COMPNOTICE") {
        $("#contents").html("컴플라이언스");
        setTitle("컴플라이언스");
        category = "R";
        $("#dataListCaption").html("컴플라이언스 : 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "ABROAD_RESEARCH") {
        $("#contents").html("리서치");
        setTitle("리서치");
        category = "R";
        $("#dataListCaption").html("리서치: 각각의 목록별로 등록일,첨부파일,조회수 확인할 수 있습니다.");
        } else if (brd_cd == "Deposit") {
        $("#contents").html("증거금/신용대출");
        setTitle("증거금/신용대출");
        category = "G";
        $("#dataListCaption").html("증거금률 및 신용대출 변경/공여 가능여부 확인");
        } else {
        category = "R";
        }
        $("#brd_cd").val(brd_cd);
        $("#board_kind").val(category);
        getBoardList($("#pageNo").val());
        if (category == "R") {
        $("#search_type").append("<option value='writer'>작성자</option>");
        }
    });
    //게시 목록 취득
    function getBoardList(page_no){
        if( page_no == ""){
            page = 0;
        }else{
            page = page_no;
        }
        //검색구분
        $("#searchtype").val($("#search_type").val());
        //검색어
        $("#searchword").val($("#search_key").val());
        var param = {
                search_type : $("#searchtype").val(),       //조회구분
                search_key  : $("#searchword").val(),       //조회단어
                board_kind  : $("#board_kind").val(),       //조회구분(일반게시판G ,리서치 R)
                brd_cd      : brd_cd,                       //게시판코드
                page        : page,                         //페이지번호
                row         : row                           //한페이지당 출력건수
        };
        if (category == "R") {
        param.dtl_div_cd = dtl_div_cd;                                                                // 기업 / 산업 구분
                           }
        forbidden("/openweb/db/board_tr.jsp", param, getBoardListComplete, getBoardListFail);                        // @violation
                           //callXecureAjax("/openweb/db/board_tr.jsp", param, getBoardListComplete, getBoardListFail);          -- 사용 o
    }
    //게시 목록 취득 성공시 후처리
    function getBoardListComplete(jdata){



        var html = "";
        //게시물 초기화
        $("#board_list").html("");
        var len = jdata.board_list.length;

        if( len > 0 ){
            var cnt = jdata.board_list[0].CNT;
            var board_list = jdata.board_list;
            var tot_page = cnt % row == 0 ? (cnt / row) : (cnt - cnt % row) / row + 1 ;

            for(var i = 0; i < board_list.length; i++){
                     var attach_img = "<img src='/openweb/img/common/icon/bbs_file.gif' alt='"+board_list[i].TTL+"첨부파일 다운로드'>";
                var fileName = "";
                if ( nullLengthCheck(board_list[i].FILEN1) ){
                    fileName = board_list[i].FILEN1;
                }else if( nullLengthCheck(board_list[i].FILEN2) ){
                    fileName = board_list[i].FILEN2;
                }else if( nullLengthCheck(board_list[i].FILEN3) ){
                    fileName = board_list[i].FILEN3;
                }else if( nullLengthCheck(board_list[i].FILEN4) ){
                    fileName = board_list[i].FILEN4;
                }else if( nullLengthCheck(board_list[i].FILEN5) ){
                    fileName = board_list[i].FILEN5;
                }
                $("#totalPage").text( "Page " + ( parseInt(page)+ 1 ) + " / " + tot_page );

                html += "<tr>";
                html += "  <td>" + (board_list[i].CNT - board_list[i].RN) + "</td>";
                html += "  <td class='tleft'><a href=\"javascript:boardView('" + board_list[i].BRD_CD + "','" + board_list[i].BLT_NO + "')\">" +  cutStr(board_list[i].TTL,70) + "</a></td>";
                html += "  <td>" + dateFormat(board_list[i].BSSD_T, "yyyy/MM/dd") + "</td>";
                if (nullLengthCheck(fileName)){
                    html += "<td><a href=\"javascript:fileDown('"+fileName+"', '"+board_list[i].TTL+"');\">"+attach_img+"</a></td>";
                }else{
                    html += "<td></td>";
                }
                html += "  <td class='end_line'>" + board_list[i].SCHC + "</td>";
                html += "</tr>";
            }
        }else{
            html += "<tr class='acenter'>";
            html += "  <td colspan='5' class='end_line'>조회된 게시물이 존재하지 않습니다.</td>";
            html += "</tr>";
        }
        $("#board_list").html(html);

      //페이징 처리
        if( len > 0 ){
            html = "";
            html += getPaging(page_cnt, row, board_list[0].CNT, page, "getBoardList");
        }
        $("#board_paging").html(html);

    }

    //게시 목록 취득 실패시 후처리
    function getBoardListFail(jdata, status, err){
        alert($("#contents").html() + " 조회에 실패 하였습니다." + status + " Error " + err);
    }
    //상세 보기
    function boardView(brd_cd, blt_no){
        $("#brd_cd").val(brd_cd);
        $("#blt_no").val(blt_no);
        $("#searchword").val(encodeURIComponent($("#search_key").val()));         //검색어
        $("#searchtype").val($("#search_type").val());                                                                      //검색구분
        $("#pageNo").val(page);                                                                                                                                                        //페이지

        var param = {
                     brd_cd                 : $("#brd_cd").val(),
                     blt_no                  : $("#blt_no").val(),
                     searchword          : $("#searchword").val(),
                     searchtype           : $("#searchtype").val(),
                     pageNo                : $("#pageNo").val(),
                     targetId   : $("#targetId").val(),
                     board_kind           : $("#board_kind").val()
                                        };
                           var url = "";
        //var f = document.boardInfo;

        if (category == "R"){
        //f.action= "/openweb/jsp/board/researchView.jsp";
        url = "/openweb/jsp/board/researchView.jsp";
        }else{
        //f.action= "/openweb/jsp/board/generalView.jsp";
         url = "/openweb/jsp/board/generalView.jsp";
        }
        fn_saveUrlMove(url + "?" + convParam(param), "N");
        //f.submit();

    }
    //파일다운로드
    function fileDown(fileName, title){
                          var downPath = "<%=path%>" +fileName;
                           if(fn_isNative()){
                        BridgeCore.toNative('REQ', 'PDF_VIEW', title, downPath);
                           }else{
                                        window.open("<%=path%>"+fileName, "","left=0,top=0,toolbar=no,scrollbars=no");
                           }
    }
</script>
</head>
</html>
