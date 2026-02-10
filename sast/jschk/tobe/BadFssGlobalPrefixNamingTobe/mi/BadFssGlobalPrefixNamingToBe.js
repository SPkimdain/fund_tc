/*********************************************************************
 * Program ID  	: js::sal.js
 * Program Name	: 영업 모듈 공통 Script List
 * Date         : 2012.11.09
 * Author       : eajoh
 * Description  : 영업 모듈 공통 Script 목록.
 * History
 * --------------------------------------------------------------------
 *     NO          Date          Author              Description
 * --------------------------------------------------------------------
 *  Ver 1.0    2012.11.09        eajoh               Initialized
 **********************************************************************/


/**********************************************************************************
● 엑셀을그리드로전환	: cfnSalExcel2Grid
● 영업팀Tree팝업		: cfnSaleTree_Dialog
● Form KeyDown			: cfnFormOnKeyDown
● 그리드HeadClick		: cfnGridOnHeadClick
● 그리드KeyDown		    : cfnGridOnKeyDown
● TODO 수신그룹 List	: cfnRcvGrpMultiSel
● TODO 수신지역 TreeView	: cfnRcvRegnTreeView
***********************************************************************************/
var f_arg;          //@violation
var uv_svcId;       // Good
var fcallBack;     //@violation

/*
기 능 : Excel을 읽어 Grid에 대체 한다.(Popup을 띄운다)
param : strGridID (string - Target Grid ID, Tab또는 Div안에 있으면 경로 포함)
        strFileName (string - Excell File Name, Path포함, 없으면 Dialog를 띄움)
        nSheet (Number - Excell Sheet Index, 0부터 시작)
return : None
*/
function cfnSalExcel2Grid(strGridID,strFileName,nSheet) //@violation
{
	var objGrid = find(strGridID);
	var strFileDialog = "FileDlgExcel";
	var strFileID = "FileExcel";
	var objFile = find(strFileID);

	// FileExcel 이 없으면 Create...
	if (isValid(objFile) == false) {
		Create("File",strFileID,'Height="1" Left="1" Right="1" TabOrder="1000" Top="1" Width="1"');
		objFile = find(strFileID);
	}

	// strFileName가 존재하지 않는 파일이면 FileDialog를 띄움
	if (FileExcel.IsExistFile(strFileName) == false)
	{
		if (isValid(Find(strFileDialog)) == false) {
			Create("FileDialog",strFileDialog,'Height="1" Left="1" Right="1" TabOrder="100" Top="1" Width="1"');
		}

		var objFileDialog = Find(strFileDialog);

		objFileDialog.Type = "OPEN";
		objFileDialog.Filter = "Excel File(*.xls,*.xlsx)|*.xls;*.xlsx|";
		objFileDialog.FileName = "";

		if (objFileDialog.Open() == false) {
			return;
		}
		strFileName = objFileDialog.FilePath + "\\" + objFileDialog.FileName;
	}

	// nSheet가 없으면 0번째 Sheet자동 선택
	nSheet = decode(fn_isNull(nSheet), true, 0, nSheet);

	var sParam = "";
		sParam += " asGrid=" + quote(strGridID);
		sParam += " asExcel=" + quote(strFileName);
		sParam += " anSheet=" + quote(nSheet);

	trace(" sal::sParam => " + sParam );

	var bRet = dialog("sample2::Excel2Grid_Pop.xml", sParam);

	if (bRet) {
		objGrid.Redraw = false;
		objGrid.Redraw = true;
	}
}

function ufn_isNull(strValue)       // Good
{
	if (strValue == null || length(strValue) == 0)
		return true;
	else
		return false;
}

