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
/*void bub()
{
    struct link *temp,*temp2;
    temp=start;
    int flag=1;
    while(temp!=NULL)
    {
        //cout<<"\nin";
        temp2=start;
        if(flag!=0)
        {
            flag=0;
            while(temp2->next!=NULL)
            {
               // cout<<temp2->next->info<<"\n";
                if(temp2->info > temp2->next->info)
                {
                    flag=1;
                    int t=temp2->info;
                    temp2->info=temp2->next->info;
                    temp2->next->info=t;
                }
                temp2=temp2->next;

            }
            //cout<<"out";
        }
        temp=temp->next;
        //cout<<"in";
    }
}*/
void dup()
{
    struct link *prev,*current,*temp,*temp1;
    temp=start;
    while(temp!=NULL)
    {
        prev=temp;
        current=temp->next;
        while(current!=NULL)
        {
            if(temp->info==current->info)
            {
                temp1=current;
                current=current->next;
                prev->next=current;
                delete temp1;
            }
            else
            {
                prev=current;
                current=current->next;
            }
        }
        temp=temp->next;
    }
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
    //bub();
    //show();
    dup();
    show();
}
