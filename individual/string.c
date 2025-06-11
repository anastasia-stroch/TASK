#include <stdio.h>
#include <stdlib.h>

long long strlen(const char *string)
{ 
    long long i = 0;
    
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

long long strlen1(char *string)
{ 
    long long i = 0;
    
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

int is_palindrome(const char *str)
{
    long long len = strlen(str);
    long long i = 0;

    while (i != (len - 1) / 2)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
        i++;
    }
    return i == (len - 1) / 2;
}

int is_palindrome_ptr(const char *ptr)
{
    const char *right = ptr + strlen(ptr) - 1;
    const char *left = ptr;
    
    while (left < right && *left == *right)
    {
        ++left;
        --right;
    }
    return left >= right;
}

int is_letter(char ch)
{
    return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

size_t word_count(const char *s)
{
    size_t count = 0;
    const char *walker = s;
    
    while (*walker != '\0')
    {
        if (is_letter(*walker) && !is_letter(*(walker + 1)))
        {
            count++;
        }
        walker++;
    }
    return count;
}

void reverse_string(char *s)
{
    char *right = s + strlen(s) - 1;
    char *left = s;
    char swap;
    
    while (right > left)
    {
        swap = *right;
        *right = *left;
        *left = swap;
        --right;
        ++left;
    }
}
