#include <string>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

string compress(string text)
{
  string result = "";
  int j;
  for (int i = 0; i < text.size(); i++)
  {
    if(i > 0 && text[i-1] == text[i]) continue;
    j=1;
    while(text[i] == text[i + j]){ j++; }
    result = result + to_string(j) + text[i];
  }
  return result;
}

vector<string> splitCompressedString(string& inputString)
{
    string delimiters = "abcdefghijklmnopqrstuvwxyz";
    vector<string> result;
    int startPos = 0;
    int endPos = 0;

    // Loop until endPos is not equal to string::npos
    while ((endPos = inputString.find_first_of(delimiters, startPos)) != string::npos) 
    {
        if (endPos != startPos) { result.push_back(inputString.substr(startPos, endPos + 1 - startPos)); }
        startPos = endPos + 1;
    }

    if (startPos != inputString.length()) { result.push_back(inputString.substr(startPos)); }
    return result;
}

string decompressSegment(string segment)
{
  string result = "";
  int count = stoi(segment.substr(0, segment.size() - 1));
  char c = segment.back();
  for(int i = 0; i < count; i++) { result = result + c; }
  return result;
}

string decompress(string text)
{
  string s = "";
  vector<string> results = splitCompressedString(text);
  for (const auto& result : results) 
  {
    s = s + decompressSegment(result);
  }
  return s;
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
  string decompressedInput;

  printFormattedText("ENTER INPUT");
  getline(cin, input);

  compressedInput = compress(input);
  printFormattedText(compressedInput);
  
  decompressedInput = decompress(compressedInput);
  printFormattedText(decompressedInput);

  return 0;
}
