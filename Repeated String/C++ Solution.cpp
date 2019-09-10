#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long remainder =  n % s.length();
        long numberOfS = (n-remainder)/s.length();
        long numberOfA = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s.at(i) == 'a'){numberOfA++;}
        }
        numberOfA *= numberOfS;
        for(int i = 0; i < remainder; i++){
            if(s.at(i) == 'a'){numberOfA++;}
        }
        return numberOfA;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
