#include <bits/stdc++.h>
#include <stdio.h>
#include<fstream>
#include"user.h"
#include<vector>
#include<string.h>
using namespace std;
char  DATE[30] , TIME[30] ;
 string gettime(){
 time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  string str(buffer);
  return str;
}
struct SIndex {
char Name[30] ;
int ID;
};
struct SIndex2 {
char Date[30] ;
int ID ;
};
struct PIndex {
int RRN;
int ID;
};
vector <PIndex> ArrOfPI;
vector <SIndex> ArrOfSI1;
vector <SIndex2> ArrOfSI2;
struct pNindx {
int RRN;
string Name;
};
struct User {
char name[50] ;
char passowrd[50] ;
bool b=0 ;
};
struct Puser {
int RRN;
char name[50];
};
vector<User>VU;
vector<Puser>VUP;
void pindx(){
ifstream file2;
file2.open("User.dat");
file2.seekg(0,ios::end);
int Numrec=file2.tellg()/101;
cout<<Numrec<<endl;
file2.seekg(0,ios::beg);
ofstream out;
user temp;
out.open("pindex.txt",ios::app | ios::out);
pNindx *pNindxArr=new pNindx [Numrec+1] ;
for(int i=0; i<Numrec; i++){

    pNindxArr[i].RRN=i;
    file2.read((char*)&temp,sizeof(user));
    pNindxArr[i].Name=temp.get_name();
    out<<pNindxArr[i].RRN<<" ";
    out<<pNindxArr[i].Name<<"\n";
}

    file2.close();
    out.clear();
    out.close();


}
void sign_up(char *name,char *pass,bool isAdmin){
ifstream file2;
file2.open("User.dat");

file2.seekg(0,ios::end);
int Numrec=file2.tellg()/101;
file2.seekg(0,ios::beg);
fstream primfile;
primfile.open("pindex.txt",ios::app |ios::in | ios::out);
pNindx *pNindxArr=new pNindx [Numrec+1] ;

if (file2.fail())
    {
        cout << "FAIL TO OPEN\n";
        return ;}

user Admin,temp;
bool found =false;

      for(int i=0; i<Numrec; i++){
        primfile>>pNindxArr[i].Name;
        if(pNindxArr[i].Name==(string)name){
            cout<<"User name already exist \n";
              found = true ;
              break;
        }
      }
        primfile.close();

        if (!found){
            ofstream file;
            file.open("User.dat",ios::binary|ios::app);

            Admin.set_all((char*)name,(char*)pass,isAdmin);
            file.write((char*)&Admin,sizeof(user));
            file.close();

        primfile.open("pindex.txt",ios::app |ios::in | ios::out);
        pNindxArr[Numrec].Name=name;
        pNindxArr[Numrec].RRN=Numrec;
        primfile<<pNindxArr[Numrec].RRN<<" "<<pNindxArr[Numrec].Name<<"\n";
        cout<<"New record is registered \n";
            primfile.clear();
            primfile.close();
            file.close();
        }

    file2.close();

}
// Function Name: log in
// Parameters: char* name , char* pass , bool isAdmin
// Last Modification Date: 1/5/2014
// Author:5 Amany mohamed
// Purpose: log in system
void log_in(char* name,char* pass,bool isAdmin){
ofstream file;
file.open("User.dat",ios::binary|ios::app);
ifstream file2;
file2.open("User.dat");

file2.seekg(0,ios::end);
int Numrec=file2.tellg()/101;
file2.seekg(0,ios::beg);
fstream primfile;
primfile.open("pindex.txt",ios::app |ios::in | ios::out);
pNindx *pNindxArr=new pNindx [Numrec+1] ;

user temp;
bool found =false;
int RNN;


      for(int i=0; i<Numrec; i++){
        primfile>>pNindxArr[i].Name;
        if(pNindxArr[i].Name==(string)name){
          RNN=pNindxArr[i].RRN;
          file2.seekg(RNN*101,ios::beg);
          file2.read((char*)&temp,sizeof(user));
          if((string)temp.get_pass()==(string)pass){
            cout<<"Welcome in system \n";
              found = true ;
              break;
        }
        }
      }

        if (!found){
          cout<<"you must sign up first"<<endl<<endl;
          sign_up(name,pass,isAdmin);
          file.close();
        }
   primfile.close();
   file2.close();

}
// Function Name: promote chashier
// Parameters: Null
// Last Modification Date: 1/5/2014
// Author: Amany mohamed
// Purpose: promote cashier to admin
//void promote_cashier(){
//fstream file2;
//file2.open("User.dat",ios::binary|ios::app | ios::in | ios:: out);
//file2.seekg(0,ios::end);
//int Numrec=file2.tellg()/101;
//file2.seekg(0,ios::beg);
//fstream primfile;
//primfile.open("pindex.txt",ios::app |ios::in | ios::out);
//pNindx *pNindxArr=new pNindx [Numrec+1] ;
//
//user Admin,temp;
//string name;
//int RNN;
//while(!file2.eof()){
//        file2.read((char*)&temp,sizeof(user));
//        if(file2.fail()) break;
//        if(temp.get_isAdmin()==false){
//            temp.display();
//        }
//       cout<<endl;
//}
//file2.close();
//file2.open("User.dat");
//cout<<"Enter cashier name \n";
//cin>>name;
//
//    for(int i=0; i<Numrec; i++){
//        primfile>>pNindxArr[i].Name;
//        if(pNindxArr[i].Name==name){
//          RNN=pNindxArr[i].RRN;
//        break;
//        }
//    }
//
//        file2.seekg(RNN*101,ios::beg);
//        file2.read((char*)&temp,sizeof(user));
//        //if(file2.fail()) break;
//        //Admin.set_all(temp.get_name(),temp.get_pass(),1);
//        temp.set_isAdmin(1);
//        file2.seekg(0,ios::beg);
//        file2.seekp(0,ios::beg);
//        file2.seekp(RNN*101,ios::beg);
//        file2.write((char*)&temp,sizeof(user));
//
//        cout<<"Cashier name successfully promoted \n";
//
//        file2.close();
//        primfile.close();
//}

