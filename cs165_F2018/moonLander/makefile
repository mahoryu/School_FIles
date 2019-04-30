###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     A moon lander game that creates a random terrain of what 
#     is considered the ground, then places a moon lander at 
#     the top of the screen in a random location. The moon 
#     lander then begins to fall based on the applied gravity 
#     of the "moon." It is then up to the user to control the 
#     fall path of the moon lander by applying thrusters from 
#     either side or the bottom. By doing so the moon lander 
#     uses fuel and once that fuel has run out the thrusters 
#     no longer work. The object of the game is to land on the 
#     landing pad as a slow enough speed that the moon lander 
#     will not crash into the ground and ends when either this 
#     is accomplished or the moon lander crashes into the 
#     ground.
# Above and Beyond
#     So I had fun by doing a few different things for the 
#     above and beyond section. I first set it up so that the 
#     moon lander's falling speed is shown below where the fuel 
#     is. Then I set the game to display warning messages at 
#     the top of the screen when the falling velocity is 4 or 
#     greater. Then finally I made it so that when the velocity 
#     is 5 or more, the lander will catch on fire and then be 
#     put out if the speed falls back below 5. I also made it 
#     so that if the lander crashed at any speed, it would also 
#     catch on fire.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o makefile
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o velocity.o lander.o $(LFLAGS)
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
lander.o: lander.h lander.cpp velocity.h point.h uiDraw.h
	g++ -c lander.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
