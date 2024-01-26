#include <cstdio>
#include <tuple>
#include <algorithm>

using std::tuple;
using std::tie;
using std::swap;
using std::sort;

tuple<int *, int> createArray();
tuple<int *, int> reduceArray(int *, int);
tuple<int *, int> mergeArray(int *, int*, int, int);
void printArray(int*, int);

int main() {
    auto [a, na] = createArray();
    auto [b, nb] = createArray();

    tie(a, na) = reduceArray(a, na);
    tie(b, nb) = reduceArray(b, nb);

    printf("\n- Array A -");
    printArray(a, na);
    printf("\n- Array B -");
    printArray(b, nb);

    auto [c, nc] = mergeArray(a, b, na, nb);
    tie(c, nc) = reduceArray(c, nc);

    printf("\n- Array C -");
    printArray(c, nc);

    delete [] a; delete [] b; delete [] c;

    return 0;
}

tuple<int *, int> createArray() {
    printf("Enter array size: ");
    int n; scanf_s("%d", &n);

    int *arr = new int [n];

    for (int i = 0; i < n; i++) {
        printf("Enter entry no. %d: ", i);
        scanf_s("%d", arr + i);
    }

    printf("\n");

    return {arr, n};
}

tuple<int *, int> reduceArray(int arr[], int n){
    int k = n;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] == arr[j]) goto checkNext1;
        }
        continue;

        checkNext1:
            k--;
    }

    int *reducedArr = new int [k];

    for (int i = 0, l = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] == arr[j]) goto checkNext2;
        }
        reducedArr[l] = arr[i]; l++;

        checkNext2:
            continue;
    }

    delete [] arr;

    sort(reducedArr, reducedArr + k);

    return {reducedArr, k};
}

tuple<int *, int> mergeArray(int arr1[], int arr2[], int n1, int n2) {
    int *arr3 = new int [n1 + n2];

    for (int i = 0; i < (n1 + n2); i++) {
        if (i < n1) {
            arr3[i] = arr1[i];
        } else {
            arr3[i] = arr2[i % n1];
        }
    }

    return {arr3, n1 + n2};
}

void printArray(int arr[], int n) {
    printf("\nListing array entries:\n");
    for (int i = 0; i < n; i++) printf("Entry #%d: %d\n", i, arr[i]);
}
