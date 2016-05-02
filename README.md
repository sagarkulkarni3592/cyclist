# Ride the bicycle
Submitted By: 

	Name: 	Kulkarni Sagar Shekhar.

Dependencies and softwares to be installed :

1. Operating System - Linux (Ubuntu 14.04).
2. Require opengl libraries - freeglut (This dependency varies from machine to machine).
	- sudo apt-get install freeglut3 freeglut3-dev
3. g++ - GNU project C and C++ compiler.
	- sudo apt-get install g++

Follow the steps to run the game :

Building the project :

1. Open the command prompt (Terminal in Linux).
2. Go to the folder where this text file is located.
3. Run the command "make" without "".
4. The command, if successfully executed, will generate a file named "output".

Running the game :

1. Run that output file by typing "./output", again without "".
2. You will see the Graphics Window as a Dashboard for the game.
3. Press SPACE button to play the game.
4. Use arrow keys to move the cyclist (the box in grey color).
5. Red color boxes are cars.
6. Left 20% portion of the lane is cycle lane and is indicated by white stripe.
7. Scoring System :
	- Any collision (either with cars or with outside road) will result in Game Over.
	- Each accelaration on cycle lane will give 10 points (as cyclist's responsibility is to drive on cycle lane).
	- If deviated from cycle lane, only 1 point is added.
8. If collided, the game is over and you will be presented with the Dashboard showing your scores, last game score and high score.

Directory structure :

1. src folder contains all the code in MVC pattern.
2. Images folder will have the screen shots of the game.
3. makefile is used to build the project.

References :

1. Stackoverflow/Stackexchange for different problems while coding.
2. http://openglut.sourceforge.net/ - The GLUT library help.
3. https://www.opengl.org/
