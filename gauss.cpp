#include <stdio.h>
#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stdio.h"
#include <sys/time.h>
int main()
{
 struct timeval begin1, end1; // structura danych typu timeval
    gettimeofday(&begin1, 0);    // funckja pobiera zegar systemowy

    vector<float> matrix;
    // readfile
    fstream file;
    file.open("matrixC.csv");
    string line;
    while (getline(file, line, '\n'))
    {
        istringstream templine(line);
        string data;
        while (getline(templine, data, ';'))
        {
            matrix.push_back(stod(data.c_str()));
        }
    }
    file.close();
    int row = 3; //(line.size()/2);
    float matrix1[row][row + 1];
    int a = 0;
    int wiersz = matrix[a];
    cout << "liczba wierszy " << wiersz << endl;
    a = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            matrix1[i][j] = matrix[a];

            a++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " " << matrix1[i][j];
            if (j == 3)
                cout << endl;
        }
    }

    int n = row, i, j, k;
    float x[n];
    cout << "\nThe matrix after Pivotisation is:\n";
    for (i = 0; i < n; i++) // print the new matrix
    {
        for (j = 0; j <= n; j++)
            cout << matrix1[i][j] << setw(16);
        cout << "\n";
    }
    for (i = 0; i < n - 1; i++) // loop to perform the gauss elimination
        for (k = i + 1; k < n; k++)
        {
            float t = matrix1[k][i] / matrix1[i][i];
            for (j = 0; j <= n; j++)
                matrix1[k][j] = matrix1[k][j] - t * matrix1[i][j]; // make the elements below the pivot elements equal to zero or elimnate the variables
        }

    cout << "\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i = 0; i < n; i++) // print the new matrix
    {
        for (j = 0; j <= n; j++)
            cout << matrix1[i][j] << setw(16);
        cout << "\n";
    }
    for (i = n - 1; i >= 0; i--) // back-substitution
    {                            // x is an array whose values correspond to the values of x,y,z..
        x[i] = matrix1[i][n];    // make the variable to be calculated equal to the rhs of the last equation
        for (j = i + 1; j < n; j++)
            if (j != i) // then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                x[i] = x[i] - matrix1[i][j] * x[j];
        x[i] = x[i] / matrix1[i][i]; // now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout << "\nThe values of the variables are as follows:\n";
    for (i = 0; i < n; i++)
        cout << "x[" << i + 1 << "]= " << setw(7) << setprecision(6) << x[i] << endl; // Print the va

    gettimeofday(&end1, 0); // pobranie zegara systemowego z konca procesu ktůre up≥ynÍ≥y, i mikrosekundach od 00:00:00, 1 stycznia 1970 r.
    long seconds1 = end1.tv_sec - begin1.tv_sec;
    long microseconds1 = end1.tv_usec - begin1.tv_usec;
    double elapsed1 = seconds1 + microseconds1 * 1e-6;


    /*OMP NIZEJ*/

    struct timeval begin, end; // structura danych typu timeval
    gettimeofday(&begin, 0);    // funckja pobiera zegar systemowy

    vector<float> matrixOMP;
    // readfile
    fstream fileOMP;
    fileOMP.open("matrixC.csv");
    string lineOMP;
    while (getline(fileOMP, lineOMP, '\n'))
    {
        istringstream templineOMP(lineOMP);
        string dataOMP;
        while (getline(templineOMP, dataOMP, ';'))
        {
            matrixOMP.push_back(stod(dataOMP.c_str()));
        }
    }
    fileOMP.close();
    int rowOMP = 3; //(lineOMP.size()/2);
    float matrix1OMP[rowOMP][rowOMP + 1];
    a = 0;
    int wierszOMP = matrixOMP[a];
    cout << "liczba wierszy " << wierszOMP << endl;
    a = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            matrix1OMP[i][j] = matrixOMP[a];

            a++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " " << matrix1OMP[i][j];
            if (j == 3)
                cout << endl;
        }
    }

    int nOMP = rowOMP;
    float xOMP[nOMP];
    cout << "\nThe matrixOMP after Pivotisation is:\nOMP";
    #pragma omp parallel for
    for (i = 0; i < nOMP; i++) // print the new matrixOMP
    {
        for (j = 0; j <= nOMP; j++)
            cout << matrix1OMP[i][j] << setw(16);
        cout << "\nOMP";
    }
    #pragma omp parallel for
    for (i = 0; i < nOMP - 1; i++) // loop to perform the gauss elimination
        for (k = i + 1; k < nOMP; k++)
        {
            float t = matrix1OMP[k][i] / matrix1OMP[i][i];
            for (j = 0; j <= nOMP; j++)
                matrix1OMP[k][j] = matrix1OMP[k][j] - t * matrix1OMP[i][j]; // make the elements below the pivot elements equal to zero or elimnate the variables
        }

    cout << "\nOMP\nThe matrixOMP after gauss-elimination is as follows:\nOMP";
    #pragma omp parallel for
    for (i = 0; i < nOMP; i++) // print the new matrixOMP
    {
        for (j = 0; j <= nOMP; j++)
            cout << matrix1OMP[i][j] << setw(16);
        cout << "\nOMP";
    }
    #pragma omp parallel for
    for (i = nOMP - 1; i >= 0; i--) // back-substitution
    {                            // xOMP is an array whose values correspond to the values of xOMP,y,z..
        xOMP[i] = matrix1OMP[i][nOMP];    // make the variable to be calculated equal to the rhs of the last equation
        for (j = i + 1; j < nOMP; j++)
            if (j != i) // then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                xOMP[i] = xOMP[i] - matrix1OMP[i][j] * xOMP[j];
        xOMP[i] = xOMP[i] / matrix1OMP[i][i]; // now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout << "\nThe values of the variables are as follows:\nOMP";
    for (i = 0; i < nOMP; i++)
        cout << "xOMP[" << i + 1 << "]= " << setw(7) << setprecision(6) << xOMP[i] << endl; // Print the va

    gettimeofday(&end, 0); // pobranie zegara systemowego z konca procesu ktůre up≥ynÍ≥y, i mikrosekundach od 00:00:00, 1 stycznia 1970 r.
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

   printf("czas realizacji zadania sekwencyjnie przez jeden watek TP: %.5f seconds.\n", elapsed1);
   printf("czas realizacji zadania sekwencyjnie przez wielewątkow watek TP: %.5f seconds.\n", elapsed);
   if(elapsed1>elapsed){
       cout<<endl<<"Dobrze dziala"<<endl;
   }else{
       cout<<endl<<"Zle dziala"<<endl;
   }
    string nazwa = "C_"+to_string(elapsed1)+"_"+to_string(elapsed)+".csv";
    printf("%s",nazwa.c_str());

    fstream file4;
    file4.open(nazwa, ios::out | ios::app);
    if (file4)
    {
        // file4<<"czas realizacji zadania sekwencyjnie przez jeden watek Ts: "<<elapsed<<endl;
        file4<<"czas realizacji zadania sekwencyjnie przez wiele watkow Ts: "<<elapsed<<endl;
         file4<<"czas realizacji zadania sekwencyjnie przez jeden watkow Tp: "<<elapsed1<<endl;
        file4 << rowOMP << endl;

        for (int i = 0; i < rowOMP; i++)
        {
            for (int j = 0; j < rowOMP + 1; j++)
            {
                file4 << xOMP[i] << ";";
            }
            file4 << endl;
        }
    }

    return 0;
}
