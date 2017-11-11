#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Partition();
void QuickSort();
void Quickbubble();
double mierz();
void losowanie();
void malejacy();
void bubbleSort();
void liczenieZwykle();
void liczenieMalejace();
void liczenieZwykleBubble();
void liczenieMalejaceBubble();



int Partition(int A[] , int p , int r){
	int x = A[r];
	int i = p-1;
	int zamiana;
	for(int j=p ; j<=r ; j++){
		if(A[j]<=x){
		i++;
		zamiana = A[i];
		A[i] = A[j];
		A[j] = zamiana;
		}
	}
	if(i<r) return i;
	else return i-1;
}

void QuickSort(int A[] , int p , int r){
	int q;
	if(p<r){
		q=Partition(A,p,r);
		QuickSort(A,p,q);
		QuickSort(A,q+1,r);
	}
}

void Quickbubble(int A[], int p, int r, int c) { // quick i bubble
	int q;
	if(p<r && r-p+1>=c) {
		q = Partition(A,p,r);
		Quickbubble(A,p,q,c);
		Quickbubble(A,q+1,r,c);
	}
	if(p<r && r-p+1<c) bubbleSort(A,r-p+1);
}

double mierz(void) { // czas
	struct timespec tv;
  if (clock_gettime(CLOCK_REALTIME, &tv) != 0) return 0;
return (tv.tv_sec + (tv.tv_nsec / 1000000000.0));
	
}

void losowanie(int A[], int rozmiar) { //losowanie liczby
	srand(time(NULL));
	for(int i = 0; i < rozmiar; i++) A[i] = rand()%20000;
}

void malejacy(int A[], int rozmiar) { //ciag malejacy
	for(int i = rozmiar-1; i >0 ; i--) 
	A[i] = i;
}

void bubbleSort(int A[], int ile) { // bubble
	
	for(int i = 0; i < ile; i++) {
		for(int j = 1; j < ile-i; j++) {
			if(A[j]<A[j-1]){
				int zamiana;
				zamiana = A[j];
				A[j] = A[j-1];
				A[j-1] = zamiana;
			}
		}
		
	}
	
}

void liczenieZwykleBubble(double czas[] , int c){ // liczenie bubble i quick
	int tab100[100] , tab500[500] , tab1000[1000] , tab2500[2500] , tab5000[5000] ,tab20000[20000];
	double start , stop;
	
	losowanie(tab100,100);
	start = mierz();
	Quickbubble(tab100 , 0 , 100 , c);
	stop = mierz();
	czas[0] = stop - start;
	
	losowanie(tab500,500);
	start = mierz();
	Quickbubble(tab500 , 0 , 500 , c);
	stop = mierz();
	czas[1] =stop - start;
	
	losowanie(tab1000,1000);
	start = mierz();
	Quickbubble(tab1000 , 0 , 1000 , c);
	stop = mierz();
	czas[2] =stop - start;
	
	losowanie(tab2500,2500);
	start = mierz();
	Quickbubble(tab2500 , 0 , 2500 , c);
	stop = mierz();
	czas[3] =stop - start;
	
	losowanie(tab5000,5000);
	start = mierz();
	Quickbubble(tab5000 , 0 , 5000 , c);
	stop = mierz();
	czas[4] =stop - start;
	
	losowanie(tab20000,20000);
	start = mierz();
	Quickbubble(tab20000 , 0 , 20000 , c);
	stop = mierz();
	czas[5] =stop - start;
}

void liczenieMalejaceBubble(double czas[] , int c){ // liczenie bubble i quick
	int tab100[100] , tab500[500] , tab1000[1000] , tab2500[2500] , tab5000[5000] ,tab20000[20000];
	double start , stop;
	
	malejacy(tab100,100);
	start = mierz();
	Quickbubble(tab100 , 0 , 100 , c);
	stop = mierz();
	czas[0] = stop - start;
	
	malejacy(tab500,500);
	start = mierz();
	Quickbubble(tab500 , 0 , 500 , c);
	stop = mierz();
	czas[1] =stop - start;
	
	malejacy(tab1000,1000);
	start = mierz();
	Quickbubble(tab1000 , 0 , 1000 , c);
	stop = mierz();
	czas[2] =stop - start;
	
	malejacy(tab2500,2500);
	start = mierz();
	Quickbubble(tab2500 , 0 , 2500 , c);
	stop = mierz();
	czas[3] =stop - start;
	
	malejacy(tab5000,5000);
	start = mierz();
	Quickbubble(tab5000 , 0 , 5000 , c);
	stop = mierz();
	czas[4] =stop - start;
	
	malejacy(tab20000,20000);
	start = mierz();
	Quickbubble(tab20000 , 0 , 20000 , c);
	stop = mierz();
	czas[5] =stop - start;
}

