#include <bits/stdc++.h>
#define ll long long
#define md 1000000007
#define pb push_back
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int main() {
	FAST
	ll t,h,p;
	cin >> t;
	while(t--) {
	    cin >> h >> p;
	    while(p > 0 && h > 0) {
	        h = h - p;
	        p = floor(p/2);
	    }
	    if(h <= 0) 
	        cout << "1" << endl;
	    else
	        cout << "0" << endl;
	}
	
	return 0;
}
