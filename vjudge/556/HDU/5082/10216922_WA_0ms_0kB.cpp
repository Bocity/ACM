#include <bits/stdc++.h>
int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << a.substr(a.find('_') + 1) + "_small_" + b.substr(b.find('_') + 1) << std::endl;
}