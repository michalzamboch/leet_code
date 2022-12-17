#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
      int j = s.size() - 1;
      for (auto i = 0; i < s.size() / 2; i++)
      {
          swap(s.at(i), s.at(j));
          j--;
      }
    }
};

void print(vector<char>& s)
{
  for (auto x : s)
    cout << x << " ";
  cout << endl;
}

int main()
{
  printf("Start...\n");
  
  vector<char> pole{'H', 'a', 'n', 'n', 'a', 'h'};
  Solution solution;
  
  print(pole);
  solution.reverseString(pole);
  print(pole);



  return 0;
}
