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
		vector<bool> vis(sqrt(n)+1);
		int rn = vis.size();

		for(int i = 2; i*i <= rn; i++)
		{
			if(vis[i]) continue;
			for(int j = i*i; j <= rn; j+=i)
				vis[j] = true;
			// cout<<endl;
		}
		vector<int> primes;
		for(int i = 2; i <= rn; i++)
		{
			// cout<<i<<" ";
			if(!vis[i]) 
				primes.push_back(i);
		}
		// cout<<endl;
		
		vector<bool> ans(n-m+1);
		for(int x : primes)
		{
			// cout<<x<<":  ";
			int i = (ceil(1.0*(m+1)/x)*x);
			// int i = (m%x == 0)? m/x : m/x+1;
			if(i < x) i = x;
			for(; i <= n; i+=x)
				if(i != x)
					ans[i-m] = true;
					// cout<<i<<", ";
			// cout<<endl;
		}
		// cout<<endl;
		
		for(int i = 0; i < n-m+1; i++)
		{
			// cout<<i+m<<" -> "<<ans[i]<<",  ";
			if(!ans[i] && i+m != 1)
				cout<<i+m<<"\n";
		}
		// cout<<endl;
	}	
	return 0;
}