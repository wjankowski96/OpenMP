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
using namespace std;
FILE * myFile3 = stdout;
#include <stdio.h>
//#include <process.h>
int main()
{


/*
    WCZYTANIE PIERWSZEJ MACIERZY
*/
string fname;
	cout<<"Enter the file name: ";
	cin>>fname;
 
	vector< vector<string> > content;
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ';'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";

 double matrix1[content.size()][content.size()];
	for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
			matrix1[i][j]=(int)content[i][j];
		}
		cout<<"\n";
	}

/*
    WCZYTANIE DRUGIEJ MACIERZY

string fname1;
	cout<<"Enter the file name: ";
	cin>>fname1;
 
	vector< vector<string> > content1;
	vector<string> row1;
	string line1, word1;
 
	fstream file1 (fname1, ios::in);
	if(file1.is_open())
	{
		while(getline(file1, line1))
		{
			row.clear();
 
			stringstream str(line1);
 
			while(getline(str, word1, ';'))
				row.push_back(word1);
			content.push_back(row1);
		}
	}
	else
		cout<<"Could not open the file\n";

 double matrix2[content1.size()][content1.size()];
	for(int i=0;i<content1.size();i++)
	{
		for(int j=0;j<content1[i].size();j++)
		{
			matrix2[i][j]=stod(content1[i][j]);
		}
		cout<<"\n";
	}


*/


    /*
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Wprowadz liczbe wierszy i kolumn pierwszej macierzy: ";
    cin >> r1 >> c1;
    cout << "Wprowadz liczbe wierszy i kolumn drugiej macierzy: ";
    cin >> r2 >> c2;

    
    while (c1!=r2)
    {
        cout << "Blad, ilosci kolumn pierwszej nie jest rowna drugiej wierszy.";

        cout << "Wprowadz liczbe  kolumn i wierszy pierwszej macierzy ";
        cin >> r1 >> c1;

        cout << "EnWprowadz liczbe  kolumn i wierszy drugiej macierzy: ";
        cin >> r2 >> c2;
    }

    
    cout << endl << "Wprowadz wartosci dla macierzy 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Wartość macierzy a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

   
    cout << endl << "Wprowadz wartosci dla macierzy 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Wartość macierzy b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

   
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // mnozenie macierzy a i b
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // wyswietlanie wyniku mnozenia
    cout << endl << "Wynik mnozenia macierzy: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }
//Zapis do pliku wynikow mnozenia
fstream file;
    file.open ("matrix3.csv", ios::out | ios::app);
    if (file) {
        file << "Liczba kolumn: "<<c1<<endl;
        file<<"Liczba wierszy: "<<c2 <<endl;
        for(int i = 0; i < c1; i++){
            for(int j = 0; j < c2; j++)
            {
                file << mult[i][j]<<";";
            }
            file <<  endl;
        }
            
    }else{
        printf("Blad pliku");
    }
    
    file.close();
    */
    return 0;
}
