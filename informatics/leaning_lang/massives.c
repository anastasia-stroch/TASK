#include <stdio.h>

#define N 100

// https://informatics.msk.ru/mod/statements/view.php?id=208#1
int main()
{
    int arr[N];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i += 2)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

