//进制转换,10进制转换为13进制
#include<iostream>

using namespace std;

int main(){
    string ans="#";
    int number, radix=13, remain;
    for(int i=0;i<3;i++){
        cin>>number;
        string single="";
        while(number>0){
            remain = number%radix;
            number = number / radix;
            if(remain == 10){
                single = "A" + single;
            }
            else if(remain == 11){
                single = "B" + single;
            }
            else if(remain == 12){
                single = "C" + single;
            }
            else{
                single = to_string(remain) + single;
            }
        }
        //cout<<single<<endl;
        while(single.length()<2){
            single = "0"+single;
        }
        ans += single;
    }
    cout<<ans;
    return 0;
}
