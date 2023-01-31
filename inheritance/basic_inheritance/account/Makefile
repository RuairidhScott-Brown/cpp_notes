default:account

CXX=g++
CXXFLAGS=-std=c++17 -Wall -O2
SRC_DIR=src
OBJ_DIR=build

$(OBJ_DIR)/account.o: $(SRC_DIR)/account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/saving_account.o: $(SRC_DIR)/saving_account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/main.o: main.cpp $(OBJ_DIR)/account.o $(OBJ_DIR)/saving_account.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

account: $(OBJ_DIR)/main.o $(OBJ_DIR)/account.o $(OBJ_DIR)/saving_account.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f build/*.o