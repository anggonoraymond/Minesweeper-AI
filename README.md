# Minesweeper-AI
## Project Overview
### Minimal AI (Base Case)
For the minimal AI, we just applied the “rule of thumb”. The algorithm is risk-free since it only opens a surrounding tile if all possible mines in the neighbor have been marked. For example, if our current tile label is 2 and it has 2 marked neighbors then its remaining neighbors are mine free. On the other hand, we flag the surrounding tile if the number of remaining neighbor cover tiles is equal to the current label number. For instance, if our current label number is 2 and it has 2 remaining cover tiles in its surrounding, then all cover tiles neighbors must be mines. Using the checkNeighbor() and markNeighbor() function, the algorithm decides to flag or open the tiles. If the algorithm decides to open a tile, the algorithm will store the next row and column coordinate to the queue called nextTiles. Otherwise, if the algorithm decides to flag the tile, it will mark the tile with -2 and record it to the persistent board.
### Frontier AI (Logics - Probability)
Created an algorithm that can open and flag a tile if our minimal algorithm has stopped working. The algorithm’s idea is to enumerate all possible configurations of mines in the frontier tiles. Using the getFrontierTiles() function, we return the frontier tiles that are adjacent with uncover tiles. Since our algorithm is designated to enumerate all the possible configuration of mines in all the frontier tiles, it will take a lot of time. In order to reduce the runtime, we create a helper function called getGroupedFrontierTiles() to group frontier tiles into a few sections. Then, after we group the frontier tiles into a few sections, we are going to find all possible mine positions in each section respectively using the function called findAllPossibleMine(). Finally, the solver() function will calculate the probability of mine location in each section of frontier tile and compare it with the random guessing.
## How To Run
### Generate World
In order to run the minesweeper AI, we have to generate different world (boards in this case). We would have to create a directory called "Problems" on the "WorldGenerator" directory.
- Go to the WorldGenerator directory using the cd command "cd WorldGenerator/"
- Create a folder or directory called "Problems"
- To generate worlds, enter the command "python3 WorldGenerator.py [#worlds] [base_filename] [rowDimension] [colDimension] [numMines]"
    - [#world] is the number of worlds you want to generate
    - [base_filename] is anything you want your generated world filename to start with
    - [rowDimension] is the number of rows you would like the each board to have
    - [colDimension] is the number of columns you would like each board to have
    - [numMines] is the number of mines you would like each board to have
    
    - Sample command: python3 WorldGenerator.py 10 easy 5 5 3
      - This command produce 10 different boards with 5 rows, 5 columns with 3 mines inside the Problems folder calling each board easy1.txt , easy2.txt ... easy10.txt
### Run the code on the generated world
- Go to the Minesweeper_CPP directory using the cd command on the terminal "cd Minesweeper_Cpp"
- Compile the program 
  - type the command "make" to the terminal
  - A bin folder will be created on the Minesweeper_Cpp directory
- Type the following command to run the Agent
  - ./bin/Minesweeper -f ../WorldGenerator/Problems/
