###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     This is a working asteroids game. At the moment it 
#     compiles properly and diplays 5 large asteroids that move 
#     in random directions at 1 pixel per frame. It also 
#     displays a ship that starts in the center of the screen. 
#     If the left arrow turns the ship to the left and the 
#     right arrow turns the ship to the right. The up arrow 
#     applies the thrusters that show as fire coming out of the 
#     back of the ship. Then if the spacebar is pushed the ship 
#     fires bullets out its front and the bullets only last for 
#     40 frames. Next when each asteroid is hit by a bullet, 
#     the bullet and asteroid are killed and if it was bigger 
#     than a small asteroid, it creates new ones that spread 
#     out.
# Above and Beyond
#     The extra things I added was a scoring feature and that 
#     the game will display GAME OVER when the ship is killed. 
#     I also added a shield feature to the game. The game 
#     starts out with the ship having a shield with 1 health 
#     point and a radius of 15. Then the games plays like 
#     normal except that if the ship is hit by a rock with the 
#     shield up, the rock will still be destroyed, but the 
#     ship will bounce in the opposite direction and the 
#     shield will lose 1 HP. Then when a small asteroid is 
#     created it has a 1 in 10 chance of being a special 
#     (appears as a color changing small asteroid). If a 
#     special asteroid is hit by a bullet, the ship's shield 
#     gains 1 HP. 
#     The scoring is as follows: 
#       -Each hit to a rock with a bullet is 100 pts.
#       -Special asteriods are worth 150 pts.
#       -If the ship is hit by an asteroid 100 pts are lost.
#	-if it's a regular small asteriods only lose 50 pts.
#     The shield's color is based on the amount of HP it has. 
#     Red means 1 HP, Blue means 2 HP & Green means 3 more HP.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o makefile
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
