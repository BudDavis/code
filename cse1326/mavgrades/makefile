CXXOPTS=-Wall -std=gnu++17 -g
all: mavgrades
mavgrades:mavgrades.cpp course.cpp
	${CXX} ${CXXOPTS} ${CPPOPTS} -Wall -o $@ $^
clean:
	-rm -f mavgrades
