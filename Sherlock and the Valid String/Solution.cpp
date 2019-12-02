#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char, int> counts;

    // Map character counts
    for(int i = 0; i < s.length(); i++){
        counts[s[i]] += 1;
    }

    int val = counts[s[i]];
    int removed = 0;
    // Check character counts
    for(int i = 0; i < s.length(); i++){
        // Not equal to another?
        if(counts[s[i]] != val){
            // Remove it, update removed
            if(removed == 0){
                removed++;
                counts[s[i]] = counts[s[i]] - 1;
            }else{
                // Already removed one
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
