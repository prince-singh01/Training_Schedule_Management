#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include"adminlogin.h"
#include"facultylogin.h"

using namespace std;

int main(){
    int choice;
    bool flag=1;
    do{                                     //Menu to choose between admin and faculty 
    cout<<endl;
    cout<<"|========================================|"<<endl;                                   
    cout<<"|         **-----Welcome-----**          |"<<endl;
    cout<<"|========================================|"<<endl;
    cout<<"|                                        |"<<endl;
    cout<<"|          -Select An Option-            |"<<endl;
    cout<<"|          1. Login As Admin             |"<<endl;
    cout<<"|          2. Login As Faculty           |"<<endl;
    cout<<"|          3. Exit                       |"<<endl;
    cout<<"|                                        |"<<endl;
    cout<<"|========================================|"<<endl;
    cout<<"--Select a Choice :-- "<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            adm();
            flag=0;
            break;
        case 2:
            fac();
            flag=0;
            break;
        case 3:
            system("exit");
            break;
        default:
            cout<<"Invalid Input..!"<<endl;
            cout<<"Try Again.."<<endl;
            break;
        }
    }while(choice!=3 && flag);
    return 0;
}

