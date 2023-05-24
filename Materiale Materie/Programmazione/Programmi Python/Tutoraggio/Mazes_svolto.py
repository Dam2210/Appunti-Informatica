from tracemalloc import start
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

directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
def solution(starting_position, path, previous_position, arrival_direction):
    if not starting_position in previous_position:
        previous_position.append(starting_position)
    if Mazes.getMazeCellType(starting_position) == 2:
        path.insert(0, arrival_direction)
        return(True, path)
    if Mazes.getMazeCellType(starting_position) == 0:
        for direction in directions:
            if arrival_direction[0] != -direction[0] or arrival_direction[1] != -direction[1]:
                new_position = (starting_position[0] + direction[0], starting_position[1] + direction[1])
                flag, temp_path = solution(new_position, path, previous_position, direction)
                if flag:
                    if arrival_direction != (0, 0):
                        temp_path.insert(0, arrival_direction)
                    return (flag, temp_path)
    return (False, None)

Mazes.selectMaze(1)
flag, solution = solution((4, 5), [], [], (0, 0))
print(solution)
print(Mazes.test_solution((4, 5), solution))


