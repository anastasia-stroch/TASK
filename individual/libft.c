#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = (s1) ? strlen(s1) : 0;
    size_t len2 = (s2) ? strlen(s2) : 0;
    int i = 0;
    char c;
    char *str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

    if (!str)
        return NULL;
    if (s1)
        while ((c = *s1++))
            str[i++] = c;
    if (s2)
        while ((c = *s2++))
            str[i++] = c;
    str[i] = 0; // '\0'
    return (str);
}

// int a;
// b = (a = 4);
// if (a)
//     printf("hello");

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

t_list *ft_lstnew(void *content)
{
    t_list *item = malloc(sizeof(t_list));

    if (item)
        item->content = content;
    return item;
}

int word_count(char const *s, char c)
{
    int count = 0;
    int prev = -1;
    int length = 0;
    
    for (int i = 0; s[i] != 0; i++)
    {
        if (s[i] == c)
        {
            if (i - prev > 1)
                count++;
            prev = i;
        }
        ++length;
    }
    if (prev != length - 1)
        count++;
    return count;
}

char **ft_split(char const *s, char c)
{
    size_t length = strlen(s);
    size_t j = word_count(s, c);  

    char **str2 = (char **)malloc(sizeof(char *) * (j + 1));
    size_t prev = 0;
    size_t k = 0;
    
    j = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (s[i] == c)
        {
            if (i != prev)
            { 
                char *str = (char *)malloc(sizeof(char) * (i - prev));
                // strncpy(s + prev, str, i - prev - 1);
                
                k = prev;
                while (s[k] != c)
                {
                    str[k - prev] = s[k];
                    k++;
                }
                str2[j] = str;
                j++;
            }
            prev = i + 1;
        }    
    }
    if (prev < length)
    {
        if (prev - 1 != length)
        {
            char *str1 = (char *)malloc(sizeof(char) * (length - prev));
            k = prev;
            while (k != length)
            {
                str1[k - prev] = s[k];
                k++;
            }
            str2[j] = str1;
        }
    }
    str2[j + 1] = NULL;
    return str2;
}


char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int length = strlen(s);
    char *str = 0;
    int i = 0;

    if ((start < 0 || len <= 0) || start >= length)
    {
        return NULL;
    }
    if (length - 1 - start >= len)
    {
        str = (char *)malloc(sizeof(char) * (len));
        i = start;
        while (i != len + start + 1)
        {
            str[i - start] = s[i];
            i++;
        }
        return str;
    }
    str = (char *)malloc(sizeof(char) * (length - start - 1));
    i = start;
    while (i != length - 1)
    {
        str[i - start] = s[i];
        i++;
    }
    return str;
}


int main()
{
    char const *input_str = "lllftd  ldfhrds ft";
    char l = ' ';
    char **substr = ft_split(input_str, l);
    int i = 0;
    while (substr[i] != NULL) {
        printf("%s", substr[i]);
        free(substr[i]);
        i++;
    }
    return 0;
}

// https://github.com/evgenkarlson/ALL_SCHOOL_42/tree/master/00_Projects__(%D0%9E%D1%81%D0%BD%D0%BE%D0%B2%D0%BD%D0%BE%D0%B5_%D0%9E%D0%B1%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5)/00_Global_(begin_cadet)/01____libft

