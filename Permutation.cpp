#include<bits/stdc++.h>
using namespace std;

string main_res = "";
void solve(vector< vector<string> > arr,int n,int i,string str) {

    if(i == n) {
    	::main_res += str+", ";
        return;
    }
    vector<string> data = arr[i];
    vector<string> :: iterator k;
    for(k=data.begin();k!=data.end();k++) {
        str += *k;
        solve(arr,n,i+1,str);
        int len = str.length();
        str = str.substr(0,len-1);
    }
}
int main() {
	
	string file;
	getline(cin,file);
	char arr[file.length()];
	for(int i=0;i<file.length();i++) {
		arr[i] = file[i];
	}
	ifstream in;
	in.open(arr,ios::in);
    vector< vector<string> > fields;
    vector<string> :: iterator m;
    vector< vector<string> > :: iterator k;
    if (in) {
        string line;
        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            fields.push_back(vector<string>());
            while (getline(sep, field, ',')) {
                fields.back().push_back(field);
            }
        }
    }
    solve(fields,fields.size(),0,"");
    int len = (::main_res).length();
    cout<<(::main_res).substr(0,len-2);
    return 0;
}