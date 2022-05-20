#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;                     //维护一个栈，元素类型为char
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') st.push(')');      //从左边开始遍历右括号入栈
      else if (s[i] == '[') st.push(']');
      else if (s[i] == '{') st.push('}');
      //当遍历过程中栈为空或者栈顶元素不是所遍历的元素时return false;
      else if (st.empty() || s[i] != st.top()) return false;
      else st.pop();  //遍历的元素为栈顶元素时出栈
    }
    return st.empty();  //栈空为true
  }
};

int main () {

  return 0;
}