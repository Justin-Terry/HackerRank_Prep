#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int c;
    vector<int> ints;
    cin >> c;

    for(int i = 0; i < c; i++){
        int t;
        cin >> t;
        ints.push_back(t);
    }
    cin >> c;
    while(cin >> c){
        vector<int>::iterator it = lower_bound(ints.begin(), ints.end(), c);
        if(*it == c){
            cout << "Yes " << it - ints.begin() + 1 << endl;
        } else{
            cout << "No " << it - ints.begin() + 1 << endl;
        }
        // Slow, brute force (first try) method of doing it.
        // for(int i = 0; i < ints.size(); i++){
        //     if(ints[i] > c){
        //         cout << "No " << i+1 << endl;
        //         break;
        //     }
        //     if(ints[i] == c){
        //         cout << "Yes " << i+1 << endl;
        //         break;
        //     }
        // }
    }

    return 0;
}
