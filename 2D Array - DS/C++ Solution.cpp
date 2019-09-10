#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<vector<int>> arr(6);
    int maxTotal = INT_MIN;
    int hourGlassTotal = 0;

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            int tl = arr[i][j];
            int tm = arr[i][j+1];
            int tr = arr[i][j+2];
            int mid = arr[i+1][j+1];
            int bl = arr[i+2][j];
            int bm = arr[i+2][j+1];
            int br = arr[i+2][j+2];

            hourGlassTotal = tl + tm + tr + mid + bl + bm + br;
            if(hourGlassTotal > maxTotal) {
                maxTotal = hourGlassTotal;
            }
        }
    }
    
    cout << maxTotal;
    return 0;
}
