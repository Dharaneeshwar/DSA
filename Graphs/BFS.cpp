// TODO to check
#include <iostream>
#include<list>
using namespace std;
void BFS(list<int> adj_list[],int *visited,int i,int n)
{
  cout<<i<<" ";
  visited[i] = 1;
  list<int>::iterator it;
  while(1)
  {
    if(adj_list[i].begin()!=adj_list[i].end())
    {
    	it = adj_list[i].begin();
    	int j = *it;
    	for(; it!=adj_list[i].end(); ++it)
    	{
      		if(visited[*it]!=1)
      		{
      			cout<<*it<<" ";
      			visited[*it] = 1;
      		}
    	} 
      	i = j;
  	 }
    else
      break;
   }
}
int main() 
{
  int n,sn,en;
  cin>>n;
  if(n>0)
  {
  	list<int> adj_list[n+1];
  	do
  	{
    	cin>>sn>>en;
    	if(sn!=-1 && en!=-1)
      		adj_list[sn].push_front(en);
  	}while(sn!=-1 && en!=-1);
    int visited[n+1];
    for(int i=0;i<=n;i++)
      visited[i]=0;
    cout<<"BFS :  ";
    BFS(adj_list,visited,0,n);
  }
  else
    cout<<"Graph doesn't exist";
  return 0;
}