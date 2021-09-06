#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

string arr1[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string arr2[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

int main(){
    int N;
    cin>>N;
    getchar();
    unordered_map<string,int> mp1;
    unordered_map<string,int> mp2;
    for(int i=0;i<=12;i++){
        mp1[arr1[i]] = 13*i;
        mp2[arr2[i]] = i;
    }
    for(int i=0;i<N;i++){
        string str;
        getline(cin, str);
        //cout<<"this str is: "<<str<<endl;
        if(isdigit(str[0])){//是数字
            string res = "";
            int num = stoi(str);
            if (num / 13)  res += arr1[num / 13];
            if ((num / 13) && (num % 13))  res += " ";
            if (num % 13 || num == 0)  res += arr2[num % 13];
            cout<<res<<endl;
        }
        else{//是火星文
            int res=0;
            if(str.length() <= 4){
                //如何查看map中元素的存在情况
                if(mp1.count(str))  res = mp1[str];
                else  res = mp2[str];
            }
            else{
                string str1 = str.substr(0,3);
                string str2 = str.substr(4,3);
                res = mp1[str1] + mp2[str2];
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
