reverselist([], []).

reverselist([X|Y], R):-
    reverselist(Y, R1), append(R1, [X], R).
