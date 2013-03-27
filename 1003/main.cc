#include <iostream>
#include <math.h>
using namespace std;



int main(int argc, char const *argv[])
{
	float length = 0.0;
	cin >>length;
	while (length != 0.0){
		float l = 0.0;
		int i=1;
		while(length>l){
			i++;
			l += (float)1/i;
		}
		cout <<i-1 <<" card(s)" <<endl;
		cin >>length;
	}
	return 0;
}