//寻找狼人,有两个狼人,所有人中有两个人撒谎,有一个狼人说谎
//参与游戏的总人数范围为[5,100]
//遍历,假设有两个人是狼人,那么如何判断这种情况是否成立？
/*
  创建一个数组arr,其中记录的是第i个下标(下标从1开始)的人说的某个下标的人是普通人还是狼人
  遍历观察下标为i的人有没有说谎,说谎则将该下标存入一个lie数组
  之后用lie数组判断是否符合一个狼人和一个普通人说谎的情况
*/
