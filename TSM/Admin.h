#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include"Valid.h"

using namespace std;

void aadmin();

class admin{
public:
    string technology;
    int batch_id;
    string start_date;
    string end_date;
    int no_of_days;
    string venue;
    int no_of_participants;
    string month_of_start;


    void createTraining(){   //Generate a training schedule      (UTI-Id :-Ad-001)
    fstream file;
    file.open("database.csv", ios::out | ios::app);
  
    cout << "Enter the details of Faculty :"<< endl; 
    int fl=1;
    while(fl!=0){
    cout<<"Enter Batch Id :"<<endl;
    cin >>batch_id;
    fl=isdup(batch_id);
    if(fl==1){
        cout<<"Duplicate Batch id"<<endl;
        cout<<"Try Another id"<<endl;
    }
    }
    cout<<"Enter Technology :"<<endl;
    cin >>technology;
    int flag=0;
    while(flag!=1){
    cout<<"Enter Start_Date(DD-MM-YYYY) :"<<endl;
    cin >>start_date;
    flag=vaild(start_date);
    if(flag==0){
        cout<<"Invalid Date.."<<endl;
        cout<<"Try Again"<<endl;
    }
    }
    int f=0;
    while(f!=1){
    cout<<"Enter End_Date(DD-MM-YYYY) :"<<endl;
    cin >>end_date;
    f=vaild(end_date);
    if(f==0){
        cout<<"Invalid Date.."<<endl;
        cout<<"Try Again"<<endl;
    }
    }
     bool f1=1;
    while(f1!=0){
    cout<<"Enter No_Of_Days :"<<endl;
    cin >>no_of_days;
    f1=difference(start_date,end_date,no_of_days);
    if(f1==1){
        cout<<"Invalid Number Of Days"<<endl;
        cout<<"Try Again"<<endl;
    }
    }
    cout<<"Enter Venue :"<<endl;
    cin >>venue;
    cout<<"Enter no_of_participant :"<<endl;
    cin >>no_of_participants;
    cout<<"Enter month_of_start"<<endl;
    cin>>month_of_start;

    // Insert the data to file
    file<<batch_id<<","<<technology<<","<<start_date<<","<<end_date<<","<<no_of_days<<","<<venue<<","<<no_of_participants<<","<<month_of_start<<endl;
    cout<<"Insertion Successfull...!"<<endl;
    cout<<endl;
    //aadmin();
    }  


    void updateSchedule(){         //update the schedule for specific batch id

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
    string id;
    cout<<"Enter Batch_id for updating the schedule.."<<endl;
    cin>>id;
    
    int i=0; 
    cout<<"Press 1 to Modify Technology "<<endl;
    cout<<"Press 2 to Modify StartDate "<<endl;
    cout<<"Press 3 to Modify EndDate "<<endl;
    cout<<"Press 4 to Modify Number Of Days "<<endl;
    cout<<"Press 5 to Modify Venue "<<endl;
    cout<<"Press 6 to Modify Number Of Participants"<<endl;
    cout<<"Press 7 to Modify Month Of Start "<<endl;
    int ch;
    cout<<"Enter Which Data you want to Modify :"<<endl;
    cin>>ch;
    int f1=0;
    string data;
    while(i<v.size()){
        if(v[i]==id){
            f1=1;
            cout<<"Enter data to be Modified"<<endl;
            if(ch==2 || ch==3){
                int f=0;
                while(f!=1){
                cout<<"Enter Date(DD-MM-YYYY) :"<<endl;
                cin>>data;
                f=vaild(data);
                if(f==0){
                    cout<<"Invalid Date.."<<endl;
                    cout<<"Try Again"<<endl;
                 }
                }
            }else{
                cin>>data;
            }
            v[i+ch]=data;    
        }
        i=i+8;
    }
    if(f1==1){
        cout<<"Schedule Updated Successfully "<<endl;
    }
    if(f1==0){
        cout<<"No Such Record Found for batch_id...!!"<<endl;
        cout<<endl;
    }
    file.open("database.csv",ios::out|ios::trunc);
    int z=0;
    while(z<v.size()){
        file<<v[z]<<","<<v[z+1]<<","<<v[z+2]<<","<<v[z+3]<<","<<v[z+4]<<","<<v[z+5]<<","<<v[z+6]<<","<<v[z+7]<<endl;
        z=z+8;
    }
    file.close();
    cout<<endl;

}  


