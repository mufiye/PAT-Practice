//像编译原理一样读取每一个字符，遇到非字母数字的分隔符作为整个字符串读取，使用isalnum判断一个char是否为字母或数字(cctype库)
//用map记录字符串及出现次数，寻找最大值就遍历map