/**
* HSA_HqExpnsSrchP
* @author : zhubingzheng D(2012.11.09)
*           eajoh(2012.12.03) sal/hsa/cst moved
*/
function cfnPopHqExpnsSrchP(sSvcId, sMkSpCd,sAcctNm,sCallback,bPopCk) { //@violation
	http.Sync = true;
	if(gfnIsNull(bPopCk)){
		bPopCk = false;
	}
	var sArg = "asCallBack="+ quote(sCallback)
			 + " asMkSpCd=" + quote(sMkSpCd)
			 + " asAcctNm=" + quote(sAcctNm)
			 + " asSvcId="  + quote(sSvcId);
	cfnGolbalValSett(sSvcId,sCallback,sArg);
	if (bPopCk == false) {
		dsHqExpnsParam.ClearData();
		dsHqExpnsParam.AddRow();
		dsHqExpnsParam.setColumn(0,"mkSpCd",sMkSpCd);
		dsHqExpnsParam.setColumn(0,"acctNm",sAcctNm);

		var strURL      = "Svl::gssm/sal/hsa/cst/unitdecoMstMgntNav/retrieveUnitdeco.mip";
		var sInDataSet  = "dsSearchCond=dsHqExpnsParam";
		var sOutDataSet = "dsUnitdecoListRtn=dsUnitdecoList";
		var sArgument   = "";

		gfnCallService("selectHqExpns", strURL, sInDataSet, sOutDataSet, sArgument, "cfnPopCallBack");
	}else {
		gfnDialog("sal_hsa_cst::HSA_HqExpnsSrchP.xml",f_arg,-1,-1);
	}
	http.Sync = true;
}

/**
* fnPopCallBack
* @author : zhubingzheng D(2012.11.09)
*/
function cfnPopCallBack(strSvcId, strErrCode, strErrMsg)  { //@violation
	if(strSvcId == "selectHqExpns") {
		if(dsUnitdecoListRtn.rowcount == 1) {
			var sCallback1 = f_callBack + "(f_svcId, dsUnitdecoListRtn)";
			var res = eval(sCallBack1);
		} else {
			gfnDialog("sal_hsa_cst::HSA_HqExpnsSrchP.xml",f_arg,-1,-1);
		}
	}
}

/********************************************************************************************
 * Description : 업무공통 - 전역변수에 코드필드와 코드명 필드 ID 및 리턴함수명 셋팅			*
 * Usage       : cfnGolbalValSett(sSvcId, sCallback, sArg)              				    *
 * Params      : sSvcId, sCallback, sArg                                                    *
 * Author      : zhubingzhengD. 2012.11.12												    *
 ********************************************************************************************/
function ufn_GolbalValSett(sSvcId, sCallback, sArg) // Good
{
	f_svcId   = sSvcId;
	f_arg = sArg;
	f_callBack  = sCallback;
}

/*
기 능 : 영업팀 Tree 표시
param : arg, targetObj
        팝업여부, 콜백함수, 검색어(지역코드,지역명,영업팀코드,영업팀명,점포코드,점포명)
return : regnCd, regnNm, saleTeamCd, saleTeamNm, strCd, strNm
*/
function ufnSaleTree_Dialog(arg, targetObj) //@violation
{
	var X_pos;
	var Y_pos;
	var calW = 222;
	var calH = 250;
	var wnd = GetTopWindow();

	//부모오브젝트 있으면
	if ( targetObj != null )
	{
		//x 가 탑폼 오버시 안쪽으로 이동( 폼내에서만 조정)
		if ( ClientToScreenX(targetObj, 0) +  calW > ClientToScreenX(wnd, wnd.Width) )
		{
			X_pos = ClientToScreenX(targetObj, 0) - calW;
		}
		else
		{
			X_pos = ClientToScreenX(targetObj, 0);
		}
		X_pos = ClientToScreenX(targetObj, 0);

		if ( ClientToScreenY(targetObj, 0) + targetObj.Height + calH > ClientToScreenY(wnd, wnd.Height) )
			Y_pos = ClientToScreenY(targetObj, 0) - calH;
		else
			Y_pos = ClientToScreenY(targetObj, 0) + targetObj.Height;

		var sRslt = Dialog("common::ComSaleTeamTree.xml", arg, calW, calH,"TitleBar=false NoMove=true", X_pos, Y_pos);

		return sRslt;
	}
	else
	{
		alert("팝업을 뛰울 Object를 지정해주십시오.");
	}
}

/****************************
*  cfnFormOnKeyDown*
******************************/
function ufn_FormOnKeyDown(obj,objSenderObj,nChar,bShift,bControl,bAlt,nLLParam,nHLParam)  // Good
{
	if ( nChar == 13 )
	{
		if(objSenderObj.GetType() == "Grid" ||
			objSenderObj.GetType() == "File" ||
			objSenderObj.GetType() == "FileDialog" ||
			objSenderObj.GetType() == "PopupDiv" ||
			objSenderObj.GetType() == "Static" ||
			objSenderObj.GetType() == "Image" ||
			objSenderObj.GetType() == "Shape") {
				return;
		} else {
			if ( bShift )
			{
				var objCom 	= GetPrevComponent(True);
				if(IsValidObject(objCom))
					objCom.SetFocus();
			}
			else
			{
				var objCom 	= GetNextComponent(True);
				if(IsValidObject(objCom))
					objCom.SetFocus();
			}
		}
	}
}

