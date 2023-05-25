/************************************************************************
                   STRING ASSIGNMENT - BY LUCA DUARTE
                    ICS4U1 - MS. MEDD 31/03/2022
 *************************************************************************/

#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

int search_forward(string s){ //function which locates the position of the first vowel in the sentence through a for loop
    for(int i = 0; i < s.length() + 1; i++){
        if(tolower(s[i - 1]) == 'a' || tolower(s[i - 1]) == 'e' || tolower(s[i - 1]) == 'i' || tolower(s[i - 1]) == 'o' || tolower(s[i - 1]) == 'u') //for loop with all letters set to lowercase
            return i;
    }
}

int count(string s, int c){ //function which counts all characters in a sentence
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') //conditional statement which removes spaces from the total amount
            c++;
    }

    return c;
}

string replace(string s, char c, char c2)  { //function which detects a desired character in a sentence and replaces it for another
    for (int i = 0; i < s.length() + 1; ++i) {
        if (s[i] == c) 
            s[i] = c2;
     } 

    return s;
    
  }

string erase(string s, char c) { //function which erases a character from a string
    string editedString;

    for(int i = 0; i < s.length() + 1; ++i) {
        if (tolower(s[i]) != c)
            editedString = editedString + s[i];
    }
    return editedString;
}

string add_string(string s, string s2) { //function which adds another string into the end of a string
    s = s + " " + s2;
    return s;
    
  }

string insert(string s, char c, int pst) { //function which inserts a character at a certain position in a string
     string editedString;

    for(int i = 0; i < s.length(); i++){
        if(i == pst - 1)
            editedString = editedString + c;
        else
            editedString = editedString + s[i];
    }

    return editedString;
}

string remove_string(string s) { //function which finds the first word of a sentence
    bool search = true;
    string editedString;

    for (int i = 0; search == true; i++) {
        if (s[i] == ' ')
            search = false;
        else 
            editedString = editedString + s[i];
    }

    return editedString;
}

int main() {

    char ch1, ch2, ch3, ch4;
    int position, counting;
    string sentence, statement; 

    cout<<"Type a setence: "; //player input which creates a string to modify
    getline(cin, sentence);

    char sentence_array[sentence.length()]; //a character array to place my string function into
    cout<<"\nYour sentence was:"<<endl;
    cout<<"'";
    for (int i = 0; i < sizeof(sentence_array); i++) { //for loop which places each character of the string in the char array
        sentence_array[i] = sentence[i];
        cout<<sentence_array[i]; //prints out each character of the array successively
    }
    cout<<"'"<<endl;

    printf("\nYour sentence has %i characters and the first vowel is at %i", count(sentence, counting), search_forward(sentence)); 
    //prints two integers: the number of characters in a sentence(minus spaces) and the position of the first vowel
    cout<<endl;

    cout<<"\nType a letter you would like to replace for another character in that sentence: ";
    scanf("%c %c", &ch2, &ch1);
    cout<<replace(sentence, ch1, ch2)<<endl; //prints new string with all the characters replaced

    cout<<"\nType a letter you would like to insert in the sentence: ";  
    cin>>ch3;
    cout<<"Which position would you like that letter in the sentence? ";
    cin>>position;
    //player input used in the function below
    cout<<insert(sentence, ch3, position)<<endl; //prints sentence with the new character inserted

    cout<<"\nType a letter you would like to erase in the sentence: ";
    cin>>ch4;
    cout<<erase(sentence, ch4)<<endl;
    cin.ignore();

    cout<<"\nType a new sentence to combine with the first sentence: "; //new string created to combine with the previous string
    getline(cin, statement);
    cout<<add_string(sentence, statement)<<endl; //prints a new string with the combination of two strings

    cout<<"\nThe first word of the sentence is: "; 
    cout<<remove_string(sentence)<<endl; //prints the first word of the string

    return 0;

}
    