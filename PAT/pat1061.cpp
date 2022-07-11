#include<iostream>
#include<vector>
#include<string.h>
#include<map>
using namespace std;
 
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif // ONLINE_JUDGE
 
    int d, h, m;//d天 h时 m分
    string day[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
 
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
 
    int flag = 0;
    for(int i = 0; i < s1.length() && i < s2.length(); i++){
        if(flag == 1 && s1[i] == s2[i]){
            if(s1[i] >= '0' && s1[i] <= '9'){
                h = s1[i] - '0';
                break;
            }
            else if(s1[i] >= 'A' && s1[i] <= 'N'){           //A - N 是顺序
                h = s1[i] - 'A' + 10;
                break;
            }
        }
        if(flag == 0 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G'){//'A' <= s1[i] <= 'G'
            d = s1[i] - 'A';
            flag = 1;                                    // 定义一个flag把d先求出来
        }
    }
 
    for(int i = 0; i < s3.length() && i < s4.length(); i++){
        if(s3[i] == s4[i] && isalpha(s3[i])){
            m = i;
            break;
        }
    }
 
    printf("%s %02d:%02d", day[d].c_str(), h, m);
    return 0;
}