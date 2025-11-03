#include <string>
#include <iostream>
#include <ostream>

using namespace std;

string compress(string text)
{
  string result = "";
  int j = 1;
  for (int i = 0; i < text.size(); i++)
  {
    if(i > 0 && text[i-1] == text[i]) continue;
    while(text[i] == text[i + j]){ j++; }
    result = result + to_string(j) + text[i];
    j = 1;
  }
  return result;
}

void printFormattedText(string text)
{
  cout << "----------------------------" << endl;
  cout << text << endl;
  cout << "----------------------------" << endl;
}

int main() 
{
  string input;
  string compressedInput;
  printFormattedText("ENTER INPUT");
  getline(cin, input);
  compressedInput = compress(input);
  printFormattedText(compressedInput);
  return 0;
}
