#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

// bool isLegal(string str){//如何判断是否为数字？
    
// }

int main(){
    int N,num=0;
    double temp = 0.0;
    double sum = 0.0;
    char a[100], b[100];
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%s",a);
        sscanf(a, "%lf", &temp);//输入到temp
        sprintf(b, "%.2f",temp);//输出到b
        int flag = 0;
        for(int j=0;j<strlen(a);j++){
            if(a[j] != b[j]){
                flag = 1;
                break;
            }
        }
        if(flag || temp < -1000 || temp > 1000){
            printf("ERROR: %s is not a legal number\n",a);
            continue;
        }
        else{
            sum += temp;
            num++;
        }
    }
    if(num == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(num > 1)
        printf("The average of %d numbers is %.2f", num, sum / num);
    else
        printf("The average of 0 numbers is Undefined");
//     if(num>=1)  printf("The average of %d numbers is %.2f",num,sum/num);
//     else  printf("The average of 0 numbers is Undefined");
    return 0;
}
