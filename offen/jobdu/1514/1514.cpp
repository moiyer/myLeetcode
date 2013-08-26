#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

double powerWithUnsignedExp(double base, int exponent)
{
	if(exponent == 0)return 1;
	else if(exponent == 1)return base;
	double ret = powerWithUnsignedExp(base, exponent >> 1);

	ret *= ret;
	if(exponent & 0x01)ret *= base;
	return ret;
}

bool error = 0;
double power(double base, int exponent)
{
	error = 0;
	if(base - 0.0 <= 0.0000001 && 0.0 - base <= 0.0000001 && exponent < 0)
	{
		error = 1;
		return 0.0;
	}

	int abs = 0;
	if(exponent < 0)
		abs = exponent * (-1);

	if(exponent >= 0)return powerWithUnsignedExp(base, abs);
	else return 1.0 / powerWithUnsignedExp(base, abs);
}

int main()
{
	int n;
	double base;
	int exponent;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> base >> exponent;
		cout << power(base, exponent) << endl;
	}
	system("pause");
	return 0;
}