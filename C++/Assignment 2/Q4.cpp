#include <cstdio>

int main() {
    printf("Enter upper bound: ");
    int n; scanf("%d", &n); int numbers[n - 1];

    for (int i = 2; i <= n; i++) numbers[i - 2] = i;

    for (int i = 0; i < n - 1; i++) {
        if (numbers[i] == -1) continue;

        for (int j = i + 1; j < n - 1; j++) if (numbers[j] % numbers[i] == 0) numbers[j] = -1;
    }

    printf("\nPrime numbers from 0 to %d:\n", n);

    for (int i = 0; i < n - 1; i++) if (numbers[i] != -1) printf("%d\n", numbers[i]);

    return 0;
}
