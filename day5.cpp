/*
 * Advent of Code 2025
 * Day 5: Cafeteria
 * Author: Kael
 * Language: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Range{
    ll minVal;
    ll maxVal;

    bool contains(ll num) const {
        return num >= minVal && num <= maxVal;
    }
};

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) return 1;

    vector<Range> ranges;
    vector<pair<ll, ll>> check;
    vector<ll> numbers;
    string line;

    while(getline(inputFile, line)){
        if(line.empty()) break;

        stringstream ss(line);
        ll start, end;
        char dash;

        if(ss >> start >> dash >> end){
            // part1
            // ranges.push_back({start, end});
            check.push_back({start, end});
        }
    }

    inputFile.close();

    // part 1
    // while(getline(inputFile, line)){
    //     ll num = stoll(line);
    //     numbers.push_back(num);
    // }
    // for(ll num : numbers){
    //     for(const auto& r : ranges){
    //         if(r.contains(num)){
    //             result++;
    //             break;
    //         }
    //     }
    // }

    sort(check.begin(), check.end());
    ll result = 0;
    ll start_cur = check[0].first;
    ll end_cur = check[0].second;

    for(int i=1; i<check.size(); i++){
        if(check[i].first > end_cur){
            result += (end_cur - start_cur + 1); 
            start_cur = check[i].first;          
            end_cur = check[i].second;
        } 
        else end_cur = max(end_cur, check[i].second);
    }   

    result += (end_cur - start_cur + 1);
    cout << result << endl;

    return 0;
}