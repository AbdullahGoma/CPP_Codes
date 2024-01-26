#include <cstdio>

int main() {
    printf("Enter dimension: ");
    int n; scanf("%d", &n); float arr1[n][n], arr2[n][n], sum[n][n], product[n][n];

    printf("| Array 1 |\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%f", &(arr1[i][j]));
        }
    }

    printf("| Array 2 |\n");;
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%f", &(arr2[i][j]));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            product[i][j] = 0;
            for (int k = 0; k < n; k++) product[i][j] += arr1[i][k] * arr2[k][j];
        }
    }

    printf("\n| Sum |\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++) printf("%.2f ", sum[i][j]);
        printf("\n");
    }

    printf("\n| Product |\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++) printf("%.2f ", product[i][j]);
        printf("\n");
    }

    return 0;
}
