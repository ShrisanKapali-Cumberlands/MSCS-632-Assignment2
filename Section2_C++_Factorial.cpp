// C++ Code to determine the factorial of a number
#include <iostream>

// Function declaration
long long factorial(int n);

int main()
{
    // Example usage of the factorial function
    int number = 6;
    long long result = factorial(number);
    std::cout << "The factorial of " << number << " is " << result << std::endl;

    // Testing with a negative number
    int numberNegative = -6;
    long long resultNegative = factorial(numberNegative);
    std::cout << "The factorial of " << numberNegative << " is " << resultNegative << std::endl;

    // Testing with zero
    int numberZero = 0;
    long long resultZero = factorial(numberZero);
    std::cout << "The factorial of " << numberZero << " is " << resultZero << std::endl;

    return 0;
}

// Defining the factorial function
long long factorial(int n)
{
    // Handle negative input gracefully
    if (n < 0)
    {
        return 0;
    }
    // If the number is 0, return 1 (0! = 1)
    else if (n == 0)
    {
        return 1;
    }
    // For all other positive integers, calculate factorial recursively
    else
    {
        return (long long)n * factorial(n - 1);
    }
}