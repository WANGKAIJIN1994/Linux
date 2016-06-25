#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char filename[100]; char ch;
    cout << "pleae enter filename" << endl;
    cin >> filename;
    ifstream infile(filename,ios::in);
    if(!infile){
        cerr << "open error!" << endl;
    }
    cout << "this is the file content:" << endl;
    while(infile.get(ch)){
        cout << ch; 
    }
    ofstream outfile(filename,ios::app);
    outfile << "it's the new change!" << endl;
    infile.close();
    outfile.close();
    return 0;
}

