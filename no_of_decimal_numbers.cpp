#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int no_of_digits_before_decimal(char *ptr){
	int count=0;
	while(*ptr != '.')
	{
		count++;
		ptr++;
	}
	return count;
	
}

int no_of_even(char *ptr){
	
	int count=0;
	while(*ptr != '.')
	{
		if(*ptr%2==0)
		{
			count++;
		}
		ptr++;
	}
	return count;
}
int no_of_odd(string s)
{
	int count=0,n=0;
	
	while(s[n] != '.')
	{
		if(s[n]%2!=0)
		{
			count++;
		}
		n++;
	}
	return count;
}
int no_of_digits_after_decimal(char *ptr,int l)
{
	int current_length,count=0;
	while(*ptr != '.')
	{
		current_length++;
		ptr++;
	}
	ptr++;
	current_length++;
	while(current_length != l)
	{
		count++;
		ptr++;
		current_length++;
	}
	return count;
}
int main()
{
	string str ="123845.678990";
//	cout<<"Number of digits before decimal= "<<no_of_digits_before_decimal(&str[0])<<endl;
//	cout<<"Number of even numbers= "<<no_of_even(&str[0])<<endl;
//	cout<<"Number of odd numbers= "<<no_of_odd(str)<<endl;
	cout<<"Number of digits after decimal= "<<no_of_digits_after_decimal(&str[0],str.length()<<endl;


	return 0;
}

