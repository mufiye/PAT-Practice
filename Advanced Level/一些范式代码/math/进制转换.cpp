//将P进制数x转换为十进制数y
int y = 0, product = 1;
while(x != 0){
    y = y + (x%10)*product;
    x = x / 10;
    product = product * P;
}

//将十进制数y转换为Q进制数z
int z[40], num=0;
do{
  z[num++] = y % Q;
  y = y / Q;
}while(y != 0);
