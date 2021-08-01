//存储大整数
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
}

//将字符串表示的整数存入bign结构体
//整数的高位变为数组的低位, 整数的低位变为了数组的高位
bign change(char str[]){
    bign a;
    a.len = strlen(str); //bign的长度就是字符串的长度
    for(int i=0; i<a.len; i++){
        a.d[i] = str[a.len - i -1] - '0';
    }
    return a;
}

//比较两个大数
int compare(bign a, bign b){
    if(a.len > b.len)  return 1;//a大
    else if(a.len < b.len)  return -1;//a小
    else{
        for(int i = a.len-1; i>=0; i--){
            if(a.d[i] > b.d[i])  return 1;
            else if(a.d[i] < b.d[i])  return -1;
        }
        return 0; //表示相等
    }
}

//高精度加法
bign add(bign a, bign b){
    bign c;
    int carry = 0; //carry表示进位
    for(int i=0; i<a.len || i<b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}

//高精度减法
bign sub(bign a, bign b){
    bign c;
    for(int i=0; i<a.len || i<b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    
    while(c.len - 1 >= 1 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}

//高精度乘法
bign multi(bign a, int b){
    bign c;
    int carry = 0;
    for(int i=0; i<a.len; i++){
        int temp = a.d[i]*b + carry;
        c.d[c.len++] = temp % 10; 
        carry = temp/10;
    }
    
    while(carry != 0){//和加法不一样, 乘法的进位可能不止一位
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

//高精度除法
bign divide(bign a, int b, int& r){//r为余数
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i>=0; i--){
        r = r*10 + a.d[i]; //和上一位遗留的余数组合
        if(r<b) c.d[i] = 0;
        else{ //够除
            c.d[i] = r/b; //商
            r = r%b; /获取新的余数
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){//去除最高位的0,同时至少保留一位最低位
        c.len--;
    }
    return c;
}
