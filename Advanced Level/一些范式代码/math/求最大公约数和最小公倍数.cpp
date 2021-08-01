int gcd(int a, int b){
    if(b == 0)  return a;
    else  return gcd(b, a%b);
}

//或者
int gcb(int a, int b){
    return !b ? a : gcd(b, a%b);
}

//求最小公倍数
/*
  求两个数字分别为a,b; 他们的最大公约数为c
  那么最小公倍数为  a*b/c
*/
