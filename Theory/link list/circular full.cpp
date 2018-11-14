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

    struct link *ptr,*temp;
    ptr=new A;
    if(start==NULL)
    {
        start=ptr;
        ptr->info=num;
        ptr->next=start;
    }
    else
    {
        ptr->info=num;
        temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=ptr;
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
        while(temp1->next!=start)
        {
            cout<<temp1->info<<"\t";
            temp1=temp1->next;
        }
    cout<<temp1->info;
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
        ptr->next=start;
    }
    else
    {

        ptr->info=num;
        ptr->next=start;
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=ptr;

    }

}
void dfront()
{
    A *temp1,*temp2;
    temp1=start;
    if(temp1==NULL)
        cout<<"underflow";
    else
    {
        temp2=start;
        while(temp1->next!=start)
        {
            temp1=temp1->next;
        }
        temp1->next=temp2->next;
        start=temp2->next;
        delete temp2;
    }

}
void dback()
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
    temp2->next=start;
}
void reverse()
{
    A *temp,*temp2,*temp1;
    if(start==NULL)
        cout<<"underflow";
    else
    {
        temp1=start;
        temp=temp1->next;
        temp2=temp;
        while(temp!=start)
        {
            cout<<"in\t";
            temp=temp->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp;
        }
        start->next=temp1;
        start=temp1;
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
