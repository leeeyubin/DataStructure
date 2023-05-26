#include <iostream>
using namespace std;
int Combination(int n, int r)
{
	if (r == 1)
		return n;
	else if (r == 0 || n == r)
		return 1;

	return (Combination(n - 1, r - 1) + Combination(n - 1, r));
}
int main(void)
{
	int n, r;
	cin >> n >> r;
	int res = Combination(n, r);
	cout << res;

	return 0;
}