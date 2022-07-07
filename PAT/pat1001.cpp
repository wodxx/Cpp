// 本题输入输出：
// input:-1000000 9
// output: -999,991

// [知识点]:英文书写中数字的标准书写,低位起每三位用一个逗号隔开,逗号前后无空格！！！！
// [知识点]：一个数值，整体对某一个数m取余若等于开头某几位对m取余，则说明开头某几位后面的位数个数是m的倍数

// 解法1： 直接遍历输出
// [理解]
// 插入间隔位的判别处理，总字符数对3取余的余数（即开头的数位情况），直接影响后续的判别下标（在此基础上累加3个单位，然后末尾情况要排除）。
#include <iostream>
#include <string>
using namespace std;

int main () {
  int m, n, sum;
  cin >> m >> n;
  sum = m + n;
  if (sum != 0) { 
    if (sum < 0) cout <<"-";                     //负数情况处理 先输出负号
    sum = abs(sum);
    string str = to_string(sum);                 //转字符串
    for (int i = 0; i < str.size (); i++) {
      cout << str[i];
      if (i != str.size() - 1 && (i + 1) % 3 == (str.size() % 3)) {     //i != str.size() 排除末尾情况
        //用i+1的长度取余3和str的大小取余3作比较 相等输出commas            //i从0开始，算开头的位数前要加1
        cout << ",";                                                    //一个数值，整体对某一个数m取余若等于开头某几位对m取余，则说明
      }                                                                 //开头某几位后面的位数个数是m的倍数
    }
  } else {
    cout << 0 << endl;
  }
  return 0;
}