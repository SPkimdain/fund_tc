import React from 'react';

interface SummaryContainerProps {
  property: string;
}

class SummaryContainer extends React.Component {
  render1(temp: string) {
    const test = temp;
    return (
      <div>
        Content：
        <a target="_blank" href={test}>     // @violation
          https://www.github.com
        </a>
      </div>
    );
  }

  render2() {
    const test = 'www.github.com';
    return (
      <div>
        Content：
        <a target="_blank" href={test}>
          https://www.github.com
        </a>
      </div>
    );
  }

  render3() {
    const test = 'www.github.com';
    const href = this.props.property;
    return (
      <div>
        Content：
        <a target="_blank" href={test}>
          https://www.github.com
        </a>
      </div>
    );
  }

  render4() {
    const test = 'www.github.com';
    return (
      <div>
        var href = param.property;
        <a target="_blank" href={test}>
          https://www.github.com
        </a>
      </div>
    );
  }

  render5() {
    const test = 'www.github.com';
    const href = this.props.property;
    return (
      <div>
        Content：
        <a target="_blank" hhhh={href}>
          https://www.github.com
        </a>
      </div>
    );
  }

  render6() {
    const a = document.getElementById('a0');
    if (a) {
      a.href = 'http://www.google.com';
    }
    return (
      <div>
        Content：
        <a target="_blank" href={'hrefdad'}>
          https://www.github.com
        </a>
      </div>
    );
  }
}

function test(param: SummaryContainerProps) {
  const href = param.property;
  return href;
}
