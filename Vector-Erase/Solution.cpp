#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    vector<int> ints;
    cin >> size;

    for(int i = 0; i < size; i++){
        int t;
        cin >> t;
        ints.push_back(t);
    }

    cin >> size;
    ints.erase(ints.begin()+size-1);
    int a, b;
    cin >> a;
    cin >> b;

    ints.erase(ints.begin()+a-1, ints.begin()+b-1);
    cout << ints.size() << endl;
    for(int i = 0; i < ints.size(); i++){
        cout << ints[i] << " ";
    }


    return 0;
}
