part1: part1.cpp node.h node.cpp
	g++ part1.cpp node.cpp -o part1
	
part2: part2.cpp node.h node.cpp
	g++ part2.cpp node.cpp -o part2
	
part3: part3.cpp node.h node.cpp
	g++ part3.cpp node.cpp -o part3
	
part4: part4.cpp node.h node.cpp
	g++ part4.cpp node.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
