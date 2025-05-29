// A function to calculate the factorial of a number using recursion
function factorial(n) {
  // Check if the input is a negative number, zero, or a positive integer
  // If negative, return a message indicating factorial is not defined
  if (n < 0) {
    return "Factorial is not defined for negative numbers";
  }
  // If zero, return 1 (0! = 1)
  else if (n === 0) {
    return 1;
  }
  // Else, calculate factorial recursively
  else {
    return n * factorial(n - 1);
  }
}

// Test the factorial function with different inputs
let number = 6;
let result = factorial(number);
console.log(`The factorial of ${number} is ${result}`);

// Test for negative scenario
let numberNegative = -6;
let resultNegative = factorial(numberNegative);
console.log(`The factorial of ${numberNegative} is ${resultNegative}`);

// Test for zero scenario
let numberZero = 0;
let resultZero = factorial(numberZero);
console.log(`The factorial of ${numberZero} is ${resultZero}`);
