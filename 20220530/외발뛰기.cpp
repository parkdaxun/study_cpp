#include <iostream>
using namespace std;

int n;
int board[100][100];
int possibility[100][100];

bool jump(int x, int y) {
	
	for(int i=n-1; i>=x; i--) {
		for(int j=n-1; j>=y; j--) {
			if(i==n-1 && j==n-1) possibility[i][j] = 1;
			int jumpSize = board[i][j];
			if(i+jumpSize >= n && j+jumpSize>=n) possibility[i][j]=0;
			else if(i+jumpSize >= n) possibility[i][j] = possibility[i][j+jumpSize];
			else possibility[i][j] = possibility[i][j+jumpSize] || possibility[i+jumpSize][j];
		}
	}
	return possibility[x][y];
}

int main() {
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>board[i][j];
		}
	}
	if(jump(0, 0)==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}