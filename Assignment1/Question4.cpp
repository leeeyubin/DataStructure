#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	return GCD(b, r);
}
int main(void)
{
	int num1, num2;
	cin >> num1 >> num2;
	int res = GCD(num1, num2);
	cout << res;
	return 0;
}