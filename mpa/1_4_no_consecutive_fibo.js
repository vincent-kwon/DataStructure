var MAX_LEN = 10;
var total = 0;
var totalLLL = 0;

function calP(num) {
  if (num == 1) {
    return 1;
  }
  if (num == 2) {
    return 0.75;
  }
  return (0.5*calP(num-1) + 0.25*calP(num-2));
}
var prob = 1 - calP(10);

console.log("At least 2 P:" + prob);
