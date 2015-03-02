#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
class user{

char userName[50];
char password[50];
bool isAdmin;
public:

    user();
    user(char*,char*,bool);
    user(bool);
    void set_all(char*,char*,bool);
    void set_isAdmin(bool);
    char* get_name();
    char* get_pass();
    bool get_isAdmin();
    void display();
    void changePassword (char p []) ;
    void set_pass(char p[]) ;
};
#endif


