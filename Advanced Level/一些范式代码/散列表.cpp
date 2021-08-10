const int maxn = 10010;
bool hashTable = {false}; //用空间换时间

//......

//可以用C++的STL库中的map和unordered_map来实现散列表

//字符串的散列表
//不考虑大小写的话, id = id*26 + (S[i] - 'A')
//考虑大小写的话, id = id*52 + (S[i] - 'a')
