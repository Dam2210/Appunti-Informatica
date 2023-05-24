#Labirinti
maze_0=[
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1], 
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 2, 1, 1, 1, 1] 
]

maze_1=[
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 1, 1, 1],
    [1, 1, 0, 1, 0, 1, 0, 0, 0, 1],
    [1, 0, 0, 1, 1, 1, 1, 1, 0, 1],
    [1, 0, 1, 1, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1, 0, 1, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 1, 0, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 1, 0, 1, 1, 0, 1],
    [1, 1, 1, 1, 1, 2, 1, 1, 1, 1]
]

maze_2=[
    [1, 2, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 1, 1, 1],
    [1, 1, 0, 1, 0, 1, 0, 0, 0, 1],
    [1, 0, 0, 1, 1, 1, 1, 1, 0, 1],
    [1, 0, 1, 1, 0, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 0, 1, 0, 1, 0, 1],
    [1, 0, 1, 1, 1, 1, 1, 1, 0, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 1, 0, 1, 1, 0, 1],
    [1, 1, 1, 1, 1, 2, 1, 1, 1, 1]
]

maze_3=[
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 1, 0, 1, 1, 0, 2],
    [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]

mazes = {0:maze_0, 1:maze_1, 2:maze_2, 3:maze_3}

#Versione printabile
printable_maze_0=[
    ["╔", "═", "═", "═", "═", "═", "═", "═", "═", "╗"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "░", "░", "░", "░", "║"],
    ["╚", "═", "═", "═", "═", "▓", "═", "═", "═", "╝"]
]

printable_maze_1=[
    ["╔", "═", "═", "═", "═", "═", "═", "╦", "═", "╗"],
    ["║", "░", "░", "░", "░", "░", "░", "╚", "═", "╣"],
    ["╠", "═", "░", "║", "░", "║", "░", "░", "░", "║"],
    ["║", "░", "░", "╠", "═", "╩", "═", "═", "░", "║"],
    ["║", "░", "╔", "╝", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "║", "░", "║", "░", "║"],
    ["║", "░", "╚", "═", "╦", "╩", "═", "╝", "░", "║"],
    ["║", "░", "░", "░", "║", "░", "░", "░", "░", "║"],
    ["║", "░", "║", "░", "║", "░", "╔", "╗", "░", "║"],
    ["╚", "═", "╩", "═", "╝", "▓", "╩", "╩", "═", "╝"]
]

printable_maze_2=[
    ["╔", "▓", "═", "═", "═", "═", "═", "╦", "═", "╗"],
    ["║", "░", "░", "░", "░", "░", "░", "╚", "═", "╣"],
    ["╠", "═", "░", "║", "░", "║", "░", "░", "░", "║"],
    ["║", "░", "░", "╠", "═", "╩", "═", "═", "░", "║"],
    ["║", "░", "╔", "╝", "░", "░", "░", "░", "░", "║"],
    ["║", "░", "░", "░", "░", "║", "░", "║", "░", "║"],
    ["║", "░", "╚", "═", "╦", "╩", "═", "╝", "░", "║"],
    ["║", "░", "░", "░", "║", "░", "░", "░", "░", "║"],
    ["║", "░", "║", "░", "║", "░", "╔", "╗", "░", "║"],
    ["╚", "═", "╩", "═", "╝", "▓", "╩", "╩", "═", "╝"]
]

printable_maze_3=[
    ["╔", "═", "═", "═", "╦", "═", "═", "═", "═", "╗"],
    ["║", "░", "░", "░", "║", "░", "░", "░", "░", "║"],
    ["║", "░", "║", "░", "║", "░", "╔", "═", "░", "▓"],
    ["║", "░", "║", "░", "░", "░", "║", "░", "░", "║"],
    ["╚", "═", "╩", "═", "═", "═", "╩", "═", "═", "╝"]
]

printable_mazes = {0:printable_maze_0, 1:printable_maze_1, 2:printable_maze_2, 3:printable_maze_3}

#Variabili d'indice
selected_maze           = maze_2
selected_printable_maze = 2

#Cambia labirinto
def selectMaze(maze_index):
    global mazes, printable_mazes, selected_maze, selected_printable_maze
    if maze_index in printable_mazes:
        selected_maze           = mazes.get(maze_index)
        selected_printable_maze = printable_mazes.get(maze_index)


#Controlla soluzione, ogni posizione può essere massimo uno spostamento di una cella, non diagonale
#Posizione consigliata (4,5)
def test_solution(start, solution):
    global selected_maze
    #Si può partire solo da una cella vuota valida
    if getMazeCellType(start) != 0:
        return False

    #Per evitare i bari
    for step in solution:
        if abs(step[0]) + abs(step[1]) > 1:
            return False

    actual_position = start

    #Controlla se la soluzione non esce fuori dal labirinto o passa da muri
    for step in solution:
        actual_position = (actual_position[0] + step[0], actual_position[1] + step[1])
        if getMazeCellType(actual_position) == -1 or selected_maze[actual_position[0]][actual_position[1]] == 1:
            return False

    #Se la cella di arrivo è l'uscita allora è una soluzione
    if selected_maze[actual_position[0]][actual_position[1]] == 2:
        return True
    return False

#Ritorna il tipo di cella -1 se fuori dal labirinto, 0 una cella vuota, 1 un muro, 2 l'uscita
def getMazeCellType(position):
    global selected_maze
    if position[0] < 0 or position[1] < 0 or position[0] >= len(selected_maze) or position[1] >= len(selected_maze[position[0]]):
        return -1
    else:
        return selected_maze[position[0]][position[1]]

#Vedi getMazeCellType solo che la posizione è spostata di quanto indicato
def getMazeAdjacentCellType(position, direction):
    next_position=(position[0] + direction[0], position[1] + direction[1])
    return getMazeCellType(next_position)

#Ampiezza massima del labirinto
def getMazeMaxWidth():
    global selected_maze
    max_width = -1
    for i in selected_maze:
        if len(selected_maze[i]) > max_width:
            max_width=len(selected_maze[i])
    return max_width

#Profondità massima del labirinto
def getMazeMaxHeight():
    global selected_maze
    return len(selected_maze)

#Disegna il labirinto in console
def printMaze():
    global selected_printable_maze
    print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in selected_printable_maze]))