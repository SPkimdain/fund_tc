function foo() {
	with(document.testForm) {
	//todo html정보 읽어서 , form context에서 작동하는지 확인
		action = "./test.jsp";
		method = "post";
		submit(); //@violation
	}
}

// stackoverflow example code
// http://stackoverflow.com/questions/6812765/how-to-demonstrate-a-csrf-attack
function post_to_url(path, params, method) {
    method = method | "post"; // Set method to post by default, if not specified.

    // for test todo: 위에거 지원해야함
    method = "post";
    // The rest of this code assumes you are not using a library.
    // It can be made less wordy if you use one.
    var form = document.createElement("form");
    form.setAttribute("method", method);
    form.setAttribute("action", path);

    for(var key in params) {
        var hiddenField = document.createElement("input");
        hiddenField.setAttribute("type", "hidden");
        hiddenField.setAttribute("name", key);
        hiddenField.setAttribute("value", params[key]);

        form.appendChild(hiddenField);
    }

    document.body.appendChild(form);
    form.submit(); //@violation
}
