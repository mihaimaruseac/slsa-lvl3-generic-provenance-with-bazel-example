#include <iostream>

// Basic fibonacci

int fib(int x) {
  if (x < 2) return 1;
  return fib(x-1) + fib(x-2);
}

int main(int argc, char** argv) {
  std::cout << "fib(11) = " << fib(11) << "\n";
  std::cout << "fib(13) = " << fib(13) << "\n";
  return 0;
}
