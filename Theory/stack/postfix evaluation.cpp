#include<iostream>
using namespace std;
int stack[50];
int top=-1;
char gettype(char ch)
{
    switch(ch)
    {
        case  '%':case'^':case '*':case'/': case'+':case'-':
            return 'o';
            break;
        default:
            return 'z';
            break;
    }
}
int eval(char t,int num1,int num2)
{
    int su;
    switch(t)
    {
        case '+':
            su=num2+num1;
            break;
        case '-':
            su=num2-num1;
            break;
        case '*':
            su=num2*num1;
            break;
        case '/':
            su=num2/num1;
            break;
        case '^':
            su=num2^num1;
            break;
    }
    return su;
}
void push(char item)
{
    top++;
    stack[top]=item;
}
int pop()
{
    int ele=stack[top];
    top--;
    return ele;
}
int main()
{
    char post[50];
    int num,arr[10],i=0,j=0,k,l=0;
    cin.get(post, 50);
    while(post[i]!='\0')
    {
        switch(gettype(post[i]))
        {
            case'z':
                if(post[i]==' '||post[i]=='\t')
                {
                    if(j!=0)
                    {
                        num=0;
                        for(k=0;k<j;k++)
                        {
                            num=num*10+arr[k];
                        }
                        push(num);
                        j=0;
                    }
                    else
                        break;
                }
                else
                {
                    arr[j]=post[i]-'0';
                    j++;
                }
                break;

            case'o':
                int num1,num2;
                num1=pop();
                num2=pop();
                push(eval(post[i],num1,num2));
                break;
        }
        i++;
    }
    //cout<<"printing i"<<i<<endl;
    //cout<<"printing top "<<top<<endl;
    cout<<stack[top];
}
