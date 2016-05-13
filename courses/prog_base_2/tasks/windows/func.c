#include "func.h"

char * randMaleName(){
    static char * MaleNames[] = {"Igor", "Alex", "Dmitriy","Vovan","Ruslan"};
    char * name = MaleNames[rand()%5];
    return name;
}

char * randFemaleName(){
    static char * FemaleNames[] = {"Sveta", "Alexandra", "Morozhka","Vitalina","Bogdana"};
    return FemaleNames[rand()%5];
}

char * randSurname(){
    static char * Surnames[] = {"Statham", "Tatum", "Reynolds","Legeza","Tishchenko"};
    return Surnames[rand()%5];
}

char * randBirthday(){
    static char * Birthday[] = {"12-09-1999", "06-06-2000", "31-01-1999","24-05-2000","08-08-1999"};
    return Birthday[rand()%5];
}

char * randSpeciality(){
    static char * Speciality[] = {"Fiz-mat", "Linguistics", "Nature","History"};
    return Speciality[rand()%4];
}

char * randScore(){

    double asd = rand()%6 + 6 + 0.1*(rand()%10);
    static char sc[10];
    sprintf(sc, "%2.1lf",asd);
    return sc;
}
