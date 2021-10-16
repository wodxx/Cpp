/* 
 * @Author: wxh
 * @Date: 2021-10-16 17:00:51
 * @LastEditTime: 2021-10-16 17:29:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Cpp/算法/Josephuse环/递推.cpp
   @Question:从0到n个数中，每次数m个数，删除第m个数，下次从第m+1个数开始，继续数m个数删除第m个数，
   直到最后剩最后一个数，返回输出最后一个数。
 */
#include <iostream>
using namespace std;

class solution{
  int LastRemaining(unsigned m, unsigned n){
    if(m < 1 || n < 1) return -1;
    
    int last = 0;
    //这里从2开始，n的值要取到n
    for(int i = 2; i <= n; i++){
      last = (last + m) % i;
    }
    
    return last;
  }
};

int main(){

  return 0;
}

/* 

[理解]：
最后只剩下一个元素，假设这个最后存活的元素为 num, 这个元素最终的的下标一定是0 （因为最后只剩这一个元素），
所以如果我们可以推出上一轮次中这个num的下标，然后根据上一轮num的下标推断出上上一轮num的下标，
直到推断出元素个数为n的那一轮num的下标，那我们就可以根据这个下标获取到最终的元素了（因为这是一组从0开始的n个数字，
元素个数为n之后的数字的下标值同数字本值）。

推断过程如下：

首先最后一轮中num的下标一定是0， 这个是已知的。
那上一轮应该是有两个元素，此轮次中 num 的下标为 (0 + m)%n = (0+3)%2 = 1; 说明这一轮删除之前num的下标为1；
再上一轮应该有3个元素，此轮次中 num 的下标为 (1+3)%3 = 1；说明这一轮某元素被删除之前num的下标为1；
再上一轮应该有4个元素，此轮次中 num 的下标为 (1+3)%4 = 0；说明这一轮某元素被删除之前num的下标为0；
再上一轮应该有5个元素，此轮次中 num 的下标为 (0+3)%5 = 3；说明这一轮某元素被删除之前num的下标为3；
....

因为我们要删除的序列为0到n-1, 所以求得下标其实就是求得了最终的结果。比如当n 为5的时候，num的初始下标为3，
 所以num就是3，也就是说从0-n-1的序列中， 经过n-1轮的淘汰，3这个元素最终存活下来了，也是最终的结果。

总结一下推导公式：(此轮过后的num下标 + m) % 上轮元素个数 = 上轮num的下标（num也就是最后剩余的最后一个值）
上面为反推公式，程序中已知最后剩的值的下标为0,即从0开始，写递推公式 last = (last + m) % i ,i值循环取到n。

注：摘自leetcode《剑指offer》第62题“不是秒针”用户的评论。

 */
