#include <iostream>
using namespace std;
void Q(int z)
{
  z += z;
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;
  Q(x);
  *y = x - 1; 
  cout<<x << " ";
}

int main()
{
  int x = 5;
  int* p = &x;
//   P(&x);
//   cout<<x;

  cout << *p + 1 << endl;
  cout << *(p) + 1 << endl;
  cout << (p + 1) << endl;
  cout << *(p + 1) << endl;
  return 0;
}