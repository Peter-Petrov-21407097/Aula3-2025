//
// Created by Peter P on 23/09/2025.
//

#include <stdio.h>
int main()
{

    int A[100][4];
    int i, j, n, total = 0, index, temp;
    float media_te, media_tat;
    printf("Indica o numero de processos ");
    scanf("%d", &n);
    printf("Indica o tempo de espera:\n");
    // Somos nos que indicamos o numero de processos e o tempo de espera
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }

    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    A[0][2] = 0;
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    media_te= (float)total / n;
    total = 0;
    printf("P     BT     WT     TAT\n");

    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        printf("P%d     %d     %d      %d\n", A[i][0],
               A[i][1], A[i][2], A[i][3]);
    }
    media_tat = (float)total / n;
    printf("Tempo medio de espera= %f\n", media_wt);
    printf("Tempo medio de ida e volta %f", media_tat);
}