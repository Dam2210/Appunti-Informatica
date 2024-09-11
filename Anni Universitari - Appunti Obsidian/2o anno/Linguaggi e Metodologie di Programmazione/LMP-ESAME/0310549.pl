:- dynamic mangia/2.


mangia(mucca, erba).
mangia(coccodrillo, rana).
mangia(rana, insetto).
mangia(insetto, erba).
mangia(zebra, erba).
mangia(leone, zebra).
mangia(squalo, pesce).
mangia(pesce, alga).


%Funzione che aggiunge un nuovo fatto, chi mangia chi.
add_mangia(A, B) :-
    assertz(mangia(A, B)).

%Funzione che rimuove un fatto.
del_mangia(A, B) :-
    retract(mangia(A, B)).


inquinamento(A, B, N) :-
    visitaDFS(A, B, M),
    pow(0.87, M, N).

% DFS per trovare il percorso e la relativa lunghezza tra A e B
visitaDFS(A, B, 1) :-
    mangia(A, B).

visitaDFS(A, B, N) :-
    mangia(A, C),
    visitaDFS(C, B, N2),
    N is N2 + 1.

%predicato che calcola la potenza che servirà per calcolare l'inquinamento(0.87^n)
pow(_, 0, 1).
pow(A, B, R) :-
    E1 is B - 1,
    pow(A, E1, R1),
    R is A * R1.
