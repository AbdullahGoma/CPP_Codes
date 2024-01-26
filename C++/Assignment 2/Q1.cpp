#include <cstdio>
#include <cmath>

int S1(int *arr, int n);
int S2(int *arr, int n);
int S3(int *arr, int n);

int main() {
    printf("Enter array size: ");
    int n; scanf("%d", &n); int data[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", data + i);
    }

    printf("S1 = %d\n", S1(data, n));
    printf("S2 = %d\n", S2(data, n));
    printf("S3 = %d", S3(data, n));

    return 0;
}

int S1(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += abs(arr[i]);
    return sum;
}

int S2(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += pow(arr[i], 2);
    return sqrt(sum);
}

int S3(int *arr, int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) if (largest < arr[i]) largest = arr[i];
    return largest;
}
