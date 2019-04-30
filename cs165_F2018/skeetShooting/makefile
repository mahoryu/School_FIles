###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     This program is a skeet shooting style of game. First 
#     it sets up a rectangle to be the gun that can be aimed 
#     with the left and right arrows and then fired with the 
#     space bar. Then randomly on the left side of the screen 
#     three different kinds of birds could appear. The standard 
#     that looks like a circle, a tough bird that can take 
#     three hits and looks like a filled in circle with a 
#     number of hits it takes to distroy it, and finally a 
#     sacred bird that looks like a red star that if hit the 
#     player will lose 10 points. Then each time a bullet hits 
#     a bird the bird an bullet are removed and points are 
#     awarded based on the kind of bird.
# Above and Beyond
#     To go abaove and beyond I made it so that the birds each 
#     have a different percent chance to appear, the standard 
#     bird has a 50% chance, the tough bird has a 30% chance 
#     and the sacred birds only have a 20% chance of appearing. 
#     Then I also made it so that the sacred birds are not only 
#     a red star, but have a color changing circle around them 
#     so that they look a little more like the other birds and 
#     stand out more as well.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o standardBird.o toughBird.o sacredBird.o makefile
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o standardBird.o toughBird.o sacredBird.o $(LFLAGS)
	tar -cf skeet.tar makefile *.cpp *.h
###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h
	g++ -c flyingObject.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h uiDraw.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h flyingObject.h uiDraw.h
	g++ -c bird.cpp

standardBird.o: standardBird.cpp standardBird.h bird.h
	g++ -c standardBird.cpp

toughBird.o: toughBird.cpp toughBird.h bird.h
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h bird.h
	g++ -c sacredBird.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar *~
