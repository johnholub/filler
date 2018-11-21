# Filler

### Compile with your files

Run make to compile the project.
```
make
```
Open directory with resources.
```
cd assets
```
Run filler_vm (you can read usage if you run it without arguments)
```
./filler_vm -f maps/map00 -p1 players/hcao.filler -p2 ../yholub.filler
```
• In this game, two players fight each other. They play one after the other.

• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.

• The board is defined by X columns and N lines, it will then become X*N cells.

• At the beginning of each turn, you will receive your game piece.

• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.

• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).

• The shape must not exceed the dimensions of the board

• When the game starts, the board already contains one shape.

• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.
