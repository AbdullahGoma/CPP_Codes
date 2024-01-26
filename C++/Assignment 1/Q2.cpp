#include <cstdio>

int main(){
    int number, sum = 0;

    printf("Enter a number: "); scanf("%d", &number);

    for (int i = 1; i < number; i++){
        (number % i == 0) ? (sum += i) : 0;
    }

    printf("This number is %s.", (sum == number) ? "perfect" : (sum > number) ? "abundant" : "deficient");

    return 0;
}

