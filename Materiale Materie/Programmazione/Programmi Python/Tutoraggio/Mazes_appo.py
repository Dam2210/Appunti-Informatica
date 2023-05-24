import Mazes 

"""
Tipi di caselle:
- (-1) casella fuori dal labirinto
- (0) casella vuota
- (1) muro
- (2) uscita

- (1, 0) = passo verso il basso
- (-1, 0) = passo verso l'alto
- (0, 1) = passo verso destra
- (0, -1) = passo verso sinistra
"""

#labirinto 0
print("MAZE 0:")
Mazes.selectMaze(0)
Mazes.printMaze()
pos0 = Mazes.getMazeCellType((1,1))
print(pos0)
sol0 = Mazes.test_solution((1,1), [(1, 0), (1, 0), (1, 0), (1, 0), (1, 0), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0)])
print("il percorso per l'uscita partendo dalla casella (1,1) è:", sol0)
print("\n")

#labirinto 1
print("MAZE 1:")
Mazes.selectMaze(1)
Mazes.printMaze()
pos1 = Mazes.getMazeCellType((1,1))
print(pos1)
sol1 = Mazes.test_solution((1,1), [(0, 1), (1, 0), (1, 0), (0, -1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (-1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (1, 0), (0, -1), (0, -1), (0, -1), (1, 0), (1, 0)])
print("il percorso per l'uscita partendo dalla casella (1,1) è:", sol1)
print("\n")

#labirinto 2
print("MAZE 2:")
Mazes.selectMaze(2)
Mazes.printMaze()
pos2 = Mazes.getMazeCellType((8,8))
print(pos2)
sol_alto2 = Mazes.test_solution((8,8), [(-1, 0), (-1, 0), (-1, 0), (-1, 0), (0, -1), (0, -1), (0, -1), (0, -1), (1, 0), (0, -1), (0, -1), (0, -1), (-1, 0), (-1, 0), (0, 1), (-1, 0), (-1, 0), (0, -1), (-1, 0)])
print("il percorso per l'uscita verso l'alto partendo dalla casella (8,8) è:", sol_alto2)
sol_basso2 = Mazes.test_solution((8,8), [(-1, 0), (0, -1), (0, -1), (0, -1), (1, 0), (1, 0)])
print("il percorso per l'uscita verso il basso partendo dalla casella (8,8) è:", sol_basso2)
print("\n")

#labirinto 3
print("MAZE 3:")
Mazes.selectMaze(3)
Mazes.printMaze()
pos3 = Mazes.getMazeCellType((3,1))
print(pos3)
sol3 = Mazes.test_solution((3,1), [(-1, 0), (-1, 0), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (-1, 0), (-1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1)])
print("il percorso per l'uscita partendo dalla casella (3,1) è:", sol3)
print("\n")
