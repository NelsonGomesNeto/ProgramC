// Paulo Cezar, Maratona 2017, Brincadeira
#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1000000;

namespace LFSR {
  unsigned nbits, state, input_bit;
  vector<unsigned> taps;

  void init() {
    input_bit = (1u << (nbits - 1));
    for (auto& v : taps) v = 1u << v;
  }

  unsigned clock() {
    unsigned input {0};
    for (auto& v : taps) if (state & v) input ^= input_bit;
    unsigned previous = state;
    state = (state >> 1) | input;
    return previous;
  }
};

array<int, MAXX> first_idx;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int X, Y, ntaps;

  cin >> LFSR::nbits >> ntaps >> LFSR::state >> X >> Y;
  LFSR::taps.resize(ntaps);
  for (auto& v : LFSR::taps) cin >> v;

  LFSR::init();

  first_idx[0] = 1;
  unsigned acm = 0;
  for (int i = 2; ;++i) {
    acm = (acm + LFSR::clock()) % X;
    cout << acm << " " << first_idx[acm] << "\n";
    if (first_idx[acm]) {
      if (i-first_idx[acm] >= Y) {
        cout << first_idx[acm]-1 << " " << i-2 << "\n";
        break;
      }
    } else {
      first_idx[acm] = i;
    }
  }

  return 0;
}