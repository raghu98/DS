#include<stdlib.h>
#include<iostream>
using namespace std;
class A
{
        int info;
        A *next,*temp;
        A *start=NULL;
public:

        void front(int num)
        {
            A *ptr;
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
                    cout<<temp1->info;
                    temp1=temp1->next;
                }
                cout<<"\n";
            }

        }
        void back(int num)
        {

            A *ptr,*temp;
            ptr=new A;
            if(start==NULL)
            {
                    start=ptr;
                    ptr->info=num;
                    ptr->next=NULL;
                    temp=ptr;
            }
            else
            {

                ptr->info=num;
                ptr->next=NULL;
                temp=start;
                while(temp->next=NULL)
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
                temp2->next=NULL;
        }
};
int main()
{
    int a,num;
    A list;
    cout<<"1=front\n2=back\n3=dfront\n4=dback\n5=show";

    while(1)
    {
        cout<<"\npls enter your choice\n";
        cin>>num;

        switch (num)
        {
            case 1:
                cin>>a;
                list.front(a);
                break;
            case 2:
                cin>>a;
                list.back(a);
                break;
            case 3:
                list.dfront();
                break;
            case 4:
                list.dback();
                break;
            case 5:
                list.show();
                break;
            default:
                exit(0);
        }
    }
}
