#ifndef USER_H
#define USER_H
#include <QString>


class user
{
public:
    user(int id,QString name,QString surname,int phone,QString birthday);
private:
    QString surname;
    QString name;
    int phone;
    QString birthday;
    int id;

};

#endif // USER_H
