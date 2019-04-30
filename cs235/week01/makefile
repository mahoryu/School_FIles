###############################################################
# Program:
#     Assignment 01, Vector
#     Brother Kirby, CS235
# Author:
#     Ethan Holden
# Summary:
#     This is a custom data type of the vector class. It is a 
#     template that allows the user to store any basic data 
#     type into an array that can expand as needed. It also 
#     allows the user to have random access to each of the 
#     elements within the vector.
# Coding Time:
#     4.5 hours -- main assignment
#     10 minutes - extra credit
# The most difficult part:
#     The most diffifcult part of this assinment for me was 
#     figuring out that I had a memory leak in my program and 
#     then finding where that was. Turns out I had forgotten 
#     to reallocate an array in my assignment operator and so 
#     it let some things work, but others did some really crazy 
#     things.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h assignment01.o
	g++ -o a.out assignment01.o -std=c++11
	tar -cf assignment01.tar vector.h assignment01.cpp makefile

##############################################################
# The individual components
#      assignment01.o     : the driver program
##############################################################
assignment01.o: vector.h assignment01.cpp
	g++ -c assignment01.cpp -std=c++11

clean:
	rm a.out *.o *.tar
