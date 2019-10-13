  #include<bits/stdc++.h>
  using namespace std;
  #define int long long

  vector<int> adj[1000005];
  bool visited[1000005];
  vector<int> ans;
  int n, m;
  void dfs(int s)
  {
    if(visited[s])
    {
      return;
    }
    visited[s] = true;
    for(auto i:adj[s])
    {
      if(!visited[i])
      {
        dfs(i);
      }
    }

    ans.push_back(s);
  }

  void toposort()
  {
    for(int i = 1;i <= n;i++)
    {
      if(!visited[i])
      {
        dfs(i);
      }
    }
    reverse(ans.begin(),ans.end());
  }
int32_t main()
{
       

   #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
 
      
    
    
    cin >> n >> m;

    for(int i = 1;i <= m;i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
    }

    toposort();
    for(auto i:ans)
    {
      cout << i << " ";
    }


    return 0;

    
}