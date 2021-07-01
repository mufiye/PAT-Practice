#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Student{
    string name;
    string id;
    int grade;
    bool isMan;
};

int N;

bool cmpM(Student stu1, Student stu2){
    return stu1.grade<stu2.grade;
}

bool cmpF(Student stu1, Student stu2){
    return stu1.grade>stu2.grade;
}

int main(){
    cin>>N;
    vector<Student> vecM;
    vector<Student> vecF;
    for(int i=0;i<N;i++){
        Student stu;
        char sex;
        cin>>stu.name>>sex>>stu.id>>stu.grade;
        if(sex == 'M'){
           stu.isMan = true;
           vecM.emplace_back(stu);
        }
        else{
           stu.isMan = false;
           vecF.emplace_back(stu);
        }
    }
    
    if(vecF.size() <= 0 && vecM.size() <= 0){
        cout<<"Absent"<<endl;
        cout<<"Absent"<<endl;
        cout<<"NA"<<endl;
    }
    else if(vecM.size() <= 0){
        sort(vecF.begin(),vecF.end(),cmpF);
        cout<<vecF.begin()->name<<" "<<vecF.begin()->id<<endl;
        cout<<"Absent"<<endl;
        cout<<"NA"<<endl;
    }
    else if(vecF.size() <= 0){
        cout<<"Absent"<<endl;
        sort(vecM.begin(),vecM.end(),cmpM);
        cout<<vecM.begin()->name<<" "<<vecM.begin()->id<<endl;
        cout<<"NA"<<endl;
    }
    else{
        sort(vecM.begin(),vecM.end(),cmpM);
        sort(vecF.begin(),vecF.end(),cmpF);
        cout<<vecF.begin()->name<<" "<<vecF.begin()->id<<endl;
        cout<<vecM.begin()->name<<" "<<vecM.begin()->id<<endl;
        cout<<vecF.begin()->grade-vecM.begin()->grade<<endl;
    }
}
