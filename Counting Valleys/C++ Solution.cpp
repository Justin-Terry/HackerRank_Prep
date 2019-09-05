#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int elevation = 0;
    int numOfValleys = 0;

    for(int i = 0; i < n; i++) {
        char c = s.at(i);
        if(c == 'D') {
            if(elevation == 0){
                numOfValleys++;
            }
            elevation --;
        } else {
            elevation++;
        }
    }
    return numOfValleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
