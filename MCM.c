#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n){
    int m[n][n];
    for (int i = 1; i < n; i++){
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++){
        for (int i = 1; i < n - L + 1; i++){
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++){
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main(){
    int num;
    printf("Enter the number of dimensions : ");
    scanf("%d", &num);
    int p[num];
    printf("Enter the dimensions : ");
    for(int i=0; i<num; i++){
        scanf("%d", &p[i]);
    }
    int n = sizeof(p) / sizeof(p[0]);
    printf("Minimum number of multiplications is %d ", matrixChainOrder(p, n));
    return 0;
}