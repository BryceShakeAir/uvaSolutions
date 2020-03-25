#include<bits/stdc++.h>
using namespace std;

#define INF 100001
typedef pair<int,int> ii;

int clockStarter(int num,int level)
{
  int start = 2 + level*(level-1)*3;
  return (num - start)/level;
}

void bfs(ii arr[])
{
  int num=1,level=1,start=2;
  set<ii> s;
  queue<ii> q;
  arr[num].first=0;
  arr[num].second=0;
  q.push(arr[num]);
  s.insert(arr[num]);

  int dx[] = {0,-1,-1,0,1,1},dy[]={1,1,0,-1,-1,0};
  int lx[] = {1,0,-1,-1,0,1},ly[]={0,1,1,0,-1,-1};

  for(int i=0;i<6;i++)
    q.push( make_pair( dx[i], dy[i] ) );

  while(!q.empty() && num<=INF)
  {
    ii curr = q.front();
    q.pop();

    if(s.find(curr)==s.end())
    {
      s.insert(curr);
      arr[++num]=curr;
      if(num>=start)
      {
        level++;
        start = 2 + level*(level-1)*3;
      }
      //cout<<num<<" "<<curr.first<<" "<<curr.second<<endl;
      for(int i=clockStarter(num,level-1),j=0 ; j<6 ; i=(i+1)%6 ,j++)
      {
        q.push( make_pair( curr.first+lx[i], curr.second+ ly[i] ) );
        //cout<<curr.first+lx[i]<<" "<<curr.second+ ly[i]<<endl;
      }


    }

  }
  return;
}

int main()
{
  ii arr[INF+1];
  bfs(arr);
  int n;
  while(scanf("%d",&n)==1)
    cout<<arr[n].first<<" "<<arr[n].second<<endl;

  return 0;
}
