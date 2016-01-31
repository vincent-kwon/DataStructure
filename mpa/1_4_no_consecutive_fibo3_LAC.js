var MAX_LEN = 10;
var total = 0;
var totalLLL = 0;

function calP(num) {
  if (num == 3) {
    return (26/27);
  }
  if (num == 2) {
    return 1;
  }
  if (num == 1) {
    return 1;
  }
  return ((1/3)*calP(num-1) +
          (1/3)*calP(num-1) +
          (1/3)*(1/3)*(1/3)*calP(num-3) +
          (1/3)*(1/3)*(1/3)*calP(num-3) +
          (1/3)*(1/3)*calP(num-2) +
          (1/3)*(1/3)*calP(num-2));
}
var prob = 1 - calP(10);

console.log("At least 3 P:" + prob);
