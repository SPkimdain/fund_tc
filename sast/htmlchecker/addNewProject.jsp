<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<!--  일본어 테스트
かな
はははは
-->
<head>
    <jsp:include page="include/head.jsp"/>
    <link type='text/css' rel='stylesheet' href='css/tree.css'></link>
    <script type="text/javascript" src="js/tree.js"></script>
    <script type="text/javascript" src="js/selectListMove.js"></script>
    <script type='text/javascript' src='js/jquery/jquery.min.1.5.js'></script>
    <script type="text/javascript" src="js/jquery/jquery.form.js"></script>
    <script type="text/javascript" src="js/project.js"></script>
    <script type="text/javascript" src="http://aaa/js/project.js"></script>
    <script type="text/javascript" src="http://aaa/js/project.js"></script>
    <script type="text/javascript">
    //<![CDATA[
        var $J = jQuery.noConflict();
        window.onload = function(){
            setEnableBtn(document.getElementById('projectDto.checkerGroupId'), 'btnCheckerGroupDesign');
            setEnableBtn(document.getElementById('projectDto.extendedLibraryId'), 'btnExtendedLibrary');
            setEnableBtn(document.getElementById('projectDto.checkerGroupId'), 'btnCheckerGroup');
            changeProjectShare();
        }
        function addNewProject() {
            ajaxAddNewProject("projectList.spw");
        }
        function createAndContinueProject() {
            ajaxAddNewProject();
        }
        function ajaxAddNewProject(nextPage) {
            var includeUserId = document.getElementById("includeUserId");
            if(includeUserId != null)
                document.getElementById("projectDto.includeUserIds").value = getSelectedValues(includeUserId);
            jQuery.ajax({
                type: "POST",
                dataType: "text",
                url: "ajaxAddNewProject.spw",
                data: $J("#form").formSerialize(true),
                success: function(data) {
                   $J("#tdMsg").html(getTrim(data));
                   if(document.getElementById("errorUmu").value == "false" && nextPage != null)
                       goPage(nextPage);
                },
                error: function(request) {
                    alert("Error:"+ request.status);
                }
           });
        }
    //]]>
    </script>
