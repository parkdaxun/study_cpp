#include <iostream>
using namespace std;

int n;
int m;
bool relation[10][10];

int countParing(bool taken[])
{
	int small;
	bool finished = true;
	for(int i=0; i<n; i++)
	{
		if(!taken[i])
		{
			finished = false;
			small = i;
			break;
		}
	}
	if(finished) return 1;
	
	int count = 0;
	for(int i=small+1; i<n; i++) {
		if(!taken[i] && relation[small][i])
		{
			taken[small] = true;
			taken[i] = true;
			count += countParing(taken);
			taken[small] = false;
			taken[i] = false;
		}
	}
	return count;
}

int main(void) 
{
	bool taken[10];
	
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int f1, f2;
		cin >> f1 >> f2;
		relation[f1][f2] = true;
		relation[f2][f1] = true;
	}
	
	for(int i=0; i<10; i++)
	{
		taken[i] = false;
	}
	int result = countParing(taken);
	cout << result << endl;
	return 0;
}
