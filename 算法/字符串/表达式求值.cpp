#include <bits/stdc++.h>
using namespace std;

// 描述
// 请写一个整数计算器，支持加减乘三种运算和括号。
// 输入：
// "(2*(3-4))*5"
// 返回值：
// -10

class Solution {
public:
    int solve(string s) {
        int res = 0; //用于返回当前字符串的计算结果
        stack<int> sum; //用于求和
        char sign = '+'; //记录前一个符号，初始化为+，因为可以看成当前字符串前先加0
        int num = 0; //用于将连续数字字符串转化成数字或者记录递归结果
        for(int i = 0; i < s.size(); i++) { //遍历每一个字符
            if(s[i] >= '0' && s[i] <= '9') //先处理数字字符
                num = 10 * num + s[i] - '0'; //进位后加个位数
            if(s[i] == '(') { //对于括号
                int left = i++, count = 1; //用left记录最左括号位置，count记录左括号数，i当成右指针右移一格
                while(count > 0) { //最终目的是找到与最左括号匹配的右括号，类似于栈操作
                    if(s[i] == '(') count++;
                    else if(s[i] == ')') count--;
                    i++;
                }
                num = solve(s.substr(left + 1, i - left - 2)); //迭代计算括号内数值，注意不要包含最左最右括号，不然会死循环
                i--; //此时i是最右括号下一位，需要左移一位防止最右括号在字符串尾时发生越界从而使下面的判定失效
            }
            if(i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*') { //对于字符串尾，或者加减乘，此时我们用的符号是上一次的，结算当前数字
                if(sign == '+') sum.push(num); //加法入栈
                else if(sign == '-') sum.push(-num); //减法相当于加负数
                else if(sign == '*') sum.top() *= num; //乘法与栈顶相乘
                sign = s[i]; //更新符号，若为末尾的右括号也无妨，因为马上就退出循环了
                num = 0; //重置当前数
            }
        }
        while(!sum.empty()) { //将栈内所有数字相加
            res += sum.top();
            sum.pop();
        }
        return res; //返回当前字符串计算结果
    }
};

int main() {

}