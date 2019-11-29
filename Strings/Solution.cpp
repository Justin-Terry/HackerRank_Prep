#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string s1, s2;
    cin >> s1;
    cin >> s2;

    cout << s1.length() << " " << s2.length() << endl;
    cout << s1 + s2 << endl;
    cout << s2.substr(0,1) << s1.substr(1, -1) << " " << s1.substr(0,1) << s2.substr(1, -1);
  
    return 0;
}

