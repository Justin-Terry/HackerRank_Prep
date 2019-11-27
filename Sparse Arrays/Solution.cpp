#include <bits/stdc++.h>

using namespace std;

void addOne(map<string, int> &map, string s){
    if(map.find(s) != map.end()){
        // int value = map[s]->second;
        map[s] = map[s]+1;
    }else{
        map[s] = 1;
    }
}

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> mMap;
    vector<int> results;

    for(int i = 0; i < strings.size(); i++){
        addOne(mMap, strings[i]);
    }

    for(int i = 0; i < queries.size(); i++){
        if(mMap.find(queries[i]) != mMap.end()){
            results.push_back(mMap[queries[i]]);
        }else{
            results.push_back(0);
        }
    }

    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
