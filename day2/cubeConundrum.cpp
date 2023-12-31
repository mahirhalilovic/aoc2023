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

	pos = input.find(':');
  gameID = stoi(input.substr(5, pos - 5));
  input = input.substr(8);

  std::cout << "checkValidity (gameID: " << gameID << "): ";

  while(input[0] != '\0') {
    if (isdigit(input[0])) {
      pos = input.find(' ');
      tempString = input.substr(0, pos);
      // std::cout << "tempString: " << tempString << "\n";
      temp = stoi(tempString);
      if (input[pos + 1] == 'r')
        r = std::max(r, temp);
      else if (input[pos + 1] == 'g')
        g = std::max(g, temp);
      else
        b = std::max(b, temp);

      // std::cout << "temp: " << temp << '\n';
      input = input.substr(pos + 1);
      // std::cout << "input: " << input << '\n';
    } else if (input[0] == ';' && !checkV(r, g, b)) {
					std::cout << '\n';
					return 0;
				}
    else
      input = input.substr(1);
  }

  if(!checkV(r, g, b)) {
		std::cout << '\n';
		return 0;
	}

	std::cout << "x\n";
  return gameID;
}

int main(int argc, char *argv[]) {
  std::ifstream file;
  std::string input;
  int sum = 0;

  file.open(argv[1]);
	std::cout << "Opened file: " << argv[1] << '\n';

  while (std::getline(file, input, '\n')) {
    // std::cout << "Input: " << input << '\n';
    sum += checkValidity(input);
  }

  file.close();

  std::cout << "Sum: " << sum;

  return 0;
}
