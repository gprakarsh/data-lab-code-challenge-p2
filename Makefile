# =================== SETTINGS ===================
EXENAME := MaxSubarrays

CXX			:=	clang++
CXXFLAGS	:=  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic -Iheaders
LD			:=	clang++
LDFLAGS		:=	-std=c++1y -stdlib=libc++ -lc++abi -lm -Iheaders
ALL_HEADERS	:=	headers/BFS.h headers/Edge.h headers/FullBFS.h headers/Graph.h headers/Mock.h headers/SCCGraph.h headers/Vertex.h headers/ArgumentParser.h
#----------------------------------------------


.PHONY: all-data all clean

# $^ = all dependencies
# $< = first dependency
# $@ = target

all : $(EXENAME)

$(EXENAME): MaxSubarrays.o 
	$(LD) $^ $(LDFLAGS) -o $@

MaxSubarrays.o: MaxSubarrays.cpp 
	$(CXX) $(CXXFLAGS) $< -o $@
