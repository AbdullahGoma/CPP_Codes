//Magic Square "Odd"
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x ,int y)
{
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main(){

    int size;
    cout << "Enter size of odd magic square:" << endl;
    cin >> size;
    int row ,col ,value;
    row = 1;
    col = (size+1) / 2;
    value = 1;
    do{
        gotoxy(col*5,row);
        printf("%5d",value);
        delay(1);
        if (value % size == 0)
        {
            row++;
        }else
        {
            row--;
            col--;
        }
        if (row == 0) row = size;
        if (col == 0) col = size;
        value++;
    }while(value <= size*size);

    return 0;
}



int size;

// size = 3;

// int row ,col ,value;

// row = 1;
// col = (size+1) / 2;

// for(value = 1; value <= size * size; value++){
//     Console.SetCursorPosition(row, col);
//     Console.WriteLine(value);
//     if(value % size == 0) {
//         row++;
//         if(row > size) row = 1;
//     } else {
//         row--;
//         if(row < 1) row = size;
//         col--;
//         if(col < 1)  col = size;
//     }
// }

