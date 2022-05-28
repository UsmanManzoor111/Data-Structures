#include<iostream>
using namespace std;


int Vowels(char *ptr, int count)
{
    if(*ptr == '\0'){
        return count;
    }
    
    count += Vowels(ptr+1,count);
    
    if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
        count += 1;
        return count;
    }
    
    return count;
}

int main(){
    string arr="mu name is usman";

    cout<<Vowels(&arr[0],0);
}