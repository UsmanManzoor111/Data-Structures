#include<iostream>
using namespace std;
		
int evalpostfix(string expr,int length){
	stack s(length);
	int a,b,c;
	char op1,op2;
	
	for(int i=0 ;i<10 ;i++){
		c=expr.at[i];
		
		if(c == "^"){
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
    		a = atoi(op1);
			b = atoi(op2);
			
			c=a^b;
			
			s.push(c);		
		}
		if(c == "/"){
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
    		a = atoi(op1);
			b = atoi(op2);
			
			c=a/b;
			
			s.push(c);		
		}
		if(c == "*"){
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
    		a = atoi(op1);
			b = atoi(op2);
			
			c=a*b;
			
			s.push(c);		
		}
		if(c == "+"){
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
    		a = atoi(op1);
			b = atoi(op2);
			
			c=a+b;
			
			s.push(c);		
		}
		if(c == "-"){
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
    		a = atoi(op1);
			b = atoi(op2);
			
			c=a-b;
			
			s.push(c);		
		}
		
	}
}
int main()
{
	int length;
    string exp = "435*-";
    
    length=exp.length();
 
    cout << evalPostfix(exp,length);
 
    return 0;
}
