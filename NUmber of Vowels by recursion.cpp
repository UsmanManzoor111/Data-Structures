#include<iostream>
using namespace std;

int Vowel(char *str,int vowelCounter){
	if(*str == '\0'){
		return vowelCounter;
	}else{
		if(*str == 'a' || *str == 'e' || *str == 'o' || *str == 'i' || *str == 'u'){
			vowelCounter += 1;
		}
		vowelCounter = Vowel(++str,vowelCounter);
			
	}
	return vowelCounter;
}
int main(){
	string str;
	cout<<"Enter string : ";
	cin>>str;
	int ans = Vowel(&str[0],0);
	
	cout<<"Ans : "<<ans<<endl;
	return 0;
}
