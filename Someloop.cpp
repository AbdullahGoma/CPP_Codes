#include <iostream>
#include <string>

using namespace std;

int main(){

    string dna = "CTGCCTGCATGATCGTA";
    int pos = dna.find("TG");
    int count = 0;
    while (pos >= 0) {
        
        count = count + 1;
        pos = dna.find("TG",pos);
        cout << count << "         " << pos << endl;

    }
    
}