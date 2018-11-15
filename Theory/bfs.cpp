#include <iostream>
using namespace std;

int main()
{
    int k,n,m,v,i,j;
    cout<<"enter the no. of vertices";
    cin>>n;
    cout<<"enter the no. of edges";
    cin>>m;
    int cost[n][n]={0,0,0,0,0,0},visit[n],visited[n],qu[n],rare=0,front=0;
    for(k=0;k<n;k++)
    {
        visited[k]=0;
        visit[k]=0;
        qu[k]=0;
    }
    for(k=0;k<m;k++)
    {
        cout<<"enter the  i n j";
        cin>>i>>j;
        i=--i;
        j=--j;
        cost[i][j]=1;
    }
     for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)
            cout<<cost[k][j]<<" ";
        cout<<endl;
    }
    cout<<"enter the initial vertex";
    cin>>v;
    v=v-1;
    visited[v]=1;
    qu[rare++]=v;
    k=1;
    while(k<=m)
    {
       // cout<<"k="<<k;
        for(j=0;j<n;j++)
        {
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                //cout<<"inside if j ="<<j;
                visit[j]=1;
                qu[rare++]=j;
                //cout<<qu[front];
            }
        }
        cout<<v+1<<endl;
        v=qu[++front];
        k++;
        //cout<<"k="<<k<<endl;
        visit[v]=0;
        visited[v]=1;
    }
}
