#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,i,j,k,m,count,type,position,max,max1;
	cin >> t;
	while(t--) {
	    cin >> n;
	    int a[n];
	    int v[1001] = {0};
	    max1 = 0;
	    for(i=0;i<n;i++) {
	        cin >> a[i];
	        if(a[i] > max1)
	            max1 = a[i];
	        v[a[i]]++;
	    }
	    vector<int> ans;
	    for(i=0;i<max1+2;i++) {
	        if(v[i] > 0) {
	            ans.push_back(i);
	        }
	    }
	    max = 0 ;
	    for(i=0;i<ans.size();i++) {
	        vector<int> index;
	        for(j=0;j<n;j++) {
	            if(ans[i] == a[j]) {
	                index.push_back(j);
	            }
	        }
	        position = index[0];
	        count = 1;
	        for(k=1;k<index.size();k++) {
	            if(index[k] - index[position] > 1) {
	                count++;
	                position = k;
	            }
	        }
	        if(count > max) {
	            max = count;
	            type = ans[i];
	        }
	        else if(count == max) 
	            if(ans[i] < type)
	                type = ans[i];
	    }
	    cout << type << "\n";
	}
	return 0;
}

