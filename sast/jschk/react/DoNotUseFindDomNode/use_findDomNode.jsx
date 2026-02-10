import React from 'react';
import ReactDOM from 'react-dom';

class SummaryContainer extends React.Component {

    // Function to get element from findDOMNode()
    find() {
        var node = document.getElementById("node");
        var a = ReactDOM.findDOMNode(node);  // @violation
        console.log(a);
        a.style.color = 'green';
        a.style.fontSize = "x-large";
    }
}

// Exporting your Default App Component
export default SummaryContainer;
