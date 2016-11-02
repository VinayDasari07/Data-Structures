#include<stdio.h>
#include<string.h>

#define max 50

char s[max], in[50],post[50];

int ele, tos = -1;

void push(char ele)

{

    s[++tos]=ele;

}

int isempty()

{

    if(tos==-1)

        return 1;

    else return 0;

}

char pop()

{

    tos--;

    return(s[tos+1]);

}

char stacktop()

{

    return(s[tos]);

}

int isoperand(char ch)

{

    if(ch>='a'&& ch<= 'z' || ch>= 'A' && ch<= 'Z')

        return 1;

    else

        return 0;

}

int ipr(char ch)

{

    switch(ch)

    {

        case '*':

        case '/':

        case '%': return 2;

        case '+':

        case '-': return 1;

        case '(': return 3;

    }

    return -1;

}

int rpr(char ch)

{

    switch(ch)

    {

        case '*':

        case '/':

        case '%': return 2;

        case '+':

        case '-': return 1;

        case '(': return 0;

    }

}

void convert(char in[], char post[])

{

    int i,j,k=0,l;

    char ele;

    l=strlen(in);

    for(i=0;i<=l-1;i++)

    {

        if(in[i]== '(')

            push (in[i]);

        else if(in[i]== ')')

        {

            while(1)

            {

                ele=pop();

                if(ele=='(')

                    break;

                post[k++]=ele;

            }

        }

        else if(isoperand(in[i]))

        {

            post[k++]=in[i];

        }

        else if(isempty())

        {

            push(in[i]);

        }

        else if(ipr(in[i])>rpr(stacktop()))

            push(in[i]);

        else

        {

            while(isempty()==0 && ipr(in[i])<=rpr(stacktop()))

            {

                ele=pop();

                post[k++]=ele;

            }
         Push(in[i]);
        }

}

    while(isempty()==0)

        {

            ele=pop();

            post[k++]=ele;

        }

        post[k]='\0';

}

void main()

{

    char infix[50], postfix[50];

    printf("Enter infix expression");

    gets(infix);

    convert(infix,postfix);

    printf("Postfix expression is %s", postfix);

}
