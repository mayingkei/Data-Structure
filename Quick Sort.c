#include <stdio.h>
#include <stdlib.h>

void Read(int* num, int N)
{
    printf("Input all strings: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
}

void PrintNum(int* num, int N, int cnt)
{
    printf("Final result: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
    printf("\nCalled times: %d\n", cnt);
}

int quickSort(int* num, int start, int end);

int main()
{
    int N;
    printf("Enter how many strings: ");
    scanf("%d", &N);
    int* num = (int*)malloc(sizeof(int) * N);

    Read(num, N);
    int call_cnt = quickSort(num, 0, N - 1);
    PrintNum(num, N, call_cnt);

    return 0;
}

// Please finish this function implementation.
int quickSort(int* num, int start, int end)
{
    static int counter = 0;
    counter++;
    
    if (end - start + 1 > 1) {
        int lh = start + 1, rh = end, pivot = num[start], temp;
   
        while (lh != rh) {
            while (lh < rh && num[rh] >= pivot)
                rh--;
            while (lh < rh && num[lh] < pivot)
                lh++;

            if (lh != rh) {
                temp = num[lh];
                num[lh] = num[rh];
                num[rh] = temp;
            }
        }

        if (num[lh] >= pivot)
            lh = start;

        else {
            num[start] = num[lh];
            num[lh] = pivot;
        }

        quickSort(num, start, lh-1);
        quickSort(num, lh + 1, end);
    }

    return counter;
}
