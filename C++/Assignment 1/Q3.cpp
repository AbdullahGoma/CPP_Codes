#include <cstdio>
#include <cmath>

int main(){
    printf("Pythagorean triples in range 1 to 50:\n");
    for (int x = 1; x <= 50; x++){
        for (int y = 1; y <= 50; y++){
            for (int z = 1; z <= 50; z++){
                (x < y) && (y < z) && (pow(x, 2) + pow(y, 2) == pow(z, 2)) ? printf("(%d, %d, %d)\n", x, y, z) : 0;
            }
        }
    }
    return 0;
}
