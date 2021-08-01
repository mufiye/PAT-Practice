struct Fraction{
    int up;
    int down;
}

/*
  化简规则
  1. 如果分母的down为负数,那么分子和分母变为原来的相反数
  2. 如果该分数恰为0, 那么规定分子为0,分母为1
  3. 分子和分母没有除了1以外的公因数
*/
Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    
    if(result.up == 0){
        result.down = 1;
    }
    else{
        int d = gcd(abs(result.up), abs(result.down));
        result.up = result.up / d;
        result.down = result.down / d;
    }
    return result;
}

//分数的四则运算
//分数的加法
Fraction add(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//分数的减法
Fraction mimu(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//分数的乘法
Fraction multi(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

//分数的除法
Fraction divide(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;    
    return reduction(result);
}
