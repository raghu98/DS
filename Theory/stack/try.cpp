#include<iostream>
using namespace std;
struct link
{
    int info;
    struct link **next;
};
void show(struct link **start)
{
    struct link **temp1;
    temp1=start;
    if(temp1==NULL)
    cout<<"under flow";
    else
    {
        while(temp1!=NULL)
        {
            cout<<(*temp1)->info<<"\t";
            temp1=(*temp1)->next;
        }
    cout<<"\n";
    }
}
void back(int num,struct link **start)
{
    struct link **ptr,**temp;
    *ptr=new link ;
    if(start==NULL)
    {
        (start)=(ptr);
        (*ptr)->info=num;
        (*ptr)->next=NULL;
    }
    else
    {

        (*ptr)->info=num;
        (*ptr)->next=NULL;
        temp=start;
        while((*temp)->next!=NULL)
        {
            temp=(*temp)->next;
        }
        (*temp)->next=(ptr);
    }

}
int main()
{
    int num,temp,size,i,j;
    cout<<"enter the number of list you want to create";
    cin>>num;
    struct link *start ;
    //(*start)[num]={NULL};
    cout<<"enter the size of list";
    cin>>size;
   // back(temp,&start);
    //show(&start);

    for(i=0;i<num;i++)
    {
            for(j=0;j<size;j++)
            {
                cin>>temp;
                back(temp,&start);

            }
            show(&start);
    }


}