// Function Name: delete cashier
// Parameters: Null
// Last Modification Date: 1/5/2014
// Author: Amany mohamed
// Purpose: delete chashier from system
void delete_cashier (){
ofstream file1;
file1.open("Temp.dat",ios::binary|ios::app);
ifstream file2;
file2.open("User.dat",ios::binary|ios::app);
user Admin,temp,Admin1;
string name;
while(!file2.eof()){
        file2.read((char*)&temp,sizeof(user));
        if(file2.fail()) break;
        if(temp.get_isAdmin()==false){

            temp.display();
        }
       cout<<endl;
}
file2.close();
file2.open("User.dat");
cout<<"Enter cashier name \n";
cin>>name;
while(!file2.eof()){
        file2.read((char*)&temp,sizeof(user));
        if(file2.fail()) break;
        if(temp.get_name()!=name){
   file1.write((char*)&temp,sizeof(user));
                    }
}
file1.close();
file2.close();
remove("User.dat");
rename("Temp.dat","User.dat");
}
void change_pass(){
fstream file2;
file2.open("User.dat",ios::binary|ios::app | ios::in | ios:: out);
file2.seekg(0,ios::end);
int Numrec=file2.tellg()/101;
file2.seekg(0,ios::beg);
fstream primfile;
primfile.open("pindex.txt",ios::app |ios::in | ios::out);
//primfile.open("pindex.txt",ios::app |ios::binary |ios::in | ios::out);
pNindx *pNindxArr=new pNindx [Numrec+1] ;

user Admin,temp;
string name;
int RNN;
char PASS[50];

while(!file2.eof()){
        file2.read((char*)&temp,sizeof(user));
        if(file2.fail()) break;
        if(temp.get_isAdmin()==false){

            temp.display();
        }
       cout<<endl;
}
file2.close();
file2.open("User.dat");
cout<<"Enter cashier name \n";
cin>>name;
cout<<"Enter your new password \n";
cin>>PASS;

    for(int i=0; i<Numrec; i++){
        primfile>>pNindxArr[i].Name;
        //primfile.read((char*)&pNindxArr[i],sizeof(pNindx));
        if(pNindxArr[i].Name==name){
          RNN=pNindxArr[i].RRN;
        break;
        }
    }
        file2.seekg(RNN*101,ios::beg);
        file2.read((char*)&temp,sizeof(user));
        //if(file2.fail()) break;
        //Admin.set_all(temp.get_name(),temp.get_pass(),1);
        temp.set_pass(PASS);
        file2.seekg(0,ios::beg);
        file2.seekp(0,ios::beg);
        file2.seekp(RNN*101,ios::beg);
        file2.write((char*)&temp,sizeof(user));
        cout<<"Cashier password successfully changed \n";
        file2.close();
        primfile.close();

}
class BillEntery{
char productName[20];
double unitPrice,quantity,productPrice;
public:
void getBillEntery() {
// Function Name: getBillEntery()
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: Enter the Entries of the bills
    cout<<"enter product name"<<endl;
    cin>>productName;
    cout<<"Enter unitPrice"<<endl;
    cin>>unitPrice;
    cout<<"enter the Quantity"<<endl;
    cin>>quantity;
    productPrice=unitPrice*quantity;
}
void writeBillEntery(){
// Function Name: writeBillEntery
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: write on the file
int sz=strlen(productName)+1;
ofstream out("bill.dat",ios::app|ios::binary);
out.write((char*)&sz,sizeof(int));
out.write((char*)&productName,sz);
out.write((char*)&unitPrice,sizeof(double));
out.write((char*)&quantity,sizeof(double));
out.write((char*)&productPrice,sizeof(double));
out.close();
}
double getProducPrice(){
// Function Name: getProducPrice
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: get product price

return productPrice ;
}
double getUnitPrice() {
// Function Name: getUnitPrice
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: get Unit Price
	return unitPrice ;
}
BillEntery readBE (ifstream & in){
    BillEntery B ;
    int sz ;
in.read((char*)&sz,sizeof(int));
in.read((char*)&B.productName,sz);
in.read((char*)&B.unitPrice,sizeof(double));
in.read((char*)&B.quantity,sizeof(double));
in.read((char*)&B.productPrice,sizeof(double));
return B ;
}
void printBE()
{
    cout<<"Product Name: \t"<<productName<<"\tUnit Price: \t"<<unitPrice<<"\tQuantity\t"<<quantity<<"\tProduct price\t"<<productPrice<<"\n" ;

}
friend void UpdateBill () ;
} ;
class Bill{
   char cashier[30];
   int ID;
   char Date[30];
   char Time[30];
   vector<BillEntery>products;
   double total;
public:
Bill(){
total=0;
}
void getBill(){
// Function Name: getBill
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: get the Bill entries

cout<<"Enter the cashier Name"<<endl;
cin>>cashier;
for(int i=0;i<10;i++)
Date[i]=gettime()[i];
Date[10]='\0';
strcpy(DATE,Date);
for(int i=11;i<gettime().size();i++)
Time[i-11]=gettime()[i];
Time[8]='\0';
strcpy (TIME, Time);
int x=1;
while(x==1)
{
  BillEntery obj;
  obj.getBillEntery();
  products.push_back(obj);
  total+= obj.getProducPrice() ;
  cout<<total<<endl;
  cout<<"Enter the 1 if to enter other product else enter any other number"<<endl;
  cin>>x;
}}
void writeBill(){
// Function Name: writeBill
// Parameters:
// Last Modification Date: 1/5/2014
// Author: Maryam Mamdouh
// Purpose: write the bill of the file

PIndex p ;

ifstream in ("bill.dat" ) ;
if(!in.fail())
{
in.seekg(0 , ios::end) ;
p.ID= ArrOfPI.size() + 1 ;
p.RRN = in.tellg() ;

}
else
{
p.ID= ArrOfPI.size() + 1 ;
p.RRN = 0 ;

}
in.close();

ID = ArrOfPI.size()+1;
cout<<ID<<endl;
ofstream out("bill.dat",ios::app|ios::binary);
int sz;
sz=strlen(cashier)+1;
out.write((char*)&sz,sizeof(int));
out.write((char*)&cashier,sz);
out.write((char*)&ID,sizeof(int));
sz=strlen(Date)+1;
out.write((char*)&sz,sizeof(int));
out.write((char*)&Date,sz);
sz=strlen(Time)+1;
out.write((char*)&sz,sizeof(int));
out.write((char*)&Time,sz);
out.write((char*)&total,sizeof(double));
sz=products.size();
out.write((char*)&sz,sizeof(int));
out.close();
for(int i=0;i<sz;i++)
{
products[i].writeBillEntery();
}
out.close() ;
ofstream outPI ("PrimIndex.dat", ios::binary | ios::out | ios::app);
outPI.write((char*)&p.ID , sizeof(int));
outPI.write((char*)&p.RRN , sizeof(int)) ;
outPI.close();
SIndex S;
S.ID = ID ;
strcpy(S.Name,cashier);
ofstream outSEC ("SecIndex1.dat", ios::binary | ios::out | ios::app);
outSEC.write((char*)&S.ID , sizeof(int));
int s= strlen(S.Name)+1 ;
outSEC.write((char*)&s , sizeof(int));
outSEC.write((char*)&S.Name, s);
outSEC.close();
SIndex2 S2;
S2.ID =ID ;
strcpy( S2.Date,Date);
cout<<"DATE    "<<S2.Date ;
ofstream outSEC2 ("SecIndex2.dat", ios::binary|ios::out|ios::app);
outSEC2.write((char*)&S2.ID,sizeof(int));
s= strlen(S2.Date)+1;
outSEC2.write((char*)&s, sizeof(int)) ;
outSEC2.write((char*)&S2.Date,s);
outSEC2.close();
}
Bill readBill (ifstream & in) {
Bill B ;
int sz;
in.read((char*)&sz,sizeof(int));
in.read((char*)&B.cashier,sz);
in.read((char*)&B.ID,sizeof(int));
in.read((char*)&sz,sizeof(int));
in.read((char*)&B.Date,sz);
in.read((char*)&sz,sizeof(int));
in.read((char*)&B.Time,sz);
in.read((char*)&B.total,sizeof(double));
in.read((char*)&sz,sizeof(int));
for(int i=0;i<sz;i++)
{
    BillEntery B1 ;
    B1= B1.readBE(in) ;
    B.products.push_back(B1);
}
in.close() ;
return B ;
}
void print(){

cout<<"Bills Of The Day:-\n";
    cout<<"Cashir Name: \t"<<cashier<<"\n Bill ID: "<<ID<<"\n Date: "<<Date<<"\n Total of These Bills:\t"<<total<<"\n";
cout<<"Size of products  :"<<products.size() <<endl ;
system("pause");
    for(int i=0;i<products.size();i++)
    {
        products[i].printBE();
    }
}
friend void UpdateBill () ;
};
void Load (){
    for(int i=0;i<10;i++)
DATE[i]=gettime()[i];
DATE[10]='\0';
for(int i=11;i<gettime().size();i++)
TIME[i-11]=gettime()[i];
TIME[8]='\0';
    int s;
    ifstream in ("PrimIndex.dat") ;
    int pre=-1;
    if(!in.fail())
    while (!in.eof())
    {
    PIndex P2;
    in.read((char*)&P2.ID,sizeof(int));
    in.read((char*)&P2.RRN,sizeof(int));
    if(pre==P2.ID)break;
    pre=P2.ID;
    ArrOfPI.push_back(P2);
    }
    in.close();
    ifstream inSEC1 ("SecIndex1.dat") ;
    pre=-1;
    if(!inSEC1.fail())
    while (!inSEC1.eof())
    {
    SIndex S1;
    inSEC1.read((char*)&S1.ID,sizeof(int));
    inSEC1.read((char*)&s,sizeof(int));
    inSEC1.read((char*)&S1.Name , s ) ;
    if(pre==S1.ID)break;
    pre=S1.ID;
    ArrOfSI1.push_back(S1);
    }
    inSEC1.close() ;
    ifstream inSEC2 ("SecIndex2.dat") ;
    pre=-1;
    if(!inSEC2.fail())
    while (!inSEC2.eof())
    {
    SIndex2 S2;
    inSEC2.read((char*)&S2.ID,sizeof(int));
    inSEC2.read((char*)&s,sizeof(int));
    inSEC2.read((char*)&S2.Date , s ) ;
    if(pre==S2.ID)break;
    pre=S2.ID;
    ArrOfSI2.push_back(S2);
    }
    inSEC2.close() ;
}
void CreateBill() {
    Bill obj ;
    obj.getBill() ;
    obj.writeBill();
}
void viewBillOfDay(){
char name[30];
cout<<"Enter Name of Cashir"<<endl;
cin>>name;
int target;
int po;
for(int i=0;i<ArrOfSI1.size();i++)
{
    //cout<<"F1 loop"<<endl;
    if (string(ArrOfSI1[i].Name) == string(name))
    {
//        cout<<"F2 loop"<<endl;
        target = ArrOfSI1[i].ID ;
//        cout<<"Target  "<<target <<endl;
        for (int j=0;j<ArrOfSI2.size();j++) {
            //cout<<"F3 before if : " <<ArrOfSI2[j].ID<<endl;
            if ( ArrOfSI2[j].ID==target)
            {
//                cout<<"F3 loop"<<endl;
//                 cout<<" DATE OD DAY  "<<ArrOfSI2[j].Date<<endl;
                 if(string(ArrOfSI2[j].Date)==string(DATE)){
                      //  cout<<"KKK: "<<endl;
                 for ( int t=0 ; t<ArrOfPI.size(); t++) {
//                        cout<<" Primary ID : "<<ArrOfPI[t].ID<<endl;
                  if (ArrOfPI[t].ID==target)
                            {
//                                cout<<"F4 loop Core"<<endl;
                                po=ArrOfPI[t].RRN;
                                cout<<"Po: "<<po<<endl;
                                ifstream in("bill.dat");
                                in.seekg(po,ios::beg);
                                Bill bb1;
                                bb1=bb1.readBill(in);
                                bb1.print();
                                in.close();
                            }
                 }}

                 else
                    break ;
    }}}}}
