#include <iostream>using namespace std;int main() {   char *ptr;   try {	  ptr = new char[ 1000000000 ];   }   catch( ... ) {      cout << "Too many elements" << endl;   }   return 0;}