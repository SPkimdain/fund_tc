import React from 'react';
class SummaryContainer extends React.Component {

    render1(temp) {
		const test = temp;
        return (
            <div>Content：
                <a target="_blank" href={test}>     // @violation
                    https://www.github.com
                </a>
            </div>
        );
    }

    render2() {
		const test = "www.github.com";
        return (
            <div>Content：
                <a target="_blank" href={test}>
                    https://www.github.com
                </a>
            </div>
        );
    }

    render3() {
        const test = "www.github.com";
        var href = param.property;
        return (
            <div>Content：
                <a target="_blank" href={test}>
                    https://www.github.com
                </a>
            </div>
        );
    }

    render4() {
        const test = "www.github.com";
        return (
            <div>var href = param.property;
                <a target="_blank" href={test}>
                    https://www.github.com
                </a>
            </div>
        );
    }

    render5() {
        const test = "www.github.com";
        var href = param.property;
        return (
            <div>Content：
                <a target="_blank" hhhh={href}>
                    https://www.github.com
                </a>
            </div>
        );
    }

    render6() {
        var a = document.getElementById('a0');
        if (a) {
            a.href = "http://www.google.com";
        }
        return (
            <div>Content：
                <a target="_blank" href={"hrefdad"}>
                    https://www.github.com
                </a>
            </div>
        );
    }
}
function test(param) {
    var href = param.property;
    return href;
}