void UpdateBill () {
int BillID;
cout<<"Enter Bill ID"<<endl;
cin>>BillID;
bool b=0 ;
for(int i=0 ;i<ArrOfPI.size();i++){
        if (ArrOfPI[i].ID==BillID) {
        b=1 ;
        break ;
}}
if (b==0)
    cout<<"The ID of the bill is not valid\n" ;
else {
        int po ;
        bool b1=0 ;
      for ( int i=0; i <ArrOfSI2.size() ; i++) {
        if (BillID==ArrOfSI2[i].ID) {
//            cout<<"SECOND IF"<<endl;
//        cout<<ArrOfSI2[i].Date<< "   "<<DATE<<endl;
       if (string(ArrOfSI2[i].Date)==string(DATE)){
          cout<<"BILL'ID is Valid\n";
          b1=1 ;
          break ;
        }}}
       if (b1==0)
        cout<<"The Date of The Bill is not today\n";
        for ( int t=0 ; t<ArrOfPI.size(); t++) {
                  if (ArrOfPI[t].ID==BillID)
                            {
                                po=ArrOfPI[t].RRN;
                                cout<<"Po: "<<po<<endl;
                                ifstream in("bill.dat");
                                in.seekg(po,ios::beg);
                                Bill bb1;
                                bb1.getBill();
                                bb1.writeBill();
                                bb1.print();
                                in.close();
                            }}}}
