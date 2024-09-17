# Othello: Design of the Othello game with UI using the MLV-2.0.2 library

Project carried out as part of my first year of engineering school.
The project consisted in developing the Othello game in C with a graphical interface; the application allows two players to play against each other;I used the MLV library for the user interface; 
The game incorporates the standard Othello rules, with the possibility of adding extra features such as different AI difficulty levels;

## Compile
```shell
make # keep objects as well
make exec # make only executable clean rest

make clean
```

## Execution
```shell
./Othello
```
Window should addapt to fullscreen

## Menu 
Naviagate to the New Game and About sections


### About
You can find the set of rules (in French)

### New Game
#### Chose between playing with a friend or against an AI


#### AI mode
### There are 3 main game modes

1. Level 0: The AIs next move is the one that brings the most value without looking ahead.
2. Level 1: The AI uses min max algorithm looking 2 rounds forward
3. Level 1: Chose betwwen a depth of 4, 6 or 8 (level 8 requires alot of RAM) ![lv3]
## Game

### The red numbers on the side show the each players score and the red arrows the possible moves 

### The green numbers show players the board value they currently have

### When playing against the AI it will display the grade it assesed each possible move (orange)

