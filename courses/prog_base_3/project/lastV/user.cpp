#include "user.h"

user::user(){
    QString user_getSurname(user);
    QString user_getName(user);
    int user_getId(user);
    QString user_getBirthday(user);
    int user_getPhone(user);
}

QString user_getSurname(user){
    return user.surname;
}
QString user_getName(user){
    return user.name;
}
int user_getId(user){
    return user.id;
}
QString user_getBirthday(user){
    return user.birthday;
}
int user_getPhone(user){
    return user.phone;
}