void creatuser () {
    User x ;
    Puser y ;
    cout<<"Enter Name of user\n" ;
    cin>>x.name ;
    cout<<"Enter Password of user\n" ;
    cin>>x.passowrd ;
    x.b=0 ;
    strcpy(y.name, x.name );
    ofstream outUser ("Puser.dat" , ios::binary|ios::out| ios::app) ;
    ofstream outP ("Prim.dat", ios::binary|ios::out|ios::app);
    outUser.write((char*)& x.name,50) ;
    outUser.write((char*)&x.passowrd,50) ;
    outUser.write((char*)&x.b,1);
    int t = outUser.tellp() ;
    cout<<t<<endl;
    y.RRN = t;
    outP.write((char*)& y.name ,50) ;
    outP.write((char*)&t ,sizeof(int));
    outUser.close();
    outP.close() ;
}

//vector<User>VU;
//vector<Puser>VUP;
void Loadd() {
    ifstream outUser ("Puser.dat" , ios::in);
    while (!outUser.eof())
    {
    User x;
    outUser.read((char*)&x.name , 50) ;
    outUser.read((char*)&x.passowrd , 50);
    outUser.read((char*)&x.b , 1) ;
    VU.push_back(x);
    }
    outUser.close();
    ifstream outP ("Prim.dat", ios::in);
    while(!outP.eof()) {
                Puser y;
    outP.read((char*)&y.name ,50) ;
    outP.read((char*)&y.RRN , sizeof(int)) ;
    VUP.push_back(y) ;
    }
    outP.close();
}
void ChangePassword (){
    char Password[50] ;
    char name[50] ;
    User x ;
    cout<<"Enter Name:\n" ;
    cin>>name;
    fstream outUser("Puser.dat" ,ios::in |ios::out| ios::binary | ios::app);
    int rn=0 ;
    Loadd() ;
    for (int i=0 ; i<VU.size() ; i++) {
         if ((string)VU[i].name==(string)name) {
            cout<<"Enter the new passowrd\n" ;
            cin>>Password ;
            rn=i*101;
            strcpy(x.name,name) ;
            strcpy(x.passowrd,Password) ;
            break ;
        }
        }
        outUser.seekg(rn , ios::beg);
        outUser.write((char*)&x.name,50) ;
        outUser.write((char*)&x.passowrd,50);
        outUser.write((char*)&x .b,1);
        outUser.close();
        Loadd() ;
        for ( int i=0 ; i<VU.size() ; i++) {
             cout<<VU[i].name<<"  "<<VU[i].passowrd<<endl;
        }
}
void viewBillBYDATE(){
char DD[30];
cout<<"Enter Name of Date"<<endl ;
cout<<"Enter 1-Day \t 2-Month \t 3-year.\n";
    string day , month , year , D  ;
    cin>>day >> month >> year;
    if (day.size()==1)
        day="0"+day ;
    if (month.size()==1)
        month="0"+ month;
        D=day+"-"+month+"-"+year;
        strcpy (DD ,D.c_str()) ;
int target;
int po;
        //target = ArrOfSI1[i].ID ;
        for (int j=0;j<ArrOfSI2.size();j++)
            {
                 if(string(ArrOfSI2[j].Date)==string(DD)){
                 for ( int t=0 ; t<ArrOfPI.size(); t++) {
                            {
                                po=ArrOfPI[t].RRN;
                                cout<<"Po: "<<po<<endl;
                                ifstream in("bill.dat");
                                in.seekg(po,ios::beg);
                                Bill bb1;
                                bb1=bb1.readBill(in);
                                bb1.print();
                                in.close();
                            }}}}}
 void ViewBillsOfCashir() {
 char name[30];
 cout<<"Enter the name of Cashir"<<endl;
 cin>>name ;
int target;
int po;
        //target = ArrOfSI1[i].ID ;
        for (int j=0;j<ArrOfSI1.size();j++)
            {
                 if(string(ArrOfSI1[j].Name)==string(name)){
                     target = ArrOfSI1[j].ID ;
                 for ( int t=0;t<ArrOfPI.size(); t++) {
                            {
                                if (ArrOfPI[t].ID==target) {
                                po=ArrOfPI[t].RRN;
                                cout<<"Po: "<<po<<endl;
                                ifstream in("bill.dat");
                                in.seekg(po,ios::beg);
                                Bill bb1;
                                bb1=bb1.readBill(in);
                                bb1.print();
                                in.close();
                            }}}}}
}
void promote_cashier(){
fstream file2;
file2.open("User.dat",ios::binary|ios::app | ios::in | ios:: out);
file2.seekg(0,ios::end);
int Numrec=file2.tellg()/101;
file2.seekg(0,ios::beg);
fstream primfile;
primfile.open("pindex.txt",ios::app |ios::in | ios::out);
//primfile.open("pindex.txt",ios::app |ios::binary |ios::in | ios::out);
pNindx *pNindxArr=new pNindx [Numrec+1] ;

user Admin,temp;
string name;
int RNN;
while(!file2.eof()){
        file2.read((char*)&temp,sizeof(user));
        if(file2.fail()) break;
        if(temp.get_isAdmin()==false){
            temp.display();
        }
       cout<<endl;
}
file2.close();
file2.open("User.dat");
cout<<"Enter cashier name \n";
cin>>name;

    for(int i=0; i<Numrec; i++){
        primfile>>pNindxArr[i].Name;
        //primfile.read((char*)&pNindxArr[i],sizeof(pNindx));
        if(pNindxArr[i].Name==name){
          RNN=pNindxArr[i].RRN;
        break;
        }
    }

        file2.seekg(RNN*101,ios::beg);
        file2.read((char*)&temp,sizeof(user));
        //if(file2.fail()) break;
        //Admin.set_all(temp.get_name(),temp.get_pass(),1);
        temp.set_isAdmin(1);
        file2.seekg(0,ios::beg);
        file2.seekp(0,ios::beg);
        file2.seekp(RNN*101,ios::beg);
        file2.write((char*)&temp,sizeof(user));

        cout<<"Cashier name successfully promoted \n";

        file2.close();
        primfile.close();
}
void Display () {
cout<<"1- If you want to create a bill\n2- If you want to view bill of today\n3- If you want to Update a bill\n" ;
cout<<"4- If you want to view bills of specific date\n5- If you want to change your password\n6- If you want to view bills of Cashir\n7- If you want to reuse the ssytem\n8- If you want to exit\n" ;
}
void Display2() {
cout<<" 1- for sign up press >> 1 \n" <<" 2- for log in press >> 2 \n"<<" 3- for promote cashier to admin press >> 3 \n"<<" 4- for delete cashier press >> 4 \n";
}
int main() {
char name [50];
char pass [50];
bool isAdmin;
int choic;
cout<<" 1- for sign up press >> 1 \n" <<" 2- for log in press >> 2 \n"<<" 3- for promote cashier to admin press >> 3 \n"<<" 4- for delete cashier press >> 4 \n";
cin>>choic;
while (choic<5) {
if(choic==1){
        cout<<"Eneter your name \n";
cin>>name;
cout<<"Enter your password \n";
cin>>pass;
cout<<"Enter your position ( 1 for Admin or 0 for Cashier )\n";
cin>>isAdmin;
sign_up(name,pass,isAdmin);
system("pause") ;
system("cls") ;
Display2() ;
cin>>choic ;
}
else if (choic==2){
cout<<"Enter your name \n";
cin>>name;
cout<<"Enter your password \n";
cin>>pass;
cout<<"Enter your position ( 1 for Admin or 0 for Cashier ) \n";
cin>>isAdmin;
log_in(name,pass,isAdmin);
system("pause") ;
system("cls") ;
Display2() ;
cin>>choic ;
}
else if (choic==3) {
promote_cashier();
system("pause") ;
system("cls") ;
Display2() ;
cin>>choic ;
}
else if(choic==4) {
delete_cashier();
system("pause") ;
system("cls") ;
Display2() ;
cin>>choic ;
}
else if (choic==5)
    pindx();
system("pause") ;
system("cls");
}
cout<<"Welcom to THE SUPER MARKET SYSTEM\n";
int t ;
Display() ;
cin>>t ;
while (t<8) {
        Load();
        if (t==1) {
        CreateBill() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==2) {
        viewBillOfDay() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==3) {
        UpdateBill() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==4) {
        viewBillBYDATE() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==5) {
                int y ;
                cout<<"If you want mine press 1 else press 2\n" ;
                cin>>y;
                if (y==1)
                    change_pass() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==6) {
        ViewBillsOfCashir() ;
        system("cls") ;
            Display() ;
            cin>>t;
        }
        if (t==7) {
            system("cls") ;
            Display() ;
            cin>>t;
        }
}

return 0 ;}
