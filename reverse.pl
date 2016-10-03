reverselist([], L).

reverselist([X|Y], R):-
    reverselist(Y, [X|R]).