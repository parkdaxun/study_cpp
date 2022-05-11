#include<iostream>
#include<vector>
using namespace std;

void PrintPermutation(vector<int> perm)
{
	for(int i=0; i<perm.size(); i++)
		cout << perm[i] << " ";
	cout << endl;
}

void Permutation(vector<int> perm, vector<int> remain) 
{
	if(remain.size() == 0)
	{
		PrintPermutation(perm);
		return;
	}
	
	for(int i=0; i<remain.size(); i++)
	{
		perm.push_back(remain[i]);
		remainCopy.erase(remainCopy.begin()+1);
		remain.erase(remain.begin()+1);
		Permutation(perm, remainCopy);
		perm.pop_back();
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> num_list;
	for(int i=1; i<=n; i++) num_list.push_back(i);
	vector<int> perm;
	Permutation(vector<int>(), num_list);
	return 0;
}
