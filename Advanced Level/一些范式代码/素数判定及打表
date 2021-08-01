bool isPrime(int n){
    if(n <= 1)  return false; //特判
    int sqr = (int)sqrt(1.0 * n);
    for(int i=2; i<=sqr; i++){
        if(n%i == 0)  return false;  //n不是素数
    }
    return true; //n为素数
}

const int maxn = 101;
int prime[maxn], pNum = 0; //prime数组存放所有素数, pNum为素数个数
bool p[maxn] = {0}; //p[i] == true表示i是素数
void Find_Prime(){
    for(int i=1; i<maxn; i++){
        if(isPrime(i) == true){
            prime[pNum++] = i;  //是素数则把i存入prime数组
            p[i] = true;
        }
    }
}
