#include <iostream>
#include <fstream>
#include <cstring>

struct Num {
  std::string name;
  int value;
};

Num lookup[9] = {
  {"one", 1},
  {"two", 2},
  {"three", 3},
  {"four", 4},
  {"five", 5},
  {"six", 6},
  {"seven", 7},
  {"eight", 8},
  {"nine", 9}
};

int charNumToInt(char input) { return input - '0'; }

int checkNum(std::string input, Num *nums) {
  for(int i = 0; i < 9; ++i) {
    if(!strncmp(input.c_str(), nums[i].name.c_str(), nums[i].name.length()))
      return nums[i].value;
  }

  return -1;
}

int findCalibrationValue(std::string input) {
  short fst = -1, lst = -1;
  int i = 0, n = input.length();

  for(; i < n; ++i) {
    if(isdigit(input[i]) && fst == -1) fst = lst = charNumToInt(input[i]);
    else if(isdigit(input[i])) lst = charNumToInt(input[i]);
    else if(checkNum(input.substr(i, n - i), lookup) != -1 && fst == -1) fst = lst = checkNum(input.substr(i, n - i), lookup);
    else if(checkNum(input.substr(i, n - i), lookup) != -1) lst = checkNum(input.substr(i, n - i), lookup);
  }

  return fst * 10 + lst;
}

int main(int argc, char *argv[]) {
  std::ifstream file;
  int calibrationSum = 0;
  std::string input;

  file.open(argv[1]);

  while(file >> input) {
    calibrationSum += findCalibrationValue(input);
  }

  file.close();
  std::cout << calibrationSum;
  
  return 0;
}

