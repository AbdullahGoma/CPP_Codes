#include <cstdio>
#include <algorithm>

using std::sort;

int main() {
    printf("Enter array #1 size: ");
    int n1; scanf("%d", &n1); int data1[n1];

    for (int i = 0; i < n1; i++) {
        printf("Enter array #1 element %d: ", i);
        scanf("%d", data1 + i);
    }

    printf("\nEnter array #2 size: ");
    int n2; scanf("%d", &n2); int data2[n2];

    for (int i = 0; i < n2; i++) {
        printf("Enter array #2 element %d: ", i);
        scanf("%d", data2 + i);
    }

    if (n1 != n2) printf("Array #1 is not equal to array #2");
    else {
        sort(data1, data1 + n1);
        sort(data2, data2 + n2);

        for (int i = 0; i < n1; i++) {
            if (data1[i] != data2[i]) {
                printf("Array #1 is not equal to array #2");
                return 0;
            }
        }

        printf("\nArray #1 is equal to array #2\n");
    }

    return 0;
}
