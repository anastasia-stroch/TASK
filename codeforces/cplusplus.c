// https://codeforces.com/problemset/problem/1915/B

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void solve_test(char a, char b, char c) {
    if (a == b)
    {
        cout << c << "\n";
    }
    else if (a == c)
    {
        cout << b << "\n";
    }
    else if (c == b)
    {
        cout << a << "\n";
    }
}

void vector_test() {
    vector<vector<char>> v1(3, vector<char>(3,0));
    for (vector<char>& i: v1) {
        for (char& j: i) {
            cin >> j;
        }
    }
    int c = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (v1[i][j] == '?') {
                c = i;
            }
        }
    }
    char h = 'B', k = 'A', j = 'C';
    for (int i = 0; i < 3; ++i) {
        if (v1[c][i] == 'B'){
            h = 'K';
        }
        else if (v1[c][i] == 'A') {
            k = 'K';
        }
        else if (v1[c][i] == 'C') {
            j = 'K';
        }
    }
    solve_test(h,k,j);
}

int main() {
    int h;
    cin >> h;
    for (int i = 0; i < h; ++i)
    {
        vector_test();
    }
    return 0;
}

// https://vjudge.net/contest/639237#problem/I

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n,k;
    cin >> n >> k;
    int c = 0;
    vector<int> v1(n,0);
    for (int& i: v1) {
        cin >> i;
    }
    int iter = 0;
    int i = n - 1;
    sort(v1.begin(),v1.end());
    while (i >= iter ) {
        if (v1[i] + v1[iter] <= k) {
            iter += 1;
            i -= 1;
        }
        else {
            i -= 1;
        }
        c += 1;
    }
    if (n % 2 != 0) {
        if (v1[i] + v1[iter] > k) {
            c += 2;
        }
    }
    cout << c << "\n";

    return 0;
}

// https://codeforces.com/problemset/problem/1774/A?locale=ru

#include <iostream>
#include <string>


using namespace std;

void solve_test() {
    int k;
    cin >> k;
    string str;
    cin >> str;
    string str2 = "";
    int c = 0;
    if (str[0] == '1') {
        c = 1;
    }
    for (int i = 1; i < k; ++i) {
        if (str[i] == '1') {
            if (c == 0) {
                str2.push_back('+');
                c = 1;
            }
            else {
                str2.push_back('-');
                c = 0;
            }
        }
        else {
            str2.push_back('+');
        }
    }
    cout << str2 << "\n";

}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve_test();
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1175/A

#include <iostream>

using namespace std;


void solve_test() {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    long long r = 0;
    while (n != 0) {
        if (n % k == 0) {
            n /= k;
            sum += 1;
        }    
        else {
            long long r = n % k;
            n -= r;
            sum += r;
        }    
    }
    cout << sum << "\n";
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve_test();
    }
    return 0;
}

// https://vjudge.net/contest/639237#problem/I

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n,k;
    cin >> n >> k;
    int c = 0;
    vector<int> v1(n,0);
    for (int& i: v1) {
        cin >> i;
    }
    int iter = 0;
    int i = n - 1;
    sort(v1.begin(),v1.end());
    while (i >= iter ) {
        if (v1[i] + v1[iter] <= k) {
            iter += 1;
            i -= 1;
        }
        else {
            i -= 1;
        }
        c += 1;
    }
    if (n % 2 != 0) {
        if (v1[i] + v1[iter] > k) {
            c += 2;
        }
    }
    cout << c << "\n";

    return 0;
}

// https://vjudge.net/contest/639237#problem/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> lol1(n * 2, "ok");
    vector<int> coun(n, 0);
    int ma = 0;
    int c = 0;
    string temp;
    getline(cin, temp);
    for (int i =0; i < n * 2; i += 2) {
        string h;
        getline(cin, h);
        string lol;
        getline(cin, lol);
        lol1[i] = h;
        lol1[i+1] = lol;
    }
    int imho;
    cin >> imho;
    getline(cin, temp);
    for (int l = 0; l < imho; ++l) {
        string ofc;
        getline(cin, ofc);
        for (int i = 0; i < n * 2; i += 2) {
            if (ofc == lol1[i]) {
                coun[i / 2] += 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (coun[i] > ma) {
            ma = coun[i];
            c = i;
        }
    }
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (coun[c] == coun[i]) {
            if (i != c) {
                cout << "tie";
                x = 1;
                break;
            }
        }
    }
    if (x != 1) {
        cout << lol1[c * 2 + 1];
    }
    return 0;
}