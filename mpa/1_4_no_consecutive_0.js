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
    if (str.indexOf("LL") >= 0 && str.indexOf("LL") < strLen) {
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
console.log("LL: " + totalLLL);
var p = totalLLL/total; 
console.log("A: " + p);
