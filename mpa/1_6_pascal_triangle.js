function printLine(arr, floor) {

  console.log("enter floor" + floor);
  if (floor == 1) {
    arr.push(1);
    var eObj = {};
    eObj.arr = arr;
    eObj.ind = floor -1;  
    return eObj;
  }
  var obj =  printLine(arr, floor-1);
  var prevStart = obj.ind;
  var prevEnd = prevStart + (floor-1) - 1;
  var curStart = prevEnd + 1;
  var curEnd = curStart + floor - 1;
  var val1;
  var val2;
  var tmp = prevStart;

  for (var i = curStart; i <= curEnd; i++) {
    if ((tmp-1) < prevStart || tmp > prevEnd) {
      arr.push(1);
    } else {
      val1 = arr[tmp-1];
      val2 = arr[tmp];
      arr.push(val1 + val2);
    }
    tmp++;
  }

  var eObj = {};
  eObj.arr = arr;
  eObj.ind = curStart;
  return eObj;
}

var arr = [];
var floors = 4;

var result = printLine(arr, floors);

var resA = result.arr;

for (var t in resA) {
  console.log(resA[t]);
}
