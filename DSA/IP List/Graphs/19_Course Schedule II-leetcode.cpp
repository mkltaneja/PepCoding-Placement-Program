
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> gp(numCourses);
        vector<int> inDeg(numCourses);
        for(auto e : prerequisites)
        {
            gp[e[0]].push_back(e[1]);
            inDeg[e[1]]++;
        }
        
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(inDeg[i] == 0)
                que.push(i);
        
        vector<int> ans;
        while(!que.empty())
        {
            int u = que.front();
            que.pop();
            ans.push_back(u);
            
            for(int v : gp[u])
                if(--inDeg[v] == 0)
                    que.push(v);
        }
        if(ans.size() != numCourses) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }