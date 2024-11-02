#include <stdbool.h>

// https://leetcode.com/problems/palindrome-number/description/
bool isPalindrome(int number) 
{
    long long number_copy = number;
    long long rev_number = 0;

    if (number < 0)
        return 0;
    while (number_copy != 0)
    {
        rev_number = rev_number * 10 + number_copy % 10;
        number_copy /= 10;
    }
    return rev_number == number;
}
