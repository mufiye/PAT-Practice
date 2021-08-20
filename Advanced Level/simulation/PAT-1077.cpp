//寻找最长的后缀,没有就输出nai
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<string> vec;
    string str, suffix="";
    scanf("%d\n",&n);
    //cout<<n<<endl;
    for(int i=0; i<n; i++){
        getline(cin, str);
        //cout<<str<<endl;
        vec.push_back(str);
    }
    int minLen=vec[0].length();
    for(int i=1; i<n; i++){
        if(vec[i].length()<minLen)  minLen = vec[i].length();
    }
    bool ifBreak = false;
    for(int i=0; !ifBreak && i<minLen; i++){
        for(int j=0; j<n-1; j++){
            if(vec[j][vec[j].length()-i-1] != vec[j+1][vec[j+1].length()-i-1]){
                ifBreak = true;
                break;
            }
        }
        if(!ifBreak)  suffix = vec[0][vec[0].length()-i-1] + suffix;
    }
    if(suffix.length() <= 0)  cout<<"nai"<<endl;
    else  cout<<suffix<<endl;
    return 0;
}
