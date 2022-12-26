#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void GetCsv(double y, double s, double a, double r);
FILE* f;
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
        Print(y, s, a, r * s * b);
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
    fopen_s(&f, "results.csv", "wt");
    srand(time(NULL));
    double a = 1.0 * 2 / 3; // B(0) = 2/3;
    double b = a + normal();
    double y = 0;
    double r = 1; // biến quy định dấu
    double s = 1; // biến quy định dấu
    int k = 0; // biến đệ quy
    int m = 8; // độ phân giải

    cout << "|";
    cout << setw(8) << "y" << setw(9) << "|";
    cout << setw(8) << "s" << setw(8) << "|";
    cout << setw(8) << "a" << setw(8) << "|";
    cout << setw(10) << "r*s*b" << setw(6) << "|";
    cout << endl;
    Bzero(y, a, b, r, s, k, m);
    if (n == 0)
    {
        system("cls");
        cout << "Ham B(x) khong co so 0 nao!!!";
        return 0;
    }
    cout << "Ham B(x) co " << n << " so 0 o do phan giai " << m;
    fclose(f);
    return 0;
}
void Print(double y, double s, double a, double r)
{
    cout << "| ";
    cout << setw(15) << right << y << "|";
    cout << setw(15) << right << s << "|";
    cout << setw(15) << right << a << "|";
    cout << setw(15) << right << r << "|" << endl;
    GetCsv(y, s, a, r);
}
void GetCsv(double y, double s, double a, double r)
{
    fprintf(f, "%f,", y);
    fprintf(f, "%f,", a);
    fprintf(f, "\n");
}   