void liczenieZwykle(double czas[]){ 
	int tab100[100] , tab500[500] , tab1000[1000] , tab2500[2500] , tab5000[5000] ,tab20000[20000];
	double start , stop;
	
	losowanie(tab100,100);
	start = mierz();
	QuickSort(tab100 , 0 , 100);
	stop = mierz();
	czas[0] = stop - start;
	
	losowanie(tab500,500);
	start = mierz();
	QuickSort(tab500 , 0 , 500);
	stop = mierz();
	czas[1] =stop - start;
	
	losowanie(tab1000,1000);
	start = mierz();
	QuickSort(tab1000 , 0 , 1000 );
	stop = mierz();
	czas[2] =stop - start;
	
	losowanie(tab2500,2500);
	start = mierz();
	QuickSort(tab2500 , 0 , 2500 );
	stop = mierz();
	czas[3] =stop - start;
	
	losowanie(tab5000,5000);
	start = mierz();
	QuickSort(tab5000 , 0 , 5000 );
	stop = mierz();
	czas[4] =stop - start;
	
	losowanie(tab20000,20000);
	start = mierz();
	QuickSort(tab20000 , 0 , 20000);
	stop = mierz();
	czas[5] =stop - start;
	
	
}

void liczenieMalejace(double czas[]){ 
	int tab100[100] , tab500[500] , tab1000[1000] , tab2500[2500] , tab5000[5000] , tab20000[20000];
	double start , stop;
	
	malejacy(tab100,100);
	start = mierz();
	QuickSort(tab100 , 0 , 100 );
	stop = mierz();
	czas[0] = stop - start;
	
	malejacy(tab500,500);
	start = mierz();
	QuickSort(tab500 , 0 , 500 );
	stop = mierz();
	czas[1] =stop - start;
	
	malejacy(tab1000,1000);
	start = mierz();
	QuickSort(tab1000 , 0 , 1000 );
	stop = mierz();
	czas[2] =stop - start;
	
	malejacy(tab2500,2500);
	start = mierz();
	QuickSort(tab2500 , 0 , 2500 );
	stop = mierz();
	czas[3] =stop - start;
	
	malejacy(tab5000,5000);
	start = mierz();
	QuickSort(tab5000 , 0 , 5000 );
	stop = mierz();
	czas[4] =stop - start;
	
	malejacy(tab20000,20000);
	start = mierz();
	QuickSort(tab20000 , 0 , 20000);
	stop = mierz();
	czas[5] =stop - start;
}

int main()
{
	double czas[6]; // tablica czasu
	int c;
	printf("Podaj c >= 1 : ");
	scanf("%d", &c);
	
	liczenieZwykle(czas);
	printf("Liczby losowe i sam quicksort \n");
	printf("------------------------------------------\n");
	printf("Rozmiar tablicy     |      czas sortowania\n");
	printf("      100           |          %lf        \n",czas[0]);
	printf("      500           |          %lf        \n",czas[1]);
	printf("     1000           |          %lf        \n",czas[2]);
	printf("     2500           |          %lf        \n",czas[3]);
	printf("     5000           |          %lf        \n",czas[4]);
	printf("    20000           |          %lf        \n",czas[5]);
	printf("------------------------------------------\n");
	
	liczenieMalejace(czas);
	printf("Quicksort w ciagu malejącym \n");
	printf("------------------------------------------\n");
	printf("Rozmiar tablicy     |      czas sortowania\n");
	printf("      100           |          %lf        \n",czas[0]);
	printf("      500           |          %lf        \n",czas[1]);
	printf("     1000           |          %lf        \n",czas[2]);
	printf("     2500           |          %lf        \n",czas[3]);
	printf("     5000           |          %lf        \n",czas[4]);
	printf("    20000           |          %lf        \n",czas[5]);
	printf("------------------------------------------\n");
	
	liczenieZwykleBubble(czas , c);
	printf("Liczby losowe , quicksort i bubble \n");
	printf("------------------------------------------\n");
	printf("Rozmiar tablicy     |      czas sortowania\n");
	printf("      100           |          %lf        \n",czas[0]);
	printf("      500           |          %lf        \n",czas[1]);
	printf("     1000           |          %lf        \n",czas[2]);
	printf("     2500           |          %lf        \n",czas[3]);
	printf("     5000           |          %lf        \n",czas[4]);
	printf("    20000           |          %lf        \n",czas[5]);
	printf("------------------------------------------\n");
	
	liczenieMalejaceBubble(czas ,c);
	printf("Quicksort i  bubble w ciagu malejacym \n");
	printf("------------------------------------------\n");
	printf("Rozmiar tablicy     |      czas sortowania\n");
	printf("      100           |          %lf        \n",czas[0]);
	printf("      500           |          %lf        \n",czas[1]);
	printf("     1000           |          %lf        \n",czas[2]);
	printf("     2500           |          %lf        \n",czas[3]);
	printf("     5000           |          %lf        \n",czas[4]);
	printf("    20000           |          %lf        \n",czas[5]);
	printf("------------------------------------------\n");
	
	
	return 0;
}
