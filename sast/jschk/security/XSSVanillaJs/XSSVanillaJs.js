var xssFilters = require('xss-filters');
function Click(){
    const query = document.getElementById("profile_url").value;
    document.write(query);  // @violation
}

function Click(){
    const query = document.getElementById("profile_url").value;
    document.write(decodeURI(encodeURIComponent(query)));
}
function Click(){
    const query = document.getElementById("profile_url").value;
    document.write(xssFilters.inHTMLData(query));
}