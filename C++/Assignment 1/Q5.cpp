#include <cstdio>

#define SEC_PER_HR 3600
#define SEC_PER_MIN 60

int main(){
    int input, hours, minutes, seconds;

    printf("Enter number of seconds: "); scanf("%d", &input);

    hours = input / SEC_PER_HR;
    minutes = input % SEC_PER_HR / SEC_PER_MIN;
    seconds = input % SEC_PER_HR % SEC_PER_MIN;

    printf("That's equivalent to: %d hours, %d minutes, %d seconds.", hours, minutes, seconds);

    return 0;
}
