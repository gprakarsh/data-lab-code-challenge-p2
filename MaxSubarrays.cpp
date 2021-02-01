#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

size_t n,k,prevX;
size_t m = pow(2,31) - 1;
unordered_map<size_t, size_t>Xs;

size_t X(size_t i){
    if(Xs.find(i)==Xs.end()){
        size_t m = pow(2,31)-1;
        size_t a = 48271;
        for(size_t j = 1; j < i; j++){
            a*=48271;
            a%=m;
        }
        Xs.insert(make_pair(i,((a*prevX)%m)));
    }
    return Xs[i];
};

size_t l(size_t i){
    size_t num = n+(2*i)-1;
    return (X(num)%n)+1;
};

size_t s(size_t i){
    size_t num = n+(2*i);
    return (X(num)%(n-l(i)+1))+1;
};


int main(){
    ifstream file("input.txt");
    string str;
    getline(file,str);

    string args[3];
    int x = 0;
    stringstream ssin(str);
    while (ssin.good() && x < 3){
        ssin >> args[x];
        ++x;
    }

    n = stoi(args[0]);
    k = stoi(args[1]);
    prevX = stoi(args[2]);

    size_t product = 1;
    for(size_t a=1; a<=k; a++){
        size_t start = X(s(a));
        size_t max = start;
        size_t arrLen = l(a);
        for(size_t b=0; b<arrLen; b++){
            if(max<X(s(a)+b)){
                max = X(s(a)+b);
            }
        }
        product*=max;
        product%=m;    
    }
    ofstream output("output.txt");
    output << (product);
    output.close();
};

