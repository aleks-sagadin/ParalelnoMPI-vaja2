# ParalelnoMPI-vaja2
S pomočjo MPI pripravite računalniški program, ki izračunava naslednji paralelni algoritem.

Algoritem kot vhod prejme tok podatkov, v obliki besedila B, ki v vsaki vrstici i vsebuje niz bj, v katerem so črke bi,j.

Rezultat algoritma je vsota funkcijskih vrednosti funkcij f1, f2 in f3, ki morajo biti izvedene vzporedno nad vsako vrstico.

Funkcija f1 izračuna dolžino najdaljše besede v nizu bj.
Funkcija f2 vrne število samoglasnikov v nizu bj.
Funkcija f3 vrne število presledkov v nizu bj.

Program naj poskrbi za ustrezen vnos podatkov in ob zaključku izpiše rezultat ter čas izvajanja algoritma.

-----------------------------------------------------------------------------------------------
Translation:
-----------------------------------------------------------------------------------------------
Using MPI to prepare a computer program that calculates the following parallel algorithm.

The algorithm receives as input data stream in the form of text B, which in each row i contains the string bj in which there are characters bi,j.

The result of the algorithm is the sum of functional values of the functions f1, f2, and f3, which must be executed in parallel over each row.

Function f1 calculated length of the longest word in the string bj.
f2 function returns the number of vowels in a string bj.
f3 function returns the number of spaces in a string bj.

The program should provide sufficient data entry and at completion, displays the duration of the algorithm run.
