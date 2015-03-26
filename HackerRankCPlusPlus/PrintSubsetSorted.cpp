#include <iostream>
#include <string>
#include <stack>
#include <list>

using namespace std;

void pushToList(stack<char> st, list<string>& result) {
    stack<char> bc = st;
    stack<char> final;
    
    while(!bc.empty()) {
        final.push(bc.top());
        bc.pop();
    }
    
    string str;
    
    while(!final.empty()) {
        str += final.top();
        final.pop();
    }
    
    result.push_back(str);
}

void printSubsetsSortedLG(string s, int low, int high, stack<char> st, list<string>& result) {
    for(int i = low; i <= high; i++) {
        st.push(s[i]);
        
        printSubsetsSortedLG(s, i + 1, high, st, result);
        
        //print stack contents
        pushToList(st, result);
        
        //backtrack
        st.pop();
    }
}

int main()
{
   int T;
   cin >> T;
   
   while(T) {
       T--;
       
       int L; cin >> L;
       string s; cin >> s;
       
       stack<char> st;
       list<string> result;
       
       printSubsetsSortedLG(s, 0, L - 1, st, result);
       
       result.sort();
       
       //print list
       for(list<string>::iterator it = result.begin(); it != result.end(); ++it) 
            cout << *it << endl;
   }
        
   return 0;
}

