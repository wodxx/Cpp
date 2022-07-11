#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int sign=1;
        //1.消去空格
        int i=0;
        while(str[i]==' ') i++;
        //2.判断符号
        if(str[i]=='-'){ 
            sign=-1;
            i++;
        }
        else if(str[i]=='+'){
            sign=1;                    //＋号sign不变
            i++;
        }
        long num=0; //防止越界
       while(str[i]>='0'&&str[i]<='9'){
           int val=str[i]-'0';
           num=num*10+sign*val;             //高位乘10 加 低位乘符号sign
           i++;
         if(num>=INT_MAX) return INT_MAX;
         if(num<=INT_MIN) return INT_MIN;
       }
       return (int)num;

    }
};