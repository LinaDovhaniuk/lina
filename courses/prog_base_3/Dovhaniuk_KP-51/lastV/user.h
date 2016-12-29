#ifndef USER_H
#define USER_H
#include <QString>


class user
{
public:
    user(int id,QString name,QString surname,QString phone,QString birthday,QString login);
    QString user_getSurname();
    QString user_getName();
    int user_getId();
    QString user_getBirthday();
    QString user_getPhone();
    QString user_getLogin();
private:
    QString surname;
    QString name;
    QString phone;
    QString birthday;
    QString login;
    int id;

};

#endif // USER_H
