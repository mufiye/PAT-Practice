//有错误，只拿了14分
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string getDecreNum(string str){
    vector<int> vec;
    for(int i=0;i<str.length();i++){
        vec.emplace_back(str[i]-'0');
    }
    sort(vec.rbegin(),vec.rend());
    string res;
    for(int i=0;i<vec.size();i++){
        res = res + to_string(vec[i]);
    }
    return res;
}

string getIncreNum(string str){
    vector<int> vec;
    for(int i=0;i<str.length();i++){
        vec.emplace_back(str[i]-'0');
    }
    sort(vec.begin(),vec.end());
    string res;
    for(int i=0;i<vec.size();i++){
        res = res + to_string(vec[i]);
    }
    return res;
}

string convert(int number){//将整数类型转换成字符串类型
    string str = to_string(number);
    for(int i=str.length();i<4;i++){
        str = "0" + str;
    }
    return str;
}

int main(){
    string str;
    cin>>str;
    int res=-1;
    while(res!=0 && res!=6174){
        string numStr1 = getDecreNum(str);
        string numStr2 = getIncreNum(str);
        cout<<numStr1<<" - "<<numStr2<<" = ";
        int number1 = stoi(numStr1);
        int number2 = stoi(numStr2);
        res = number1 - number2;
        str = convert(res);//要补齐为四位
        cout<<str<<endl;
    }
    return 0;
}
