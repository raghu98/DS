#include<stdlib.h>
#include <iostream>
using namespace std;
char stack[50];
int top=-1;
void push(char item)
{
        top++;
        stack[top]=item;
}
void pop()
{
    top=top-1;
}
int main()
{
    int i=0;
    char num1[10],num;
    cin>>num1;
    while(num1[i]!='\0')
    {
            num=num1[i];
            if(num==']'||num=='}'||num==')')
            {
                if(top==-1)
                {
                    cout<<"invalid";
                    exit(0);
                }
                    else if(num=='}'&& stack[top]=='{')
                            pop();
                    else if(num==']'&& stack[top]=='[')
                            pop();
                    else if(num==')'&& stack[top]=='(')
                            pop();
            }
            else
                push(num);
            i++;
    }
    if(top==-1)
        cout<<"valid";
    else
        cout<<"not valid";
}
