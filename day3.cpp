#include <bits/stdc++.h>
using namespace std;

int turnBattery (string s) {
  int max1 = s[0] - '0';
  int index = 0;
  for (int i=1; i<s.size()-1; i++) {
    if (s[i] - '0' > max1) {
      max1 = s[i] - '0';
      index = i;
    }
  }

  int max2 = s[index+1] - '0';
  if (s.size() - index == 2) return max1*10+max2;

  for (int i=index+2; i<s.size(); i++) {
    if (s[i] - '0' > max2) {
      max2 = s[i] - '0';
    }
  }

  return max1*10+max2;
}

//987654321111111
long long turnBattery2 (string s) {
  int maxIndex = s.size() - 12;
  int max1 = s[0] - '0';
  int index = 0;
  for (int i=1; i<=maxIndex; i++) {
    if (s[i] - '0' > max1) {
      max1 = s[i] - '0';
      index = i;
    }
  }

  string newString = s.substr(index);
  int numTurnOff = s.size() - index - 12;

  while (numTurnOff > 0) {
    for (int i=2; i<newString.size(); i++) {
      if (newString[i] - '0' > newString[i-1] - '0') {
        newString.erase(i-1,1);
        break;
      }
    }
    numTurnOff--;
  }
  newString = newString.substr(0, 12);

  return stoll(newString);
}

long long turnBattery2AI(string s) {
    int k = 12; 
    string result = "";
    int n = s.length();

    for (int i = 0; i < n; i++) {
        while (!result.empty() && result.back() < s[i] && (result.length() - 1 + (n - i) >= k)) {
            result.pop_back();
        }
        result.push_back(s[i]);
    }
    result = result.substr(0, k);

    return stoll(result);
}

int main() {
  ifstream inputFile("input.txt");

  if (!inputFile.is_open()) return 1;

  long long result = 0;
  string number;

  while (inputFile >> number) {
    result += turnBattery2AI(number); 
  }

  cout << result << endl;

  inputFile.close();
  return 0;
}
