#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//本菜鸡参考了https://blog.csdn.net/qq_24572475/article/details/82811274
//我觉得关键点是使用结构体记录学生id和成绩（这样方便之后的排序），Rank数组记录排名
//第一次提交测试点过不了，仔细检查以后发现是Rank[stuVec[i].id][course] = i+1;这个语句一开始赋值号右边写成了Rank[stuVec[i-1].id][course]

struct Student{
    int id;
    float grade[4];
};

int course,N,M;
string coursesName[4] = {"A","C","M","E"};
int Rank[1000000][4]={0};
bool cmp(Student a, Student b){
    return a.grade[course]>b.grade[course];
}

int main(){
    cin>>N>>M;
    vector<Student> stuVec;
    vector<int> idVec(M);
    for(int i=0;i<N;i++){
        Student stu;
        cin>>stu.id;
        cin>>stu.grade[1];
        cin>>stu.grade[2];
        cin>>stu.grade[3];
        stu.grade[0] = (stu.grade[3]+stu.grade[1]+stu.grade[2])/3;
        stuVec.emplace_back(stu);
    }
    for(int i=0;i<M;i++){
        cin>>idVec[i];
    }
    for(course=0;course<4;course++){
        sort(stuVec.begin(),stuVec.end(),cmp);
        Rank[stuVec.begin()->id][course] = 1;
        for(int i=1;i<stuVec.size();i++){
            if(stuVec[i].grade[course] == stuVec[i-1].grade[course])  Rank[stuVec[i].id][course] = Rank[stuVec[i-1].id][course];
            else  Rank[stuVec[i].id][course] = i+1;//这里要注意是i+1
        }
    }
    for(int i=0;i<idVec.size();i++){
        if(Rank[idVec[i]][0] == 0)  cout<<"N/A"<<endl;
        else{
            int tempCourse = 0;
            for(int j=1;j<4;j++){
                if(Rank[idVec[i]][j]<Rank[idVec[i]][tempCourse]) tempCourse = j;
            }
            cout<<Rank[idVec[i]][tempCourse]<<" "<<coursesName[tempCourse]<<endl;
        }
    }
    return 0;
}
