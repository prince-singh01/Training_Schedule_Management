#include <iostream>
#include <ctime>
#include<string>
using namespace std;

bool vaild(string s){ 
    struct tm tm;
    bool flag=0;
    if (strptime(s.c_str(), "%d-%m-%Y", &tm)){
        flag=1;
    }
    else{
        flag=0;
    }
    return flag;
}   

bool isdup(int n){
    string a=to_string(n);
    fstream file;                       //read data from file
    file.open("database.csv",ios::in);
    int count=0;
    vector<string> v;           //using vector for storing data from file
    string details,line,word;
    while(getline(file,line)){
        count++;
    }
    file.close();
    file.open("database.csv",ios::in);
    for(int i=0;i<=count;i++){
        getline(file,details);
        stringstream s(details);
        while(getline(s,word,',')){             //storing details in vector
            v.push_back(word);
        }
    }
    file.close();
     int length=v.size();        //checking for matched month & Tehnology
    int i=0;
    int flag=0;
    while(i<length){
        if(v[i]==a){
            flag=1;
        }   
        i=i+8;
    }
    return flag;
}

bool isdupli(string a){
    //string a=to_string(n);
    fstream file;                       //read data from file
    file.open("faculty.csv",ios::in);
    int count=0;
    vector<string> v;           //using vector for storing data from file
    string details,line,word;
    while(getline(file,line)){
        count++;
    }
    file.close();
    file.open("faculty.csv",ios::in);
    for(int i=0;i<=count;i++){
        getline(file,details);
        stringstream s(details);
        while(getline(s,word,',')){             //storing details in vector
            v.push_back(word);
        }
    }
    file.close();
     int length=v.size();        //checking for matched month & Tehnology
    int i=0;
    int flag=0;
    while(i<length){
        if(v[i]==a){
            flag=1;
        }   
        i=i+10;
    }
    return flag;
}

bool difference(string date1,string date2,int n){
    bool flag=0;
    int d1,m1,y1,d2,m2,y2;
    int dif1=0,dif2=0;
    int ans=0;
    
    d1 = stoi(date1.substr(0,2));
    m1 = stoi(date1.substr(3,2));
    y1 = stoi(date1.substr(6));
    
    d2 = stoi(date2.substr(0,2));
    m2 = stoi(date2.substr(3,2));
    y2 = stoi(date2.substr(6));
   
    dif1=(y1*365+m1*30+d1);
    dif2=(y1*365+m2*30+d2);
    ans=dif2-dif1;
    if((n<ans) || (n>ans+20)){
        flag=1;
    }
    return flag;
}