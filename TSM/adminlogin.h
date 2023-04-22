#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include "Admin.h"

using namespace std;
void alogin();
void adm();

void adm(){
    int choice;
    bool flag=1;
    do{
    cout<<endl;
    cout<<"|========================================|"<<endl;                                   
    cout<<"|       **-----Admin Login-----**        |"<<endl;
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
            alogin();
            flag=0;
            break;
        case 2:
            system("exit");
            break;
        default:
            cout<<"Invalid Details..."<<endl;
            cout<<"Try Again.."<<endl;
    }
    }while(choice!=2 && flag);
    
}

void alogin(){
    string username,userpass,stream;
    cout<<"*----Enter Details----*"<<endl;          //Menu
    cout<<"Enter your name : "<<endl;
    cin>>username;
    cout<<"Enter your password : "<<endl;
    cin>>userpass;
    fstream file;
    file.open("FacDAta.csv",ios::in);       //reading data from file
    int count=0;
    vector<string> v;                           //using vector to store data
    string details,line,word;
    while(getline(file,line)){
        count++;
    }
    file.close();
    file.open("FacDAta.csv",ios::in);
    for(int i=0;i<=count;i++){
        getline(file,details);
        stringstream s(details);
        while(getline(s,word,',')){
            v.push_back(word);                  //storing data in vector
        }   
    } 
    int length=v.size();
    int i=0;
    int flag=0;
    while(i<length){                //comparing uname and pass if its exist in file
        if(username==v[i] && userpass==v[i+1] && v[i+2]=="admin"){
            flag=1;
        }
        i=i+4;   
    }
    if(flag==1){                    //if yes will move forward
        cout<<"Admin Login Successfully.."<<endl;
        cout<<endl;
        aadmin();
    }
    else{
        cout<<"Invalid Credentials... "<<endl;  
        cout<<"Try Again..."<<endl;
        cout<<endl;
        adm();
    }
}