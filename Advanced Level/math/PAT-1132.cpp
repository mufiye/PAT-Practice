#include<iostream>
#include<string>

using namespace std;

bool judge(int a, int b, int sum){
    if(a == 0 || b==0)  return false;
    return sum%(a*b) == 0;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string numStr;
        cin>>numStr;
        int len = numStr.length();
        string numStr1 = numStr.substr(0,len/2);
        string numStr2 = numStr.substr(len/2,len/2);
        int number1 = stoi(numStr1);
        int number2 = stoi(numStr2);
        int sumNum = stoi(numStr);
        bool judgeVal = judge(number1,number2,sumNum);
        if(judgeVal)  cout<<"Yes"<<endl;
        else  cout<<"No"<<endl;
    }
    return 0;
}
