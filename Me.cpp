#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::ios;
using std::string;
using std::fstream;
using std::endl;

void print()
    {
        string text;
        string word = NULL;
        fstream ifile,ofile;
        ifile.open("input.txt", ios::in);
        ofile.open("output.txt", ios::out | ios::trunc);

        while (!ifile.eof())
        {
            int i;

            getline(ifile,text);
            
            if(text.length() == 0 && (text != word)){
                continue;
            }else{
                for(i = 0;text[i] == ' ';i++){
                    continue;
                }

                for(int j = i;j < text.length();j++){
                    if(text[j] != '\n'){
                        ofile << text[j];
                        if(j == text.length() - 1){
                            ofile << '\n';
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
            
            
        }
        ifile.close();
        ofile.close();
    }

int main(){
    print();
    return 0;
}