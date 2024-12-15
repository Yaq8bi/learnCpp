#include <iostream>
using namespace std;

int main(void){

    int theArray[3];
    
    for (int i = 0; i<3; i++){
        theArray[i] = (i + 1);
    }

    cout << theArray;
    
} 