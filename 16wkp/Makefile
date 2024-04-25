p1: p1.cpp
	g++ p1.cpp -o p1
p2: p2.cpp 
	g++ p2.cpp -o p2
p3: p3.cpp list.h list.cpp
	g++ p3.cpp list.cpp -o p3
runp1:
	@./p1 
runp2:
	@valgrind ./p2 2> out; python3 val.py
runp3:
	@valgrind ./p3 2> out; python3 val.py



