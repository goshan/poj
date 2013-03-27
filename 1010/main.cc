// Sample Input

// 1 2 3 0	; three different stamp types
// 7 4 0		; two customers
// 1 1 0		; a new set of stamps (two of the same type)
// 6 2 3 0	; three customers
// Sample Output

// 7 (3): 1 1 2 3 
// 4 (2): 1 3 
// 6 ---- none
// 2 (2): 1 1
// 3 (2): tie



#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm> 
using namespace std;




bool inpute_data(vector<int> &stamps, vector<int> &val){
	int temp = -1;
	bool res = false;
	while(scanf("%d ", &temp) != EOF) {
		res = true;
		int num = 0;
		for (int i = 0; i < stamps.size(); ++i)
		{
			/* code */
			if (stamps[i] == temp)
			{
				/* code */
				num ++;
			}
		}
		if (num < 5)
		{
			/* code */
			stamps.push_back(temp);
		}
		if (temp == 0)
		{
			/* code */
			break;
		}
	}
	temp = -1;
	while (scanf("%d ", &temp) != EOF) {
		res = true;
		if (temp == 0)
		{
			/* code */
			break;
		}
		val.push_back(temp);
	}
	return res;
}

string gen_key(vector<int> a){
	stringstream ss;
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i)
	{
		/* code */
		ss <<a[i] <<"-";
	}
	return ss.str();
}

int get_type_num(const vector<int> &a, const vector<int> &stamps){
	set<int> temp;
	for (int i = 0; i < a.size(); ++i)
	{
		/* code */
		if (stamps[a[i]] != 0)
		{
			/* code */
			temp.insert(a[i]);
		}
	}
	return temp.size();
}

int get_sta_num(const vector<int> &a, const vector<int> &stamps){
	int res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		/* code */
		if (stamps[a[i]] != 0)
		{
			/* code */
			res ++;
		}
	}
	return res;
}

int get_max_val(const vector<int> &a, const vector<int> &stamps){
	int res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		/* code */
		if (stamps[a[i]] > res)
		{
			/* code */
			res = stamps[a[i]];
		}
	}
	return res;
}

void search(const vector<int> &stamps, const vector<int> &val, vector<int> &type_num, vector<string> &sol, vector<bool> &tie){
	set <string> repeat;
	vector<int> sta_num;
	vector<int> max_val;
	for (int m = 0; m < val.size(); ++m)
	{
		type_num.push_back(0);
		sta_num.push_back(100);
		max_val.push_back(0);
		tie.push_back(false);
		sol.push_back("");
	}


	for (int i = 0; i < stamps.size(); ++i)
	{
		for (int j = 0; j < stamps.size(); ++j)
		{
			for (int k = 0; k < stamps.size(); ++k)
			{
				for (int l = 0; l < stamps.size(); ++l)
				{
					int sum = stamps[i] + stamps[j] + stamps[k] + stamps[l];
					for (int m = 0; m < val.size(); ++m)
					{
						/* code */
						if (sum == val[m])
						{
							/* code */
							vector<int> temp;
							if (stamps[i] != 0)
							{
								/* code */
								temp.push_back(i);
							}
							if (stamps[j] != 0)
							{
								/* code */
								temp.push_back(j);
							}
							if (stamps[k] != 0)
							{
								/* code */
								temp.push_back(k);
							}
							if (stamps[l] != 0)
							{
								/* code */
								temp.push_back(l);
							}
							string key = gen_key(temp);
							if (!repeat.count(key))
							{
								/* code */
								repeat.insert(key);
								int tn = get_type_num(temp, stamps);
								int sn = get_sta_num(temp, stamps);
								int mv = get_max_val(temp, stamps);
								if (tn > type_num[m])
								{
									/* code */
									type_num[m] = tn;
									sta_num[m] = sn;
									max_val[m] = mv;
									tie[m] = false;
									sol[m] = key;
								}
								else if (tn == type_num[m]){
									if (sn < sta_num[m])
									{
										/* code */
										sta_num[m] = sn;
										max_val[m] = mv;
										tie[m] = false;
										sol[m] = key;
									}
									else if (sn == sta_num[m])
									{
										/* code */
										if (mv > max_val[m])
										{
											/* code */
											max_val[m] = mv;
											tie[m] = false;
											sol[m] = key;
										}
										else if (mv == max_val[m])
										{
											/* code */
											tie[m] = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void output(const vector<int> &stamps, const vector<int> &val, vector<int> type_num, vector<string> &sol, vector<bool> &tie){
	for (int i = 0; i < val.size(); ++i)
	{
		/* code */
		if (sol[i] == "")
		{
			/* code */
			for (int j = 0; j < i; ++j)
			{
				/* code */
				if (val[i] == val[j])
				{
					/* code */
					type_num[i] = type_num[j];
					sol[i] = sol[j];
					tie[i] = tie[j];
					break;
				}
			}
			if (sol[i] == "")
			{
				/* code */
				cout <<val[i] <<" ---- none" <<endl;
				continue;
			}
		}
		cout <<val[i] <<" (" <<type_num[i] <<"):";
		if (tie[i])
		{
			/* code */
			cout <<" tie" <<endl;
		}
		else {
			int pos = 0;
			vector<int> res;
			for (int j = 0; j < sol[i].length(); ++j)
			{
				/* code */
				if (sol[i][j] == '-')
				{
					/* code */
					int index = atoi(sol[i].substr(pos, j-pos).c_str());
					res.push_back(stamps[index]);
					pos = j+1;
				}
			}
			sort(res.begin(), res.end());
			for (int j = 0; j < res.size(); ++j)
			{
				/* code */
				cout <<" " <<res[j];
			}
			cout <<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	while (1){
		/* code */
		vector<int> stamps;
		vector<int> val;
		if (!inpute_data(stamps, val)){
			break;
		}
		vector<int> type_num;
		vector<string> sol;
		vector<bool> tie;
		search(stamps, val, type_num, sol, tie);
		output(stamps, val, type_num, sol, tie);
	}
	return 0;
}