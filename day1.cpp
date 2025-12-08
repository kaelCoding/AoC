#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream inputFile("input.txt");

  if (!inputFile.is_open()) return 1;

  int count_begin = 50;
  int pass = 0;
  char direction;
  int steps;

  while (inputFile >> direction >> steps) {
    if (direction == 'R') {
      pass += (int) (count_begin + steps) / 100;
      count_begin = (count_begin + steps) % 100;
    } else {
      if (count_begin <= steps && count_begin != 0) {
        pass += (int) abs(count_begin - steps) / 100 + 1;
      }

      if (count_begin == 0 && steps >= 100) {
        pass += (int) steps/100;
      }

      count_begin = ((count_begin - steps) % 100 + 100) % 100;
    }
  }

  cout << pass << endl;
  inputFile.close();
  return 0;
}

