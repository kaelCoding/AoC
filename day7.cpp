/*
 * Advent of Code 2025
 * Day 7: Laboratories
 * Author: Kael
 * Language: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) return 1;

    vector<string> grid;
    string line;

    while(getline(inputFile, line)){
        grid.push_back(line);
    }

    inputFile.close();

    int result = 0;
    vector<int> tachyonIndexs; 
    tachyonIndexs.push_back(grid[0].size()/2);
    grid[1][grid[0].size()/2] = '|';

    for(int i=2; i<grid.size(); i++){
        vector<int> newIndexs;
        vector<int> oldIndexs;

        for(int index=0; index<tachyonIndexs.size(); index++){
            int indexCurrent = tachyonIndexs[index];

            if(grid[i][indexCurrent] == '^' && grid[i-1][indexCurrent] == '|'){
                newIndexs.push_back(indexCurrent-1);
                newIndexs.push_back(indexCurrent+1);
                oldIndexs.push_back(indexCurrent);
                
                grid[i][indexCurrent-1] = '|';
                grid[i][indexCurrent+1] = '|';

                result++;
            } else grid[i][indexCurrent] = '|';
        }

        for(auto& p : oldIndexs) tachyonIndexs.erase(remove(tachyonIndexs.begin(), tachyonIndexs.end(), p), tachyonIndexs.end());
        for(auto& p : newIndexs) tachyonIndexs.push_back(p);

        sort(tachyonIndexs.begin(), tachyonIndexs.end());
        tachyonIndexs.erase(unique(tachyonIndexs.begin(), tachyonIndexs.end()), tachyonIndexs.end());
    }

    cout << result << endl;

    return 0;
}