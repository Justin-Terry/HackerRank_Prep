#include <bits/stdc++.h>

using namespace std;

bool checkClosure(char a, char b){
    if(a == '{' && b == '}'){
        return true;
    }
    if(a == '[' && b == ']'){
        return true;
    }
    if(a == '(' && b == ')'){
        return true;
    }
    return false;
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    if(s.length() % 2 != 0){
        return "NO";
    }

    stack<char> mStack;
    
    for(int i = 0; i < s.length(); i++){
        if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '['){
            mStack.push(s.at(i));
        }else if(!mStack.empty() ){
            if(!checkClosure(mStack.top(), s.at(i))){
                return "NO";
            }
            mStack.pop();
        }else {
            return "NO";
        }
    }

    if(mStack.size() > 0) {
        return "NO";
    } else{
        return "YES";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
