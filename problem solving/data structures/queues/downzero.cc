#include <bits/stdc++.h>

using namespace std;



void getOperations(int n){
	if(n<3)
	{
		cout<<n<<endl;
		return;
	}
	queue<pair<int,int>> q;
	q.push(make_pair(n,0));
	vector <int> v(1000001,INT_MAX);   //will store the steps from n
	v[n] = 0;

	while(!q.empty()) {
		int t = q.front().first;
		int steps = q.front().second;
		q.pop();
		if(steps > v[t])
			continue;
		if(t==0){
			cout << steps << endl;
			break;
		}

		for(int i=2;i<=sqrt(t);i++){
			if(t%i==0){
				int factor = t/i;
				if(v[factor]<=steps+1)
					continue;
				v[factor] = steps+1;
				q.push(make_pair(factor,steps+1));
			}
		}
		if(v[t-1] > steps+1){
			v[t-1] = steps+1;
			q.push(make_pair(t-1,steps+1));
		}
	}
}

int main() {
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int N;
        cin >> N;
        getOperations(N);
    }

    return 0;
}
