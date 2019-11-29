#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int c;
    cin >> c;
    vector<int> ints;
    while(cin >> c){
        ints.push_back(c);
    }

    sort(ints.begin(), ints.end());

    for(int i = 0; i < ints.size(); i++){
        cout << ints[i] << " ";
    }
    return 0;
}
