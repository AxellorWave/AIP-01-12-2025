SRC = $(wildcard *.cpp)
paint: $(SRC)
	$(CXX) $^ -o $@