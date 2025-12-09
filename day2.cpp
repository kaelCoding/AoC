/*
 * Advent of Code 2025
 * Day 2: Gift Shop
 * Author: Kael
 * Language: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Part1
bool checkID (long long n){
  string s = to_string(n);
  int size = s.size()/2;

  if(s.size()%2 != 0) return false;

  for(int i=0; i<s.size()/2; i++){
    if(s[i] != s[size]) return false;
    size++;
  }

  return true;
}

//Part2
bool checkID2 (long long n){
  string s = to_string(n);
  int len = s.size();

  for(int steps=1; steps <= len/2; steps++){
    if(len%steps != 0) continue;

    bool isRepeated = true;
    int k = len - steps;

    for(int i=0; i<k; i++){
      if(s[i] != s[i+steps]){
        isRepeated = false;
        break;
      }
    }

    if(isRepeated) return true;
  }
  return false;
}

int main(){
  ifstream inputFile("input.txt");
  if(!inputFile.is_open()) return 1;

  long long first, last, result=0;
  char dash;

  while(inputFile >> first >> dash >> last){
    for(long long i=first; i<=last; i++){
      if(checkID2(i)) result += i;
    }

    if(inputFile.peek() == ',') inputFile.ignore();
  }
  
  cout << result << endl;
  inputFile.close();
  return 0;
}