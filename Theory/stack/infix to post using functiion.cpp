#include <iostream>
using namespace std;
char stack[50];
int top=-1;
void push(char item)
{
    top++;
    stack[top]=item;
}

char pop()
{
    char ele;
    if(top==-1)
    {
        return '0';
    }
    else
    {
        ele=stack[top];
        cout<<"ele in "<<ele<<endl;
        top--;
    }
    return ele;
}

char gettype(char ch)
{
    switch(ch)
    {
        case  '%':case'^':case '*':case'/': case'+':case'-':
            return 'o';
            break;
        case'(':
            return 'b';
            break;
        case')':
            return 'c';
            break;
        default:
            return 'a';
            break;
    }
}

int prec(char ch)
{
    //cout<<ch<<endl;
    switch(ch)
    {
        case'^':
            return '3';
            break;
        case'*':case'/':case'%':
            return '2';
            break;
        case'+':case'-':
            return '1';
        case '(':
            return '0';
            break;
    }
}

int main()
{
    int i=0,j=0;
    char my[50],c,pos[50],ch,chh,type;
    cout<<"enter the string:";
    cin>>my;
    while(my[i]!='\0')
    {
        c=my[i];
        type=gettype(c);
        //cout<<type<<endl;
        switch(type)
        {
            case 'b':
                cout<<char(c)<<"( in b"<<endl;
                push(c);
                break;
            case'c':
                ch=pop();
                cout<<ch<<"out c\n";
                while(  ch!='(')
                {
                    //cout<<ch<<" in c\n";
                    pos[j]=ch;
                    j++;
                    ch=pop();
                    //cout<<ch<<" in c\n";
                }
                break;
            case'o':
                //cout<<"in push"<<endl;
                ch=prec(c);
                //cout<<ch<<"in o"<<endl;
                switch(ch)
                {
                    case '1':
                        chh=pop();
                        cout<<chh<<"in o"<<endl;
                        while(prec(chh)>='1' && chh!='0')
                        {
                            pos[j]=chh;
                            j++;
                            chh=pop();
                        }
                        if(prec(chh<1))
                            push(chh);
                        push(c);
                        break;
                    case '2':
                        chh=pop();
                        while(prec(chh)>='2' && chh!='0')
                        {
                            pos[j]=chh;
                            j++;
                            chh=pop();
                        }
                        if(prec(chh<1))
                            push(chh);
                        push(c);
                        break;

                    case '3':
                        push(c);
                        break;
                }
                break;
            case'a':
                //cout<<"in pos arr"<<endl;
                pos[j]=c;
                j++;
                break;
        }
        i++;
    }
    ch=pop();
    cout<<ch<<"end"<<endl;
    while(ch!='0')
    {
        cout<<ch<<"in while at end\n";
        pos[j]=ch;
        j++;
        ch=pop();
    }
    cout<<"ans"<<endl;
    for(i=0;i<j;i++)
    {
        cout<<pos[i];
    }
  //  i++;
//}
    return 0;
}
