#include <iostream>
#include <vector>
using namespace std;



void com_sol(vector<int> &sol){
	for (int i = 0; i < 13; ++i)
	{
		/* code */
		sol.push_back(0);
	}
	int kill[28];
	for (int i = 0; i < 28; ++i)
	{
		/* code */
		kill[i] = 0;
	}
	for (int g = 0; g < sol.size(); ++g)
	{
		/* code */
		int k = g+1;
		int m = k+1;
		while (1){
			bool find = true;
			for (int i = 0; i < k; ++i)
			{
				/* code */
				kill[i+1] = (kill[i]+m-1)%(2*k-i);
				if (kill[i+1] < k)
				{
					/* code */
					find = false;
					break;
				}
			}
			if (find)
			{
				/* code */
				sol[g] = m;
				break;
			}
			m++;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	//vector<int> sol;
	//com_sol(sol);
	int sol[13] = {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
	int k = 0;
	while (cin >>k){
		if (k == 0)
		{
			/* code */
			break;
		}
		cout <<sol[k-1] <<endl;
	}
	return 0;
}


