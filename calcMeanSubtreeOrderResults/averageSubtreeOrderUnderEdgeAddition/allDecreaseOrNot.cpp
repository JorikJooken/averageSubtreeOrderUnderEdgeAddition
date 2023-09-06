#include <bits/stdc++.h>

// Unsafe because no defined behaviour if character = 0. ctz and clz work with 32 bit numbers.
#define unsafePrev(character, current) (__builtin_ctz(character) - current >= 0 ? -1 : current -__builtin_clz((character) << (32 - current)) - 1)

#define prev(character,current) (character ? unsafePrev(character,current) : -1)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector< pair<long long, long long> > allPairs;
    int parity=0;
    long long x;
    long long y;
    // reads triples of lines, finds the (x,y) pair with minimum y and checks if x2/y2<=x/y for all pairs
    while(getline(cin,line))
    {
	if(parity==0)
        {
        }
        else if(parity==1) x=atoll(line.c_str());
        else
        {
            y=atoll(line.c_str());
            //cerr << x << " " << y << endl;
            allPairs.push_back(make_pair(x,y));
        }
        parity=(parity+1)%3;
    }
    for(pair<long long, long long> p : allPairs)
    {
        if(p.second<y)
        {
            x=p.first;
            y=p.second;
        }
    }
    //cerr << "x and y: " << x << " " << y << endl;
    bool ok=true;
    int decreaseCtr=0;
    for(pair<long long, long long> p : allPairs)
    {
        long long x2=p.first;
        long long y2=p.second;
        //cerr << x2 << " " << y2 << endl;
        if(!(x2*y<=x*y2))
        {
            ok=false;
        }
        else
        {
            decreaseCtr++;
        }
    }
    cout << "All decreased or not: " << ok << endl;
    cout << "It decreased " << decreaseCtr << " times out of " << allPairs.size() << " pairwise non-isomorphic graphs" << endl;
    return 0;
}
