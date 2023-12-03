#include <iostream>
#include <fstream>

int charNumToInt(char input) { return input - '0'; }

int findCalibrationValue(std::string input) {
  short fst = 0, lst = 0;
  int i = 0;
  int n = input.length();

  while(!isdigit(input[i])) ++i;

  fst = charNumToInt(input[i]);
 
  i = n - 1;
  while(!isdigit(input[i])) --i;

  lst = charNumToInt(input[i]);

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

