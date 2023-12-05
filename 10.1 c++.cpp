#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Count(const string& s, const string& find, int* a)
{
    for (int i = 0; i < find.length(); i++)
    {
        int c = 0;
        size_t pos = s.find(find[i]);

        while (pos != string::npos)
        {
            c++;
            pos = s.find(find[i], pos + 1);
        }
        a[i] += c;
    }
}

int main()
{
    string str;
    string find = "BASIC";
    int* a = new int[find.length()]();

    ifstream fin("t.txt");
    while (getline(fin, str))
    {
        Count(str, find, a);
    }

    for (int i = 0; i < find.length(); i++)
    {
        cout << "Symbol " << find[i] << " occurs " << a[i] << " times" << endl;
    }

    delete[] a;

    return 0;
}