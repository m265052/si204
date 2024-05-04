part1: part1.cpp easycurses.cpp easycurses.h Pos.cpp Pos.h nm.h nm.cpp
	g++ -g part1.cpp easycurses.cpp Pos.cpp nm.cpp -l ncurses -o part1
	
part2: part2.cpp easycurses.cpp easycurses.h Pos.cpp Pos.h nm.h nm.cpp
	g++ -g part2.cpp easycurses.cpp Pos.cpp nm.cpp -l ncurses -o part2

part3: part3.cpp easycurses.cpp easycurses.h Pos.cpp Pos.h nm.h nm.cpp
	g++ -g part3.cpp easycurses.cpp Pos.cpp nm.cpp -l ncurses -o part3
	
part4: part4.cpp easycurses.cpp easycurses.h Pos.cpp Pos.h nm.h nm.cpp
	g++ -g part4.cpp easycurses.cpp Pos.cpp nm.cpp -l ncurses -o part4

part5: part5.cpp easycurses.cpp easycurses.h Pos.cpp Pos.h nm.h nm.cpp
	g++ -g part5.cpp easycurses.cpp Pos.cpp nm.cpp -l ncurses -o part5

################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

