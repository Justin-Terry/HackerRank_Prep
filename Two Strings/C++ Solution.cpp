#include <bits/stdc++.h>

using namespace std;

void addOne(map<char, int> & m, char s){
    if(m.count(s) > 0){
        m[s] = m[s] + 1;
    } else{
        m[s] = 1;
    }
}

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    map<char, int> mMap;

    for(int i = 0 ; i < s1.length(); i++){
        addOne(mMap, s1.at(i));
    }

    for(int i = 0; i < s2.length(); i++){
        if(mMap.count(s2.at(i)) > 0){
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
