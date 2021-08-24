#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct Stu{
    string name;
    int height;
};

bool cmp(Stu student1, Stu student2){
    if(student1.height == student2.height)  return student1.name > student2.name;
    else  return student1.height < student2.height;
}
int main(){
    int N,K;
    vector<Stu> vec;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        Stu stu;
        cin>>stu.name>>stu.height;
        vec.push_back(stu);
    }
    int num = N/K, extraNum = N%K;
    sort(vec.begin(), vec.end(), cmp);
    vector<Stu> arr[num];
    int upNum = num*K;
    for(int i=0; i<upNum; i++){
        arr[i/K].push_back(vec[i]);
    }
    for(int i=0;i<extraNum;i++){
        arr[num-1].push_back(vec[upNum+i]);
    }
    for(int i=num-1; i>=0; i--){
        int size = arr[i].size();
        int start = -1;
        bool isOut = false;
        if(size%2 == 0)  start = 0;
        else start = 1;
        for(int j=0; j<size/2; j++){
            isOut = true;
            if(j == 0)  cout<<arr[i][start].name;
            else  cout<<" "<<arr[i][start + 2*j].name;
        }
        if(isOut)  cout<<" "<<arr[i][size-1].name;
        else  cout<<arr[i][size-1].name;
        for(int j = size/2+1; j<size; j++){
            cout<<" "<<arr[i][size-1-(j-size/2)*2].name;
        }
        cout<<endl;
    }
    return 0;
}
