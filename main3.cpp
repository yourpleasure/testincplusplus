#ifdef MAIN3
#include <iostream>
using namespace std;
int makeChange(int n, int denom)
{
    int next_donem = 0;
    switch (denom) {
    case 25:
        next_donem = 10;
        break;
    case 10:
        next_donem = 5;
        break;
    case 5:
        next_donem = 1;
        break;
    case 1:
        return 1;
    default:
        break;
    }

    int ways = 0;
    for(int i = 0; i * denom <= n; i++){
        ways += makeChange(n - i * denom, next_donem);
    }

    return ways;
}

int main()
{
    cout << makeChange(100, 25) << endl;
    return 0;
}

#endif
