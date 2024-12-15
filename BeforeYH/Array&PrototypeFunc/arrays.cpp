/*
#include <iostream>

using namespace std;

    const int N = 3;
    //Constant

    //Prototype
    float average(int length, int array[]);

int main(){

    int scores[N];
    for (int i = 0; i<N; i++){
        cout << "What is your score?: ";
        cin >> scores[i];
    }

    //print average
    cout << "Average: " << average(N, scores);
}

float average(int length, int array[])
//In C++ you dont need to give num for an array that is a parameter.
{
    int sum = 0; //initialized to 0
    for(int i = 0; i < length; i++){
        //i goes up until its 1 below length.
        sum += array[i];
        //each num from the array gets added to one another
    }
    return sum / (float) length;
    //bu kucuk(main'nin disinda) function sunu return ediyor(main'e) => sum(array icindeki numaralarin toplami) /(bolu) length(array icinde bulnan kutular/variable'ar).
}
*/

//The header file
#include <iostream>

using namespace std;

    //The declaration of prototype function(telling pc about its existence)
    float average(int L, int scores[]);
//main function
    int main(){
        int L = 0;//int to store the user input.
        
        // character out
        cout << "How many exams?: " << endl;
        //character in


        //input then save to L.
        cin >> L; 

        //telling the PC to create an array with the amount of "L" which is given by the user.
         int scores[L];

        // as long as less then L.
        for (int i = 0; i<L; i++ ){
            cout << "What did you score on exam?: \n" << i+1 << endl;
            
            cin >> scores[i];//Store to the amount of L
        }

        cout << "The average is: " << average(L, scores) << endl;

        
    }

//Define the function that i had declared earlier.
//In C++ you dont need to give num for an array that is a parameter.
    float average(int L, int scores[]){

        int sum;
        //initialized to 0
        for(int i = 0; i<L; i++){
            //i goes up until its 1 below length.
            sum += scores[i];
             //each num from the array gets added to one another
        }

        return sum / (float) L;
        //bu kucuk(main'nin disinda) function sunu return ediyor(main'e) => sum(array icindeki numaralarin toplami) /(bolu) length(array icinde bulnan kutular/variable'ar).

    }

    