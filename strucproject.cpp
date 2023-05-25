/************************************************************************
                   STRUCTURE PROJECT - BY LUCA DUARTE
                    ICS4U1 - MS. MEDD 10/05/2022
 *************************************************************************/
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct country { //structure tied with the array that includes z variable for name, the continent and area code
    char name[15];
    char continent[15];
    int area_code;
};

void printBigCountries(country *l) {//function which prints out the elements in the array
    for (int i = 0; i < 5; i++) {
        printf("\n%-10s\t%-10s\t%-10d", l[i].name, l[i].continent, l[i].area_code);
    }

}

void printBigCountries2(country *l) { //function which adds more elements into the array
    for (int i = 0; i < 10; i++) {
        
        if(i == 5) {
           strncpy(l[i].name, "Australia", 15);
         }

        if(i == 6) {
           strncpy(l[i].name, "Argentina", 15);
         }

        if(i == 7) {
           strncpy(l[i].name, "India", 15);
         }

         if(i == 8) {
           strncpy(l[i].name, "Kazahkstan", 15);
         }

         if(i == 9) {
           strncpy(l[i].name, "Algeria", 15);
         }    
    }

}

void printSmallCountries(country *l, int i) { //function which switches elements from the array
        if(i == 0) {
           strncpy(l->name, "Vatican City", 15);
            l -> area_code = 379;
         }

        if(i == 1) {
           strncpy(l->name, "Nauru", 15);
           strncpy(l->continent, "Oceania", 15);
           l -> area_code = 674;
         }

        if(i == 2) {
           strncpy(l->name, "Tuvalu", 15);
           strncpy(l->continent, "Oceania", 15);
           l-> area_code = 688;
         }

         if(i == 3) {
           strncpy(l->name, "Palau", 15);
           strncpy(l->continent, "Oceania", 15);
           l -> area_code = 680;
         }

         if(i == 4) {
           strncpy(l->name, "San Marino", 15);
           strncpy(l->continent, "Europe", 15);
           l -> area_code = 378;
         }    

}

void printTop3(country *l, int i) {//functions which removes elements from the array
        if(i == 0) {
           strncpy(l->name, "France", 15);
           strncpy(l->continent, "Europe", 15);
            l -> area_code = 33;
         }

        if(i == 1) {
           strncpy(l->name, "Spain", 15);
           strncpy(l->continent, "Europe", 15);
           l -> area_code = 34;
         }

        if(i == 2) {
           strncpy(l->name, "United States", 15);
           strncpy(l->continent, "N.America", 15);
           l-> area_code = 1;
         }

        if(i == 3) {
          strncpy(l->name, "\0", 15);
          strncpy(l->continent, "\0", 15);
          l-> area_code = 0;
         }

         if(i == 4) {
          strncpy(l->name, "\0", 15);
          strncpy(l->continent, "\0", 15);
          l-> area_code = 0;
         }

    }

int main() {
country country_list[20] = {{"Russia", "Europe", 7}, //array with all countries, continents and area codes
           {"Canada", "N.America", 1},
           {"China", "Asia", 86},
           {"USA", "N.America", 1},
           {"Brazil", "S.America", 55}};

printf("*****************************************\n");
printf("\tTOP 5 LARGEST COUNTRIES\n");
printf("*****************************************\n");
printf("\nCountry:\tContinent:\tArea Code:");

printBigCountries(country_list);//function for printing array elements is called

cout<<"\nThe top 10 countries by area are: ";
printBigCountries2(country_list); //function which include more array elements is called
for (int i = 0; i < 10; i++) { //for loop which prints new array
        printf("%s, ", country_list[i].name);
    }


printf("\n*****************************************\n");
printf("\tTOP 5 SMALLEST COUNTRIES\n");
printf("*****************************************\n");
printf("\nCountry:\tContinent:\tArea Code:");

for(int i = 0; i < 5; i++)
    printSmallCountries(&country_list[i], i); //function attached to a for loop which switches the array with new elements

  for (int i = 0; i < 5; i++) { //for loop which prints new array
        printf("\n%-10s\t%-10s\t%-10d", country_list[i].name, country_list[i].continent, country_list[i].area_code);
    }

printf("\n*****************************************\n");
printf("\tTOP 3 MOST VISITED COUNTRIES\n");
printf("*****************************************\n");
printf("\nCountry:\tContinent:\tArea Code:");

for(int i = 0; i < 5; i++)
    printTop3(&country_list[i], i); //evokes function which removes elements from the array

    for (int i = 0; i < 5; i++) { //for loop which prints new array
        printf("\n%-10s\t%-10s\t", country_list[i].name, country_list[i].continent);
        
        if (i < 3) {
        printf("%-10d", country_list[i].area_code);
        }

    }
}


