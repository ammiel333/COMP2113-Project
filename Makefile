CXX = clang++
override CXXFLAGS += -g -Wall -Werror -pedantic-errors -std=c++11

SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OBJS = $(SRCS:.cpp=.o)

all: wordle

wordle: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

wordle-debug: $(OBJS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0 $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f wordle wordle-debug $(OBJS)
