#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
    cin>>t;
	while(t--)
	{
		int m, n;
		cin>>m>>n;
		vector<bool> arr(n-m+1, false);
		vector<bool> prev(m, false);
		
		for(int i = 2; i*i <= n; i++)
		{
			if(i < m && prev[i]) continue;
			else if(i >= m && arr[i%m]) continue;
			for(int j = i*i; j <= n; j++)
			{
				if(j < m) prev[j] = true;
				else arr[j%m] = true;
			}
		}
		
		vector<int> ans;
		for(int i = 0; i < n-m+1; i++) 
			if(!arr[i]) 
				ans.push_back(i+m);
		cout<<ans.size()<<endl;
		for(int i = 0; i < ans.size(); i++) 
            cout<<ans[i]<<" ";
		cout<<endl;
	}	
	return 0;
}