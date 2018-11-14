#include<iostream>
using namespace std;
int entry(int num1,int arr1[])
{
    int k=0,i,j,flag,temp;
    for(i=0;i<num1;i++)
    {
        flag=0;
        cin>>temp;
        for(j=0;j<i;j++)
        {
            if(temp==arr1[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            arr1[k]=temp;
            k++;
        }
    }
    return k;
}
int diff(int num1,int arr1[],int ca[],int k)
{
    int i,j,flag,p=0;
    for(i=0;i<num1;i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(arr1[i]==ca[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            p=1;
            cout<<arr1[i]<<"\t";
        }
    }
    return p;
}
void search(int num1,int num2,int arr1[],int arr2[])
{
    //cout<<"inside search"<<num1<<num2;
    int i,j,k=0,flag,p1,p2;
    int ca[num1]={0};
    //cout<<"initializaton complete";
    for(i=0;i<num1;i++)
    {
        //cout<<"inside first for ";
        for(j=0;j<num2;j++)
        {
            //cout<<"inside second for";
            if(arr1[i]==arr2[j])
            {
                ca[k]=arr1[i];
                k++;
                //cout<<"putting value";
            }
        }
    }
    cout<<"\nsame in both"<<endl;
    p1=0;
    for(i=0;i<k;i++)
    {
        p1=1;
        cout<<ca[i]<<"\t";
    }
    if(p1==0)
        cout<<"none"<<endl;
    cout<<"\ndiff in both"<<endl;
    p1=diff(num1,arr1,ca,k);
    p2=diff(num2,arr2,ca,k);
    if(p1==0&&p2==0)
        cout<<"none";
    /*
    p=0;
    cout<<"\ndiff in both\n";
    for(i=0;i<num1;i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(arr1[i]==ca[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            p=1;
            cout<<arr1[i]<<"\t";
        }
    }
    for(i=0;i<num2;i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(arr2[i]==ca[j])
            {
                flag=1;
                break;
            }

        }
        if(flag==0)
        {
            p=1;
            cout<<arr2[i]<<"\t";
        }
    }
    if(p==0)
        cout<<"none"<<endl;*/
}
int main()
{
    int flag,temp,k,i,j,num1,num2;
    cout<<"enter the size of the first arrray";
    cin>>num1;
    int arr1[num1];
    num1=entry(num1,arr1);
    cout<<"enter the size of the second arrray";
    cin>>num2;
    int arr2[num2];
    num2=entry(num2,arr2);
    /*for(i=0;i<num1;i++)
        cout<<arr1[i]<<"\t";
    cout<<"\n";
    for(i=0;i<num2;i++)
        cout<<arr2[i]<<"\t";
    cout<<endl;*/
    if(num1>=num2)
        search(num1,num2,arr1,arr2);
    else
        search(num2,num1,arr2,arr1);
}
