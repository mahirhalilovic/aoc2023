#include <fstream>
#include <iostream>
#include <string>

#define red 12
#define green 13
#define blue 14

int checkV(int r, int g, int b) {
  return (r <= red) && (g <= green) && (b <= blue);
}

int checkValidity(std::string input) {
  int pos, gameID, temp, r = 0, g = 0, b = 0;
  std::string tempString;

  gameID = stoi(input.substr(5, 1));
  input = input.substr(8);

  std::cout << "checkValidity (gameID: " << gameID << "):\n";

  while(input[0] != '\0') {
    if (isdigit(input[0])) {
      pos = input.find(' ');
      tempString = input.substr(0, pos);
      std::cout << "tempString: " << tempString << "\n";
      temp = stoi(tempString);
      if (input[pos + 1] == 'r')
        r = std::max(r, temp);
      else if (input[pos + 1] == 'g')
        g = std::max(g, temp);
      else
        b = std::max(b, temp);

      std::cout << "temp: " << temp << '\n';
      input = input.substr(pos + 1);
      std::cout << "input: " << input << '\n';
    } else if (input[0] == ';' && !checkV(r, g, b)) return 0;
    else
      input = input.substr(1);
  }

  if(!checkV(r, g, b)) return 0;

  return gameID;
}

int main(int argc, char *argv[]) {
  std::ifstream file;
  std::string input;
  int sum = 0;

  std::cout << "Input file: " <<  argv[1] << '\n';
  file.open(argv[1]);

  while (std::getline(std::cin, input)) {
    std::cout << "Input: " << input << '\n';
    sum += checkValidity(input);
  }

  file.close();

  std::cout << sum;

  return 0;
}
