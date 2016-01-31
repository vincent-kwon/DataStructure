// input n bit

function gray(n, str, reverse) {
  //console.log(n + " str " + str);

  if (n == 0) {
    console.log(str);
    return;
  }

  if (reverse) {
    gray(n-1, "1" + str, true);
    gray(n-1, "0" + str, false);
  } 
  else {
    gray(n-1, "0" + str, false);
    gray(n-1, "1" + str, true);
  }
}

gray(4, "", false);
