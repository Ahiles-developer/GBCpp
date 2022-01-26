#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("1.txt");

    if (fout.is_open()) 
    {
        fout << "dsffsfas" << 1234213 << endl;
       
        fout.close();
    }

}

