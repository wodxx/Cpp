#include <bist/stdc++.h>
using namespace std;

bool isPrime(unsigned int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <=  sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {

  return 0;
}