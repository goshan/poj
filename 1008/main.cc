// Sample Input

// 3
// 10. zac 0
// 0. pop 0
// 10. zac 1995
// Sample Output

// 3
// 3 chuen 0
// 1 imix 0
// 9 cimi 2801





#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;


string Haab_letter[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
							"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string Tzolkin_letter[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
							"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};



int getHaabInt(const string &s){
	for (int i = 0; i < 19; ++i)
	{
		/* code */
		if (s == Haab_letter[i])
		{
			/* code */
			return i;
		}
	}
}

int getTzolkinInt(const string &s){
	for (int i = 0; i < 20; ++i)
	{
		/* code */
		if (s == Tzolkin_letter[i])
		{
			/* code */
			return i;
		}
	}
}

int getDateFromHaab(const int &date, const string &month, const int &year){
	return year*365+getHaabInt(month)*20+date;
}

void getTzolkinFromDate(const int &date, int &num, string &letter, int &year){
	year = date/260;
	int sub_date = date-year*260;
	int letter_num = sub_date%20;
	letter = Tzolkin_letter[letter_num];
	num = sub_date%13+1;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<string> res;
	int n;
	cin >>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		string Haab_date_str;
		string Haab_month;
		int Haab_year;
		cin >>Haab_date_str >>Haab_month >>Haab_year;
		int Haab_date = atoi(Haab_date_str.substr(0, Haab_date_str.length()-1).c_str());
		
		int date = getDateFromHaab(Haab_date, Haab_month, Haab_year);
		
		int Tzolkin_num;
		string Tzolkin_letter;
		int Tzolkin_year;
		getTzolkinFromDate(date, Tzolkin_num, Tzolkin_letter, Tzolkin_year);

		stringstream ss;
		ss <<Tzolkin_num <<" " <<Tzolkin_letter <<" " <<Tzolkin_year;
		res.push_back(ss.str());
	}

	cout <<res.size() <<endl;
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}