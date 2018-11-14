#include<iostream>
using namespace std;
struct link
{
    int info;
    struct link *next;
};
struct link *start = NULL;
void front(int num)
{
    struct link *ptr;
    ptr=new link;
    if(start==NULL)
    {
            start=ptr;
            ptr->info=num;
            ptr->next=NULL;
    }
    else
    {

        ptr->info=num;
        ptr->next=start;
        start=ptr;

    }
}
void show()
{
    struct link *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
void fact()
{
    long long int ptr=1;
    for(int i=1;i<=start->info;i++)
    {
        ptr = ptr * i;
    }
    cout<<ptr;

}
int main()
{
    int a,num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a;
        front(a);
    }
    show();
    fact();

}
