
function partition2(n) {
  var count = 0;
  var i = 0;

  for (i = 1; i <= n-1 ; i++) {
    console.log("start:" + i + " remain " + (n-i) + " ");
    count += partition2(n-i);
  }

  console.log("n " + n);
  return count + 1;
}

console.log("starting");

console.log(partition2(3));

