#include<iostream>
#include<string>

using namespace std;

const int INF = 999999999;

bool isContain(string str1, string str2, int &i){
    int j=0, len1 = str1.length(), len2 = str2.length();
    while(i<len1 && j<len2){
        if(str1[i] == str2[j]){
            j++;
        }
        i++;
    }
    return  j >= len2;
}

int main(){
    string s,p;
    cin>>s>>p;
    int len1 = s.length(), len2 = p.length();
    int minLen = INF, left = 0, right = len1-1;
    for(int i=0; i<len1-len2+1; i++){
        int index = i;
        if(isContain(s,p,index)){
            //cout<<"in"<<endl;
            int len = index-i;
            if(len < minLen){
                //cout<<"in"<<endl;
                minLen = len;
                left = i;
                right = index-1;
            }
        }
    }
    //cout<<"left is: "<<left<<endl;
    //cout<<"right is: "<<right<<endl;
    cout<<s.substr(left, right-left+1);
}
