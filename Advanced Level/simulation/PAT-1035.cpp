#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    string str, teamId;
    vector<string> vec1, vec2;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>teamId>>str;
        bool isModify = false;
        for(int j=0; j<str.length(); j++){
            if(str[j] == '1'){
                isModify = true;
                str[j] = '@';
            }
            else if(str[j] == '0'){
                isModify = true;
                str[j] = '%';
            }
            else if(str[j] == 'l'){
                isModify = true;
                str[j] = 'L';
            }
            else if(str[j] == 'O'){
                isModify = true;
                str[j] = 'o';
            }
        }
        if(isModify){
            vec1.push_back(teamId);
            vec2.push_back(str);
        }
    }
    
    if(vec1.size() > 0){
        cout<<vec1.size()<<endl;
        for(int i=0;i<vec1.size();i++){
            cout<<vec1[i]<<" "<<vec2[i]<<endl;
        }
    }
    else if(n != 1){
        cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    else if(n == 1){
        cout<<"There is 1 account and no account is modified"<<endl;
    }
    return 0;
}
