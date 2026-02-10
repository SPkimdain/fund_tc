import React from 'react'
import ReactDOM from 'react-dom'

interface ValueInfo {
    name: string;
    age: number;
    location: string;
}

const value: ValueInfo = {
    name: 'Aidan Lee',
    age: 36,
    location: 'Seoul'
}

//case 1
const App = () => (
    <div>
        {JSON.stringify(value)} // @violation
    </div>
)

//case 2
const App2 = () => (
    <pre>
        <code>
            {JSON.stringify(value, null, 0)} // @violation
        </code>
    </pre>
)

function replacer(key: string, value: string) {
    if(typeof value === "string")
        return undefined;
    return value;
}

//safe case
const App3 = () => {
    <pre>
        <code>
            {JSON.stringify(value, replacer)} //It's ok.
        </code>
    </pre>
}