    void generatereport(){   //will show result of a technology of a specific month

    string tech,month;        //Menu
    cout<<"*----Enter Details----*"<<endl;
    cout<<"Enter Technology : "<<endl;
    cin>>tech;
    cout<<"Enter Month : "<<endl;
    cin>>month;
    cout<<endl;

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
        if(tech==v[i+1] && month==v[i+7]){
            flag=1;
            cout<<"Batch Id is : "<<v[i]<<endl;
            cout<<"Technology is : "<<v[i+1]<<endl;
            cout<<"Start_Date is : "<<v[i+2]<<endl;
            cout<<"End_Date is : "<<v[i+3]<<endl;
            cout<<"No_Of_Days is : "<<v[i+4]<<endl;
            cout<<"Venue is : "<<v[i+5]<<endl;
            cout<<"No_Of_Participant is : "<<v[i+6]<<endl;
            cout<<"Month_Of_Start is : "<<v[i+7]<<endl;
            cout<<"Trainer Name is : "<<v[i+8]<<endl;
            cout<<"Status is : "<<v[i+9]<<endl;
            cout<<endl;
        //break;
        }   
        if(i==length-10){
            break;
        }
        i=i+10;
    }
        if(flag==0){
            cout<<"Record not Found...!"<<endl;
            cout<<"There is no Such Training for "<<tech<<" in the month "<<month<<endl;
        }
    }     


    void alloacteTrainer(){

    string id,tech;        //Menu 
    cout<<"*----Enter Details----*"<<endl;
    int fl=1;
    while(fl!=0){
    cout<<"Enter Batch Id :"<<endl;
    cin >>id;
    fl=isdupli(id);
    if(fl==1){
        cout<<"Batch id has already a Trainer Allocated.."<<endl;
        cout<<"Try Another id"<<endl;
    }
    }
    cout<<"Enter Technology : "<<endl;
    cin>>tech;
    cout<<endl;

    fstream file;                       //read data from file
    file.open("database.csv",ios::in);
    fstream f;
    f.open("faculty.csv",ios::out|ios::app);
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
    int length=v.size();        //checking for matched month & Tehnology
    int i=0;
    int flag=0;
    vector<string> str;
    while(i<length){
        if(id==v[i] && tech==v[i+1]){
            flag=1;
            str.push_back(v[i]);
            str.push_back(v[i+1]);
            str.push_back(v[i+2]);
            str.push_back(v[i+3]);
            str.push_back(v[i+4]);
            str.push_back(v[i+5]);
            str.push_back(v[i+6]);
            str.push_back(v[i+7]);
            break;
        }   
        if(i==length-8){
            break;
        }
        i=i+8;
    }
        if(flag==0){
            cout<<"Record not Found...!"<<endl;
            cout<<"There is No Batch for "<<id<<" in the given Technology  "<<tech<<endl;
        }
        else if(flag==1){
        string fname;
        cout<<"Enter Faculty Name "<<endl;
        cin>>fname;
        str.push_back(fname);
        str.push_back("Yes/No");
        for(int i=0;i<str.size();i++){
            cout<<str[i]<<" ";
        }
        cout<<endl;
        
        int z=0;
        while(z<10){
            f<<str[z]<<","<<str[z+1]<<","<<str[z+2]<<","<<str[z+3]<<","<<str[z+4]<<","<<str[z+5]<<","<<str[z+6]<<","<<str[z+7]<<","<<str[z+8]<<","<<str[z+9]<<endl;
            break;
            z=z+10;
        }
        f.close();
        cout<<"Trainer Allocated Successfully...!"<<endl;
        }
       // aadmin();
    }  
};



void aadmin(){
    admin a;
    int choice;
    bool flag=1;
    do{
    cout<<endl;
    cout<<endl;
    cout<<"|================================================|"<<endl;                                   
    cout<<"|             **-----Admin Menu-----**           |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|               -Select An Option-               |"<<endl;
    cout<<"|          1. Create A Training Schedule         |"<<endl;
    cout<<"|          2. Update/Change Schedule             |"<<endl;
    cout<<"|          3. Allocate A Trainer                 |"<<endl;
    cout<<"|          4. Generate Report                    |"<<endl;
    cout<<"|          5. Quit                               |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            a.createTraining();
            break;
        case 2:
            a.updateSchedule();
            break;
        case 3:
            a.alloacteTrainer();
            break;
        case 4:
            a.generatereport();
            break;
        case 5:
            system("exit");
            break;
        default:
            cout<<"Invalid Details..."<<endl;
            cout<<"Try Again.."<<endl;
    }
    }while(choice!=5);
}