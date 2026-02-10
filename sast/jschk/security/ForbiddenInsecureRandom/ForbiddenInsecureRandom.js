function getRandomURL (baseURL){
  var randomNumber = Math.random(); //@violation
  var URL = baseURL + randNum + ".spw";
  return URL;
}

let dan_randStr = "";
for (let i = 0; i < lmt; i++) {
  dan_randStr += String(Math.floor(Math.random() * 10)); // @violation
}

const crypto = require("crypto");

const array = new Uint32Array(1);
const tmp = crypto.getRandomValues(array);  /* SAFE */
let result = "";
for (let i = 0; i < tmp.length; i++) {
  result += String(array[i]);
}
const safe_randStr = String(result).substring(0, 6);