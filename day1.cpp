/*
 * Advent of Code 2025
 * Day 1: Secret Entrance
 * Author: Kael
 * Language: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>    
#include <vector>

using namespace std;

int main(){
  ifstream inputFile("input.txt");
  if(!inputFile.is_open()) return 1;

  int current_pos = 50;
  int total_passes = 0;
  int steps;
  char direction;

  while(inputFile >> direction >> steps){
    if(direction == 'R'){
      total_passes += (current_pos + steps) / 100;
      current_pos = (current_pos + steps) % 100;
    } else{
      if(current_pos <= steps && current_pos != 0){
        total_passes += abs(current_pos - steps) / 100 + 1;
      }

      if(current_pos == 0 && steps >= 100){
        total_passes += steps / 100;
      }

      // ((a % n) + n) % n
      current_pos = ((current_pos - steps) % 100 + 100) % 100;
    }
  }

  cout << total_passes << endl;
  inputFile.close();

  return 0;
}