#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool checkIfNum(const char& c) {
  return (c >= '0' && c <= '9');
}

bool checkIfNegative(const char& c) {
  return (c == '-');
}

int createNum(const string& inStr, int start, int end) {
  cout << "Debug: substr " << inStr.substr(start, end-start+1) << endl;
  return stoi(inStr.substr(start, end - start + 1));
}

string plusone(const string& inStr) {
  int mult = 1;
  int start = -1;
  int end = -1;
  stringstream outSS;
  bool ignoreNums = false;
  for (int i = 0; i < inStr.size(); ++i) {
    if (checkIfNum(inStr[i])) {
      if (ignoreNums) {
        outSS << inStr[i];
      } else {
        if (start == -1) {
          start = i;
          end = i;
        } else {
          end = i;
        }
      }
    } else {
      if (start != -1 && end != -1) {
        int num = createNum(inStr, start, end) * mult + 1;
        outSS << num;
        start = -1;
        end = -1;
        mult = 1;
      }

      if (inStr[i] == '.') {
        ignoreNums = true;
        outSS << '.';
      } else {
        ignoreNums = false;
        if (checkIfNegative(inStr[i])) {
          mult = -1;
        } else {
          outSS << inStr[i];
        }
      }
    }
  }

  if (start != -1 && end != -1) {
    int num = createNum(inStr, start, end) * mult + 1;
    outSS << num;
  }

  return outSS.str();
}

int main() {
  string inStr;
  while(1) {
    cout << "Enter a string : ";
    cin >> inStr;
    cout << "And the plusone string is : "
         << plusone(inStr) << endl;
  }
  return 0;
}
