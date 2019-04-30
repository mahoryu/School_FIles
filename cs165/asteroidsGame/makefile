###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     This program creates 5 big asteroids in random
#     loactions each moving in a random direction. It also 
#     creates a ship in the center of the screen that can be 
#     controlled with the up, left, and right arrow keys. Once 
#     the ship starts moving it continues to move in that 
#     direction until the thrusters are engaged to change it 
#     the ship's velocity. Then the user can also use the space 
#     bar to fire bullets from the ship that move with the same 
#     angle and velocity as the ship plus ten to its speed. 
#     Then when the bullets hit any of the rocks then they will 
#     break apart into meduim and small rocks until all the 
#     small rocks are distroyed. Then if the ship gets hit by 
#     any of the rocks it is killed and can no longer fire 
#     bullets.
# Above and Beyond
#     The first thing I added was a scoring system that goes up 
#     by one point for each asteroid hit reguardless of size. I 
#     also made it so that the flames lit up on the ship 
#     whenever the up button is pushed. Then finally I changed 
#     the ship to a more detailed design rather than the basic 
#     arrow shape.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o $(LFLAGS)
	tar -cf asteroids.tar makefile *.cpp *.h

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
