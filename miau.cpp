#include <bits/stdc++.h>

class A {
public:
  int a;
  A(int aa) {
    a = aa;
  }
};

class B: public A {
public:
  B(int a):A(a) {

  }
};

int main()
{
  B b = B(1);
  printf("%d\n", b.a);
  return(0);
}