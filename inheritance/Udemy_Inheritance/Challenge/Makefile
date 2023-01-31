default:account

CXX=g++
CXXFLAGS=-std=c++17 -Wall -O2
SRC_DIR=src
OBJ_DIR=build

$(OBJ_DIR)/Account.o: $(SRC_DIR)/Account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/Account_Util.o: $(SRC_DIR)/Account_Util.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/Savings_Account.o: $(SRC_DIR)/Savings_Account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/Checking_Account.o: $(SRC_DIR)/Checking_Account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/Trust_Account.o: $(SRC_DIR)/Trust_Account.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/main.o: main.cpp $(OBJ_DIR)/Account.o $(OBJ_DIR)/Savings_Account.o $(OBJ_DIR)/Checking_Account.o $(OBJ_DIR)/Account_Util.o $(OBJ_DIR)/Trust_Account.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

account: $(OBJ_DIR)/main.o $(OBJ_DIR)/Account.o $(OBJ_DIR)/Savings_Account.o $(OBJ_DIR)/Checking_Account.o $(OBJ_DIR)/Account_Util.o $(OBJ_DIR)/Trust_Account.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	
.PHONY: clean
clean:
	rm -f build/*.o