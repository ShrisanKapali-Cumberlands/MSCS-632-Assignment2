# A simple Python program to calculate the factorial of a number using recursion.
def factorial(n):
    # If the number is negative, return an error message
    if n < 0:
        return "Factorial is not defined for negative numbers"
    # Base case: factorial of 0 is 1
    elif n == 0:
        return 1
    # Recursive case: n! = n * (n-1)!
    else:
        return n * factorial(n - 1)


# Demonstration of the factorial function
number = 6
result = factorial(number)
print(f"The factorial of {number} is {result}")

# Providing additional test cases for negative
number_negative = -6
result_negative = factorial(number_negative)
print(f"The factorial of {number_negative} is {result_negative}")

# Providing a test case for zero
number_zero = 0
result_zero = factorial(number_zero)
print(f"The factorial of {number_zero} is {result_zero}")
