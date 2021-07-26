#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Stu{
    string id;
    string name;
    int grade;
};

int N,C;

bool cmp(Stu student1, Stu student2){//均要求升序
    if(C == 1){//考虑id
        return student1.id<student2.id;
    }
    else if(C==2){//考虑name,如果相同则考虑id
        if(student1.name == student2.name)  return student1.id<student2.id;
        else  return student1.name<student2.name;
    }
    else{//考虑grade,如果相同则考虑id
        if(student1.grade == student2.grade)  return student1.id<student2.id;
        else  return student1.grade<student2.grade;
    }
}

int main(){
    //读取
    cin>>N>>C;
    vector<Stu> vec;
    for(int i=0;i<N;i++){
        Stu student;
        string id,name;
        int grade;
        cin>>id>>name>>grade;
        student.id = id;
        student.name = name;
        student.grade = grade;
        vec.push_back(student);
    }
    
    //排序
    sort(vec.begin(),vec.end(),cmp);
    
    //输出
    for(size_t i=0;i<vec.size();i++){
        cout<<vec[i].id<<" "<<vec[i].name<<" "<<vec[i].grade<<endl;
    }
    return 0;
}
