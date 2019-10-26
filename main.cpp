#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Date
{
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};
struct Student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};
struct Class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <Student> Data;
};
vector <Class> Database ;
void SelectClass(string);
void AddClass(string);
void RemoveClass(string);
void AddStudent(string, Date, unsigned long long int, float);
void RemoveStudent(unsigned long long int);
void Search(unsigned long long int);
void Search(string,string);
void ShowClass(string);
void ShowAll();
void SortByName();
void SortByID();
void Save();
void start();
void Rank();
int main()
{
    start();
    return 0;
}
vector <string> slct; //name of classes that added
int bad=-1;//number of selected class in database
vector <string> classnm;
string esm;//name of selected class(Classname)
int h=0;//show that the user select none class or not
void start(){
    cout<<"HELLO DEAR USER!"<<endl<<" WELCOME TO YOUR PROGRAM!!  "<<endl<<"Command something:"<<"(for understanding how to use this programm ,command basu help)" << endl;
    while(1){
        string receive;
        getline(cin, receive);
        vector <string> command;
        vector <string> sttt;
        string temp;
        string selected;
        for (char i : receive)
        {
            if (i != ' '){
                temp += i;
            }
            else
            {
                command.push_back(temp);
                temp = "";
            }
        }
        command.push_back(temp);
       
        if(command[0]=="basu") {
            if (command[1] == "add") {
                if (command[2] == "class") {
                    if ((command[3] == "L1.basu") || (command[3] == "L2.basu") || (command[3] == "L3.basu") ||
                        (command[3] == "L4.basu") || (command[3] == "L5.basu")) {
                        classnm.push_back(command[3]);
                        AddClass(command[3]);
                    }
                    cout << "wrong file name!!" << endl;
                }
                if (command[2] == "student") {
                    float average;
                    unsigned long long int code;
                    Date mmm;
                    string name, days;
                    cout << "enter your average:";
                    while (true) {
                        cin >> average;
                        if (average > 20 || average < 0) {
                            cout << "Wrong input for average!!!";
                            continue;
                        }
                        break;
                    }
                    cout << "enter your student code:";
                    while (true) {
                        cin >> code;
                        if (code < 1000000000 || code >= 10000000000) {
                            cout << "Wrong input for code!!!";
                            continue;
                        }
                        break;
                    }
                    cout << "enter your name & familyname:";
                    getline(cin, name);
                    cout << "enter your date of birth(with this type(year/month/day)):";
                    while (true) {
                        cin >> days;
                        for (char i : days) {
                            if (i != '/') {
                                temp += i;
                            } else {
                                sttt.push_back(temp);
                                temp = "";
                            }
                        }
                        sttt.push_back(temp);
                        if (sttt[1] == "" || sttt[2] == "" || sttt[3] == "") {
                            cout << "Wrong input for inputing type!!!";
                            continue;
                        }
                        break;
                    }
                    mmm.Year = (stoi(sttt[1]));
                    mmm.Month = (stoi(sttt[2]));
                    mmm.Day = (stoi(sttt[3]));
                    AddStudent(name, mmm, code, average);
                }
            }
            if (command[1] == "remove") {
                if (command[2] == "class") {
                    for (int i = 0; i < slct.size(); i++) {
                        if (command[3] == slct[i]) {
                            RemoveClass(command[3]);
                        }
                    }
                    cout << "Wrong input for classname!!!" << endl;
                } else if (command[2] == "student") {
                    cout << "enter your student code:" << endl;
                    RemoveStudent(stoi(command[3]));
                }
            }
            if (command[1] == "select") {
                if (command[2] == "class") {
                    for (int i = 0; i < slct.size(); i++) {
                        if (command[3] == slct[i]) {
                            h--;
                            SelectClass(command[3]);
                        }
                    }
                    cout << "Wrong input for classname!!!" << endl;
                }
            } else if (command[2] == "none") {
                h++;
                cout << "unselected choosen" << endl;//I don't know//
            }

            if (command[1] == "search") {
                string ten;
                vector<string> sdsd;
                for (char ss: command[2]) {
                    if (ss != ' ')
                        ten += ss;
                    else {
                        sdsd.push_back(ten);
                    }
                }
                sdsd.push_back(ten);
                if (sdsd[1] != "") {
                    Search(sdsd[0], sdsd[1]);
                } else {
                    Search(stoi(sdsd[0]));
                }
                cout << "enter your student code:" << endl;
                Search(stoi(command[2]));//syntax is correct or not???//
            }

            if (command[1] == "show") {
                if (command[2] == "") {
                    if (h < 0) {
                        ShowClass(esm);
                    }
                    ShowAll();    //showing all classes//
                } else if (command[2] != "") {
                    ShowClass(command[2]);//showing a particular class//
                }
            }
            if (command[1] == "sort") {
                if (command[2] == "name") {
                    SortByName();
                } else if (command[2] == "id") {
                    SortByID();
                }
            }
            if (command[1] == "save") {
                Save();
            }
            if (command[1] == "help") {
                cout << "Hello dear user.this program works with command lines that you enter." << endl;
                cout << "we have 16 command lines that each other do some works diffrence. " << endl;
                cout << "First:basu add class File Name" << endl;
                cout << "Notice:File Names are L1.basu ,L2.basu,L3.basu,L4.basu,L5.basu" << endl;
                cout << "First describtion:this command added one file that you choose to the database" << endl;
                cout << "Second:basu remove class Class Name" << endl;
                cout << "Notice:Class Name is the first string in the classes " << endl;
                cout << "Second describtion:this command gets a classname and remove it from database" << endl;
                cout << "Third:basu add student" << endl;
                cout << "Third describtion:this command add a student to the choosen class" << endl;
                cout << "Notice:the choosen class is a class the we select it (go to Fifth type of command) " << endl;
                cout << "Forth:basu remove student ID" << endl;
                cout << "Forth describtion:you choose a student id and then that student will removefrom database"
                     << endl;
                cout << "Fifth:basu select class Class Name" << endl;
                cout
                        << "Fifth describtion:it means that the class that its classname is that one you command contains removing,adding,showing and something like this"
                        << endl;
                cout << "Sixth: basu select none" << endl;
                cout
                        << "Sixth describtion:it means that the class that you selected doesn't have that particular options"
                        << endl;
                cout << "Seventh:basu search Id" << endl;
                cout << "Seventh describtion:this command search this id in the selected class and show it's parameters"
                     << endl;
                cout << "Eight:basu search Full Name" << endl;
                cout << "Notice:Full Name means Firstname and Lastname" << endl;
                cout
                        << "Eight describtion:this command search this firstname and lastname in the selected class and show the parameters "
                        << endl;
                cout << "Ninth:basu show" << endl;
                cout
                        << "Ninth describtion:this command have two manners:first one is that you were selected a class(in this manner the programm will show you data of this class)   "
                        << endl;
                cout
                        << "second one is that you haven't selected any class or you none that(in this manner the programm will show you all classes you added)"
                        << endl;
                cout << "Tenth:basu show Class Name" << endl;
                cout << "Tenth describtion: this command will show you a particular class " << endl;
                cout << "Eleventh:basu sort name" << endl;
                cout
                        << "Eleventh describtion:this command will sort all studentclasses with their Firstnames and Lastnames "
                        << endl;
                cout << "Twelveth:basu sort name" << endl;
                cout << "Twelveth describtion:this command will sort all studentclasses with their ids " << endl;
                cout << "Thirteenth:basu save" << endl;
                cout
                        << "Thirteenth decscribtion:this command save any class in our database that you added on a diffrent file"
                        << endl;
                cout << "Fourtheenth:exit" << endl;
                cout << "Fourtheenth describtion:this command will ended the programm" << endl;
                cout << "Fifteenth:basu help" << endl;
                cout
                        << "Fifteenth describtion:this is what you ccommand it and show you what the programm works and how to use it"
                        << endl;
                cout << "The last one:basu rank" << endl;
                cout
                        << "The last describtion:this command show you the number of the people who get more than 18 with A,between 15 and 18 with B,between 12 and 15 with C, between 10 and 12 with D and lower than 10 with E "
                        << endl;
                //explains how  does the programm work
            }
            if (command[1] == "rank") {
                Rank();
            }
        }

    if(command[0]=="exit"){
            cout<<"thank you for using this programm"<<endl;
            break;
        }
        else{
            cout<<"The title is not valid ."<<endl;
        }
    }
    return;
}
void SelectClass(string slnm)
{
    Class cls;
    ifstream y;
    y.open(slnm.c_str(),ios::in);
    if(!y)
    {
        cout<<"there is error!!"<<endl;
        return;
    }
    y>>cls.ClassName;
    int i = 0;
    for(i=0;i<slct.size();i++)
    {
        if(cls.ClassName==slct[i])
        {
            bad=i;
            esm=cls.ClassName;
            break;
        }
    }
    if(bad!=-1)
        cout<<"the class was selected"<<endl;
    return;
}
void AddClass(string clname)
{
    Class cl;
    ifstream x;
    x.open(clname.c_str(),ios::in);
    if(!x)
    {
        cout<<"there is error!!"<<endl;
        return;
    }
    x>>cl.ClassName;
    slct.push_back(cl.ClassName);
    x>>cl.Capacity;
    float sum = 0;
    for(int i=0;i<cl.Capacity;i++){
        Student mcl;
        x>>mcl.Firstname;
        x>>mcl.Lastname;
        string date;
        x>>date;
        string temp;
        vector <string> st;
        for (char i : date)
        {
            if (i != '/') {
                temp += i;
            }
            else
            {
                st.push_back(temp);
                temp = "";
            }
        }
        st.push_back(temp);
        mcl.Birthday.Year = (stoi(st[0]));
        mcl.Birthday.Month = (stoi(st[1]));
        mcl.Birthday.Day = (stoi(st[2]));
        x>>mcl.Grade;
        sum+=mcl.Grade;
        x>>mcl.ID;
        cl.Data.push_back(mcl);
    }
    cl.Average=(sum/cl.Capacity);
    Database.push_back(cl);
    return;
}
void RemoveClass(string clnm)
{
    for(int i=0;i<classnm.size();i++)
    {
        if(Database[i].ClassName == clnm)
        {
            Database.erase(Database.begin() + i);
            cout<<"class was removed successfully!!"<<endl;
            return;
        }
    }
    cout<<"the class was not added before"<<endl;
}
void AddStudent(string nmvfa, Date tt, unsigned long long int id, float av)
{
    if(h>0){
        cout<<"first you have to choose a class"<<endl;
        return;
    }

    Student st;
    st.ID=id;
    st.Birthday=tt;
    st.Grade=av;
    vector <string> nms;
    string nm;
    for(char i:nmvfa){
        if(i!=' ')
            nm+=i;
        else
            nms.push_back(nm);

    }
    nms.push_back(nm);
    st.Firstname=nms[0];
    st.Lastname=nms[1];
    Database[bad].Data.push_back(st);
    int h=Database[bad].Capacity;
    Database[bad].Average=((Database[bad].Average*h+av)/h+1);
    Database[bad].Capacity+=1;
    return;
}
void RemoveStudent(unsigned long long int id)
{
    if(h>0){
        cout<<"first you have to choose a class"<<endl;
        return;
    }
    for(int i=0;i<Database[bad].Capacity;i++)
    {
        if(Database[bad].Data[i].ID==id)
        {
            float av=Database[bad].Data[i].Grade;
            Database[bad].Data.erase(Database[bad].Data.begin() + i);
            int h=Database[bad].Capacity;
            Database[bad].Average=((Database[bad].Average*h-av)/h-1);
            Database[bad].Capacity-=1;
            return;
        }
    }
    cout<<"wrong there is no id match"<<endl;
    return;
}
void Search(unsigned long long int id){

    for(int i=0;i<Database.size();i++){
        for(int j=0;j<Database[i].Data.size();j++){
            if(Database[i].Data[j].ID==id){
                cout<<Database[i].Data[j].ID<<'\t';
                cout<<Database[i].Data[j].Firstname<<'\t';
                cout<<Database[i].Data[j].Lastname<<'\t';
                cout<<Database[i].Data[j].Grade;
                cout<<Database[i].Data[j].Birthday.Year<<"/";
                cout<<Database[i].Data[j].Birthday.Month<<"/";
                cout<<Database[i].Data[j].Birthday.Day<<endl;
                return;
            }
        }
    }
    cout<<"there is no student with this id "<<endl;

    return;
}
void Search(string name, string fname){
    for(int i=0;i<Database.size();i++){
        for(int j=0;j<Database[i].Data.size();j++){
            if((Database[i].Data[j].Firstname==name)&&(Database[i].Data[j].Lastname==fname)){
                cout<<Database[i].Data[j].ID<<'\t';
                cout<<Database[i].Data[j].Firstname<<'\t';
                cout<<Database[i].Data[j].Lastname<<'\t';
                cout<<Database[i].Data[j].Grade;
                cout<<Database[i].Data[j].Birthday.Year<<"/";
                cout<<Database[i].Data[j].Birthday.Month<<"/";
                cout<<Database[i].Data[j].Birthday.Day<<endl;
                return;
            }
        }
    }
    cout<<"there is no student with this name and familyname!!";
    return;
}
void ShowClass(string clnm){
    for(int i=0;i<Database.size();i++){
        if(Database[i].ClassName==clnm){
            cout<<"this is Classname"<<clnm<<endl;
            cout<<"this is Average"<<Database[i].Average<<endl;
            cout<<"this is Capacity"<<Database[i].Capacity<<endl;
            for(int j=0;j<Database[i].Data.size();j++)
            {
                cout<<Database[i].Data[j].Firstname<<'\t';
                cout<<Database[i].Data[j].Lastname<<'\t';
                cout<<Database[i].Data[j].ID<<'\t';
                cout<<Database[i].Data[j].Grade<<'\t';
                cout<<Database[i].Data[j].Birthday.Year<<"/";
                cout<<Database[i].Data[j].Birthday.Month<<"/";
                cout<<Database[i].Data[j].Birthday.Day<<endl;
            }
            return;
        }
        cout<<"there is no class name like this "<<endl;
    }



    return;
}
void ShowAll(){
    for(int i=0;i<Database.size();i++){

        cout<<"this is Classname"<<Database[i].ClassName<<endl;
        cout<<"this is Average"<<Database[i].Average<<endl;
        cout<<"this is Capacity"<<Database[i].Capacity<<endl;
        for(int j=0;j<Database[i].Data.size();j++){
            cout<<Database[i].Data[j].Firstname<<'\t';
            cout<<Database[i].Data[j].Lastname<<'\t';
            cout<<Database[i].Data[j].ID<<'\t';
            cout<<Database[i].Data[j].Grade<<'\t';
            cout<<Database[i].Data[j].Birthday.Year<<"/";
            cout<<Database[i].Data[j].Birthday.Month<<"/";
            cout<<Database[i].Data[j].Birthday.Day<<endl;
        }

    }

    return;
}
void SortByName(){
    for(int i=0;i<Database.size();i++){
        for(int j=Database[i].Capacity;j>0;j--){
            for(int k=0;k<j;k++){
                if((Database[i].Data[k].Firstname)>(Database[i].Data[k+1].Firstname)){
                    string f=(Database[i].Data[k+1].Firstname);
                    (Database[i].Data[k+1].Firstname)=(Database[i].Data[k].Firstname);
                    (Database[i].Data[k].Firstname)=f;
                }

            }
        }
    }
    cout<<"the classes was sort by names"<<endl;

    return;
}
void SortByID(){
    for(int i=0;i<Database.size();i++){
        for(int j=Database[i].Capacity;j>0;j--){
            for(int k=0;k<j;k++){
                if((Database[i].Data[k].ID)>(Database[i].Data[k+1].ID)){
                    unsigned long long int f=(Database[i].Data[k+1].ID);
                    (Database[i].Data[k+1].ID)=(Database[i].Data[k].ID);
                    (Database[i].Data[k].ID)=f;
                }

            }
        }
    }
    cout<<"the classes was sort by ids"<<endl;

    return;
}
void Save(){
    for(int i=0;i<Database.size();i++){
        ofstream open("text" + to_string(i) + ".txt");
        open<<Database[i].ClassName<<endl;
        open<<Database[i].Average<<endl;
        open<<Database[i].Capacity<<endl;
        for(int j=0;j<Database[i].Data.size();j++){
            open<<Database[i].Data[j].Firstname<<'\t';
            open<<Database[i].Data[j].Lastname<<'\t';
            open<<Database[i].Data[j].ID<<'\t';
            open<<Database[i].Data[j].Grade<<'\t';
            open<<Database[i].Data[j].Birthday.Year<<"/";
            open<<Database[i].Data[j].Birthday.Month<<"/";
            open<<Database[i].Data[j].Birthday.Day<<endl;
        }
        open.close();
        open.close();
    }
    return;
}
void Rank(){
    if(h>0){
        cout<<"you hadn't select a class";
        return;
    }
    int fff = 0, B = 0, C = 0, D = 0, E=0;
    for(int j=0;j<Database[bad].Data.size();j++){
        if((Database[bad].Data[j].Grade>18)&&(Database[bad].Data[j].Grade<=20))
        fff++;
        if((Database[bad].Data[j].Grade>15)&&(Database[bad].Data[j].Grade<=18))
        B++;
        if((Database[bad].Data[j].Grade>12)&&(Database[bad].Data[j].Grade<=15))
        C++;
        if((Database[bad].Data[j].Grade>10)&&(Database[bad].Data[j].Grade<=12))
        D++;
        if((Database[bad].Data[j].Grade>0)&&(Database[bad].Data[j].Grade<=10))
        E++;
    }
    cout<<"rank A:"<<fff<<endl;
    cout<<"rank B:"<<B<<endl;
    cout<<"rank C:"<<C<<endl;
    cout<<"rank D:"<<D<<endl;
    cout<<"rank E:"<<E<<endl;

    return;
}









