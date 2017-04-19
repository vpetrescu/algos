#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
string findExcelSheet(int n) {
    string result;
    while (n) {
        int r = ((n -1) % 26);
        result.push_back(char('A' + r));
        n = (n - r) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

int excel(string s) {
    int result = 0;
    int position = 1;
    for (int i = s.size() - 1; i>=0; i--) {
        result += int(s[i] - 'A' + 1) * position;
        position = 26 * position;
    }
    return result;
}

int main() {
    for (int i = 27; i <= 60; ++i) {
        cout << findExcelSheet(i) << endl;
    }
    cout << "---" << endl;
    cout << findExcelSheet(3) << endl;
    cout << findExcelSheet(26) << endl;
    cout << findExcelSheet(30) << endl;
    string s = "Ana are mere.";
    reverse(s.begin(), s.begin() + 6);
    cout << s << endl;
    cout << excel("A") << endl;
    cout << excel("C") << endl;
    cout << excel("Z") << endl;
    cout << excel("AB") << endl;
    cout << excel("AD") << endl;
}



