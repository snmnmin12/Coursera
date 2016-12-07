//
//  week3.cpp
//  Structure
//
//  Created by Song on 12/23/15.
//  Copyright © 2015 Song. All rights reserved.
//

//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//int main()
//{
//    queue<char> que1;
//    string str;
//    int n;
//    cin>>n;
//    cin.get();
//    while (n--)
//    {
//        getline(cin,str);
//        for (int i=0; i<str.size(); i++)
//            que1.push(str[i]);
//        while (!que1.empty()) {
//            char c=que1.front();
//            if ((c>=65 && c<=90) || (c>=97 && c<=122) )
//            {
//                if (c==90) cout<<'A';
//                else if(c==122) cout<<'a';
//                else cout<<(char)(c+1);
//                
//            }
//            else
//                cout<<c;
//            que1.pop();
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <stack>
//using namespace std;
//int n;
//int number=0;
//stack<int> a;
//void fun(int i,const int n )
//{
//    if(i == n+1)
//        ++number;
//    else
//    {
//        a.push(i);//入栈
//        fun(i+1,n);
//        a.pop();//为保持stack不变，出栈
//        
//        if(!a.empty())//将栈顶元素输出
//        {
//            int top;//用来取top
//            top=a.top();
//            a.pop();
//            fun(i,n);//i不变
//            a.push(top);
//        }
//    }
//}
//int main()
//{
//    cin>>n;
//    fun(1,n);
//    cout<<number<<endl;
//    return 0;
//}
