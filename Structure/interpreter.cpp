//
//  interpreter.cpp
//  Structure
//
//  Created by Song on 1/12/16.
//  Copyright © 2016 Song. All rights reserved.
//

#include <cctype>
#include "interpreter.h"


double Statement::factor()
{
    double var,minus=1.0;
    static char id[200];
    cin>>ch;
    while (ch=='+' || ch=='-')
    {
        if (ch=='-')
            minus*=-1.0;
        cin>>ch;
    }
    if (isdigit(ch)||ch=='.')
    {
        cin.putback(ch);
        cin>>var>>ch;
    }
    else if(ch=='(')
    {
        var=expression();
        if (ch==')')
            cin>>ch;
        else issueError("Right paren left out'");
    }
    else{
        readId(id);
        if (isspace(ch))
            cin>>ch;
        var=findValue(id);
    }
    return  minus*var;
}
double Statement::term()
{
    double t=factor();
    while (true)
    {
        switch (ch) {
            case '*': t*=factor();break;
            case '/': t/=factor();break;
            default: return t;
        }
    }
}
double Statement::expression()
{
    double t=term();
    while (true)
    {
        switch (ch) {
            case '+': t+=term();break;
            case '-': t-=term();break;
            default: return t;
        }
    }
}
void Statement::getStatement()
{
    char id[20], command[20];
    double e;
    cout<<"Enter a statement: ";
    cin>>ch;
    readId(id);
    strdup(strcpy(command, id));
    if (strcmp(command, "STATUS")==0)
        cout<<*this;
    else if(strcmp(command, "PRINT")==0)
    {
        readId(id);
        cout<<id<<" = "<<findValue(id)<<endl;
    }
    else if(strcmp(command, "END")==0)
        exit(0);
    else{
        if(isspace(ch))
            cin>>ch;
        if (ch=='=') {
            e=expression();
            if (ch!=';')
                issueError("There are some extras in the statement");
            else processNode(id, e);
        }
        else issueError("'=' is missing");
    }

}
void Statement::readId(char*id)
{
    int i=0;
    if (isspace(ch))
        cin>>ch;
    if (isalpha(ch))
    {
        while (isalnum(ch))
        {
            id[i++]=ch;
            cin.get(ch);
        }
        id[i]='\0';
    }
    else issueError("Identifier expected");

}
double Statement::findValue(char* id)
{
    IdNode tmp(id);
    list<IdNode>::iterator i=find(idList.begin(),idList.end(),tmp);
    if (i!=idList.end())
        return i->value;
    else issueError("Unkown variable");
    return 0;

}
void Statement::processNode(char* id,double e)
{
    IdNode tmp(id,e);
    list<IdNode>::iterator i=find(idList.begin(), idList.end(), tmp);
    if (i!=idList.end())
        i->value=e;
    else idList.push_front(tmp);
}
ostream&  operator<<(ostream& out,const Statement& s)
{
    list<IdNode>::const_iterator  i=s.idList.begin();
    for (; i!=s.idList.end(); i++)
        out<<*i;
    out<<endl;
    return out;
}
ostream& operator<<(ostream& out, const IdNode& r)
{
    out<<r.id<<" = "<<r.value<<endl;
    return out;
}