#include <bits/stdc++.h>

using namespace std;

vector<long> heap;
map<long,long> mymap;

long getMinIndex(int l,int r){
	if(heap[l] > heap[r]){
		return r;
	}
	return l;
}

void heapify(long i){
	long size = heap.size();
	long left = (i * 2) + 1;
	long right = (i * 2) + 2;
	if((left < size && heap[i] > heap[left]) || (right < size && heap[i] > heap[right])){
		long sindex = getMinIndex(left,right);
		long temp = heap[i];
		heap[i] = heap[sindex];
		heap[sindex] = temp;
		heapify(sindex);
	}
}

void insert(long v){
	heap.push_back(v);
	long index = heap.size()-1;
	long parent = (index-1)/2;
	while(parent >=0 && heap[parent] > heap[index]) {
		long temp = heap[parent];
		heap[parent] = heap[index];
		heap[index] = temp;

		index = parent;
		parent = (index - 1)/2;
	}
}


void deleteHeap(long v){

	heap[0] = heap[heap.size()-1];
	heap.pop_back();
	heapify(0);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long q;
    long v;

    ifstream inFile;
	inFile.open("input.txt");
	inFile>>q;
    //cin>>q;

    while(q--)  {
    	int c;
    	inFile>>c;
    	//cin>>c;
    	switch(c){
    		case 1:
    			inFile>>v;
    			//cin>>v;
    			insert(v);
    			break;
    		case 2:
    			inFile>>v;
    			//cin>>v;
    			mymap[v]++;
    			//deleteHeap(v);
    			break;
    		case 3:
    			while(mymap[heap[0]] > 0){
    				deleteHeap(heap[0]);
    			}
    			cout<<heap[0]<<endl;
    			break;
    	}
    }
    return 0;
}
