#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int dem = 0;
double uniform();
double normal();
int n = 0;
bool Bzero(double y, double a, double b, double r, double s, int k, int m);
void Print(double y, double s, double a, double r);

// uniform la ham tra ve so thuc ngau nhien giua 0 va 1
double uniform()
{
    double res = 1.0 * (rand() % (1000 - 1 + 1) + 1) / 1000;
    return res;
}
// normal la ham tra ve so thuc ngau nhien giua -1 va 1
double normal()
{
    int dau = rand() & 1 ? -1 : 1;
    double res = dau * 1.0 * (rand() % (1000 - 1 + 1) + 1) / 1000;
    return res;
}
// Ham Bzero 
bool Bzero(double y, double a, double b, double r, double s, int k, int m)
{
    double c;
    if (a * b > 0)
    {
        double res = exp(pow(-2.0, k + 1) * a * b);
        if (uniform() < res)
        {
            b = -1.0 * b;
            r = -1.0 * r;
        }
        else return false;
    }
    if (k == m)
    {
        n++;
    }
    else
    {
        c = 1.0 * (a + b) / 2 + pow(2.0, -1 - 1.0 * k / 2) * normal();
        if (Bzero(y, a, c, r, s, k + 1, m))
        {
            Bzero(y + pow(2.0, -k - 1), c, b, 1, r * s, k + 1, m);
        }
        else
            Bzero(y + pow(2.0, -k - 1), c, b, r, s, k + 1, m);
    }
    return true;
}
int main()
{
    srand(time(NULL));
    double a = 1.0 * 2 / 3; // B(0) = 2/3;
    double b = a + normal();
    double y = 0;
    double r = 1; // biến quy định dấu
    double s = 1; // biến quy định dấu
    int k = 0; // biến đệ quy
    int m = 4; // độ phân giải
    int d = 0;

    FILE* f;
    fopen_s(&f, "result2.csv", "wt");
    //B(X) là sóng điiện của thiết bị điện chạy qua với B(0)=2/3,độ phức tạp= 4||Khi sóng điện bằng không là thiết bị không ổn đinhk. 
    //Ta sẽ kiểm tra 1 lô sản phẩn cũ gồm 100 thiết bị, sản phẩm nào có số lần sóng điện bằng 0 nhiều hơn .... là bỏ, ko dùng .
    while (d < 100)
    {
        Bzero(y, a, b, r, s, k, m);
        cout << n;
        fprintf(f, "%d", n); fprintf(f, "\n");
        d++;
        n = 0;
    }

    fclose(f);
    return 0;
}


