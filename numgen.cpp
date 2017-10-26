#include "commander.h"
#include <iostream>
#include <numeric>
#include <random>
#include <stdio.h>
#include <vector>

void gen_random(long long int n);
void gen_shuffle(long long int n, int shuffles);
void gen_list(long long int n, bool descending);
bool isint(char*);
long long int parseint(char*);
void printv(std::vector<long long int> S);

int main(int argc, char* argv[]) {
  int option = 0;
  bool randomized = false, shuffled = false, listed = false, descending = false;
  long long int n = 0;
  long long int shuffles = 0;
  cmd_opt_value();
  cmd_opt("-r", "--random", false);
  cmd_opt("-s", "--shuffle", true);
  cmd_opt("-l", "--list", false);
  cmd_opt("-ld", "--list-descending", false);

  while ((option = cmd_parse(argc, argv)) != -1) {
    switch (option) {
    case 1: {
      n = parseint(argv[cmd_val_index()]);
      break;
    }
    case 2:
      randomized = true;
      break;
    case 3: {
      shuffled = true;
      shuffles = parseint(argv[cmd_val_index()]);
      break;
    }
    case 4: {
      listed = true;
      descending = false;
      break;
    }
    case 5: {
      listed = true;
      descending = true;
      break;
    }
    default:
      break;
    }
  }
  if (cmd_opt_index() == 0) {
    printf("Usage: %s number [ -r random | -s shuffle [number] | -sd shuffled-descending [number] | -l list | -ld list-descending ]\n", argv[0]);
  } else {
    if (randomized) {
      gen_random(n);
    } else if (shuffled) {
      gen_shuffle(n, shuffles);
    } else if (listed) {
      gen_list(n, descending);
    }
  }
  return cmd_free();
}

void gen_random(long long int n) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(-n, n);
  for (int i = 0; i < n; i++) {
    std::cout << dist(mt) << " ";
    std::cout << '\n';
  }
}

void gen_shuffle(long long int n, int shuffles) {
  std::vector<long long int> S(n);
  std::iota(std::begin(S), std::end(S), 1);
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(0, n - 1);
  while (shuffles--) {
    long long int a = dist(mt);
    long long int b = dist(mt);
    std::swap(S[a], S[b]);
  }
  printv(S);
}

void gen_list(long long int n, bool descending) {
  if (!descending) {
    for (long long int i = 1; i <= n; i++)
      printf("%lld\n", i);
  } else {
    for (long long int i = n; i >= 1; i--)
      printf("%lld\n", i);
  }
}

bool isint(char* s) {
  int i = 0;
  if (s[0] == '-') i = 1;
  for (; s[i] != 0; i++) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

long long int parseint(char* s) {
  long long int n = 0;
  if (isint(s)) {
    sscanf(s, "%lli", &n);
  }
  return n;
}

void printv(std::vector<long long int> S) {
  for (auto n : S) {
    printf("%lli\n", n);
  }
}
