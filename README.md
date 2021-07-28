This repository contains CS101 project done under `prof. Bhaskaran Raman` in 1st semester.
This is a `lasso` game written in C++ using `simplecpp` library (a library of IIT bombay used exclusively in CS101 course to teach C++ language and basics of coding)

## How to Run

* As the programme would get compiled on the terminal, the terminal will prompt
  you to enter your username. Enter username (This username would be displayed
  on the leader-board once you have played the game)
* The text on the game may not have perfect fit due to different resolution
  in different PC. To check the fit you can refer to the video which is made on
  my PC. Don’t use mouse click anywhere on the Lasso Menu or Lasso Window
  it would terminate the programme, I haven’t used getclick anywhere in my
  code, all navigation are through keyboard controls for which controls are well
  described both in the game as well as in this document.
* If you get segmentation fault (though you will not get but in case) clear the
  highscore.txt, level1.txt, level2.txt, level3.txt files and rerun the code, it would
  definitely work. Each of my files (Except txt files) contains my name and roll
  number at the top.
* Read the source code for the comments too!

## Controls

### Main Menu

* Use `Up` and `Down`arrow keys to navigate in the menu.
* Press `Enter` to open a sub menu / leaderboard / game anywhere in the
  menu.
* Press `Esc` anywhere in the game to return back to Home menu
* Press `Space` in the tutorial (while opening it through new game) to skip
  it and continue.

### Game

* Press `+` to increase lasso speed.
* Press `-` to increase lasso speed.
* Press `]` to rotate lasso clockwise.
* Press `[` to rotate lasso counterclockwise.
* Press `T` to release lasso.
* Press `L` to loop.
* Press `Y` to yank (brings lasso back).