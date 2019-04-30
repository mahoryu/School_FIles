###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     This program draws a mountain terrain with a landing 
#     platform and draws the lander at a random point in the 
#     sky. The lander contiues to fall in a random direction 
#     down twards the ground and the user can use the left, 
#     down, and right arrows keys to chande the lander's 
#     velocity. The goal is to land on the platform without too
#     much vertical velocity, without hitting the ground or the 
#     random asteroid. However if the lander runs out of gas, 
#     then the trusters no longer work and the lander contiues 
#     to fall until it crashes or lands on the platform.
# Above and Beyond
#     To go above and beyond I added a small asteroid to the 
#     game that falls to the ground at a random direction and 
#     speed and made it so that if the lander hits the asteroid
#     it also causes it to crash and stop the game.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o smallAsteroid.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o smallAsteroid.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h lander.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.cpp lander.h velocity.h point.h uiDraw.h
	g++ -c lander.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

smallAsteroid.o: smallAsteroid.cpp smallAsteroid.h velocity.h point.h uiDraw.h
	g++ -c smallAsteroid.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
