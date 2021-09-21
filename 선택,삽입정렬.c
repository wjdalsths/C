//#include <stdio.h>
//#pragma warning(disable:4996)
//#define MAX 30
//int n, d[MAX];
//
//int main()
//{
//    scanf("%d", &n);
//
//
//    for (int i = 1; i <= n; i++)
//        scanf("%d", &d[i]);
//
//
//    for (int i = 1; i < n; i++)
//    {
//        int m = i;
//        for (int j = i + 1; j <= n; j++)
//            if (d[m] > d[j])
//                m = j;
//
//
//        int t = d[i];
//        d[i] = d[m];
//        d[m] = t;
//    }
//
//    for (int i = 1; i <= n; i++)
//        printf("%d\n", d[i]);
//}
//¹®Á¦ 2
#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 30
int n, d[MAX];

int main()
{
    scanf("%d", &n);


    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);


    int i = 2;
    while (i <= n)
    {
        int j = i;
        while (j >= 2 && d[j - 1] > d[j])
        {
            int t = d[j - 1];
            d[j - 1] = d[j];
            d[j] = t;
            j = j - 1;
        }
        i = i + 1;
    }


    for (int i = 1; i <= n; i++)
        printf("%d\n", d[i]);
}