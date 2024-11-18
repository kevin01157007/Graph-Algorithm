#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> matrix(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(matrix[i][j]);
			if(pq.size() > k){
				pq.pop();
			}
        }
    }
    cout << pq.top() << endl;
	return 0;
}