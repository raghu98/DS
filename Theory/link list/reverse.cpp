#include<iostream>
using namespace std;
struct link
{
    int info;
    struct link *next;
};
struct link *start = NULL;
struct link *start1 = NULL;
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
    if(temp==NULL)
        cout<<"empty link";
    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
void reverse1()
{
    struct link *ptr,*temp;
    ptr=new link;
    temp=start;
    while(temp!=NULL)
    {

        cout<<"*";
        if(start1==NULL)
        {
            start1=ptr;
            ptr->info=temp->info;
            ptr->next=NULL;

        }
        else
        {

            ptr->info=temp->info;
            ptr->next=start1;
            start1=ptr;

        }
        temp=temp->next;
    }
}

void show1()
{
    struct link *temp;
    temp=start1;
    if(temp==NULL)
    {
        cout<<"empty link";
    }
    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;
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
    reverse1();
    show1();

}
