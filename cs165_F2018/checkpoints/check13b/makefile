###############################################################
# Program:
#     Checkpoint 13b, Rule of Three
#     Brother Alvey, CS165
# Author:
#     Ethan Holden
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : numberList.o check13b.o
	g++ numberList.o check13b.o
	tar -cf check13b.tar makefile *.h *.cpp

numberList.o : numberList.h numberList.cpp
	g++ -c numberList.cpp

check13b.o : numberList.h check13b.cpp
	g++ -c check13b.cpp

clean :
	rm *.o *.out *.tar
