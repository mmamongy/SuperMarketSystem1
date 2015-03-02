
#include"user.h";
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
user :: user (){
}
user :: user (char* Name,char* Pass,bool x){
    strcpy(userName,Name);
    strcpy(password,Pass);
    isAdmin=x;
    }
user :: user (bool x){
    isAdmin=x;
    }
void user :: set_all(char *Name,char *Pass ,bool x){
    strcpy(userName,Name);
    strcpy(password,Pass);
    isAdmin=x;
    }
 void user :: set_isAdmin (bool x){
    isAdmin=x;
    }
char* user :: get_name(){
    return userName;
    }
char* user :: get_pass(){
    return password;
    }
bool user :: get_isAdmin(){
    return isAdmin;
    }
void user :: display (){
     cout<<get_name()<<" ";
    cout<< get_pass()<<" ";
    cout<< get_isAdmin()<<" ";
    }
void user:: set_pass(char p[])  {
strcpy(password , p) ;
}



