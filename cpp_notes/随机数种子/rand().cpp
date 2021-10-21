/*
 * @Author: your name
 * @Date: 2021-10-20 21:02:22
 * @LastEditTime: 2021-10-21 08:42:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /Cpp/cpp_notes/随机数种子/rand().cpp
 */

#include <iostream>
#include <stdlib.h>
#incldue <time.h>

int main(){
  srand((unsigned)time(0));
  cout<<" Ten random numbers from"<<MIN<<
  "to"<<MAX<<endl;

  for(int i = 0; i < 10; i++){
    cout<<MIN + (int)MAX * rand() / (RAND_MAX + 1)<<"/t";
  }

  cout<<endl;
  return 0;
}