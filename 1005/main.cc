// Sample Input

// 2
// 1.0 1.0
// 25.0 0.0
// Sample Output

// Property 1: This property will begin eroding in year 1.
// Property 2: This property will begin eroding in year 20.
// END OF OUTPUT.



#include <iostream>
#include <math.h>
#include <vector>
using namespace std;



float pi = 3.141592654;


int main(int argc, char const *argv[])
{
	int n = 0;
	cin >>n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		float x, y;
		cin >>x >>y;
		int year = ceil(pi/100*(x*x+y*y));
		v.push_back(year);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		/* code */
		cout <<"Property " <<i+1 <<": This property will begin eroding in year " <<v[i] <<"." <<endl;
	}
	cout <<"END OF OUTPUT.";
	return 0;
}