#include <stdio.h>
#include <cstdlib>

int main(){
    int *ptr = (int *) 1000;
    ptr ++;
    printf("%d",ptr);
    
}