###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     This program allows the user to control a gun using the 
#     left and right arrow keys as well as the space bar to 
#     shoot bullets at the incoming birds. Randomly a bird is 
#     generated on the left side of the screen and heads toward
#     the other side of the screen in an up or down angle. 
#     There are three possible birds that can be genrated are 
#     the standard bird that can be killed with one hit and are
#     worth 1 point. The tough bird that can be killed with 3 
#     hits and are worth a possible of 5 points depending how 
#     many times it is hit. And the sacred bird that is killed 
#     with one hit, but the player looses 10 points for doing 
#     so.
# Above and Beyond
#     So to add extra features to the game I first made it so 
#     that the tough birds have a random amount of health 
#     ranging from 3 to 6. Then to make it fair I made it so 
#     that it would move even slower if its health is 5 or 6  
#     than if it was 3, or 4. Then I added a new bird class 
#     called the Boss bird. This bird is represented as a tough
#     bird with a larger Sacred bird on top of it. The Boss 
#     bird has anywhere between 20 and 30 health and rewards 1
#     point per hit and a full ten points if it is killed. 
#     Then what really makes the Boss bird unique is that its 
#     dX is always .75, but it changes its dY after a random 
#     number of frames have passed. This causes it to "bounce" 
#     around the screen making it even harder to hit, hence why
#     I made the kill worth 10 instead of 5. Then finally to 
#     top it off I set different percent chances for each type 
#     of bird to generate. The chance of each is as follows: 
#     Standard - 50%, Tough - 30%, Sacred - 20%, and Boss - 10%
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o standardBird.o toughBird.o sacredBird.o velocity.o bossBird.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o standardBird.o toughBird.o sacredBird.o velocity.o bossBird.o $(LFLAGS)
	tar -cf skeet.tar *.cpp *.h makefile

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

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h standardBird.h toughBird.h sacredBird.h bossBird.h
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
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h flyingObject.h
	g++ -c bird.cpp

standardBird.o: standardBird.cpp standardBird.h bird.h
	g++ -c standardBird.cpp

toughBird.o: toughBird.cpp toughBird.h bird.h
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h bird.h
	g++ -c sacredBird.cpp

bossBird.o: bossBird.cpp bossBird.h bird.h
	g++ -c bossBird.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
