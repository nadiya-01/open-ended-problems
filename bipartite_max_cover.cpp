#include<iostream>
using namespace std;

#define M 6
#define N 6
//Finds a vertice for set U to match with
bool Check(int graph[][N],int m[],bool c[], int u) 
{
  for(int i=0;i<N;i++)
  {
    if(graph[u][i] && !c[i])
    {
      c[i]=true;
      if(m[i]<0 || Check(graph,m,c,m[i])) //Recursively calls the function to backtrack and find for other combinations
      {
        m[i]=u;
        return true;
      }
    }
  }
  return false;
}

int BMC(int graph[][N])
{
    int match[N],result=0;
    bool check[N]; //Array to keep track whether the vertices in set V have been checked for respective set U vertice

    for(int i=0;i<N;i++)
    {
      match[i]=-1;
      check[i]=false;
    }

    for(int i=0;i<M;i++) //Tries to find a match for every vertice in set U
    {
      if(Check(graph,match,check,i))
        result++;
    }

    return result;
}

int main()
{
    int graph[M][N]; //M represents the number of vertices in set U and N in set V
    cout<<"Enter the adjacency matrix\n";

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<BMC(graph);
    return 0;
}

