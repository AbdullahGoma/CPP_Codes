#include <cstdio>
#include <cmath>

int main(){
    float number, approx;

    printf("Enter a number: "); scanf("%f", &number); approx = number / 2;

    for (int i = 0; i < 6; i++){
        approx = (approx + number / approx) / 2;
    }

    printf("Sqrt Approx: %f\n", approx);
    printf("Sqrt Actual: %f\n", sqrt(number));

    return 0;
}
