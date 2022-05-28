#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    stringstream str;
    int x; 
    str << "5";
	str >> x;
    cout<<"Converted value of character 5 :"<<x;
}
