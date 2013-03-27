#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct node
{
	/* data */
	int height;
	int row;
	int col;
};

vector<vector<int> > height;
vector<node> node_str;
vector<vector<int> > path_length;



bool cmp(const node &a, const node &b){
	return a.height < b.height;
}

int get_max(const int &a, const int &b){
	return a>b ? a : b;
}

int get_length(const int &row, const int &col){
	int max = 1;
	if (row > 0 && height[row][col] > height[row-1][col])
	{
		/* code */
		max = get_max(max, path_length[row-1][col]+1);
	}
	if (row < height.size()-1 && height[row][col] > height[row+1][col])
	{
		/* code */
		max = get_max(max, path_length[row+1][col]+1);
	}
	if (col > 0 && height[row][col] > height[row][col-1])
	{
		/* code */
		max = get_max(max, path_length[row][col-1]+1);
	}
	if (col < height[0].size()-1 && height[row][col] > height[row][col+1])
	{
		/* code */
		max = get_max(max, path_length[row][col+1]+1);
	}
	path_length[row][col] = max;
	return max;
}

int com_path_length(){
	int max = -1;
	for (int i = 0; i < node_str.size(); ++i)
	{
		/* code */
		struct node elem = node_str[i];
		int res = get_length(elem.row, elem.col);
		if (res > max)
		{
			/* code */
			max = res;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	/* code */
	int row, col;
	cin >>row >>col;
	height = vector<vector<int> > (row, vector<int> (col, 0));
	path_length = vector<vector<int> > (row, vector<int> (col, 1));
	for (int i = 0; i < row; ++i)
	{
		/* code */
		for (int j = 0; j < col; ++j)
		{
			/* code */
			cin >>height[i][j];
			struct node n;
			n.height = height[i][j];
			n.row = i;
			n.col = j;
			node_str.push_back(n);
		}
	}
	sort(node_str.begin(), node_str.end(), cmp);
	cout <<com_path_length() <<endl;
	return 0;
}