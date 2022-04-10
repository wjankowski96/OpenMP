#include <iostream>
#include <math.h>
#include "stdio.h"
#include <omp.h>

/* Funkcja dla ktorej obliczamy calke */
float func(float x)
{
    double A = 2, B =2, C = 2;
    //printf("Zmienna A w funkcji wynosi: %fl\n", A);
    double oblCal = A * (x * x) + B * x + C;
    return oblCal;
}
/*
Funkcja calkowania metoda Simpsona, przekazanie parametrow poczatku i konca przedzialu, ilosci przedzialow i watkow
Obliczenia przedzialu calkowania na N rownych czesci, zastosowanie klauzuli redukcji zmiennej calka, ktorej wszystkie prywatne kopie zmiennych sa wspodzioelone,a wynik koncowy jesty zapisywany do globalnej zmiennej wspoldzielonej
Zastosowanie omp_get_wtime do obliczenia czasu jaki jest potrzebny na wykonanie tej funkcji
*/
double calkowanie(double poczPrzedzial, double koncPrzedzial, int n, int red)
{
   
    double now = omp_get_wtime();
    double a = poczPrzedzial, b = koncPrzedzial, xs, s=0, calka=0;
    int lobliczen = n, lwatkow = red;
    double h;
    /* Zapewnienie dostepu do innego bloku pamieci dla kazdego watku*/
  //wątek powinien mieć własne wystąpienie zmiennej
        h = (b - a) / lobliczen;            //odleglosc miedzy dwoma sasiednimi punktami, przedzial calkowania dzielony na N rownych czesci
    #pragma omp parallel for num_threads(lwatkow) reduction(+: s,calka) private(xs)//zmiennea, które jest prywatne dla każdego wątku jest obiektem operacji redukcji na końcu regionu równoległego
    for (int i = 1; i < lobliczen; i++)
    {
        xs = a + i * h;                //pozycja punktu przedziałowego
        s +=func (xs - h / 2);         //punkt srodkowy dla ktorego bedzie obliczane przyblizenie               
        calka += func(xs);
    }
        s += func(b - h / 2);           //suma wartości funkcji w punktach srodkowych
        /* Konstrukcja critical ogranicza wykonanie powiązanego z nią bloku strukturalnego w jednym wątku w danym czasie */
        //#pragma omp critical
        calka = (h / 6) * (func(a) + func(b) + 2 * calka + 4 * s); //prsyblizona wartosc calki oznaczonej funckji f(x) w przedziale pocz i konc
    
    printf("Czas Simpsonem wynosi %f\n", omp_get_wtime() - now) ;
    
    
    return (double)calka;
    

}

double trapezy(double poczPrzedzial, double koncPrzedzial, int n, int red){//retangle
    double s  = 0,xp=poczPrzedzial,xk=koncPrzedzial;
    int N=n;
  double dx = (xk - xp) / N;
  for(int i = 1; i < N; i++) s += func(xp + i * dx);
  s = (s + (func(xp) + func(xk)) / 2) * dx;
  return s;
}


double trapezy1(double poczPrzedzial, double koncPrzedzial, double n, int red){
    double s  = 0;
    double xk = koncPrzedzial, xp=poczPrzedzial;
  double dx = (xk - xp) / n;
  for(int i = 1; i <= n; i++) 
  s += func(xp + i * dx);

  s *= dx;
  printf("wynik działa = %lf\n",s);
  return s;
}

double calkowaniebez(double poczPrzedzial, double koncPrzedzial, int n, int red)
{
   
    double now = omp_get_wtime();
    double a = poczPrzedzial, b = koncPrzedzial, xs, s=0, calka=0;
    int lobliczen = n, lwatkow = red;
    double h;
        h = (b - a) / lobliczen;            //odleglosc miedzy dwoma sasiednimi punktami, przedzial calkowania dzielony na N rownych czesci
      
        for (int i = 1; i < lobliczen; i++)
        {
            xs = a + i * h;                //pozycja punktu przedziałowego
            s +=func (xs - h / 2);         //punkt srodkowy dla ktorego bedzie obliczane przyblizenie               
            calka += func(xs);
        }
        s += func(b - h / 2);           //suma wartości funkcji w punktach srodkowych
        calka = (h / 6) * (func(a) + func(b) + 2 * calka + 4 * s); //prsyblizona wartosc calki oznaczonej funckji f(x) w przedziale pocz i konc

    printf("TEST!!!!!!Czas Simpsonem bez omp wynosi %f\n", omp_get_wtime() - now) ;
        
    
    
    return calka;
    

}


/* Program glowny w ktorym wywolywana jest funkcja obliczajaca calke i pobierane sa wartosci potrzbene do okreslenia poczatku i konca, ilosci watkow i przedzialu calkowania */
int main()
{
    double poczPrzedzial, koncPrzedzial, dx, calkat, s, x, A, B, C,n;
     double A1;
    int i,  red;
    printf("Obliczamy calke dla funkcji Ax^2+Bx+C\n");
    
   //printf("Podaj zmienna A\n");
    //scanf("%lf", &A1);
    //printf("Zamienna A wynosi: %lf\n", zmiennaA(A1));
    printf("Podaj poczatek przedzialu calkowania\n");
    scanf("%lf", &poczPrzedzial);

    printf("Podaj koniec przedzialu calkowania\n");
    scanf("%lf", &koncPrzedzial);

    printf("Podaj liczbe przedzialow\n");
    scanf("%lf", &n);

    printf("Podaj ilosc watkow\n");
    scanf("%d", &red);
    
    double wynik = calkowanie(poczPrzedzial, koncPrzedzial, n, red);
 
    printf("Wartosc calki metoda simpsona wynosi=  %f\n", wynik);

    double wynik1 = trapezy(poczPrzedzial, koncPrzedzial, n, red);
    printf("Wartosc calki metoda trapezow wynosi=  %f\n",wynik1);

    double wynik3 = trapezy1(poczPrzedzial, koncPrzedzial, n, red);
    printf("Wartosc calki metoda prostokątow wynosi=  %f\n",wynik3);

 double wynik2 = calkowaniebez(poczPrzedzial, koncPrzedzial, n, red);
    printf("Wartosc calki metoda trapezow wynosi=  %f\n",wynik2);

    return 0;
 
}






