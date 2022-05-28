#include<iostream>
using namespace std;
class Factorial{
public:
	int fact(int);
};

int Factorial::fact(int num){
	if(num <= 1){
		return num;
	}
	return num*fact(num-1);
}
	
int main(){
	Factorial obj;

	cout<<"factorial : "<<obj.fact(7)<<endl;
	
	return 0;
}

