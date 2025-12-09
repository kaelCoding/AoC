/*
 * Advent of Code 2025
 * Day 6: Trash Compactor
 * Author: Kael
 * Language: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

typedef long long ll;

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) return 1;

    // part1
    // vector<vector<ll>> numList;
    // vector<char> operators;
    string line;
    vector<string> grid;
    string operatorLine;

    while(getline(inputFile, line)){
        if (line.find('*') != string::npos || line.find('+') != string::npos) {
            operatorLine = line;
        } else grid.push_back(line);

        // part1
        // stringstream ss(line);
        // ss >> ws;
        // char firstChar = ss.peek();
        // if(isdigit(firstChar)){
        //     vector<ll> row;
        //     ll num;
        //     while(ss >> num){
        //         row.push_back(num);
        //     }
        //     numList.push_back(row);
        // } else {
        //     char op;
        //     while(ss >> op){
        //         operators.push_back(op);
        //     }
        // }
    }

    inputFile.close();
    
    // part 1
    // ll rows = numList.size();
    ll result = 0;
    int maxSize = operatorLine.size();
    char currentOp = ' ';
    vector<ll> currentNumbers;

    for(ll col=0; col<maxSize; col++){
        string colNumStr = "";
        bool hasDigit = false;

        for(const string& rowStr : grid){
            if(isdigit(rowStr[col])){
                colNumStr += rowStr[col];
                hasDigit = true;
            }
        }

        if(operatorLine[col] == '*' || operatorLine[col] == '+'){
            currentOp = operatorLine[col];
        }

        if(hasDigit) currentNumbers.push_back(stoll(colNumStr));
        bool isEmptyCol = !hasDigit && (operatorLine[col] == ' ');

        if(isEmptyCol || col == maxSize-1){
            if(!currentNumbers.empty()){
                ll subTotal = currentNumbers[0];

                for(int i=1; i<currentNumbers.size(); i++){
                    if(currentOp == '+') subTotal += currentNumbers[i];
                    else subTotal *= currentNumbers[i];
                }

                result += subTotal;
                currentNumbers.clear();
                currentOp = ' ';
            }
        }
    }

    //part1
    // for(ll i=0; i<operators.size(); i++){
    //     ll timesResult = 1;
    //     if(operators[i] == '*'){
    //         for(ll row=0; row<rows; row++){
    //             timesResult *= numList[row][i];
    //         }
    //         result += timesResult;
    //     } else{
    //         for(ll row=0; row<rows; row++){
    //             result += numList[row][i];
    //         }
    //     }
    // }

    cout << result << endl;

    return 0;
}