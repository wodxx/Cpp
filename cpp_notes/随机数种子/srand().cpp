/*
 * @Author: your name
 * @Date: 2021-10-20 21:15:49
 * @LastEditTime: 2021-10-20 22:07:20
 * @FilePath: /Cpp/cpp_notes/随机数种子/srand().cpp
 */

 
#include <iostream> 
using namespace std; 
#include <stdlib.h> 
#include <time.h> 
#define MIN 0 //随机数产生的范围 
#define MAX 99 


int main() 
{ 
    srand((unsigned)time(NULL)); 
    cout<<"Ten random numbers from "<<MIN<< " to "<<MAX<<" :/n"<<endl; 
    for(int i=0; i<10; i++) //产生随机数 
    { 
        cout<<MIN + rand() % (MAX + MIN - 1)<<"/t"; 
    } 
    cout<<endl; 
    return 0; 
} 