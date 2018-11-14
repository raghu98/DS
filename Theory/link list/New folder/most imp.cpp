#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};
void insert(struct Node **start,int num)
{
   // cout<<"in insert";
    struct Node *ptr=new Node;
    if(*start==NULL)
    {
        ptr->info=num;
        ptr->next=NULL;
        *start=ptr;
    }
    else
    {
        ptr->info=num;
        ptr->next=*start;
        *start=ptr;
    }
}
void display(struct Node *start)
{
    //cout<<"in display";
    struct Node *temp;
    temp=start;
    while(temp!=NULL)
    {
        //cout<<"hi";
        cout<<temp->info<<"\t";
        temp=(temp->next)->next;
    }
}
int main() {

    int number,i,n;
    cin>>n;
    struct Node *head = NULL;
    for(i = n; i > 0; i--)
   {
	 cin>>number;
     insert(&head, number);
   }
	display(head);
    return 0;
}
