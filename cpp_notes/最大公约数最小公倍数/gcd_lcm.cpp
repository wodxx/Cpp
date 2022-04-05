#include<iostream>
using namespace std;

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a%b); //辗转相除法求最大公约数
}

int lcm(int a, int b){
  return a * b / gcd(a, b);       //两数之积等于这两数的最小公倍数乘以最大公约数
}

int main(){
  return 0;
}