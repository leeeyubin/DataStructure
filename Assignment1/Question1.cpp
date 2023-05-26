#include <iostream>
#include <string>

using namespace std;

string permutation(int n, int length) {
    string str(length, 'a');
    for (int i = length - 1; i >= 0; i--) {
        if (n & (1 << i)) {
            str[length - i - 1] = 'b';
        }
    }
    return str;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
        cout << permutation(i, n) << endl;
    return 0;
}
