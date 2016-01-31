var N  = 10;

var i, j, k, x=0;

for (i = 0; i < N ; i++) {
  for (j = i; j < N; j++) {
    for (k = j ; k < N; k++) {
      x++;
    }
  }
}

console.log(x);
