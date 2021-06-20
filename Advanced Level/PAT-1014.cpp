//有段错误和部分用例错误
//参考的是柳神

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M,K,Q;
int maxTime = 60*(17-8);
int minWaitTime;

struct node{
    int poptime=0;//该窗口队首的人完成事务的时间
    int endtime=0;//该窗口队列所有人完成事务所需要的时间
    queue<int> q;
};

int main(){
    cin>>N>>M>>K>>Q;
    int arr[K+1];//下标i存储id为i的客户的业务处理时间
    int queryRes[K+1]={0};//下标为i存储的为下标为i的客户完成业务处理的时间（以分钟为单位，以8点为起点）
    vector<node> windows(N+1);
    vector<bool> sorry(N+1,false);
    //初始化一开始不用等待就能够进入黄线的客户
    for(int i=1;i<=K;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            windows[j].q.push((i-1)*N+j);
            if(windows[j].endtime>=maxTime)  sorry[(i-1)*N+j]=true;
            windows[j].endtime += arr[(i-1)*N+j];
            if(i==1)  windows[j].poptime = windows[j].endtime;
            queryRes[(i-1)*N+j] = windows[j].endtime;
        }
    }
    
    //将等待在黄线外的客户依次放入windows队列
    for(int i=N*M+1;i<=K;i++){
        int temp = 1, tempVal = windows[1].poptime;
        for(int j=2;j<=N;j++){
            if(windows[j].poptime<tempVal){
                tempVal = windows[j].poptime;
                temp = j;
            }
        }
        windows[temp].q.push(i);
        if(windows[temp].endtime>=maxTime)  sorry[i] = true;
        windows[temp].q.pop();
        windows[temp].poptime += arr[windows[temp].q.front()];
        windows[temp].endtime += arr[i];
        queryRes[i] = windows[temp].endtime;
    }
    
    //输出结果
    for(int i=0;i<Q;i++){
        int customerId;
        cin>>customerId;
        if(sorry[customerId])  cout<<"Sorry"<<endl;
        else{
            int curTime = queryRes[customerId];
            int hour = 8+curTime/60;
            int minute = curTime%60;
            //标准化输出,HH:MM
            printf("%02d:%02d\n",hour, minute);
            //cout<<hour<<":"<<minute<<endl;
        }
    }
    return 0;
}
