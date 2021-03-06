#include <bitset>
#include <vector>

template <typename T>
bool isPrimeNaive(T x) {
  if (x % 2 == 0)
    return false;
  for (T i = 3; i * i <= x; i += 2) {
    if (x % i == 0)
      return false;
  }
  return true;
}

// Size is usually maximally 1e8 (maybe 1e9 depending on time limit?)
// https://codeforces.com/blog/entry/75852
template <std::size_t N, typename T>
std::vector<T> sieveOfEratosthenes() {
  std::bitset<N + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (T i = 4; i <= N; i += 2) {
    isPrime[i] = 0;
  }
  for (T i = 3; i * i <= N; i += 2) {
    if (isPrime[i]) {
      for (T j = i * i; j <= N; j += i * 2) {
        isPrime[j] = 0;
      }
    }
  }

  std::vector<T> primes = {2};
  for (T i = 3; i <= N; i += 2) {
    if (isPrime[i]) {
      primes.emplace_back(i);
    }
  }

  // Faster alternative if using GCC
  // Uses bitset._Find_first and bitset._Find_next(int)
  // for (T i = isPrime._Find_first(); i <= N; i = isPrime._Find_next(i)) {
  //   primes.emplace_back(i);
  // }

  return primes;
}

#include <chrono>
#include <random>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
bool isProbablyPrime(int n, int iter = 5) {
  if (n < 4) {
    return n == 2 || n == 3;
  }
  for (int i = 0; i < iter; ++i) {
    int a = 2 + std::uniform_int_distribution(0, n - 4)(rng);
    if (binpow(a, n - 1, n) != -1)
      return false;
  }
  return true;
}