/****************************
*  cfnGridOnHeadClick*
******************************/
function ufn_GridOnHeadClick(obj,nCell,nX,nY,nPivotIndex)       // Good
{
	var strType = toLower(obj.GetCellProp("Head", nCell, "Display"));

	if (strType == "checkbox")
	{
		gfnGrdcheckAll(obj, nCell);
	}
	else
	{
		var dsObject = object(obj.BindDataset);

		// 변동사항이 있을 경우, 정렬하지 않는다.
		if( dsObject.GetUpdate() == true )
			return false;

		// 선택을 클릭했을 때, 결과 값이 단 건일 때 정렬하지 않는다.
		if( dsObject.rowcount <= 1 )
			return false;

		gfnGridSort(obj, dsObject, nCell);
	}
}

/****************************
*  cfnGridOnKeyDown*
******************************/
function cfnGridOnKeyDown(obj,nChar,bShift,bCtrl,bAlt,nLLParam,nHLParam)    //@violation
{
	if(nChar == 13)
	{
		if( !bShift )
			obj.MoveToNextCell();
		else
			obj.MoveToPrevCell();
	}
}

/*
기 능 : TODO 수신그룹 List 표시
param : arg, targetObj
return : jobdutyCd, jobdutyNm
*/
function cfnRcvGrpMultiSel(arg, targetObj)      //@violation
{
	var X_pos;
	var Y_pos;
	var calW = 150;
	var calH = 174;
	var wnd = GetTopWindow();

	//부모오브젝트 있으면
	if ( targetObj != null )
	{
		//x 가 탑폼 오버시 안쪽으로 이동( 폼내에서만 조정)
		if ( ClientToScreenX(targetObj, 0) +  calW > ClientToScreenX(wnd, wnd.Width) )
		{
			X_pos = ClientToScreenX(targetObj, 0) - calW;
		}
		else
		{
			X_pos = ClientToScreenX(targetObj, 0);
		}
		X_pos = ClientToScreenX(targetObj, 0);

		if ( ClientToScreenY(targetObj, 0) + targetObj.Height + calH > ClientToScreenY(wnd, wnd.Height) )
			Y_pos = ClientToScreenY(targetObj, 0) - calH;
		else
			Y_pos = ClientToScreenY(targetObj, 0) + targetObj.Height;

		var sRslt = Dialog("sal_hsa::HSA_TodoRcvGrpP.xml", arg, calW, calH,"TitleBar=false NoMove=true", X_pos, Y_pos);

		return sRslt;
	}
	else
	{
		alert("팝업을 뛰울 Object를 지정해주십시오.");
	}
}

/*
기 능 : TODO 수신지역 TreeView 표시
param : arg, targetObj
return : jobdutyCd, jobdutyNm
*/
function ufn_RcvRegnTreeView(arg, targetObj)    // Good
{
	var X_pos;
	var Y_pos;
	var calW = 203;
	var calH = 304;
	var wnd = GetTopWindow();

	//부모오브젝트 있으면
	if ( targetObj != null )
	{
		//x 가 탑폼 오버시 안쪽으로 이동( 폼내에서만 조정)
		if ( ClientToScreenX(targetObj, 0) +  calW > ClientToScreenX(wnd, wnd.Width) )
		{
			X_pos = ClientToScreenX(targetObj, 0) - calW;
		}
		else
		{
			X_pos = ClientToScreenX(targetObj, 0);
		}
		X_pos = ClientToScreenX(targetObj, 0);

		if ( ClientToScreenY(targetObj, 0) + targetObj.Height + calH > ClientToScreenY(wnd, wnd.Height) )
			Y_pos = ClientToScreenY(targetObj, 0) - calH;
		else
			Y_pos = ClientToScreenY(targetObj, 0) + targetObj.Height;

		var sRslt = Dialog("sal_hsa::HSA_TodoRcvRegnP.xml", arg, calW, calH,"TitleBar=false NoMove=true", X_pos, Y_pos);

		return sRslt;
	}
	else
	{
		alert("팝업을 뛰울 Object를 지정해주십시오.");
	}
}