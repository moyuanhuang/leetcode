#include "iostream"

using namespace std;

int count_one(int n) {
    int count = 0;
    while(n) {
        cout << n << endl;
        n = n&(n-1);
        count++;
    }
    return count;
}

int main(){
  int n = count_one(5);
  cout << "total number of 1 is:" << n << endl;
  return 0;
}
