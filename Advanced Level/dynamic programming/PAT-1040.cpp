#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str;
    int maxLen = 1;
    bool isFind = false;
    getline(cin, str);
    //reverse(str.begin(), str.end());//反转字符串的函数
    //reverse(str.begin(), str.begin() + str.length());//证明可以用begin加长度来表示index
    //cout<<str<<endl;
    for(int len = str.length(); !isFind && len>=2; len--){
        for(int i=0; i <= str.length() - len; i++){
            string temp = str;
            reverse(temp.begin()+i, temp.begin()+i+len);
            if(temp == str){
                isFind = true;
                maxLen = len;
                break;
            }
        }
    }
    cout<<maxLen;
    return 0;
}
