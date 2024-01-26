#include <cstdio>

int main(){
    int n, average;

    printf("Enter number of students: "); scanf("%d", &n); int data[n][5];

    for (int i = 0; i < n; i++) {
    printf("Enter student ID followed by 4 marks of his: ");

    scanf("%d %d %d %d %d", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &data[i][4]);
    }

    printf("The average marks for each student are: \nID | AVERAGE | GRAPH\n");

    for (int i = 0; i < n; i++){
    average = (data[i][1] + data[i][2] + data[i][3] + data[i][4]) / 4;

    printf("%d %d ", data[i][0], average);

    for (int j = 0; j < average / 2; j++){printf("*");} printf("\n");
    }

    return 0;
}
