// Sample Input

// 95.123 12
// 0.4321 20
// 5.1234 15
// 6.7592  9
// 98.999 10
// 1.0100 12
// Sample Output

// 548815620517731830194541.899025343415715973535967221869852721
// .00000005148554641076956121994511276767154838481760200726351203835429763013462401
// 43992025569.928573701266488041146654993318703707511666295476720493953024
// 29448126.764121021618164430206909037173276672
// 90429072743629540498.107596019456651774561044010001
// 1.126825030131969720661201







#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


void sepDouble2Array(const string &r, vector<int> &val, int &ppos){
	for (int i = r.length()-1; i >= 0; --i)
	{
		/* code */
		if (r[i] == '.')
		{
			/* code */
			ppos = r.length()-i-1;
		}
		else 
		{
			/* code */
			int bit = r[i]-'0';
			val.push_back(bit);
		}
	}
}

void multiple (const vector<int> &val1, const int &ppos1, const vector<int> &val2, const int &ppos2, vector<int> &val_res, int &ppos){
	ppos = ppos1+ppos2;

	int val_len = val1.size()+val2.size();
	vector<int> val_temp;

	for (int i = 0; i < val_len; ++i)
	{
		/* code */
		val_temp.push_back(0);
	}

	for (int i = 0; i < val1.size(); ++i)
	{
		/* code */
		for (int j = 0; j < val2.size(); ++j)
		{
			/* code */
			val_temp[i+j] += val1[i]*val2[j];
		}
	}

	for (int i = 0; i <val_temp.size(); i++)
	{
		/* code */
		if (val_temp[i] > 9)
		{
			/* code */
			int bit = val_temp[i]/10;
			val_temp[i] -= bit*10;
			val_temp[i+1] += bit;
		}
	}

	int val_pos = val_temp.size();
	for (int i = val_temp.size()-1; i >=0; --i)
	{
		/* code */
		if (val_temp[i] != 0)
		{
			/* code */
			val_pos = i+1;
			break;
		}
	}

	for (int i = 0; i < val_pos; ++i)
	{
		/* code */
		val_res.push_back(val_temp[i]);
	}
}

void gpow(const vector<int> &val, const int &ppos, const int &n, vector<int> &val_res, int &ppos_res){
	if (n == 1){
		ppos_res = ppos;
		val_res = val;
	}
	else if (n == 2){
		multiple(val, ppos, val, ppos, val_res, ppos_res);
	}
	else {
		if (n%2 == 0){
			vector<int> temp;
			int ppos_temp = 0;
			multiple(val, ppos, val, ppos, temp, ppos_temp);
			gpow(temp, ppos_temp, n/2, val_res, ppos_res);
		}
		else{
			vector<int> temp;
			int ppos_temp = 0;
			multiple(val, ppos, val, ppos, temp, ppos_temp);
			vector<int> temp_fin;
			int ppos_temp_fin = 0;
			gpow(temp, ppos_temp, n/2, temp_fin, ppos_temp_fin);
			multiple(val, ppos, temp_fin, ppos_temp_fin, val_res, ppos_res);
		}
	}
}

void output(const vector<int> &val, const int &ppos){
	if (ppos >= val.size())
	{
		/* code */
		cout <<".";
		for (int i = 0; i < ppos-val.size(); ++i)
		{
			/* code */
			cout <<"0";
		}
		for (int i = val.size()-1; i >= 0; --i)
		{
			/* code */
			cout <<val[i];
		}
	}
	else if (ppos == 0){
		for (int i = val.size()-1; i >= 0; --i)
		{
			/* code */
			cout <<val[i];
		}
	}
	else {
		int flag = -1;
		for (int i = 0; i < ppos; ++i)
		{
			/* code */
			if (val[i] != 0)
			{
				/* code */
				flag = i;
				break;
			}
		}
		if (flag == -1)
		{
			/* code */
			for (int i = val.size()-1; i >= ppos; --i)
			{
				/* code */
				cout <<val[i];
			}	
		}
		else{
			for (int i = val.size()-1; i >= flag; --i)
			{
				/* code */
				cout <<val[i];
				if (i == ppos)
				{
					/* code */
					cout <<".";
				}
			}
		}
	}
	cout <<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	string r = "";
	int n = 0;
	while (cin >>r >>n){
		vector<int> val;
		int ppos = 0;
		sepDouble2Array(r, val, ppos);

		vector<int> val_res;
		int ppos_res;
		gpow(val, ppos, n, val_res, ppos_res);
		output(val_res, ppos_res);
	}
	return 0;
}
