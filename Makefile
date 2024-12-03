CXX = clang++
override CXXFLAGS += -g -Wall -Werror -pedantic-errors -std=c++11

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

OBJS = $(SRCS:.cpp=.o)

all: wordle

wordle: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o wordle

wordle-debug: $(OBJS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0 $(OBJS) -o wordle-debug

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f wordle wordle-debug $(OBJS)
