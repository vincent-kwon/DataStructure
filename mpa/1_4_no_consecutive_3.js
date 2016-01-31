var MAX_LEN = 10;
var total = 0;
var totalLLL = 0;

function culCheck(str) {
  var strLen = str.length;

  if (strLen > MAX_LEN) {
    return;
  } 
  else if (strLen == MAX_LEN) {
    console.log(str);
    total++;
    if (str.indexOf("LLL") >= 0 && str.indexOf("LLL") < strLen) {
      totalLLL++;
      console.log("\tYes");
    }
    return;
  }
  else {
    //culCheck(str+"N");
    culCheck(str+"L");
    culCheck(str+"A");
  }
}

culCheck("");
console.log("total: " + total);
console.log("LLL: " + totalLLL);
var p = totalLLL/total; 
console.log("A: " + p);
