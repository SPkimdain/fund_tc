<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <jsp:include page="include/head.jsp"/>
    <jsp:include page="include/datetimepicker.jsp"/>
    <link type="text/css" rel="stylesheet" href="css/jquery-ui-loader.css"/>
    <link type='text/css' rel='stylesheet' href='css/tree.css'/>
    <script type="text/javascript" src="js/jquery/jquery.min.1.5.js"></script>
    <script type="text/javascript" src="js/jquery/jquery-ui.min.1.8.js"></script>
    <script type="text/javascript" src="js/jquery/jquery.cookie.js"></script>
    <script type="text/javascript" src="js/jquery/jquery.form.js"></script>
    <script type="text/javascript" src="js/tree.js"></script>
    <script type="text/javascript" src="js/projectGroupTree.js"></script>
    <script type="text/javascript">
    //<![CDATA[
        var $J = jQuery.noConflict();
        window.onload = function() {
            initSortIcon();
            setEnable();
            alertMsg();
            openNotice();
        }
        function goDataList() {
            goPageLoader("projectList.spw");
        }
        function deleteProject(projectId, scans, analyzing) {
            if(!confirm("<spring:message code='confirm.Selected.project.is.deleted'/>"))
                return;
            if(scans != 0 && !confirm("<spring:message code='confirm.All.result.of.selection.will.be.deleted'/>"))
                return;
            if(analyzing == true && !confirm("<spring:message code='confirm.This.project.may.be.analyzing.now'/>"))
                return;
            showDialogLoader();
            document.getElementById("projectId").value = projectId;
            ajaxDeleteProject("ajaxDeleteProject.spw");
        }
        function batchDeleteProject(obj) {
            if(!isEnableBtn(obj))
                return;
            if(!confirm("<spring:message code='confirm.Selected.project.is.deleted'/>"))
                return;
            if(!confirm("<spring:message code='confirm.All.result.of.selection.will.be.deleted'/>"))
                return;
            showDialogLoader();
            ajaxDeleteProject("ajaxBatchDeleteProject.spw");
        }
        function ajaxDeleteProject(url) {
            jQuery.ajax({
                type: "POST",
                dataType: "json",
                url: url,
                data: $J('#form').formSerialize(true),
                success: function(data) {
                  if(data != ""){
                      if(document.applet)
                          document.applet.deleteProjectFile("projectIds=" + data.projectIds);
                      document.getElementById("curPage").value = data.updateCurPage;
                      goPage("projectList.spw");
                  }
                },
                error: function(request) {
                  alert("Error:"+ request.status);
                }
           });
        }
        function searchList() {
            goPageLoader("projectListSearch.spw");
        }
        function clearSearch(){
            document.getElementById("searchCondition.fromAnalysisStartedTime").value = "";
            document.getElementById("searchCondition.toAnalysisStartedTime").value = "";
            document.getElementById("searchCondition.projectGroupName").value = "";
            document.getElementById("searchCondition.projectGroupId").value = "";
            document.getElementById("searchCondition.selectedColumn").value = "";
            document.getElementById("searchCondition.searchWord").value = "";
            searchList();
        }
        function changeLanguage(){
            $J.cookie("projectList.language", document.getElementById("pageCondition.language").value,  { expires: 7 });
            goDataList();
        }
        function goModifyMultipleProjects(obj) {
            if(!isEnableBtn(obj))
                return;
            goPage("modifyMultipleProjects.spw");
        }
        function goModifyProject(projectId, progress) {
            if(progress != "" && !confirm("<spring:message code='confirm.Modifying.a.project.during.analysis.can.change.the.analysis.result.of.the.project'/>"))
                return;
            location.href = "modifyProject.spw?projectId=" + projectId;
        }
        function setEnable(){
            setEnableExportExcel();
        }
        var selectedUserListId = -1;
        function getProjectUserList(projectId) {
            var userTable = document.getElementById("userTable" + projectId);
            if (selectedUserListId == projectId) {
                if (userTable.style.display == "none" || userTable.style.display == "" ) {
                    closeComment();
                    userTable.style.display = "block";
                } else {
                    userTable.style.display = "none";
                }
            } else {
                closeComment();
                try {
                    document.getElementById("userTable" + selectedUserListId).style.display = "none";
                } catch (e) {
                }
                userTable.style.display = "block";
                selectedUserListId = projectId;
                if($J("#userTable" + projectId).html() == ""){
                    jQuery.ajax({
                        type: "POST",
                        dataType: "text",
                        url: "ajaxGetProjectUserList.spw",
                        data: "projectId=" + projectId,
                        success: function(data) {
                          $J("#userTable" + projectId).html(data);
                        },
                        error: function(request) {
                          alert("Error:"+ request.status);
                        }
                   });
                }
            }
        }
        function closeProjectUserList() {
            if(selectedUserListId != -1)
                document.getElementById("userTable" + selectedUserListId).style.display = "none";
        }
    //]]>
    </script>
