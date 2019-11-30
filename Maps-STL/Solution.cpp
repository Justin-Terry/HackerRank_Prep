#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map<string, int> myMap;
    int c;
    cin >> c; 

    while(cin >> c){
        switch(c){
            case 1:{
                string name;
                cin >> name;
                cin >> c;
                myMap[name] += c;
                break;
            }
            case 2:{
                string del;
                cin >> del;
                myMap[del] = 0;
                break;
            }
            case 3:{
                string query;
                cin >> query;
                cout << myMap[query] << endl;
                break;
            }
        }
    }


    return 0;
}



