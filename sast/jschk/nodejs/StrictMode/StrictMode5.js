'use strict';

const printHelloWorld = () =>{
    console.log('hello World');
}

module.exports = printHelloWorld;

export default function cube(x){
    return x * x * x;
}