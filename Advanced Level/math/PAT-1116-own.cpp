//冠军是Mystery Award, 质数的排名为Minion, 其余均为Chocolate
//如果在上面的query中出现过结果则显示Checked, 如果query的id号未出现在rank list中则显示Are you kidding?
//1.如何判断是否存在      遍历查询
//2.如何判断是否判断过    哈希表？
//3.如何判
#include<iostream>
#include<string>
#include<unordered_set>
#define max_size 10001
using namespace std;

string arr[max_size];//下标从1开始
int N,K;
unordered_set<string> st;

bool isPrime(int number){
    if(number == 1)  return false;
    if(number == 2)  return true;
    for(int i=2;i*i<=number;i++){
        if(number % i == 0)  return false;
    }
    return true;
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++)  cin>>arr[i];
    cin>>K;
    for(int i=0;i<K;i++){
        string temp;
        cin>>temp;
        bool isExist = false;
        int j=1;
        for(;j<=N;j++){
            if(arr[j] == temp){
                isExist = true;
                break;
            }
        }
        if(!isExist)  cout<<temp<<": Are you kidding?"<<endl;//不存在的情况
        else{//存在的情况
            if(st.find(temp) == st.end()){//未检查过
                st.insert(temp);
                if(j == 1){//是冠军
                    cout<<temp<<": Mystery Award"<<endl;
                }
                else if(isPrime(j)){//排名是质数
                    cout<<temp<<": Minion"<<endl;
                }
                else{
                    cout<<temp<<": Chocolate"<<endl;
                }
            }
            else{//已经检查过
                cout<<temp<<": Checked"<<endl;
            }
        }
    }
    return 0;
}
