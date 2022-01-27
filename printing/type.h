#ifndef XJQ_TYPE
#define XJQ_TYPE
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<fstream>
using namespace std;
string int2str(int x){
    vector<int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
//////////////////////////////////////////////////////
string type(bool x);
string type(char x);
string type(unsigned char x);
string type(float x);
string type(double x);
string type(long double x);
string type(int x);
string type(unsigned int x);
string type(short x);
string type(unsigned short x);
string type(long int x);
string type(unsigned long int x);
string type(long long int x);
string type(unsigned long long int x);
string type(const string&x);
string type(const fstream&x);
string type(const ifstream&x);
string type(const ofstream&x);
string type(const istream&x);
string type(const ostream&x);
template<class T>
string type(const vector<T>&x);
template<class T,long long unsigned int NUm>
string type(const array<T,NUm>&x);
template<class T>
string type(const deque<T>&x);       
template<class T,class T2>
string type(const map<T,T2>&x);     
template<class T>
string type(const set<T>&x);
template<class T>
string type(const list<T>&x);
template<class T>
string type(const stack<T>&x);
template<class T>
string type(const queue<T>&x);
template<class T>
string type(const priority_queue<T>&x);
template<class T>
string type(const unordered_set<T>&x);
template<class T,class T2>
string type(const unordered_map<T,T2>&x);
template<class T>
string type(T*x);
template<class T,class T2>
string type(const pair<T,T2>&x);
template<class T>
string type(const T&x);
//////////////////////////////////////////////////////
string type(bool x){
    return "bool";
}
string type(char x){
    return "char";
}
string type(unsigned char x){
    return "unsigned char";
}
string type(float x){
    return "float";
}
string type(double x){
    return "double";
}
string type(long double x){
    return "long double";
}
string type(int x){
    return "int";
}
string type(unsigned int x){
    return "unsigned int";
}
string type(short x){
    return "short";
}
string type(unsigned short x){
    return "unsigned short";
}
string type(long int x){
    return "long int";
}
string type(long long int x){
    return "long long int";
}
string type(unsigned long int x){
    return "unsigned long int";
}
string type(unsigned long long int x){
    return "unsigned long long int";
}
string type(const string&x){
    return "string";
}
string type(const fstream&x){
    return "fstream";
}
string type(const ifstream&x){
    return "ifstream";
}
string type(const ofstream&x){
    return "ofstream";
}
string type(const istream&x){
    return "istream";
}
string type(const ostream&x){
    return "ostream";
}
template<class T>
string type(const vector<T>&x){
    T tmp;
    return "vector<"+type(tmp)+">";
}
template<class T,long long unsigned int NUm>
string type(const array<T,NUm>&x){
    T tmp;
    return "array<"+type(tmp)+", "+int2str(NUm)+">";
}
template<class T,class T2>
string type(const map<T,T2>&x){
    T tmp;
    T2 tmp2;
    return "map<"+type(tmp)+", "+type(tmp2)+">";
}
template<class T>
string type(const deque<T>&x){
    T tmp;
    return "deque<"+type(tmp)+">";
}
template<class T>
string type(const set<T>&x){
    T tmp;
    return "set<"+type(tmp)+">";
}
template<class T>
string type(const list<T>&x){
    T tmp;
    return "list<"+type(tmp)+">";
}
template<class T>
string type(const stack<T>&x){
    T tmp;
    return "stack<"+type(tmp)+">";
}
template<class T>
string type(const queue<T>&x){
    T tmp;
    return "queue<"+type(tmp)+">";
}
template<class T>
string type(const priority_queue<T>&x){
    T tmp;
    return "priority_queue<"+type(tmp)+">";
}
template<class T>
string type(const unordered_set<T>&x){
    T tmp;
    return "unordered_set<"+type(tmp)+">";
}
template<class T,class T2>
string type(const unordered_map<T,T2>&x){
    T tmp;
    T2 tmp2;
    return "unordered_map<"+type(tmp)+", "+type(tmp2)+">";
}
template<class T>
string type(T*x){
    T tmp;
    return type(tmp)+"*";
}
template<class T,class T2>
string type(const pair<T,T2>&x){
    T tmp;
    T2 tmp2;
    return "pair<"+type(tmp)+", "+type(tmp2)+">";
}
template<class T>
string type(const T&x){
    return x.__type__;
}
#endif