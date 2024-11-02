#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// https://ejudge.algocode.ru/cgi-bin/new-client?SID=b8190a55fb92c6a7&action=139&prob_id=9

void reverse(char *arr, int size)
{
    int half = (size >> 1);
    int temp = 0;

    for (int i = 0; i < half; i++)
    {
        temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

int main() 
{
    const int cnt_len = 26;
    int cnt[cnt_len];
    char ch;
    int size_str = 0;
    int str_length = 0;
    
    // memset(cnt, 0, cnt_len * sizeof(cnt[0]));
    bzero(cnt, cnt_len * sizeof(cnt[0]));

    scanf("%d", &str_length);
    scanf("%c", &ch);
    
    for (int i = 0; i < str_length; i++)
    {
        scanf("%c", &ch);
        ++cnt[ch - 'A'];
    }
    for (int i = 0; i < cnt_len; i++)
    {
        size_str += cnt[i] / 2;
    }
    char *str = (char *)malloc(sizeof(char) * (size_str + 1));
    str[size_str] = '\0';
    int indx_str = 0;
    for (int i = 0; i < cnt_len; i++)
    {
        for (int j = 0; cnt[i] >= 2; ++j)
        {
            str[indx_str + j] = 'A' + i;
            indx_str += 1;
            cnt[i] = cnt[i] - 2;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", cnt[i]);
    }
    printf("\n");
    char letter = 'a';
    printf("%s", str);
    if (letter != 'a')
    {
        printf("%c", letter);
    }
    reverse(str,size_str);
    printf("%s", str);
    free(str);
    return 0;
}








// #include <stdlib.h>
// #include <string.h>

// void input(size_t *alpha, const size_t alpha_len)
// {
//     char ch;
//     size_t str_len;

//     bzero(alpha, alpha_len * sizeof(alpha[0]));
//     scanf("%d", &str_len);
//     scanf("%c", &ch); // for '\n' if need

//     for (int i = 0; i < str_len; i++)
//     {
//         scanf("%c", &ch);
//         ++alpha[ch - 'A'];
//     }
// }

// int main()
// {
//     const size_t alpha_len = 26;
//     size_t alpha[alpha_len];
//     char *str;
//     size_t str_len = 0;
//     int is_odd = -1;

//     input(alpha, alpha_len);

//     for (size_t i = 0; i < alpha_len; ++i)
//     {
//         str_len += (alpha[i] >> 1);
//         if (alpha[alpha_len - 1 - i] & 1)
//             is_odd = alpha_len - 1 - i;
//     }
//     str_len = (str_len >> 1) + (is_odd != -1);
//     str = malloc(sizeof(char) * str_len);

//     for (size_t i = 0, k = 0; i < alpha_len; ++i)
//     {
//         while (alpha[i] > 1)
//         {
//             str[k] = 'A' + alpha[i];
//             str[str_len - 1 - k] = 'A' + alpha[i];
//             alpha[i] -= 2;
//             ++k;
//         }
//     }

//     if (is_odd != -1)
//         str[str_len << 1] = alpha[is_odd] + 'A';

//     printf("%s\n", str);
//     free(str);
//     return 0;
// }