</head>
<body>
<iframe id="iFrameProjectGroup" class="hiddenArea"></iframe>
<form:form id="form" method="post" autocomplete="off">
     Password for new user: <input type="password" name="user_passwd">

    <input type="hidden" id="projectCheckerGroupUpdateMsg" value="<spring:message code="confirm.Do.you.want.to.change.the.checker.group.accordingly"/>"/>
    <form:hidden path="projectDto.includeUserIds"/>
    <input type="hidden" id="curManager" value="${command.projectDto.manager}"/>
    <jsp:include page="include/topMenu.jsp"/>
    <table cellpadding="3" cellspacing="0" class="navigator" width="100%">
        <tr>
            <td width="5">&nbsp;</td>
            <td>
                <table cellpadding="3" cellspacing="0" border="0">
                    <tr>
                        <td><a href="projectList.spw"><spring:message code="label.Projects"/></a></td>
                        <td>&gt;</td>
                        <td><b><spring:message code="label.Add.New.Project"/></b></td>
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
                <span class="title"><spring:message code="label.Add.New.Project"/></span><br/><br/>
                <table cellpadding="0" cellspacing="0">
                    <tr>
                        <td>
                            <table cellpadding="20" cellspacing="0" class="formBox" width="100%">
                                <tr>
                                    <td>
                                        <table cellpadding="0" cellspacing="0">
                                            <tr>
                                                <td valign="top">
                                                    <table cellpadding="2" cellspacing="0" width="350">
                                                        <col width="110">
                                                        <col width="240">
                                                        <tr>
                                                            <td><b><spring:message code="label.Language"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td><form:radiobuttons path="projectDto.language" items="${command.languageItems}" onclick="changeProjectLanguage();" delimiter="</td><td width='14'>&nbsp;</td><td>"/></td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td nowrap="nowrap"><b><spring:message code="label.Project.Group"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td>
                                                                            <form:hidden path="projectDto.projectGroupId"/>
                                                                            <label for="projectDto.projectGroupName" class="placeholder pointer prjectGroupName"><img src="image/icon_glass.png"/></label>
                                                                            <form:input path="projectDto.projectGroupName" onclick="javascript:showProjectGroupTree();" cssStyle="width: 160px;" cssClass="textfield" readonly="true"/>
                                                                        </td>
                                                                    <c:if test="${command.loginUser.roleAdminOrManager}">
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td><a href="projectGroup.spw" target="_blank"><img src="image/new_nest.png"/></a></td>
                                                                    </c:if>
                                                                    </tr>
                                                                </table>
                                                                <div id="divProjectGroupTree" style="display: none;position: absolute;z-index: 999;"></div>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td><b><spring:message code="label.Project.Name"/></b></td>
                                                            <td><form:input path="projectDto.name" size="25" maxlength="50" onkeydown="inhibitPaste(event);" onfocus="inhibitRightClick()" onkeypress="return onKeyDownEnter(event);" onblur="allowRightClick();" cssClass="onlyEnglish textfield" cssStyle="width: 160px;" /></td>
                                                        </tr>

                                                        <tr>
                                                            <td><b><spring:message code="label.Memo"/></b></td>
                                                            <td><form:input path="projectDto.comments" size="25" maxlength="40" onkeydown="inhibitPaste(event);" onfocus="inhibitRightClick()" onkeypress="return onKeyDownEnter(event);" onblur="allowRightClick();" cssClass="textfield" cssStyle="width: 160px;" /></td>
                                                        </tr>
                                                        <tr>
                                                            <td nowrap="nowrap"><b><spring:message code="label.Checker.Group"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0" border="0">
                                                                    <tr>
                                                                        <td><form:select path="projectDto.checkerGroupId" cssStyle="width: 165px" items="${command.checkerGroupItems}" onchange="setEnableBtn(this, 'btnCheckerGroupDesign');"/></td>
                                                                    <c:if test="${command.loginUser.roleAdminOrManager}">
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td>
                                                                            <c:if test="${!empty command.projectDto.checkerGroupId && command.projectDto.checkerGroupId != 0}">
                                                                            <img id="btnCheckerGroupDesign" class="pointer" src="image/modify_pencil.png" onclick="openCheckerGroupDesign(this);"/>
                                                                            </c:if>
                                                                            <c:if test="${empty command.projectDto.checkerGroupId || command.projectDto.checkerGroupId == 0}">
                                                                            <img id="btnCheckerGroupDesign" src="image/modify_pencil_gray.png" onclick="openCheckerGroupDesign(this);"/>
                                                                            </c:if>
                                                                        </td>
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td><a href="checkerGroup.spw" target="_blank"><img src="image/new_nest.png"/></a></td>
                                                                    </c:if>
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td><img id="refreshCheckerGroup" class="pointer" onclick="refreshCheckerGroupItems()" src="image/refresh.gif"/></td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td nowrap="nowrap"><b><spring:message code="label.Extended.Library"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td><form:select path="projectDto.extendedLibraryId" cssStyle="width: 165px" items="${command.extendedLibraryItems}" onchange="setEnableBtn(this, 'btnExtendedLibrary');"/></td>
                                                                    <c:if test="${command.loginUser.roleAdminOrManager}">
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td>
                                                                            <c:if test="${!empty command.projectDto.extendedLibraryId && command.projectDto.extendedLibraryId != 0}">
                                                                            <img id="btnExtendedLibrary" class="pointer" src="image/modify_pencil.png" onclick="goModifyExtendedLibrary(this);"/>
                                                                            </c:if>
                                                                            <c:if test="${empty command.projectDto.extendedLibraryId || command.projectDto.extendedLibraryId == 0}">
                                                                            <img id="btnExtendedLibrary" src="image/modify_pencil_gray.png" onclick="goModifyExtendedLibrary(this);"/>
                                                                            </c:if>
                                                                        </td>
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td><a href="extendedLibrary.spw" target="_blank"><img src="image/new_nest.png"/></a></td>
                                                                    </c:if>
                                                                        <td>&nbsp;&nbsp;</td>
                                                                        <td><img id="refreshExtendedLibrary" class="pointer" onclick="refreshExtendedLibraryItems()" src="image/refresh.gif"/></td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td><b><spring:message code="label.Encoding"/></b></td>
                                                            <td><form:select path="projectDto.encoding" items="${command.encodingItems}" cssStyle="width: 165px" /></td>
                                                        </tr>
                                                        <tr>
                                                            <td><b><spring:message code="label.Max.Scans.to.Keep"/></b></td>
                                                            <td><form:input path="projectDto.maxScans" size="25" maxlength="50" onkeydown="inhibitPaste(event);" onfocus="inhibitRightClick()"
                                                                onkeypress="return onKeyDownEnter(event);" onblur="allowRightClick();" cssClass="textfield onlyEnglish" cssStyle="width: 160px;" /></td>
                                                        </tr>
                                                        <tr>
                                                            <td nowrap="nowrap"><b><spring:message code="label.Duplicated.Defect.Status"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td><form:radiobuttons path="projectDto.defectAnnotationCode" items="${command.defectAnnotationItems}" delimiter="</td><td width='20'>&nbsp;</td><td>"/></td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                        <c:if test="${command.loginUser.roleAdmin}">
                                                        <tr>
                                                            <td><b><spring:message code="label.Manager"/></b></td>
                                                            <td>
                                                                <form:select path="projectDto.manager" cssStyle="width: 165px;" onmousedown="downProjectManager();" onchange="changeProjectManager();">
                                                                <c:forEach items="${command.managerItems}" var="data"><form:option value="${data.key}" label="${data.value.sparrowUserId}" title="${data.value.name}" /></c:forEach>
                                                                </form:select>
                                                            </td>
                                                        </tr>
                                                        </c:if>
                                                        <tr>
                                                            <td><b><spring:message code="label.Project.Share"/></b></td>
                                                            <td>
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td><form:radiobuttons path="projectDto.projectShareCode" items="${command.projectShareItems}"
                                                                                onclick="changeProjectShare();" delimiter="</td><td width='20'>&nbsp;</td><td>"/></td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td colspan="2" style="padding-left: 20px;">
                                                                <table cellpadding="0" cellspacing="0">
                                                                    <tr>
                                                                        <td>
                                                                            <spring:message code="label.Exclude.Group.Sharing"/><br/>
                                                                            <form:select path="" id="excludeUserId" cssStyle="height:208px;width:125px;" multiple="multiple">
                                                                            <c:forEach items="${command.excludeUserIdItems}" var="data"><form:option value="${data.key}" label="${data.value.sparrowUserId}" title="${data.value.userName}" /></c:forEach>
                                                                            </form:select>
                                                                        </td>
                                                                        <td width="20" align="center">
                                                                            <input id="btnArrowRight" type="image" src="image/icon_arrow_right.gif" onclick="moveOptions(this.form.excludeUserId, this.form.includeUserId);return false;"/><br/><br/>
                                                                            <input id="btnArrowLeft" type="image" src="image/icon_arrow_left.gif" onclick="moveOptions(this.form.includeUserId, this.form.excludeUserId);return false;"/>
                                                                        </td>
                                                                        <td>
                                                                            <spring:message code="label.Include.Group.Sharing"/><br/>
                                                                            <form:select path="" id="includeUserId" cssStyle="height:208px;width:125px;" multiple="multiple">
                                                                            <c:forEach items="${command.includeUserIdItems}" var="data"><form:option value="${data.key}" label="${data.value.sparrowUserId}" title="${data.value.userName}" /></c:forEach>
                                                                            </form:select>
                                                                        </td>
                                                                    </tr>
                                                                </table>
                                                            </td>
                                                        </tr>
                                                    </table>
                                                </td>
                                                <td width="30" nowrap="nowrap"> &nbsp; &nbsp; &nbsp; </td>
                                                <td valign="top">
                                                    <table cellpadding="1" cellspacing="0" width="500">
                                                        <tr>
                                                            <td>
                                                                <br/><b><spring:message code="label.Global.Exclude.Path.Lists"/></b>
                                                                <div style="overflow: auto;width: 99%;height: 100px;border: solid 1px #a9a9a9;background:#ffffe0;"><xmp>${command.globalExcludePath}</xmp></div>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>
                                                                <br/><b><spring:message code="label.Exclude.Path.Lists"/></b>
                                                                <form:textarea path="projectDto.excludeFiles" cssStyle="width: 99%;height:91px;" title="e.g)&#013;/test/use/sample.c&#013;*sample.c&#013;c:\test\*&#013;*use/*" htmlEscape="false" />
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>
                                                                <br/><b><spring:message code="label.Global.Exclude.Function.Lists"/></b>
                                                                <div style="overflow: auto;width: 99%;height: 100px;border: solid 1px #a9a9a9;background:#ffffe0"><xmp>${command.globalExcludeFunc}</xmp></div>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>
                                                                <br/><b><spring:message code="label.Exclude.Function.Lists"/></b>
                                                                <form:textarea path="projectDto.excludeFunc" cssStyle="width: 99%;height:91px;"  title="e.g.)&#013;foo&#013;*foo&#013;foo*&#013;*foo*" htmlEscape="false" />
                                                            </td>
                                                        </tr>
                                                    </table>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td colspan="3" align="center">
                                                    <br/>
                                                    <table cellpadding="5" cellspacing="0">
                                                        <tr>
                                                            <td><a href="javascript:addNewProject();"><img src="image/create_btn.png"/></a></td>
                                                            <td><a href="javascript:createAndContinueProject();"><img src="image/createandcontinue_btn.png"/></a></td>
                                                            <td><a href="projectList.spw"><img src="image/cancel_btn.png"/></a></td>
                                                        </tr>
                                                    </table>
                                                </td>
                                            </tr>
                                        </table>
                                    </td>
                                </tr>
                            </table>
                        </td>
                        <td valign="top" id="tdMsg"></td>
                    </tr>
                </table>
            </td>
        </tr>
    </table>
    <jsp:include page="include/footer.jsp"/>
</form:form>


<form method="get">
    Name of new user: <input type="text" name="username">
    Password for new user: <input type="password" name="user_passwd">
    Password for new user: <input type="text" name="user_passwd">
    <input type="submit" name="action" value="Create User">
</form>

<form method="post">
    Name of new user: <input type="text" name="username">
    Password for new user: <input type="password" name="user_passwd">
    Password for new user: <input type="text" name="user_passwd" autocomplete="on">
    <input type="submit" name="action" value="Create User">
</form>

<form method="post">
    Name of new user: <input type="text" name="username">
    Password for new user: <input type="password" name="user_passwd" autocomplete="off">
    Password for new user: <input type="text" name="user_passwd">
    <input type="submit" name="action" value="Create User">
</form>

<form method="post" autocomplete="off">
    Name of new user: <input type="text" name="username">
    Password for new user: <input type="password" name="user_passwd">
    Password for new user: <input type="text" name="user_passwd">
    <input type="submit" name="action" value="Create User">
</form>

<script src="http://www.example.com/js/fancyWidget.js"/>


</body>
</html>
