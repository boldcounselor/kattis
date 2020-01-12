#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;
class Person{
    public:
        string name;
        vector<string> class;
        Person(string){
            name = string;
        }
    private:
}
bool comparePeople(const pair<string,vector<string>> ){

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        set<Person> society;
        while(k--){
            string name, fullclass, trash;
            cin >> name >> fullclass >> trash;
            name.pop_back();
            istringstream split(fullclass);
            vector<string> token_class;
            for(string cls; getline(split, cls, '-'); token_class.push_back(cls));
        }
    }
    return 0;
}