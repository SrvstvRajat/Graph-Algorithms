void shortest(int V,vector<int> adj[])
{
	queue<int> q;
	int dist[V]={INT_MAX};
	dist[0]=0;
	q.push(0);
	while(q.size()!=0)
	{
		int src=q.front();
		q.pop();
		for(auto j:adj[src])
		{
			if(dist[src]+1<dist[j])
			{
				dist[j]=dist[src]+1;
				q.push(j);
			}
		}
	}
}