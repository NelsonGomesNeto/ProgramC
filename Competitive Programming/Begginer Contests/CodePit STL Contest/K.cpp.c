#include <bits/stdc++.h>

int main ()
{

  string word;
  cin >> word;
  if(std::next_permutation(word, word + 6) != 0)
  {
    cout << word;
  }

  //std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
