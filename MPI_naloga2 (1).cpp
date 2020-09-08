// MPI_naloga1.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "mpi.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <math.h>   
#include <string>
#include <sstream>
#include <vector>
using namespace std;






int main(int *argc, char **argv)
{
	time_t start = time(0);
	//int N = atoi(argv[1]); //  velikost
	
	
	//int N = 3;
	//cin >> N; // vpises 3
	//cin.ignore();
	int tagg = 1;
	//int n = N; // x
	//int m = N; // y
	int najdaljsa_bes =0;
	int samoglasniki = 0;
	int presledki = 0;
	string line;
	int tmp;
	ifstream inFile;
	


	//vector<vector<int> > vec(n, vector<int>(m));

	//MPI_Status status;
	//if (myid == 0) { // master
	
		MPI_Init(NULL, NULL);
		int myid;
		MPI_Comm_rank(MPI_COMM_WORLD, &myid);

		//ifstream inFile;

		inFile.open("C:\\Fax\\Omrezja\\hibridnoSIfriranje\\MPI_naloga1\\MPI_naloga1\\test.txt");

		if (inFile.is_open())
		{
			while (getline(inFile, line))
			{
				//cout << line << '\n';
			}
			//inFile.close();
		}
		else if (!inFile) {
			cout << "Unable to open file";
			exit(1); // terminate with error

		}
		
	
	
		if (myid == 0)
		{

				int tmp = 0; // to je za sestevek besede
					for (int i = 0; i < line.size(); i++)
					{										//tmp =0
						tmp++;	//tmp=1
						if (line[i] == ' '||line[i]==',') {
							tmp = 0;

							//najdaljsa_bes++;
						}
						
						if (tmp > najdaljsa_bes) {  
							najdaljsa_bes = tmp;
							
						}
						
					}
			
			
			
			MPI_Send(&najdaljsa_bes, 1, MPI_INT, 3, tagg, MPI_COMM_WORLD);
		}

		else  if (myid == 1) {


					for (int i = 0; i < line.size(); i++)
					{

						if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u'
							|| line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U') {

							samoglasniki++;
						}
					}
			


			
			MPI_Send(&samoglasniki, 1, MPI_INT, 3, tagg, MPI_COMM_WORLD);
		

			//-----------------------------------------------------
		 }
		 else if (myid == 2) {


					 for (int i = 0; i < line.size(); i++)
					 {

						 if (line[i] == ' ') {

							 presledki++;
						 }

					 }
			

			 MPI_Send(&presledki, 1, MPI_INT, 3, tagg, MPI_COMM_WORLD);

		 }else if(myid==3)
		 {
			
		
			 MPI_Recv(&najdaljsa_bes, 1, MPI_INT, 0, tagg, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Recv(&samoglasniki, 1, MPI_INT, 1, tagg, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Recv(&presledki, 1, MPI_INT, 2, tagg, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			cout << "najdaljsa_beseda: " << najdaljsa_bes << endl;
			cout << "Samoglasnikov: " << samoglasniki<< endl;
			cout << "Presledki: " << presledki << endl;
			cout << "Skupaj:"<< najdaljsa_bes + samoglasniki + presledki<<endl;
			double seconds_since_start = difftime(time(0), start);
			cout << seconds_since_start << "seconds";




		}

		 
		 inFile.close();
		MPI_Finalize();


	return 0;
	}
	
	/*


NACIN DELOVANJA, postavis se v file Debug:
cmd: mpexec -n 4 MPI_naloga1.exe  // 4 pomeni 4 procesi 

PRIMER IZHODA: 
C:\Fax\Omrezja\hibridnoSIfriranje\MPI_naloga1\Debug>mpiexec -n 4 MPI_naloga1.exe
najdaljsa_beseda: 12
Samoglasnikov: 10
Presledki: 4
0seconds



NASLOV NALOGE:
N02-MPI_2
S pomočjo MPI pripravite računalniški program, ki izračunava naslednji paralelni algoritem.

Algoritem kot vhod prejme tok podatkov, v obliki besedila B, ki v vsaki vrstici i vsebuje niz bj, v katerem so črke bi,j.

Rezultat algoritma je vsota funkcijskih vrednosti funkcij f1, f2 in f3, ki morajo biti izvedene vzporedno nad vsako vrstico.

Funkcija f1 izračuna dolžino najdaljše besede v nizu bj.
Funkcija f2 vrne število samoglasnikov v nizu bj.
Funkcija f3 vrne število presledkov v nizu bj.

Program naj poskrbi za ustrezen vnos podatkov in ob zaključku izpiše rezultat ter čas izvajanja algoritma.

	
	*/

	

	
/*
	TESTIRANJE:

	MPI_Init(NULL, NULL);
	int myid;
	int vec = 1;
	int y = 0;
	int tag = 0;
	int tagg=1;

	MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	vec = 0;

	
	 if (myid == 0) {
		int  x = 11;
		MPI_Send(&vec, 1, MPI_INT, 2, tagg, MPI_COMM_WORLD);

	}
	else if (myid == 1) {
		y = 10;
		MPI_Send(&vec, 1, MPI_INT, 2, tagg, MPI_COMM_WORLD);

	}
	else if (myid == 2) {

		int yy;
		int z;
		MPI_Recv(&yy, 1, MPI_INT, 0, tagg, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(&z, 1, MPI_INT, 1, tagg, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		vec = yy + z;

		cout << "Koncni sestevek: " << vec << endl;
		

		


	}*/



