# Joc Tic_Tac_Toe_C

Acest proiect este o implementare simplă a jocului **Tic-Tac-Toe** în limbajul C. Jocul se desfășoară între un jucător și calculator.

Jucătorul folosește simbolul **X**, iar calculatorul folosește simbolul **O**. Pentru a-și alege mutările, calculatorul folosește algoritmul **Minimax**, prin care analizează mutările disponibile și încearcă să aleagă cea mai bună variantă.

Proiectul este realizat în **consolă** și folosește funcționalități standard ale limbajului C.

## Cum funcționează

La începutul jocului, tabla este afișată astfel:

```text
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

Pentru a face o mutare, jucătorul introduce numărul poziției dorite.

De exemplu:

```text
Alege o pozitie (1-9): 5
```

Dacă poziția este liberă, aceasta este marcată cu **X**. După mutarea jucătorului, calculatorul își alege automat poziția și o marchează cu **O**.

Jocul continuă până când unul dintre cei doi jucători câștigă sau toate pozițiile sunt ocupate.

## Algoritmul Minimax

Calculatorul își calculează mutarea folosind algoritmul **Minimax**.

Pentru fiecare poziție disponibilă, programul simulează posibilele continuări ale jocului și atribuie un scor situației rezultate:

* **10** – câștig pentru calculator
* **-10** – câștig pentru jucător
* **0** – egalitate

Calculatorul încearcă să maximizeze scorul, în timp ce mutările jucătorului sunt evaluate astfel încât scorul să fie minimizat.

## Structura programului

Programul este împărțit în mai multe funcții, fiecare având un rol bine definit:

* `init_board()` – inițializează tabla cu pozițiile de la `1` la `9`
* `print_board()` – afișează tabla de joc
* `check_win()` – verifică dacă există un câștigător
* `check_draw()` – verifică dacă tabla este completă
* `minimax()` – implementează algoritmul Minimax
* `execute_player_move()` – citește și validează mutarea jucătorului
* `execute_computer_move()` – determină și execută mutarea calculatorului
* `play_game()` – gestionează desfășurarea jocului
* `main()` – inițializează jocul și afișează rezultatul final

## Compilare și rulare

Pentru compilarea programului poate fi folosit compilatorul **GCC**.

```bash
gcc main.c -o tictactoe
```

Pe **Windows**:

```bash
tictactoe.exe
```

Pe **Linux / macOS**:

```bash
./tictactoe
```

## Rezultate posibile

La finalul jocului, programul poate afișa unul dintre următoarele rezultate:

```text
Ai castigat!
```

```text
Computerul a castigat!
```

sau:

```text
Egalitate!
```

Proiect realizat în scop educațional.
