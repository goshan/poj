#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;



// void decoding(const vector<int> &val, const vector<int> &len, vector<int> &image){
// 	int cnt = 0;
// 	for (int i=0; i<val.size(); i++){
// 		cout <<len[i] <<endl;
// 		for (int j=0; j<len[i]; j++){
// 			image.push_back(val[i]);
// 		}
// 	}
// }

// void encoding(const vector<int> &image, vector<int> &val, vector<int> &len){
// 	int l = 1;
// 	for (int i=1; i<image.size(); i++){
// 		if (image[i] == image[i-1]){
// 			l ++;
// 		}
// 		else {
// 			val.push_back(image[i-1]);
// 			len.push_back(l);
// 			l = 1;
// 		}
// 		if (i == image.size()-1){
// 			val.push_back(image[i]);
// 			len.push_back(l);
// 		}
// 	}
// }

// void get_edge1(const int &col_num, const vector<int> &image, vector<int> &edge){
// 	vector<vector<int> > state;    //0--not compute, 1--has computed
// 	for(int i=0; i<image.size(); i++){
// 		edge.push_back(-1);
// 		vector<int> s;
// 		for(int j=0; j<8; j++){
// 			s.push_back(0);
// 		}
// 		state.push_back(s);
// 	}

// 	for (int i=0; i<image.size(); i++){
// 		int pos = 0;
// 		int sub = 0;
// 		if (i%col_num != col_num-1)
// 		{
// 			/* code */
// 			//right 
// 			pos = i+1;
// 			sub = abs(image[i]-image[pos]);
// 			if (sub > edge[i])
// 			{
// 				/* code */
// 				edge[i] = sub;
// 			}
// 			if (sub > edge[pos])
// 			{
// 				/* code */
// 				edge[pos] = sub;
// 			}

// 			if (i < image.size()-col_num)
// 			{
// 				/* code */
// 				//right down conner 
// 				pos = i+col_num+1;
// 				sub = abs(image[i]-image[pos]);
// 				if (sub > edge[i])
// 				{
// 					/* code */
// 					edge[i] = sub;
// 				}
// 				if (sub > edge[pos])
// 				{
// 					/* code */
// 					edge[pos] = sub;
// 				}
// 			}
// 		}

// 		if (i < image.size()-col_num)
// 		{
// 			/* code */
// 			//down 
// 			pos = i+col_num;
// 			sub = abs(image[i]-image[pos]);
// 			if (sub > edge[i])
// 			{
// 				/* code */
// 				edge[i] = sub;
// 			}
// 			if (sub > edge[pos])
// 			{
// 				/* code */
// 				edge[pos] = sub;
// 			}

// 			if (i%col_num != 0)
// 			{
// 				/* code */
// 				//left down conner
// 				pos = i+col_num-1;
// 				sub = abs(image[i]-image[pos]);
// 				if (sub > edge[i])
// 				{
// 					/* code */
// 					edge[i] = sub;
// 				}
// 				if (sub > edge[pos])
// 				{
// 					/* code */
// 					edge[pos] = sub;
// 				}
// 			}
// 		}
// 	}
// }

int get_val(const vector<int> &val, const vector<int> &sum, const int &current){
	if (current < sum[0])
	{
		/* code */
		return val[0];
	}
	else if (current >= sum[sum.size()-1])
	{
		/* code */
		return -1;    //out of range
	}
	for (int i = 0; i < sum.size()-1; ++i)
	{
		/* code */
		if (current >= sum[i] && current < sum[i+1])
		{
			/* code */
			return val[i+1];
		}
	}
}

