#include <iostream>
#include <string>
using namespace std;

struct student{
    string name;
    float marks[4];
    float average;
    char grade;
};

float grade(float avg){
    if(avg > 100 or avg <0){
        cout << "Not valid" << endl;
    }else{
        if (avg >= 90){
                return 'A';
            }else  if (avg >= 80){
                return 'B';
            }else  if (avg >= 70){
                return 'C';
            }else if (avg >= 60){
                return 'D';
            }else{
                return 'F';
            }
    }
}

int sum (float a[],int n)
{
    int s = 0;
    for (int i = 0;i < n; i++)
    {
        s += a[i];
    }
    return s;
}

void AddStudents(Students Addstud,n){
    for(int i = 0;i < n;i++){
        string name;
        int numberOfmarks;
        cout << "Enter name of Studnet : "<<endl;
        cin >> AddStud[i].name;
        cout << "Enter number of marks :"<<endl;
        cin >> numberOfmarks;
        for(int j = 0;j < numberOfmarks;j++){
            cout < <"Enter " << j << " mark : " << endl;
            cin >> AddStud[i].marks[j];
        }
        AddStud[i].average = sum(AddStud[i].marks,numberOfmarks)/numberOfmarks;
        AddStud[i].grade = grade(AddStud[i].average);
    }
}

int search(student searchstud[],n,string name){
    for(int i = 0;i < n;i++){
        if(searchstud[i].name == name){
            return i;
        }
    }
    return -1;
}


int main(){

    int n,x;
    int num;
    string name;
    student stud;
    student slist[10];
    while(true)
    {
        cout << "Enter 0 for exit : " << endl;
        cout << "Enter 1 for add new students : " << endl;
        cout << "Enter 2 for modify the data : " << endl;
        cout << "Enter 3 for add one student : "<<endl;
        cout << "Enter 4 for delete student : " << endl;
        cout << "Enter 5 for print info for all students : " << endl;
        cout << "Enter 6 for print info for one student : " << endl;
        cin >> num;

        if(num == 0){
            break;
        }else if(num == 1){

            cout << "Enter number of students : ";
            cin >> n;
            AddStudents(slist,n);
        }else if(num == 2){
            cout << "Enter any name for modify : " << endl;
            cin >> name;
            x = search(slist,n,name);
            modify_S(slist,x);
        }else if(num == 3){
            Addone(slist,n);
        }
        else if(num == 4){
            cout << "Enter name you want searc for it :" << endl;
            cin >> name;
            x = search(slist,n,name);
            Delete(slist,x,n);
        }else if(num == 5){
            printStud(slist,n);
        }else if (num == 6)
        {
            cout << "Enter name of Student : " << endl;
            cin >> name;
            x = search(slist,n,name);
            information(slist,x);
        }
        else{
            cout << "You entered an error text." << endl;
        }
    }
    return 0;    
}