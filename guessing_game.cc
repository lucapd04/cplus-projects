/************************************************************************
                   GUESSING GAME - BY LUCA DUARTE
                    ICS4U1 - MS. MEDD 24/02/2022
 *************************************************************************/

#include<iostream>
#include<cstdio>
#include<time.h>
#include<Windows.h>
using namespace std;

int main(){
    
    string name; 
    int end, tries; //variables used for the username and the number of tries they took to get the true answer

    cout<<"Hello, thank you for playing our game! What is your name?"<<endl;
    getline(cin, name); //input to get user's name

    printf("Pleasure meeting you %s, I hope you enjoy this experience!\nFirst, select up until what number do you want the range to go to: ", name.c_str());
    scanf("%i", &end); //input to decide the range of numbers

    printf("Selecting random numbers from a range up to %i...\n",end);
    Sleep(3000);
    bool game = true; 
    tries = 0;

    while (game == true) { //while loop which starts the game and leads to the guessing input

        int answer, guess; //variables for the randomly picked number and the player's guess

        srand (time(NULL));
        answer = rand() %end; //code which randomly generates a number for the player to guess
        
        cout<<"\nType your guess: ";
        cin>>guess; //input for the player's answer

        while(guess != answer){//while-loop which sends player back into the start of the "while (game == true)" loop as long as the player's guess isnt equal to the answer

        if (guess < answer) { //condition if player's guess is higher than the answer
            cout<<"The answer is higher than " <<guess<<endl;
            tries++;

        }

        if (guess > answer) { //condition if player's guess is lower than the answer
            cout<<"The answer is lower than "<<guess<<endl;
            tries++;
        }

        //in both conditions, the variable 'tries' increases by one in order to keep track of the amount of the player's guesses

        cout<<"\nGuess: ";
        cin>>guess;

        }
            bool end = true; //variable which activates the next while-loop

            while (end == true){ //while loop which leads to a game over screen

            int choice; //variable for the player's choice input
            cout<<"Good job! Your guess of " << guess << " was right, it took you "<<tries<<" tries! Do you wish to continue?(type 1 for yes, 0 for no) ";
            cin>>choice; //player input which either closes the game or restarts it

            switch (choice) { //switch for the player's choice input

                case 0: //case which closes the game
                cout<<"\nThanks for playing my game!"<<endl;
                end = false;
                game = false;
                break;

                case 1: //case which restarts the game
                tries = 0;
                end = false;
                break;

                default: //case if player types neither 1 nor 0
                cout<<"Not an option"<<endl;
                
            }

        }

    }

    return 0;
}