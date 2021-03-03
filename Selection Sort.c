#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Read(char A[][5], int N)
{
    printf("Input all strings: ");
    for (int i = 0; i < N; i++) {
        scanf("%s", A[i]);
        A[i][4] = '\0';
    }
}

void PrintA(char A[][5], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%s ", A[i]);
    }
    printf("\n");
}

void PrintA_in_sort(char A[][5], int N, int round)
{
    printf("After Round-%d: ", round);
    for (int i = 0; i < N; i++) {
        printf("%s ", A[i]);
    }
    printf("\n");
}

void Selection_sort(char A[][5], int N);

int main()
{
    int N;
    printf("Enter how many strings: ");
    scanf("%d", &N);
    char A[100][5]; // A[i][4] stores '\0' to be the end of one string.

    Read(A, N);
    printf("Initial Array: ");
    PrintA(A, N);

    Selection_sort(A, N);
    return 0;
}

// Please finish this function implementation.
void Selection_sort(char A[][5], int N)
{

    for (int i = 0; i < N - 1; i++) {
        char temp[5];
        int k = i + 1;
        strcpy(temp, A[k]);

        for (int j = i + 1; j < N; j++) {
            for (int count = 0; count < 5; count++) {
                if (A[j][count] < temp[count]) {
                    k = j;
                    strcpy(temp, A[k]);
                    break;
                }
                if (A[j][count] > A[i][count])
                    break;
            }
        }
        for (int count = 0; count < 5; count++) {
            if (A[k][count] < A[i][count]) {
                strcpy(A[k], A[i]);
                strcpy(A[i], temp);
                break;
            }
            if (A[k][count] > A[i][count])
                break;
        }

        PrintA_in_sort(A, N, i);
    }
}