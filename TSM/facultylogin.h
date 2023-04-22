#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include "Faculty.h"
using namespace std;
void flogin();
void fac();

void fac(){
    int choice;
    bool flag=1;
    do{
    cout<<endl;
    cout<<"|========================================|"<<endl;                                   
    cout<<"|       **-----Faculty Login-----**      |"<<endl;
    cout<<"|========================================|"<<endl;
    cout<<"|                                        |"<<endl;
    cout<<"|          -Select An Option-            |"<<endl;
    cout<<"|          1. Login                      |"<<endl;
    cout<<"|          2. Exit                       |"<<endl;
    cout<<"|                                        |"<<endl;
    cout<<"|                                        |"<<endl;
    cout<<"|========================================|"<<endl;
    cout<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            flogin();
            flag=0;
            break;
        case 2:
            system("exit");
            break;
        default:
            cout<<"Invalid Details..."<<endl;
    }
    }while(choice!=2 && flag);
}

void flogin(){
    string username,userpass,stream;        //Menu
    cout<<"*----Enter Details----*"<<endl;
    cout<<"Enter your name : "<<endl;
    cin>>username;
    cout<<"Enter your password : "<<endl;
    cin>>userpass;
    cout<<"Enter Stream : "<<endl;
    cin>>stream;

    fstream file;                       //read data from file
    file.open("FacDAta.csv",ios::in);
    int count=0;
    vector<string> v;           //using vector for storing data from file
    string details,line,word;
    while(getline(file,line)){
        count++;
    }
    file.close();
    file.open("FacDAta.csv",ios::in);
    for(int i=0;i<=count;i++){
        getline(file,details);
        stringstream s(details);
        while(getline(s,word,',')){             //storing details in vector
            v.push_back(word);
        }
    }
    int length=v.size();        //cehcking for uid and password for faculty
    int i=0;
    int flag=0;
    while(i<length){
        if(username==v[i] && userpass==v[i+1] && v[i+2]=="faculty" && stream==v[i+3]){
            flag=1;
        }
        i=i+4;   
    }
    if(flag==1){        //if data found will print and move forward in..
        cout<<"Faculty Login Successfully.."<<endl;
        cout<<endl;
        ffaculty();
    }
    else{
        cout<<"Incorrect UserName/Password.. "<<endl;
        cout<<"Try Again..."<<endl;
        cout<<endl;
        fac();
    }
}