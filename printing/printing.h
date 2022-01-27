#ifndef XJQ_PRINTING
#define XJQ_PRINTING
#include"type.h"
#include<streambuf>
using namespace std;
////////////////////////////////////////////////
string str(const char*x);
template<class T>
string str(T*x);
string str(bool x);
string str(char x);
string str(const string&x);
string str(int x);
string str(long int x);
string str(long long int x);
string str(unsigned int x);
string str(unsigned long int x);
string str(unsigned long long int x);
string repr(const string&x);
template<class T,class T2>
string str(const unordered_map<T,T2>&x);
template<class T>
string repr(const T&x);
template<class T>
string str(const vector<T>&x);
template<char pus=' ',char _end='\n',class T>
void print(const T&x);
template<char pus=' ',char _end='\n',class T,class...Ts>
void print(const T&x,const Ts&...xs);
template<char pus=' ',char _end='\n'>
void print();
template<class T>
string str(const unordered_set<T>&x);
template<class T,class T2>
string str(const pair<T,T2>&x);
string strmul(int a,const string&x);
string strmul(const string&x,int a);
string lstrip(const string&x,const string&rm);
string rstrip(const string&x,const string&rm);
string strip(const string&x,const string&rm);
string replace(const string&_x,const string&a,const string&b);
////////////////////////////////////////////////
string str(const char*x){
    return string(x);
}
template<class T>
string str(T*x){
    T tmp=0;
    return "<Pointer of <"+type(tmp)+">>";
}
string str(bool x){
    if(x)return "true";
    else return "false";
}
string str(char x){
    return {x,0};
}
string str(const string&x){
    return x;
}
string str(int x){
    if(x==0)return "0";
    if(x<0)return "-"+str(-x);
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
string str(long int x){
    if(x==0)return "0";
    if(x<0)return "-"+str(-x);
    vector<long int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
string str(long long int x){
    if(x==0)return "0";
    if(x<0)return "-"+str(-x);
    vector<long long int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
string str(unsigned int x){
    if(x==0)return "0";
    vector<unsigned int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
string str(unsigned long int x){
    if(x==0)return "0";
    vector<unsigned long int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
string str(unsigned long long int x){
    if(x==0)return "0";
    vector<unsigned long long int> a;
    while(x){
        a.push_back(x%10+'0');
        x/=10;
    }
    string ret;
    reverse(a.begin(),a.end());
    ret.assign(a.begin(),a.end());
    return ret;
}
string repr(const string&x){
    string s=replace(x,"\n","\\n");
    s=replace(s,"\a","\\a");
    s=replace(s,"\b","\\b");
    s=replace(s,"\f","\\f");
    s=replace(s,"\r","\\r");
    s=replace(s,"\t","\\t");
    s=replace(s,"\v","\\v");
    s=replace(s,"\"","\\\"");
    return '"'+s+'"';
}
template<class T,class T2>
string str(const unordered_map<T,T2>&x){
    if(!x.size())return "{}";
    string ret="{";
    for(auto i=x.begin();i!=x.end();i++){
        ret+=repr((*i).first)+":"+repr((*i).second)+", ";
    }
    return ret.substr(0,ret.size()-2)+"}";
}
template<class T>
string repr(const T&x){
    return str(x);
}
template<class T>
string str(const vector<T>&x){
    if(!x.size())return "[]";
    string ret="[";
    for(auto i=x.begin();i!=x.end();i++){
        ret+=repr(*i)+", ";
    }
    return ret.substr(0,ret.size()-2)+']';
}
template<char pus=' ',char _end='\n',class T>
void print(const T&x){
    cout<<str(x)<<_end;
}
template<char pus=' ',char _end='\n',class T,class...Ts>
void print(const T&x,const Ts&...xs){
    cout<<str(x);
    if(pus)cout<<pus;
    print<pus,_end>(xs...);
}
template<char pus=' ',char _end='\n'>
void print(){
    cout<<_end;
}
template<class T>
string str(const unordered_set<T>&x){
    if(!x.size())return "unordered_set()";
    string ret="{";
    for(auto i=x.begin();i!=x.end();i++){
        ret+=repr(*i)+", ";
    }
    return ret.substr(0,ret.size()-2)+"}";
}
template<class T,class T2>
string str(const pair<T,T2>&x){
    return "pair("+str(x.first)+", "+str(x.second)+")";
}
string strmul(const string&x,int a){
    string ret="";
    for(int i=0;i<a;i++){
        ret+=x;
    }
    return ret;
}
string strmul(int a,const string&x){
    string ret="";
    for(int i=0;i<a;i++){
        ret+=x;
    }
    return ret;
}
string lstrip(const string&x,const string&rm=""){
    int l=0;
    if(rm==""){
        while(x[l]=='\n'||x[l]=='\r'||x[l]=='\t'||x[l]==' ')l++;
    }
    else{
        while(x.substr(l,rm.size())==rm){
            l+=rm.size();
        }
    }
    return x.substr(l);
}
string rstrip(const string&x,const string&rm=""){
    string y=x;
    reverse(y.begin(),y.end());
    string mr=rm;
    reverse(mr.begin(),mr.end());
    int l=0;
    if(mr==""){
        while(y[l]=='\n'||y[l]=='\r'||y[l]=='\t'||y[l]==' ')l++;
    }
    else{
        while(y.substr(l,mr.size())==mr){
            l+=mr.size();
        }
    }
    y=y.substr(l);
    reverse(y.begin(),y.end());
    return y;
}
string strip(const string&x,const string&rm=""){
    return rstrip(lstrip(x,rm),rm);
}
string replace(const string&x,const string&a,const string&b){
    vector<int> place={0};
    string ret="";
    int i=0;
    while(i<x.size()){
        i=x.find(a,i);
        if(i==-1)break;
        place.push_back(i);
        i++;
    }
    if(place.size()==1)return x;
    for(i=1;i<place.size();i++){
        if(i==1)ret+=x.substr(place[i-1],place[i]-place[i-1]);
        else ret+=x.substr(place[i-1]+a.size(),place[i]-place[i-1]-a.size());
        ret+=b;
    }
    ret+=x.substr(place[i-1]+a.size(),place[i]-place[i-1]-a.size());
    return ret;
}
struct{
private:
    long long int mypow(long long int a,long long int n){
    	long long int re=1;
    	for(long long int i=0;i<n;i++)re*=a;
    	return re;
    }
    bool l_pair(char a){
        return a=='{'||a=='"'||a=='['||a=='\'';'}';
    }
    bool is_pair(char a,char b){
        if(a=='{'&&b=='}')return 1;
        if(a=='"'&&b=='"')return 1;
        if(a=='['&&b==']')return 1;
        if(a=='\''&&b=='\'')return 1;
        return 0;
    }
public:
    template<class T>
    string dumps(const vector<T>&x,int indent=4,int _indent=0){
        if(!x.size())return strmul(" ",_indent)+"[]";
        string ret=strmul(" ",_indent)+"[\n";
        for(auto i=x.begin();i!=x.end();i++){
            ret+=dumps(*i,indent,_indent+indent)+",\n";
        }
        return ret.substr(0,ret.size()-2)+"\n"+strmul(" ",_indent)+"]";
    }
    template<class T>
    string dumps(const T&x,int indent=4,int _indent=0){
        return strmul(" ",_indent)+repr(x);
    }
    template<class T,class T2>
    string dumps(const unordered_map<T,T2>&x,int indent=4,int _indent=0){
        if(!x.size())return strmul(" ",_indent)+"{}";
        string ret=strmul(" ",_indent)+"{\n";
        for(auto i=x.begin();i!=x.end();i++){
            ret+=strmul(" ",_indent+indent)+repr((*i).first)+": "+dumps((*i).second,indent,_indent+indent).substr(_indent+indent)+",\n";
        }
        return ret.substr(0,ret.size()-2)+"\n"+strmul(" ",_indent)+"}";
    }
    template<class T>
    void dump(string fname,const T&x){
        ofstream fout(fname,ios::out);
        fout<<dumps(x);
        fout.close();
    }
    bool loads(const string&_x,const bool&_type){
        string x=strip(_x);
        if(x=="true"||x=="1")return 1;
        else if(x=="false"||x=="0")return 0;
        cout<<"bool Error";exit(114514);
    }
    char loads(const string&_x,const char&_type){
        string x=strip(_x);
        if(x.size()==1)return x[0];
        cout<<"char Error";exit(114514);
    }
    int loads(const string&_x,const int&_type){
        string x=strip(_x);
        bool f=0;
        if(x[0]=='-'){
            f=1;
            x=x.substr(1);
        }
    	int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	if(f)return -ret;
        return ret;
    }
    long int loads(const string&_x,const long int&_type){
        string x=strip(_x);
        bool f=0;
        if(x[0]=='-'){
            f=1;
            x=x.substr(1);
        }
    	long int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	if(f)return -ret;
        return ret;
    }
    long long int loads(const string&_x,const long long int&_type){
        string x=strip(_x);
        bool f=0;
        if(x[0]=='-'){
            f=1;
            x=x.substr(1);
        }
    	long long int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	if(f)return -ret;
        return ret;
    }
    unsigned int loads(const string&_x,const unsigned int&_type){
        string x=strip(_x);
    	unsigned int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	return ret;
    }
    unsigned long int loads(const string&_x,const unsigned long int&_type){
        string x=strip(_x);
    	unsigned long int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	return ret;
    }
    unsigned long long int loads(const string&_x,const unsigned long long int&_type){
        string x=strip(_x);
    	unsigned long long int l=x.size(),ret=0;
    	for(int i=0;i<l;i++)ret+=(x[i]-'0')*mypow(10,l-1-i);
    	return ret;
    }
    template<class T>
    vector<T> loads(const string&_x,const vector<T>&_type){
        int _=_x.find("["),l=0;
        vector<int> places={0};
        vector<T> ret;
        string x=_x.substr(_,_x.rfind("]")-_+1),tmp;
        stack<char> s;
        s.push(x[l]);l++;
        while(s.size()&&l<x.size()){
            if(is_pair(s.top(),x[l])){
                s.pop();
            }
            else if(l_pair(x[l])){
                s.push(x[l]);
            }
            else if(s.size()==1&&x[l]==','){
                places.push_back(l);
            }
            l++;
        }
        for(_=1;_<places.size();_++){
            tmp=strip(x.substr(places[_-1]+1,places[_]-places[_-1]-1));
            ret.push_back(loads(tmp,T()));
        }
        tmp=strip(x.substr(places[_-1]+1,x.size()-(places[_-1]+1)-1));
        if(tmp.size()){
            ret.push_back(loads(tmp,T()));
        }
        return ret;
    }
    template<class T,class T2>
    unordered_map<T,T2> loads(const string&_x,const unordered_map<T,T2>&_type){
        int _=_x.find("{"),l=0;
        pair<int,int> ptmp;
        vector<pair<int,int>> places={{0,-1}};
        unordered_map<T,T2> ret;
        string x=_x.substr(_,_x.rfind("}")-_+1),tmp,tmp2;
        stack<char> s;
        s.push(x[l]);l++;
        while(s.size()&&l<x.size()){
            if(is_pair(s.top(),x[l])){
                s.pop();
            }
            else if(l_pair(x[l])){
                s.push(x[l]);
            }
            else if(s.size()==1&&x[l]==':'){
                places[places.size()-1].second=l;
            }
            else if(s.size()==1&&x[l]==','){
                places.push_back(pair<int,int>({l,-1}));
            }
            l++;
        }
        for(_=1;_<places.size();_++){
            tmp=strip(x.substr(places[_-1].first+1,places[_-1].second-places[_-1].first-1));
            tmp2=strip(x.substr(places[_-1].second+1,places[_].first-places[_-1].second-1));
            ret[loads(tmp,T())]=loads(tmp2,T2());
        }
        if(places[_-1].second!=-1){
            tmp=strip(x.substr(places[_-1].first+1,places[_-1].second-places[_-1].first-1));
            tmp2=strip(x.substr(places[_-1].second+1,x.size()-1-places[_-1].second-1));
            ret[loads(tmp,T())]=loads(tmp2,T2());
        }
        return ret;
    }
    template<class T>
    unordered_map<T,string> _loads(const string&_x,const unordered_map<T,string>&_type){
        int _=_x.find("{"),l=0;
        pair<int,int> ptmp;
        vector<pair<int,int>> places={{0,-1}};
        unordered_map<T,string> ret;
        string x=_x.substr(_,_x.rfind("}")-_+1),tmp,tmp2;
        stack<char> s;
        s.push(x[l]);l++;
        while(s.size()&&l<x.size()){
            if(is_pair(s.top(),x[l])){
                s.pop();
            }
            else if(l_pair(x[l])){
                s.push(x[l]);
            }
            else if(s.size()==1&&x[l]==':'){
                places[places.size()-1].second=l;
            }
            else if(s.size()==1&&x[l]==','){
                places.push_back(pair<int,int>({l,-1}));
            }
            l++;
        }
        for(_=1;_<places.size();_++){
            tmp=strip(x.substr(places[_-1].first+1,places[_-1].second-places[_-1].first-1));
            tmp2=strip(x.substr(places[_-1].second+1,places[_].first-places[_-1].second-1));
            ret[loads(tmp,T())]=tmp2;
        }
        if(places[_-1].second!=-1){
            tmp=strip(x.substr(places[_-1].first+1,places[_-1].second-places[_-1].first-1));
            tmp2=strip(x.substr(places[_-1].second+1,x.size()-1-places[_-1].second-1));
            ret[loads(tmp,T())]=tmp2;
        }
        return ret;
    }
    vector<string> _loads(const string&_x){
        int _=_x.find("["),l=0;
        vector<int> places={0};
        vector<string> ret;
        string x=_x.substr(_,_x.rfind("]")-_+1),tmp;
        stack<char> s;
        s.push(x[l]);l++;
        while(s.size()&&l<x.size()){
            if(is_pair(s.top(),x[l])){
                s.pop();
            }
            else if(l_pair(x[l])){
                s.push(x[l]);
            }
            else if(s.size()==1&&x[l]==','){
                places.push_back(l);
            }
            l++;
        }
        for(_=1;_<places.size();_++){
            tmp=strip(x.substr(places[_-1]+1,places[_]-places[_-1]-1));
            ret.push_back(tmp);
        }
        tmp=strip(x.substr(places[_-1]+1,x.size()-(places[_-1]+1)-1));
        if(tmp.size()){
            ret.push_back(tmp);
        }
        return ret;
    }
    string loads(const string&_x,const string&_type){
        string s=strip(_x);
        s=s.substr(1,s.size()-2);
        s=replace(s,"\\\"","\"");
        s=replace(s,"\\n","\n");
        s=replace(s,"\\a","\a");
        s=replace(s,"\\b","\b");
        s=replace(s,"\\f","\f");
        s=replace(s,"\\r","\r");
        s=replace(s,"\\t","\t");
        s=replace(s,"\\v","\v");
        return s;
    }
    template<class T>
    T load(string fname,const T&x){
        ifstream fin(fname,ios::in);
        string s((istreambuf_iterator<char>(fin)),std::istreambuf_iterator<char>());
        fin.close();
        return loads(s,x);
    }
    template<class T>
    unordered_map<T,string> _load(string fname,const unordered_map<T,string>&_type){
        ifstream fin(fname,ios::in);
        string s((istreambuf_iterator<char>(fin)),std::istreambuf_iterator<char>());
        fin.close();
        return _loads(s,_type);
    }
}json;
#endif