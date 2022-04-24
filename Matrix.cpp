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

int main()
{

/*
POBRANIE MACIERZY PIERWSZEJ
*/
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
  file.open("matrix2.csv");
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
cout<<endl<<endl;
/*
MNOZENIE MACIERZY
*/
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
  return 0;
}