string gen_key(const vector<int> &val, const vector<int> &sum, const int &col_num, const int &current){
	int center = 0;
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int ul = 0;
	int ur = 0;
	int dl = 0;
	int dr = 0;

	center = get_val(val, sum, current);
	if (current < col_num)
	{
		/* code */
		up = center;
	}
	else{
		up = get_val(val, sum, current-col_num);
	}
	if (current >= sum[sum.size()-1] - col_num)
	{
		/* code */
		down = center;
	}
	else {
		down = get_val(val, sum, current+col_num);
	}
	if (current%col_num == 0)
	{
		/* code */
		left = center;
	}
	else {
		left = get_val(val, sum, current-1);
	}
	if (current%col_num == col_num-1)
	{
		/* code */
		right = center;
	}
	else {
		right = get_val(val, sum, current+1);
	}
	if (current < col_num || current%col_num == 0)
	{
		/* code */
		ul = center;
	}
	else{
		ul = get_val(val, sum, current-col_num-1);
	}
	if (current < col_num || current%col_num == col_num-1)
	{
		/* code */
		ur = center;
	}
	else{
		ur = get_val(val, sum, current-col_num+1);
	}
	if (current >= sum[sum.size()-1] - col_num || current%col_num == 0)
	{
		/* code */
		dl = center;
	}
	else {
		dl = get_val(val, sum, current+col_num-1);
	}
	if (current >= sum[sum.size()-1] - col_num || current%col_num == col_num-1)
	{
		/* code */
		dr = center;
	}
	else {
		dr = get_val(val, sum, current+col_num+1);
	}

	stringstream ss;
	ss <<center <<"-" <<up <<"-" <<down <<"-" <<left <<"-" <<right <<"-" <<ul <<"-" <<ur <<"-" <<dl <<"-" <<dr;
	return ss.str();
}

int gen_val(const vector<int> &val, const vector<int> &sum, const int &col_num, const int &current){
	int temp = 0;

	int center = 0;
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int ul = 0;
	int ur = 0;
	int dl = 0;
	int dr = 0;

	center = get_val(val, sum, current);
	if (current < col_num)
	{
		/* code */
	}
	else{
		up = get_val(val, sum, current-col_num);
		int sub = abs(center-up);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current >= sum[sum.size()-1] - col_num)
	{
		/* code */
	}
	else {
		down = get_val(val, sum, current+col_num);
		int sub = abs(center-down);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current%col_num == 0)
	{
		/* code */
	}
	else {
		left = get_val(val, sum, current-1);
		int sub = abs(center-left);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current%col_num == col_num-1)
	{
		/* code */
	}
	else {
		right = get_val(val, sum, current+1);
		int sub = abs(center-right);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current < col_num || current%col_num == 0)
	{
		/* code */
	}
	else{
		ul = get_val(val, sum, current-col_num-1);
		int sub = abs(center-ul);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current < col_num || current%col_num == col_num-1)
	{
		/* code */
	}
	else{
		ur = get_val(val, sum, current-col_num+1);
		int sub = abs(center-ur);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current >= sum[sum.size()-1] - col_num || current%col_num == 0)
	{
		/* code */
	}
	else {
		dl = get_val(val, sum, current+col_num-1);
		int sub = abs(center-dl);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}
	if (current >= sum[sum.size()-1] - col_num || current%col_num == col_num-1)
	{
		/* code */
	}
	else {
		dr = get_val(val, sum, current+col_num+1);
		int sub = abs(center-dr);
		if (sub > temp)
		{
			/* code */
			temp = sub;
		}
	}

	return temp;
}

void get_edge(const int &col_num, const vector<int> &val, const vector<int> &sum, vector<int> &val_e, vector<int> &len_e){
	map<string, int> repeat;
	for (int i = 0; i < sum[sum.size()-1]; ++i)
	{
		/* code */
		string key = gen_key(val, sum, col_num, i);
		map<string, int> ::iterator it = repeat.find(key);
		if (it == repeat.end())
		{
			/* code */
			int sub = gen_val(val, sum, col_num, i);
			repeat[key] = sub;
			val_e.push_back(sub);
			len_e.push_back(1);
		}
		else {
			if (it ->second == val_e[val_e.size()-1])
			{
				/* code */
				len_e[len_e.size()-1]++;
			}
			else {
				val_e.push_back(it ->second);
				len_e.push_back(1);
			}
		}
	}
}


int main(){
	int col_num;
	cin >>col_num;
	vector<int> val;
	vector<int> len;
	vector<int> sum;
	int last = 0;
	while (1){
		int v, l;
		cin >>v >>l;
		if (v == 0 && l == 0){
			break;
		}
		val.push_back(v);
		len.push_back(l);
		last += l;
		sum.push_back(last);
	}
	cout <<"====11111======" <<endl;
	vector<int> val_e;
	vector<int> len_e;
	get_edge(col_num, val, sum, val_e, len_e);
	for (int i=0; i<val_e.size(); i++){
		cout <<val_e[i] <<" " <<len_e[i] <<endl;
	}
	cout <<"0 0" <<endl;
	return 0;
}