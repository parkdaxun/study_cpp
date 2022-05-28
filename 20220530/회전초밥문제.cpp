#include <iostream>
using namespace std;

int arr[20][2]={0}, n, money;

int check(int i) {
	
	int nmoney=0, sum=0;
	
	for(int z=i; z<n; z++) {
		if(nmoney >= money) return sum;
		nmoney += arr[z][0];
		sum += arr[z][1];
	}
	return sum;
}

int main() {
	int max=0;
	
	cin>>n>>money;
	for(int i=0; i<n; i++) {
		for(int j=0; j<2; j++)
			cin>>arr[i][j];
	}
	
	int temp;
	for(int i=0; i<n; i++) {
		temp = check(i);
		if(temp > max) max = temp;
	}
	
	cout << max;
	return 0;
}