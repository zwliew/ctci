#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }

  for (int i = 0; i < n; ++i) {
    if (sum - 2 * arr[i] == 0) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
}