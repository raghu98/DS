#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct link
{
    struct link *next;
    int info;
}A;
struct link *start=NULL;
void front(int num)
{

    struct link *ptr;
    ptr=new A;
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
    A *temp1;
    temp1=start;
    if(temp1==NULL)
    cout<<"under flow";
    else
    {
        while(temp1!=NULL)
        {
            cout<<temp1->info<<"\t";
            temp1=temp1->next;
        }
    cout<<"\n";
    }
}
void back(int num)
{
    A *ptr,*temp;
    ptr=new link ;
    if(start==NULL)
    {
        start=ptr;
        ptr->info=num;
        ptr->next=NULL;
    }
    else
    {

        ptr->info=num;
        ptr->next=NULL;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }

}
void dfront()
{
    A *temp1;
    temp1=start;
    if(temp1==NULL)
        cout<<"underflow";
    else
    {
        start=temp1->next;
        delete temp1;
    }
}
void
()
{

    A *temp1;
    A *temp2;
    temp1=start;
    if(temp1==NULL)
        cout<<"underflow";
    else
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
    delete temp1;
    temp2->next=NULL;
}
void reverse()
{
    A *nex=NULL,*prev=NULL,*current=start;
    if(start==NULL)
        cout<<"underflow";
    else
    {
        while(current!=NULL)
        {
            nex=current->next;
            current->next=prev;
            prev=current;
            current=nex;
        }
        start=prev;
    }
}
int main()
{
    int a,num;
    A list;
    cout<<"1=front\n2=back\n3=dfront\n4=dback\n5=show\n6=reverse";

    while(1)
    {
        cout<<"\npls enter your choice\n";
        cin>>num;

        switch (num)
        {
            case 1:
                cin>>a;
                front(a);
                break;
            case 2:
                cin>>a;
                back(a);
                break;
            case 3:
                dfront();
                break;
            case 4:
                dback();
                break;
            case 5:
                show();
                break;
            case 6:
                reverse();
                break;
            default:
                exit(0);
        }
    }
}
