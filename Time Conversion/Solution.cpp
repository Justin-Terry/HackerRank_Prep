#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     string amPM = s.substr(8,-1);
     if(amPM == "PM"){
        int hours = stoi(s.substr(0,2));
        if(hours != 12){
            hours += 12;
            s.replace(0,2, to_string(hours));
        }
     } else if(s.substr(0,2) == "12"){
        s.replace(0,2, "00");
     }

     return s.substr(0,8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
