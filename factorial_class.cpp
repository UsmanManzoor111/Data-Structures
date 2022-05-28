#include<iostream>
using namespace std;
class Factorial{
private:
	int ans;
public:
	Factorial(){
		ans = 1;
	}
	
	int fact(int num){
		for(int i = num;i > 0;i--){
			ans = ans * i;
		}
		return ans;
	}
};

int main(){
	Factorial obj;

	cout<<"factorial : "<<obj.fact(4)<<endl;
	
	return 0;
}

