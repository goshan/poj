#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;




map<int, vector<string> > sequence_list;

vector<int> convert2num(const string &s){
	vector<int> res;
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		switch (s[i]){
			case 'A': 
			res.push_back(1);
			break;
			case 'C': 
			res.push_back(2);
			break;
			case 'G': 
			res.push_back(3);
			break;
			case 'T': 
			res.push_back(4);
			break;
		}
	}
	return res;
}

int get_sortedness(const vector<int> &sequence){
	int res = 0;

	vector<vector<int> > dis_num;
	for (int i = 0; i < sequence.size(); ++i)
	{
		/* code */
		vector<int> elem;
		elem.push_back(0);
		elem.push_back(0);
		elem.push_back(0);
		elem.push_back(0);
		dis_num.push_back(elem);
	}

	for (int i = 0; i < sequence.size()-1; ++i)
	{
		/* code */
		dis_num[i+1][0] = dis_num[i][0];
		dis_num[i+1][1] = dis_num[i][1];
		dis_num[i+1][2] = dis_num[i][2];
		dis_num[i+1][3] = dis_num[i][3];
		dis_num[i+1][sequence[i]-1] ++;
	}

	for (int i = 0; i < sequence.size(); ++i)
	{
		/* code */
		for (int j = sequence[i]; j < 4; ++j)
		{
			/* code */
			res += dis_num[i][j];
		}
	}
	return res;
}

void add_sequence(const string &sequence){
	vector<int> seq_arr = convert2num(sequence);
	int sortedness = get_sortedness(seq_arr);
	map<int, vector<string> > ::iterator it = sequence_list.find(sortedness);
	if (it == sequence_list.end())
	{
		/* code */
		vector<string> elem;
		elem.push_back(sequence);
		sequence_list[sortedness] = elem;
	}
	else {
		sequence_list[sortedness].push_back(sequence);
	}
}

void output(){
	map<int, vector<string> > ::const_iterator it = sequence_list.begin();
	for(; it!=sequence_list.end(); it++){
		for (int i = 0; i < it ->second.size(); ++i)
		{
			/* code */
			cout <<it ->second[i] <<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	int m, n;
	cin >>m >>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		string s;
		cin >>s;
		add_sequence(s);
	}
	output();
	return 0;
}