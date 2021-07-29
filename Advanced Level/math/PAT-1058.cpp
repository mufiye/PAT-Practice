// #include<iostream>
// #include<string>
// #include<vector>
// #include<stack>

// using namespace std;

// int main(){
//     string str1, str2, temp="";
//     cin>>str1>>str2;
//     stack<int> a,b;
//     vector<int> res;
//     for(int i=0;i<str1.length();i++){
//         if(i == str1.length()-1)  a.push(stoi(temp));
//         else if(str1[i] != '.'){
//             temp += str1[i];
//         }
//         else{
//             a.push(stoi(temp));
//             temp = "";
//         }
//     }
//     for(int i=0;i<str2.length();i++){
//         if(i == str2.length()-1)  b.push(stoi(temp));
//         else if(str2[i] != '.'){
//             temp += str2[i];
//         }
//         else{
//             b.push(stoi(temp));
//             temp = "";
//         }
//     }
//     //做加运算
//     int arr[3] = {29,17,10000000};
//     for(int i=0;i<3;i++){
//         int num1 = a.top();
//         a.pop();
//         int num2 = b.top();
//         b.pop();
//         int fillNum = (num1+num2)%arr[i];
//         int inNum = (num1+num2)/arr[i];
//         if(i!=2)  a.top() += inNum;
//         res.push_back(fillNum);
//     }
//     for(int i=2;i>=0;i--){
//         if(i!=2)  cout<<res[i];
//         else  cout<<"."<<res[i];
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    int a1, b1, c1, a2, b2, c2, a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c = c1 + c2;
    b = b1 + b2 + c / 29; c = c % 29;
    a = a1 + a2 + b / 17; b = b % 17;
    printf("%d.%d.%d\n", a, b, c);
    return 0;
}
