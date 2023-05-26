#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int>& mychar, int left, int right, int m, int& count);
int main() {
    int n, m;
    cin >> n;
    vector<int> mychar(n);
    for (int i = 0; i < n; i++) {
        cin >> mychar[i];
    }
    cin >> m;
    int count = 0;
    int res = BinarySearch(mychar, 0, n - 1, m, count);
    cout << res << endl;
    cout << count << endl;
    return 0;
}
int BinarySearch(vector<int>& mychar, int left, int right, int m, int& count) {
    if (left <= right) {
        int middle = (left + right) / 2;
        count++;
        if (m < mychar[middle]) {
            return BinarySearch(mychar, left, middle - 1, m, count);
        }
        else if (m > mychar[middle]) {
            return BinarySearch(mychar, middle + 1, right, m, count);
        }
        else {
            return middle;
        }
    }
    return -1;
}
