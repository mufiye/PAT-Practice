//my rule learned from this question: 散列问题中有string的话就可以不用set了
//疑问: toupper的参数类型是int为什么s1[i]输进去也可以？
//toupper将小写字母变为大写字母, tolower将大写字母变为小写字母

#include<iostream>
#include<cctype>

using namespace std;

int main(){
    string s1,s2,ans;
    cin>>s1>>s2;//因为没有空格,空格被_代替
    for(int i=0;i<s1.length();i++){
        if(s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    }
    cout<<ans<<endl;
    return 0;
}
