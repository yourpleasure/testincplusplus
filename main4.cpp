#define MAIN4
#ifdef MAIN4
#include <iostream>
using namespace std;

int makeChange(int n)
{
    int allDenom[] = {5, 10, 25};
    int *result[sizeof(allDenom)/sizeof(allDenom[0])+1];
    int maxLength = n / allDenom[0];
    for(int i = 0; i <= (int)(sizeof(allDenom)/sizeof(allDenom[0]));i++)
        result[i] = new int[maxLength + 1];

    for(int i = 0; i <= maxLength; i++)
        result[0][i] = 1;
    for(int i = 0; i < (int)(sizeof(allDenom) / sizeof(allDenom[0])); i++){
        int temp = allDenom[i] / allDenom[0];
        for(int j = 0; j <= maxLength; j += 1){
            for(int k = j; k >= 0; k -= temp){
                result[i+1][j] += result[i][k];
            }
        }
    }

    int ways = result[sizeof(allDenom)/sizeof(allDenom[0])][n/allDenom[0]];
    for(int i = 0; i <= (int)(sizeof(allDenom)/sizeof(allDenom[0]));i++)
        delete[] result[i];
    return ways;
}

int main()
{
    cout << makeChange(100) << endl;
    return 0;
}

#endif
