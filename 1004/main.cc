/*
Sample Input

100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75
Sample Output

$1581.42
*/



#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	float sum = 0.0;
	for (int i = 0; i < 12; ++i)
	{
		/* code */
		float val = 0.0;
		cin >>val;
		sum += val;
	}
	cout <<"$" <<sum/12 <<endl;
	return 0;
}