</head>
<body>
<jsp:include page="include/dialogLoader.jsp"/>
<input type="hidden" id="labelAllGroups" value="<spring:message code="label.All.Groups"/>"/>
<div id="dialogPopupNotice" style="display:none;"></div>
<form:form id="form" name="form" method="post">
    <tags:token/>
    <form:hidden path="projectId" />
    <form:hidden path="alertMsg"/>
    <input type="hidden" id="projectDto.language" name="projectDto.language" />
    <form:hidden path="pageCondition.fromAnalysisStartedTime"/>
    <form:hidden path="pageCondition.toAnalysisStartedTime"/>
    <form:hidden path="pageCondition.selectedColumn"/>
    <form:hidden path="pageCondition.searchWord"/>
    <form:hidden path="pageCondition.includeWord"/>
    <form:hidden path="pageCondition.projectGroupId"/>
    <form:hidden path="searchCondition.projectGroupId"/>
    <form:hidden path="searchCondition.excludeHiddenDefects"/>
    <jsp:include page="include/topMenu.jsp" />
    <table cellpadding="3" cellspacing="0" class="navigator">
        <tr>
            <td width="5">&nbsp;</td>
            <td>
                <table cellpadding="3" cellspacing="0" border="0">
                    <tr>
                        <td><b><spring:message code="label.Projects"/></b></td>
                    </tr>
                </table>
            </td>
            <td width="100%">&nbsp;</td>
            <td><jsp:include page="include/goToDefectId.jsp"/></td>
        </tr>
    </table>
    <table cellpadding="0" cellspacing="0">
        <tr>
            <td class="contents">
                <span class="title"><spring:message code="label.Projects"/></span>
                <br/><br/>
                <table cellpadding="0" cellspacing="0" border="0" width="100%">
                    <tr>
                        <td>
                            <table cellpadding="2" cellspacing="0">
                                <tr>
                                    <th nowrap="nowrap"><spring:message code="label.Analysis.Started.Time"/>:</th>
                                    <td width="135"><form:input path="searchCondition.fromAnalysisStartedTime" onkeydown="return searchKeyDown(event);" cssClass="datetimepicker" /></td>
                                    <td width="7" align="center">~</td>
                                    <td width="135"><form:input path="searchCondition.toAnalysisStartedTime" onkeydown="return searchKeyDown(event);" cssClass="datetimepicker" /></td>
                                    <th nowrap="nowrap"><spring:message code="label.Project.Group"/>:</th>
                                    <td>
                                        <label for="searchCondition.projectGroupName" class="placeholder pointer prjectGroupName"><img src="image/icon_glass.png"/></label>
                                        <form:input path="searchCondition.projectGroupName" onclick="javascript:showProjectGroupTree();" cssClass="textfield pointer prjectGroupName" readonly="true"/>
                                    </td>
                                    <td>
                                        <form:select path="searchCondition.selectedColumn">
                                            <form:option value="p.name"><spring:message code="label.Project"/></form:option>
                                            <form:option value="u.sparrow_user_id||'('||u.name||')'"><spring:message code="label.Analysis.Owner"/></form:option>
                                            <form:option value="p.manager"><spring:message code="label.Manager"/></form:option>
                                            <form:option value="p.comments"><spring:message code="label.Memo"/></form:option>
                                        </form:select>
                                    </td>
                                    <td><form:input path="searchCondition.searchWord" onkeydown="return searchKeyDown(event);" cssStyle="width:150px" cssClass="textfield" /></td>
                                    <td><form:checkbox path="searchCondition.includeWord" /></td>
                                    <td nowrap="nowrap"><label for="searchCondition.includeWord1" class="pointer"><spring:message code="label.Including.Words"/></label></td>
                                    <td><img src="image/search_btn.png" onclick="searchList();" class="pointer" /></td>
                                    <td><img src="image/clear_btn.png" onclick="clearSearch();" class="pointer" /></td>
                                </tr>
                                <tr>
                                    <td colspan="5"></td>
                                    <td><div id="divProjectGroupTree" style="display: none;position: absolute;z-index:999"></div></td>
                                </tr>
                            </table>
                        </td>
                        <td>
                            <img id="btnExportExcel" src="image/excel_btn_gray.png" onclick="exportExcel('exportExcelSelectedProjectList.spw');" />
                            <c:if test="${command.loginUser.roleAdmin || command.pageCondition.manager == 'm'}">
                            <img id="btnDelete" src="image/delete_btn_gray.png" onclick="batchDeleteProject(this);" />
                            <img id="btnModify" src="image/modify_btn_gray.png" onclick="goModifyMultipleProjects(this);" />
                            </c:if>
                            <img class="pointer" src="image/addnewproject_btn.png" onclick="redirect('addNewProject.spw');" />
                        </td>
                    </tr>
                </table>
                <table class="noLineTable" width="100%">
                    <tr>
                        <td><spring:message code="label.Total3" arguments="${cvt:toComma(command.pageCondition.totalCount)}"/>
                        <span style="color:gray">
                        <c:if test="${empty command.pageCondition.language}">
                            <c:if test="${command.pageCondition.cCount > 0 and command.pageCondition.javaCount > 0}"> &nbsp; (C/C++ ${command.pageCondition.cCount}, &nbsp; JAVA ${command.pageCondition.javaCount})</c:if>
                        </c:if>
                        <c:if test="${command.pageCondition.language == 'c'}">
                            <c:if test="${command.pageCondition.javaCount > 0}"> &nbsp; (${command.pageCondition.javaCount} JAVA Project<c:if test="${command.pageCondition.javaCount == 1}"> is</c:if><c:if test="${command.pageCondition.javaCount > 1}">s are</c:if> Hidden)</c:if>
                        </c:if>
                        <c:if test="${command.pageCondition.language == 'j'}">
                            <c:if test="${command.pageCondition.cCount > 0}"> &nbsp; (${command.pageCondition.cCount} C/C++ Project<c:if test="${command.pageCondition.cCount == 1}"> is</c:if><c:if test="${command.pageCondition.cCount > 1}">s are</c:if> Hidden)</c:if>
                        </c:if>
                        </span>
                        </td>
                        <td align="right">
                            <table cellpadding="0" cellspacing="0">
                                <tr>
                                    <td><form:checkbox path="pageCondition.excludeHiddenDefects" onclick="checkExcludeHiddenDefects('projectList.spw');" /></td>
                                    <td><label for="pageCondition.excludeHiddenDefects1" class="pointer"><spring:message code="label.Exclude.Hidden.Defects"/></label></td>
                                    <td width="15">&nbsp;</td>
                                    <td><spring:message code="label.Project"/>:</td>
                                    <td><form:select path="pageCondition.manager" onchange="goDataList();">
                                            <form:option value="a"><spring:message code="label.All"/></form:option>
                                            <form:option value="m"><spring:message code="label.My.Project"/></form:option>
                                        </form:select>
                                    </td>
                                    <td width="20">&nbsp;</td>
                                    <td><spring:message code="label.Language"/>:</td>
                                    <td><form:select path="pageCondition.language" onchange="changeLanguage();">
                                            <form:option value=""><spring:message code="label.All"/></form:option>
                                            <form:options items="${command.languageItems}"/>
                                        </form:select>
                                    </td>
                                    <td width="20">&nbsp;</td>
                                    <td align="right"><spring:message code="label.Paging"/>:</td>
                                    <td><form:select path="pageCondition.pageSize" items="${command.pageSizeItems}" onchange="changePageSize('projectList');" /></td>
                                </tr>
                            </table>
                        </td>
                    </tr>
                </table>
                <c:if test="${command.pageCondition.excludeHiddenDefects == false }">
                    <c:set var="classification" value="&pageCondition.classification=0&pageCondition.classification=1&pageCondition.classification=2&pageCondition.classification=3&pageCondition.classification=4"/>
                </c:if>
                <table cellpadding="0" cellspacing="0">
                    <tr>
                        <td>
                            <table class="commonList" width="1000">
                                <tr>
                                    <th align="left" class="nonPadding"><input type="checkbox" id="allCheckbox" onclick="setAllChecked(this.checked);setEnable()" /></th>
                                    <th align="left"><img src="image/icon_right_lavender.png" id="detailAllButton" onclick="javascript:clickAllDetail();" title="<spring:message code="label.Detail"/>" class="pointer" /></th>
                                    <th onclick="javascript:sorting(this);" align="left"   class="pointer"><img id="sort_language"            class="sorting"><spring:message code="label.Language"/></th>
                                    <th onclick="javascript:sorting(this);" align="left"   class="pointer"><img id="sort_name"                class="sorting"><spring:message code="label.Project"/></th>
                                    <th onclick="javascript:sorting(this);" align="left"   class="pointer"><img id="sort_projectGroupPath"    class="sorting"><spring:message code="label.Project.Group"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_scans"               class="sorting"><spring:message code="label.Scans2"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_checkerGroup"        class="sorting"><spring:message code="label.Checker.Group"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_newDefects"          class="sorting"><spring:message code="label.New.Defects"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_defects"             class="sorting"><spring:message code="label.Total.Defects"/></th>
                                    <th onclick="javascript:sorting(this);" align="center" class="pointer"><img id="sort_sparrowUserId"       class="sorting"><spring:message code="label.Analysis.Owner"/></th>
                                    <th onclick="javascript:sorting(this);" align="center" class="pointer"><img id="sort_analysisTime"        class="sorting"><spring:message code="label.Analysis.Time"/></th>
                                    <th onclick="javascript:sorting(this);" align="center" class="pointer"><img id="sort_analysisStartedTime" class="sorting"><spring:message code="label.Analysis.Started.Time"/></th>
                                    <th onclick="javascript:sorting(this);" align="center" class="pointer"><img id="sort_analysisEndedTime"   class="sorting"><spring:message code="label.Analysis.Ended.Time"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_files"               class="sorting"><spring:message code="label.Source.Files"/></th>
                                    <th onclick="javascript:sorting(this);" align="right"  class="pointer"><img id="sort_buildLoc"            class="sorting"><spring:message code="label.Build.LOC"/></th>
                                    <th onclick="javascript:sorting(this);" align="center" class="pointer"><img id="sort_progress"            class="sorting"><spring:message code="label.Progress"/></th>
                                    <th>&nbsp;</th>
                                    <th>&nbsp;</th>
                                    <th>&nbsp;</th>
                                </tr>
                                <jsp:include page="include/allChecked.jsp"><jsp:param name="colspan" value="19"/></jsp:include>
                                <jsp:include page="include/noData.jsp"><jsp:param name="colspan" value="19"/></jsp:include>
                                <c:forEach items="${command.dataList}" var="data" varStatus="status">
                                <tr onmouseover="overLine(this);" onmouseout="outLine(this);">
                                    <td class="nonPadding">
                                        <form:checkbox path="dataList[${status.index}].checked" id="checked${status.index}" onclick="setEnable();" />
                                        <form:hidden path="dataList[${status.index}].projectId" />
                                        <form:hidden path="dataList[${status.index}].scanId" />
                                        <form:hidden path="dataList[${status.index}].language" />
                                    </td>
                                    <td><img src="image/icon_right_lavender.png" id="detailButton${data.projectId}" onclick="javascript:clickDetail(${data.projectId})" title="<spring:message code="label.Detail"/>" class="pointer" /></td>
                                    <td nowrap="nowrap">${data.viewLanguage}</td>
                                    <td>
                                        <c:if test="${ data.scanId != null }"><a title="<spring:message code='label.Project.Information'/>" href="projectInfo.spw?projectId=${data.projectId}"><c:out value="${data.name}"/></a></c:if>
                                        <c:if test="${ data.scanId == null }"><c:out value="${data.name}"/></c:if>
                                    </td>
                                    <td nowrap="nowrap"><c:out value="${data.projectGroupPath}"/></td>
                                    <td align="right">
                                        <c:if test="${data.scans > 0}"><a title="<spring:message code='label.Scans'/>" href="scanList.spw?projectId=${data.projectId}"><fmt:formatNumber value="${data.scans}" pattern="###,###,###"/></a></c:if>
                                        <c:if test="${data.scans <= 0}"><fmt:formatNumber value="${data.scans}" pattern="###,###,###"/></c:if>
                                    </td>
                                    <td nowrap="nowrap" align="right">
                                        <span title='(<spring:message code="label.Enabled.Checkers2"/> / <spring:message code="label.All.Checkers"/>)'>
                                        <c:if test="${data.checkerGroup == null}">Default (${data.defaultEnabledCheckers})</c:if>
                                        <c:if test="${data.checkerGroup != null}">
                                            <c:if test="${command.loginUser.roleAdminOrManager}"><a href="checkerGroupDesign.spw?checkerGroupDto.checkerGroupId=${data.checkerGroupId}">${data.checkerGroup} (${data.enabledCheckers})</a></c:if>
                                            <c:if test="${!command.loginUser.roleAdminOrManager}">${data.checkerGroup} (${data.enabledCheckers})</c:if>
                                        </c:if>
                                        </span>
                                    </td>
                                <c:if test="${empty data.scanId}">
                                    <td></td>
                                    <td></td>
                                </c:if>
                                <c:if test="${!empty data.scanId && !empty data.progress}">
                                    <td align="right">-</td>
                                    <td align="right">-</td>
                                </c:if>
                                <c:if test="${!empty data.scanId && empty data.progress}">
                                    <td align="right">
                                        <c:if test="${data.scanId != null and data.newDefects > 0}"><a title="<spring:message code='label.Defects'/>" href="defectList.spw?scanId=${data.scanId}&pageCondition.status=0${classification}"><fmt:formatNumber value="${data.newDefects}" pattern="###,###,###"/></a></c:if>
                                        <c:if test="${data.scanId != null and data.newDefects <= 0}"><fmt:formatNumber value="${data.newDefects}" pattern="###,###,###"/></c:if>
                                    </td>
                                    <td align="right">
                                        <c:if test="${data.scanId != null and data.allDefects > 0}"><a title="<spring:message code='label.Defects'/>" href="defectList.spw?scanId=${data.scanId}${classification}"><fmt:formatNumber value="${data.defects}" pattern="###,###,###"/></a></c:if>
                                        <c:if test="${data.scanId != null and (data.allDefects == null or data.allDefects <= 0)}"><fmt:formatNumber value="${data.defects}" pattern="###,###,###"/></c:if>
                                    </td>
                                </c:if>
                                    <td nowrap="nowrap"><c:out value="${data.sparrowUserId}"/><c:if test="${!empty data.userName}">(<c:out value="${data.userName}"/>)</c:if></td>
                                <c:if test="${empty data.scanId}">
                                    <td></td>
                                    <td></td>
                                    <td></td>
                                    <td></td>
                                    <td></td>
                                    <td></td>
                                    <td class="nonPadding"><img src="image/icon_summary_gray.png" title="<spring:message code='label.Analysis.Summary.Report'/>"/></td>
                                </c:if>
                                <c:if test="${!empty data.scanId && !empty data.progress}">
                                    <td align="center" nowrap="nowrap">-</td>
                                    <td align="right">-</td>
                                    <td align="right">-</td>
                                    <td align="right">-</td>
                                    <td align="center" nowrap="nowrap"><span style="color: red;">${data.progress}</span></td>
                                    <td class="nonPadding"><img src="image/icon_summary_gray.png" title="<spring:message code='label.Analysis.Summary.Report'/>"/></td>
                                </c:if>
                                <c:if test="${!empty data.scanId && empty data.progress}">
                                    <td align="center" nowrap="nowrap">${data.viewAnalysisTime}</td>
                                    <td align="center" nowrap="nowrap">${data.analysisStartedTime}</td>
                                    <td align="center" nowrap="nowrap">${data.analysisEndedTime}</td>
                                    <td align="right">
                                        <c:if test="${data.totalFiles > 0}"><a title="<spring:message code='label.Analyzed.File.Information'/>" href="fileInfo.spw?scanId=${data.scanId}"><fmt:formatNumber value="${data.files}" pattern="###,###,###"/></a></c:if>
                                        <c:if test="${data.totalFiles <= 0}">${data.files}</c:if>
                                    </td>
                                    <td align="right"><fmt:formatNumber value="${data.buildLoc}" pattern="###,###,###"/></td>
                                    <td align="center"><span style="color: green;">Completed</span></td>
                                    <td class="nonPadding"><a href="analysisSummaryReport.spw?scanId=${data.scanId}"><img src="image/icon_summary.png" title="<spring:message code='label.Analysis.Summary.Report'/>"/></a></td>
                                </c:if>
                                    <c:if test="${data.manager == command.loginUser.userId || command.loginUser.roleAdmin }">
                                    <td class="nonPadding"><img title="<spring:message code='label.Modify'/>" src="image/modify_pencil.png"  class="pointer" onclick="goModifyProject(${data.projectId}, '${data.progress}');"/></td>
                                    <td class="nonPadding"><img title="<spring:message code='label.Delete'/>" src="image/redcross.png"  class="pointer" onclick="deleteProject(${data.projectId}, ${data.scans}<c:if test="${!empty data.progress}">, true</c:if>);"/></td>
                                    </c:if>
                                    <c:if test="${data.manager != command.loginUser.userId && !command.loginUser.roleAdmin }">
                                    <td class="nonPadding"><img title="<spring:message code='label.Modify'/>" src="image/modify_pencil_gray.png"/></td>
                                    <td class="nonPadding"><img title="<spring:message code='label.Delete'/>" src="image/graycross.png"/></td>
                                    </c:if>
                                </tr>
                                <!-- BEGIN : Detail tr -->
                                <tr id="detail${data.projectId}" style="display:none;">
                                   <td colspan="19" class="folding">
                                        <table class="folding" cellpadding="0" cellspacing="0">
                                            <col width="10"/>
                                            <col width="80"/>
                                            <col width="100"/>
                                            <col width="80"/>
                                            <col width="80"/>
                                            <col width="100"/>
                                            <col width="100"/>
                                            <col width="100"/>
                                            <col width="100"/>
                                            <col width="100"/>
                                            <col width="50"/>
                                            <col width="80"/>
                                            <col width="100"/>
                                            <tr>
                                                <td class="nonPadding">
                                                    <c:if test='${data.projectShareCode == "g"}'>
                                                    <img title="Users" src="image/icon_user_lock.png" onclick="getProjectUserList(${data.projectId});" class="pointer"/>
                                                    <div id="userTable${data.projectId}" style="display: none;"></div>
                                                    </c:if>
                                                    <c:if test='${data.projectShareCode != "g"}'>
                                                    <img title="Users" src="image/icon_user.png"/>
                                                    </c:if>
                                                </td>
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Manager"/></b></td>
                                                <td style="white-space: nowrap;">${data.manager}</td>
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Encoding"/></b></td>
                                                <td style="white-space: nowrap;">${data.encoding}</td>
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Defect.Annotation"/></b></td>
                                                <td><spring:message code="label.${data.defectAnnotation}"/></td>
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Extended.Library"/></b></td>
                                                <td><c:if test="${data.extendedLibraryName == null}">None</c:if>${data.extendedLibraryName}</td>
                                                <c:if test="${!empty data.maxScans}">
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Max.Scans.to.Keep"/></b></td>
                                                <td><fmt:formatNumber value="${data.maxScans}" pattern="###,###,###"/></td>
                                                </c:if>
                                                <c:if test="${!empty data.comments}">
                                                <td style="white-space: nowrap;"><b><spring:message code="label.Memo"/></b></td>
                                                <td nowrap="nowrap">${data.comments}</td>
                                                </c:if>
                                            </tr>
                                        </table>
                                   </td>
                                </tr>
                                <!-- END : Detail tr -->
                                </c:forEach>
                            </table>
                        </td>
                    </tr>
                    <tr>
                        <td><jsp:include page="include/paging.jsp"/></td>
                    </tr>
                </table>
            </td>
        </tr>
    </table>
    <jsp:include page="include/footer.jsp" />
</form:form>
</body>
</html>