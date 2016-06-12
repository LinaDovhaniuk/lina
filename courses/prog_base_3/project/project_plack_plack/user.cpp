#include "user.h"

user::user(int id,QString name,QString surname,QString birthday,QString phone,QString login){
    this->name = name;
    this->surname = surname;
    this->phone = phone;
    this->id = id;
    this->birthday = birthday;
    this->login = login;
}

QString user::user_getSurname(){
    return this->surname;
}
QString user::user_getName(){
    return this->name;
}
int user::user_getId(){
    return this->id;
}
QString user::user_getBirthday(){
    return this->birthday;
}
QString user::user_getPhone(){
    return this->phone;
}
QString user::user_getLogin(){
    return this->login;
}
