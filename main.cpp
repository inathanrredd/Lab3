#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <list>


using namespace std;

int main(int argc, char *argv[]) {
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {

        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	    tokens.push_back(nopunct);
	    unique.insert(nopunct);
            // cout << token<<endl;
	}
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    ofstream out(filename+"_set.txt");
    if (out.is_open()) {
        for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
            out << *it << endl;
        }
    }
    out.close();

    ofstream out2(filename+"_vector.txt");
    if (out2.is_open()) {
        for (int i=0; i < tokens.size(); i++) {
            out2 << tokens[i] << endl;
        }
    }
    out2.close();

    const int M = 3;

    map<list<string>, vector<string> > wordmap;
    list<string> state;
    for (int i = 0; i < M; i++) {
    state.push_back("");
    }
                        
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    wordmap[state].push_back(*it);
    state.push_back(*it);
    state.pop_front();
    }
    // ofstream out3(filename+"_map.txt");
    // if (out3.is_open()) {
    //     for (map<string,vector<string>>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it) {
    //         out3 << it->first << ", " << it->second << endl;
    //     }
    // }
    // out3.close();
    srand(time(NULL));
    
    state.clear();
    for (int i = 0; i < M; i++) {
    state.push_back("");
    }
    for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind]<<" ";
    state.push_back(wordmap[state][ind]);
    state.pop_front();
    }





}