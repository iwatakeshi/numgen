default: numgen.cpp
	g++ -g -Wno-write-strings -I -std=c++11 numgen.cpp -o numgen

clean:
	rm -f ./*.o
	rm -f -r ./*.dSYM
