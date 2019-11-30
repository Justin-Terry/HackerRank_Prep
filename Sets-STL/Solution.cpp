#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> mySet;
    int c;
    cin >> c;
    while(cin >> c){
        switch(c){
            case 1:
                cin >> c;
                mySet.insert(c);
                break;
            case 2:
                cin >> c;
                mySet.erase(c);
                break;
            case 3:
                cin >> c;
                if(mySet.find(c) != mySet.end()){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
                break;
        }

    }

    return 0;
}



