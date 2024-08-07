#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void reverse(int *arr, size_t size)
{
    size_t half = (size >> 1);
    int temp = 0;

    for (size_t i = 0; i < half; i++)
    {
        temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[i];
        arr[i] = temp;
    }
}

int *dec2base(int num, size_t base, int *size)
{
    int dec = 0;
    int num1 = num;
    int mult = 1;

    while (num != 0) {
        dec += (num % 10) * mult;
        num /= 10;
        mult *= base;
    }

    int sum1 = dec;
    size_t count = 1;
    while (sum1 / 2 != 0) {
        count++;
        sum1 = sum1 / 2;
    }

    int *arr = malloc(sizeof(int) * count);
    if (!arr)
        return NULL;
    for (int i = 0; i < count - 1; i++) {
        arr[i] = dec % 2;
        dec /= 2;
    }
    arr[count - 1] = dec;
    *size = count;
    reverse(arr, count);

    return arr;
}

void print_arr(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// scope - область видимости
// глобальные - хранятся в секции данных или bss
//    видны внутри текущего модуля
//    существуют до завершения программы

// локальные - хранятся в стеке,
//    видны внутри блока, где объявлены и вложенных
//    существуют до момента выхода из блока

// передача аргументов
// 1. По значению
// 2. По ссылке

int main()
{
    int num;
    size_t h = 6;
    int size;

    scanf("%d", &num);
    int *binary = dec2base(num, h, &size);
    print_arr(binary, size);
    printf("\n");
    free(binary);

    return 0;
}
