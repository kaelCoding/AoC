/*
 * Advent of Code 2025
 * Day 4: Printing Department
 * Author: Kael
 * Language: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool isValid(int r, int c, int rows, int cols){
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

int main(){
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) return 1;

    vector<string> grid;
    string line;
    int result = 0;

    while(inputFile >> line) grid.push_back(line);
    inputFile.close();
    
    int rows = grid.size();
    int cols = grid[0].size();
    int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    
    while(true){
        vector<pair<int, int>> removeList;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '@'){ 
                    int neighborCount = 0;

                    for(int k=0; k<8; k++){
                        int ar = i + dr[k]; 
                        int ac = j + dc[k];
                        if (isValid(ar, ac, rows, cols) && grid[ar][ac] == '@') neighborCount++;
                    }

                    if (neighborCount < 4) removeList.push_back({i, j});
                }
            }
        }

        if (removeList.empty()) break;

        result += removeList.size();
        for (const auto& p:removeList) grid[p.first][p.second] = '.';
    }

    cout << result << endl;

    return 0;
}