#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
	vector<int> res_list;
	int p, e, i, d;
	int j=1;
	while (1){
		cin >>p >>e >>i >>d;
		if (p == -1 && e == -1 && i == -1 && d == -1)
		{
			/* code */
			break;
		}
		int res = (5544*p+14421*e+1288*i-d+21252)%21252;
		res = res <= 0 ? res+21252 : res;
		cout <<"Case " <<j <<": the next triple peak occurs in " <<res <<" days." <<endl;
		j++;
	}
	return 0;
}