#include <cstdio>

int main() {
    printf("Enter number of students: ");
    int n; scanf("%d", &n);
    int ids[n], marks[n], grades[n];

    for (int i = 0; i < n; i++) {
        printf("Enter student ID: ");
        scanf("%d", ids + i);

        printf("Enter student mark: ");
        scanf("%d", marks + i);
    }

    for (int i = 0; i < n; i++) {
        switch (marks[i] / 10) {
            case 10:
            case 9:
                grades[i] = 'A';
                break;

            case 8:
                grades[i] = 'B';
                break;

            case 7:
                grades[i] = 'C';
                break;

            case 6:
                grades[i] = 'D';
                break;

            default:
                grades[i] = 'F';
        }

    }

    for (int i = 'A'; i < 'G'; i++) {
        if (i == 'E') continue;

        printf("\nStudent ID's with %c's:\n", i);

        for (int j = 0, k = 1; j < n; j++) {
            if (grades[j] == i) printf("(%d.) %d\n", k, ids[j]);
            k++;
        }
    }

    return 0;
}

