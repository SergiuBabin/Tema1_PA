# Tema1_PA
P.D./Greedy....

Tema 1 "ANOTHER DAY IN GIGELAND" Proiectarea Algoritmilor

Babin Sergiu
Grupa: 324CC

Tema a fost realizata timp de 5 zile.

Probleme intilnite au fost in mare parte in legatura cu (checker-coding style),
am mai avut probleme cu gasirea unei metode de rezolvare cat mai rapida, pentru
fiecare problema in parte.

====================  Problema 1: Gigel trezorier la BNR  ===================

Am folosit Programarea Dinamica pentru rezolvarea acestei probleme.
Instructiuni: 

Tip 1 - am observat ca exista o similitudine intre fiecare rezultat, astfel
am ajuns la o formula general valabila (5 * 2^(n-1)), unde k = numarul de 
elemente intr-o multime, pentru o ridicarea la putere mai rapida am folosit 
functia (fast_pow()) (rezolvata la laboratorul 1).
----------- Complexitate = O(log n) (ridicarea la putere) -------------------

Tip 2 - am folosit numarul de combinatii a fiecarei bancnote de la momentul
precedent, astfel pentru fiecare bancnota numarul de combinatii fiind egal cu 
numarul de combinatii a bancnotelor care il preced, astfel suma lor este egala 
cu numarul total de aranjamente. 
-------------------------- Complexitate = O(n) ------------------------------

=====================  Problema 2: Gigel si gardul  =========================

Am folosit Algoritmul Greedy pentru rezolvarea acestei probleme.

La aceasta problema am format un vector de obiecte de tip Gard dupa care l-am
sorta astfel micsorand timpul de cautare a bucatilor redundante.
Am verificat coliziunile cu un obiect de tip gard pana cand inceputul urmatorului
gard era >= decat sfarsitul gardului pastrat, astfel in caz afirmativ el i-a 
valoarea urmatorului gard.
----------------------  Complexitate = O(n^2) caz cel mai defavorabil  -------
----------------------  Complexitate = O(n * log n) caz mediu  -----------------

====================  Problema 3: Gigel bombonel  ===========================

Am folosit Programarea Dinamica mai exact ceva aproximativ problemei rucsacului.

Pentru aceasta problema am format o matrice(dp) linie dupa linie dupa urmatoarea 
regula.

Caz de baza: dp[0][i] = intervalul de bomboane al primului elev l-am completat 
cu 1.(start, end)

Caz general: dp[i][j] = suma(dp[i-1][k]), unde k = start ... end.

Astfel construind matricea, ultimul element va fi numarul total de posibilitati
de a inparti bomboanele la elevi.
-----------------------  Complexitate = O(n * W)
