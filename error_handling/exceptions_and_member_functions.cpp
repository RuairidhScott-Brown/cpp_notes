#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException {
    private:
        int m_username_length;
    
    public:
        BadLengthException():m_username_length{0} {}
        
        BadLengthException(int n):m_username_length{n} {}
        
        int what() {
            return m_username_length;
        }
           
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		} catch (std::exception &e) {
			std::cout << "Standard Exception: " << e.what() << '\n';
		} catch (...) {
			std::cout << "Unknown exception." << '\n';
		}
	}
	return 0;
}