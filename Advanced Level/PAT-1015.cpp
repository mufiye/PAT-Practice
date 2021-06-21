//十进制转换为N进制 和 N进制数表示
//注意不仅要判断reverse的number还要判断not reserve的number
#include<iostream>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

bool judgePrime(int number){
	bool yes = true;
	if (number<2) yes = false;
	for (int i=2; i*i<=number;i++){
		if (number%i==0) {
			yes = false;
			break;
		}	
	}
	return yes;
}

int main(){
    while(true){
        //获取输入
        int N,D;
        cin>>N;
        if(N<0) return 0;
        cin>>D;
        
        //开始处理
        vector<int> v;
		do
		{
			v.push_back(N%D);
			N /= D;
		} while (N);
		int sum = 0,sum2 = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i] * pow(D, v.size()-1-i);
		}
        for (int i = 0; i < v.size(); i++)
		{
			sum2 += v[i] * pow(D, i);
		}
		if (judgePrime(sum) && judgePrime(sum2))  cout<<"Yes"<<endl;
		else  cout<<"No"<<endl;
    }
    return 0;
}
