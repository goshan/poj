#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;


class Counter{
public:
	string number;
	int count;

	bool operator < (const Counter &c) const{
		return this ->number < c.number;
	};
};

string convert2Num(const string &line){
	stringstream ss;
	for (int i = 0; i < line.length(); ++i)
	{
		/* code */
		if (line[i] <= 'P' && line[i] >= 'A')
		{
			/* code */
			int val = (line[i]-'A')/3+2;
			ss <<(char)(val+'0');
		}
		else if (line[i] <= 'Y' && line[i] >= 'R')
		{
			/* code */
			int val = (line[i]-'Q')/3+7;
			ss <<(char)(val+'0');
		}
		else if (line[i] <= '9' && line[i] >= '0')
		{
			/* code */
			ss <<line[i];
		}
	}
	string res = ss.str();
	res = res.substr(0, 3) + "-" + res.substr(3);
	return res;
};

void insterQueue(const string &res, set<Counter> &queue){
	Counter c;
	c.number = res;
	set<Counter> ::iterator it = queue.find(c);
	if (it == queue.end())
	{
		/* code */
		c.count = 1;
		queue.insert(c);
	}
	else{
		queue.erase(c);
		c.count = it ->count + 1;
		queue.insert(c);
	}
};

void output(const set<Counter> &queue){
	int count = 0;
	set<Counter> ::const_iterator it = queue.begin();
	for (; it!=queue.end(); it++){
		if (it ->count > 1)
		{
			/* code */
			cout <<it ->number <<" " <<it ->count <<endl;
			count ++;
		}
	}
	if (count == 0)
	{
		/* code */
		cout <<"No duplicates." <<endl;
	}
};



int main(int argc, char const *argv[])
{
	char baseChr = 'A'-1;
	int num = 0;
	cin >>num;
	set<Counter> queue;

	for (int i = 0; i < num; ++i)
	{
		/* code */
		string line = "";
		cin >>line;
		string res = convert2Num(line);
		insterQueue(res, queue);
	}
	output(queue);
	return 0;
}