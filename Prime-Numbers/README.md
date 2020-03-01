# prime-numbers

Feladatunk, hogy megírjunk egy olyan algoritmust, amely megkeres N darab prímszámot, amelyeknek az összegük S háromféleképpen:
  1. nyers backtracking
  2. backtracking + MVR + forward checking
  3. backtracking + MVR + AC-3 //TODO

Adott 3 természetes szám: egy S (összeg), P (prím), N
Feladat lényege, hogy találjunk N db. prímszámot, ami nagyobb mint P és összegük S

pl: S = 54, N = 2, P = 3

Eredmény:
7 47
11 43
13 41
17 37
23 31

Time taken SIMPLE BACKTRACKING: 0.011
Number of calculations: 5762

Time taken FORWARD CHECK BACKTRACKING: 0.011
Number of calculations: 5103