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
