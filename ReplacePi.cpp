///Replace all the occurrences of pi in a string
#include<iostream>
#include<string.h>

using namespace std;

char* replaceAllOccurrencesOfPi(char str[], int length, int startIndex){
    if(length == 0) return '';
    if(startIndex == length) return '';

    char temp[] = replaceAllOccurrencesOfPi(str, length, startIndex + 1);
    if(str[startIndex] == 'p' && temp[0] == 'i'){
        str[startIndex] = 'P';
        temp[0] = 'I';
    }
    return (str[startIndex]).concat(temp);
}
int main(){
char arr[] = {'p','i','p','t','w'};
char ans[] = replaceAllOccurrencesOfPi(arr, 5, 0);
for(int i = 0; i < 5; i++){
    cout<<ans[i];
}
return 0;
}
