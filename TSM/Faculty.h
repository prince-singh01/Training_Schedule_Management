#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

void ffaculty();

class faculty{
public:
    string technology;
    int batch_id;
    string start_date;
    string end_date;
    int no_of_days;
    string venue;
    int no_of_participants;
    string month_of_start;
    string faculty_Name;
    string status;

    void generateSchedule(){
    string tech,fname;        //Menu
    cout<<"*----Enter Details----*"<<endl;
    cout<<"Enter Technology : "<<endl;
    cin>>tech;
    cout<<"Enter Faculty Name : "<<endl;
    cin>>fname;
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
    int length=v.size();        //checking for matched month & Tehnology
    int i=0;
    int flag=0;
    while(i<length){
        if(tech==v[i+1] && fname==v[i+8]){
            flag=1;
            cout<<"Batch Id is : "<<v[i]<<endl;
            cout<<"Technology is : "<<v[i+1]<<endl;
            cout<<"Start_Date is : "<<v[i+2]<<endl;
            cout<<"End_Date is : "<<v[i+3]<<endl;
            cout<<"No_Of_Days is : "<<v[i+4]<<endl;
            cout<<"Venue is : "<<v[i+5]<<endl;
            cout<<"No_Of_Participant is : "<<v[i+6]<<endl;
            cout<<"Month_Of_Start is : "<<v[i+7]<<endl;
            cout<<"Faculty Name is : "<<v[i+8]<<endl;
            cout<<"Current Status is : "<<v[i+9]<<endl;
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
            cout<<"There is no Such Training for "<<tech<<" with name "<<fname<<endl;
        }
    }



    void updateSession(){
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
    string id;
    cout<<"Enter Batch_id for updating the Status.."<<endl;
    cin>>id;
    
    int i=0;
    int flag=0;
    string s;
    while(i<v.size()){
        if(v[i]==id){
            flag=1;
            cout<<"Enter No if you Wanna Cancel the Session else Enter Yes"<<endl;
            cin>>s;
            if(v[i+9]=="Yes"){
                cout<<"You cannot cancel the session"<<endl;
            }
            else if(v[i+9]=="No" || v[i+9]=="Yes/No"){
                v[i+9]=s;  
            }      
        }
        i=i+10;
    }
    if(flag==0){
        cout<<"No Such Record Found for batch_id...!!"<<endl;
    }
    file.open("faculty.csv",ios::out|ios::trunc);

    int z=0;
    while(z<v.size()){
        file<<v[z]<<","<<v[z+1]<<","<<v[z+2]<<","<<v[z+3]<<","<<v[z+4]<<","<<v[z+5]<<","<<v[z+6]<<","<<v[z+7]<<","<<v[z+8]<<","<<v[z+9]<<endl;
        z=z+10;
    }
    if(flag==1){
        cout<<"Session Updated Successfully...!"<<endl;
    }
    file.close();
    }

};

void ffaculty(){
    faculty f;
    int choice;
    bool flag=1;
    do{
    cout<<endl;
    cout<<endl;
    cout<<"|================================================|"<<endl;                                   
    cout<<"|             **-----Faculty Menu-----**         |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|               -Select An Option-               |"<<endl;
    cout<<"|          1. Find Schedule Allocated            |"<<endl;
    cout<<"|          2. Cancel Specific Session            |"<<endl;
    cout<<"|          3. Quit                               |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            f.generateSchedule();
            break;
        case 2:
            f.updateSession();
            break;
        case 3:
            system("exit");
            break;
        default:
            cout<<"Invalid Details..."<<endl;
            cout<<"Try Again.."<<endl;
    }
    }while(choice!=3);
}