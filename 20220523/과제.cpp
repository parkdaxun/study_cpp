#include <iostream>
using namespace std;

int f(int n) { //n을 인자로 받음 -> n*n*-1*n-2* 이렇게 계속 곱하다가 1이 나오면 토탈 리턴 ㅇㅇ
 
	int total=1;
	
	if(n==0) return 1;
	
	for(int i=n; i>=1; i--) {
		total *= i;
	}
	
	return total;
}
int main() {
	int n,r;
	
	cin >> n >> r;
	cout << f(n) / (f(r) * f(n-r)); //이건 사실 서치한거..  
	
	return 0;
}

