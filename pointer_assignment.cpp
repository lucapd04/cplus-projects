#include<iostream>
#include<string>
using namespace std;

int main () {

    int *xPtr, *forPtr; 
    forPtr = new int; 
    xPtr = new int; //returning an int pointer to an allocated memory
    cout<<"How many people are in your class? ";
    cin>> *xPtr; //code sets user input as the int value for the pointer

    string *aPtr; 
    aPtr = new string[*xPtr]; //declared a pointer with string value then creating an array with the number of values equal to the user input
    cin.ignore(); 

    for (*forPtr = 0; *forPtr < *xPtr; (*forPtr)++) { //for-loop which stores user input into an array
        cout<<"Student "<<*forPtr + 1<<": " ;
        getline(cin, *(aPtr + *forPtr));

    }

    cout<<"\nList of students: "<<endl;

    for (*forPtr = 0; *forPtr < *xPtr; (*forPtr)++) { //for loop which types the values of the array into a list
        cout<<*forPtr + 1<<". "<<*(aPtr + *forPtr)<<endl;

    }

    delete xPtr, forPtr;
    delete[] aPtr; //returns allocated memory back into the system
    return 0;

}