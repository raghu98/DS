#include <iostream>
using namespace std;

int main()
{
    int top=-1,count=0,c,va=0,temp=0,i,j=0;
    char arr[10],ans[10],my[50];
    cout << "Enter a character: ";
    cin>>my;
  while(my[j]!='\0')
 {

    c=my[j];
    if(c==40)
    {
        top++;
        arr[top]=c;
    }
    else if(c==41)
    {
        while(arr[top]!=40)
        {
                ans[va]=arr[top];
                va++;
                top--;
        }
        top--;
    }
    else if(c>=42&&c<=47 || c==94)
    {
            while(arr[top]==47 || arr[top]==42 || arr[top]==94)
            {
                ans[va]=arr[top];
                va++;
                top--;
            }
            if(c==43 || c==45)
            {
                while(arr[top]==43 || arr[top]==45)
                {
                    ans[va]=arr[top];
                    va++;
                    top--;
                }
            }
        top++;
        arr[top]=c;
    }
    else
    {
        ans[va]=c;
        va++;
    }
    count++;
    j++;
 }
temp=top;
while(temp>=0)
{
    ans[va]=arr[temp];
    temp--;
    va++;
}

 for(i=0;i<va;i++)
 {
     cout<<ans[i];
 }
 return 0;
}
