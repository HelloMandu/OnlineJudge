#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
 
int main()
{
    int A[100001], B[100001];
    string strA, strB;
    cin >> strA >> strB;
    int i = strA.length() - 1;
    while (i != -1){
        A[i] = strA[i] - '0';
        B[i] = strB[i] - '0';
        i--;
    }
 
    int len = strA.length();
    for (i = 0; i < len; i++)
        printf("%d", A[i] & B[i]);
        printf("\n");
 
    for (i = 0; i < len; i++)
        printf("%d", A[i] | B[i]);
        printf("\n");
 
    for (i = 0; i < len; i++)
        printf("%d", A[i] ^ B[i]);
        printf("\n");
 
    for (i = 0; i < len; i++)
        printf("%d", !A[i]);
        printf("\n");
 
    for (i = 0; i < len; i++)
        printf("%d", !B[i]);
        printf("\n");

    return 0;
}