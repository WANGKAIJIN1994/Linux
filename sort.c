#include<iostream>
#include<fstream>
using namespace std;
int main (){
    int number[10];  int tem;
    ofstream outfile("result.txt",ios::out);
    cout << "please enter ten numbers" << endl;
    for(int i=0;i<10;i++){
        cin >> number[i];
    }
    //sort 
    for(int i=0;i<10;i++){
        for(int j=9;j>i;j--){
            if(number[j] < number[j-1]){
               tem = number[j-1];
               number[j-1] = number[j]; 
               number[j] = tem; 
            }
         } 
     }
    //out 
    for(int i=0;i<10;i++){
        outfile << number[i] << " "; 
    }
    return 0;
}
