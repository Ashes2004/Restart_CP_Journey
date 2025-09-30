#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 1 << n; // 2^n
    for (int i = 0; i < total; i++) {
        int g = i ^ (i >> 1); 
        
        for (int j = n - 1; j >= 0; j--) {
            cout << ((g >> j) & 1);
        }
        cout << "\n";
    }
    return 0;
}
