#include <bits/stdc++.h>
using namespace std;

bool checkID (long long n) {
  string s = to_string(n);
  int size = s.size()/2;
  if (s.size()%2 != 0) return false;
  for (int i=0; i<s.size()/2; i++) {
    if (s[i] != s[size]) return false;
    size++;
  }
  return true;
}

//689689689
bool checkID2 (long long n) {
  string s = to_string(n);
  int len = s.size();

  for (int steps=1; steps <= len/2; steps++) {
    if (len%steps != 0) continue;

    bool isRepeated = true;
    int k = len - steps;

    for (int i=0; i<k; i++) {
      if (s[i] != s[i+steps]) {
        isRepeated = false;
        break;
      }
    }
    if (isRepeated) return true;
  }
  return false;
}

//689689689
bool isInvalidID(long long n) {
    string s = to_string(n);
    int len = s.length();

    for (int k = 1; k <= len / 2; k++) {
        if (len % k == 0) {
            string pattern = s.substr(0, k); // Lấy mẫu thử nghiệm
            string constructed = "";
            
            for (int i = 0; i < len / k; i++) {
                constructed += pattern;
            }

            if (constructed == s) {
                return true; // Tìm thấy mẫu lặp lại -> Invalid ID
            }
        }
    }
    return false; // Không tìm thấy mẫu nào
}

int main() {
  ifstream inputFile("input.txt");

  if (!inputFile.is_open()) return 1;

  long long first, last, result=0;
  char dash;

  while (inputFile >> first >> dash >> last) {
    for (long long i=first; i<=last; i++) {
      if (checkID2(i)) {
        result += i;
      } 
    }

    if (inputFile.peek() == ',') {
      inputFile.ignore();
    }
  }
  
  cout << result << endl;
  inputFile.close();
  return 0;
}
