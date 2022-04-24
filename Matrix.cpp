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
  vector<double> matrix;
  //readfile
  fstream file;
  file.open("matrix1.csv");
  string line;
  while (getline( file, line,'\n'))  //讀檔讀到跳行字元
	{
	  istringstream templine(line); // string 轉換成 stream
	  string data;
	  while (getline( templine, data,';')) //讀檔讀到逗號
	  {
	    matrix.push_back(atof(data.c_str()));  //string 轉換成數字
	  }
	}
  file.close();
  int row =  (line.size()/2);
  double matrix1[row][row];
  int a=0;
for(int i=0; i<row; i++){
    for(int j=0; j<row; j++){
        
       matrix1[i][j]  = matrix[a];
       a++;
    }
}
for(int i=0; i<row; i++){
    for(int j=0; j<row; j++){
    cout << " " << matrix1[i][j];
        if(j == row-1)
            cout << endl;
    }}

  //writefile
  file.open("write.csv");
  for (int i=0;i<matrix.size();i++)
  {
    file << matrix[i]<<",";
  }
  file.close();
  cout<<endl<<endl;
   /*
  POBRANIE DRUGIEJ MACIERZY
  */

 vector<double> matrix2;
  //readfile
  fstream file1;
  file1.open("matrix2.csv");
  string line1;
  while (getline( file1, line1,'\n'))  //讀檔讀到跳行字元
	{
	  istringstream templine1(line1); // string 轉換成 stream
	  string data1;
	  while (getline( templine1, data1,';')) //讀檔讀到逗號
	  {
	    matrix2.push_back(atof(data1.c_str()));  //string 轉換成數字
	  }
	}
  file1.close();
  int row1 =  (line1.size()/2);
  double matrix3[row1][row1];
  int a1=0;
for(int i=0; i<row1; i++){
    for(int j=0; j<row1; j++){
        
       matrix3[i][j]  = matrix2[a1];
       a1++;
    }
}
for(int i=0; i<row1; i++){
    for(int j=0; j<row1; j++){
    cout << " " << matrix3[i][j];
        if(j == row-1)
            cout << endl;
    }}
cout<<endl<<row1<<endl;

/*
MNOZENIE MACIERZY JEDNOWĄTKOWA
*/
 struct timeval begin, end; //structura danych typu timeval
    gettimeofday(&begin, 0); //funckja pobiera zegar systemowy
double mnozenie[row1][row1];
for(int i = 0; i < row1; ++i)
        for(int j = 0; j < row1; ++j)
        {
            mnozenie[i][j]=0;
        }
    // mnozenie macierzy a i b
    for(int i = 0; i < row1; ++i)
        for(int j = 0; j < row1; ++j)
            for(int k = 0; k < row1; ++k)
            {
                mnozenie[i][j] += matrix1[i][k] * matrix3[k][j];
            }
    // wyswietlanie wyniku mnozenia
    cout << endl << "Wynik mnozenia macierzy: " << endl;
    for(int i = 0; i < row1; ++i)
    for(int j = 0; j < row1; ++j)
    {
        cout << " " << mnozenie[i][j];
        if(j == row1-1)
            cout << endl;
    }
    gettimeofday(&end, 0); // pobranie zegara systemowego z konca procesu ktůre up≥ynÍ≥y, i mikrosekundach od 00:00:00, 1 stycznia 1970 r.
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;


    printf("czas realizacji zadania sekwencyjnie przez jeden watek Ts: %.3f seconds.\n", elapsed);




/*
MNOZENIE MACIERZY WIELOWĄTKOWA
*/

struct timeval begin1, end1; //structura danych typu timeval
    gettimeofday(&begin1, 0); //funckja pobiera zegar systemowy
double mnozenie1[row1][row1];
for(int i = 0; i < row1; ++i)
        for(int j = 0; j < row1; ++j)
        {
            mnozenie1[i][j]=0;
        }
    // mnozenie macierzy a i b
    for(int i = 0; i < row1; ++i)
        for(int j = 0; j < row1; ++j)
            for(int k = 0; k < row1; ++k)
            {
                mnozenie1[i][j] += matrix1[i][k] * matrix3[k][j];
            }
    // wyswietlanie wyniku mnozenia
    cout << endl << "Wynik mnozenia macierzy: " << endl;
    for(int i = 0; i < row1; ++i)
    for(int j = 0; j < row1; ++j)
    {
        cout << " " << mnozenie1[i][j];
        if(j == row1-1)
            cout << endl;
    }
    gettimeofday(&end1, 0); // pobranie zegara systemowego z konca procesu ktůre up≥ynÍ≥y, i mikrosekundach od 00:00:00, 1 stycznia 1970 r.
    long seconds1 = end1.tv_sec - begin1.tv_sec;
    long microseconds1 = end1.tv_usec - begin1.tv_usec;
    double elapsed1 = seconds1 + microseconds1*1e-6;


    printf("czas realizacji zadania sekwencyjnie przez wielewątkow watek TP: %.3f seconds.\n", elapsed1);

    fstream file4;
     file4.open ("matrix3.csv", ios::out | ios::app);
     if (file4) {
         file4<<"czas realizacji zadania sekwencyjnie przez jeden watek Ts: "<<elapsed<<endl;
         file4 << "Liczba kolumn: "<<row1<<endl;
         file4<<"Liczba wierszy: "<<row1 <<endl;
         for(int i = 0; i < row1; i++){
             for(int j = 0; j < row1; j++)
             {
                 file4 << mnozenie[i][j]<<";";
             }
             file4 <<  endl;
         }
     }

  return 0;
}
