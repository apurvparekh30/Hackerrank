#include <bits/stdc++.h>

using namespace std;

/*long insertSort(long arr[],long n) {
	long moves = 0; 
	for(long i = 0;i<n;i++) {
		long x = arr[i];
		long j = i - 1;

		while(j>=0 && arr[j] > x) {
			arr[j+1] = arr[j];
			j--;
			moves ++;
		}
		arr[j+1] = x;
	}

	return moves;
}*/

/*long insertSort(long arr[],long n) {

	long moves = 0; 
	for(long i = 0;i<n;i++) {
		long x = arr[i];
		long j = i - 1;

		while(j>=0) {
			if(arr[j] > x)
				moves ++;
			j--;
		}
	}
	return moves;
}
*/
long getSum(long BIA[],long index) {
	long sum = 0;
	while(index > 0) {
		sum = sum + BIA[index];
		index = index - (index & (-index));
	}
	
	return sum;
}

void updateBIA(long BIA[], long n, long index, long value) {

	while (index <= n) {
		BIA[index] = BIA[index] + value;
		//printf("\nindex = %ld sum = %ld",index,BIA[index]);
		index = index + (index & (-index));
	}
	
}
long getInversions(long a[],long n) {
	long invcount = 0;
	long max=0;

	for(long i =0;i<n;i++) {
		if(a[i] > max) {
			max = a[i];
		}
	}

	int BIA[max + 1];
/*	for (long i=0; i<=max; i++)
        BIA[i] = 0;*/

	
	memset(BIA,0,sizeof(BIA));

	/*for(long i=n-1;i>=0;i--) {

		invcount = invcount + getSum(BIA,a[i] -1);

		updateBIA(BIA,max,a[i],1);

	}

	//printf("\ninvcount = %ld",invcount);
	return invcount;*/

}
int main() {

	long t;
	scanf("%ld",&t);

	for (long i = 0; i < t; ++i)
	{
		long n;
		scanf("%ld",&n);

		long arr[n];
		for (long j = 0; j < n; ++j)
		{
			scanf("%ld",&arr[j]);
		}

		long moves = getInversions(arr,n);
		printf("%ld",moves);
		printf("\n");
	}
	return 0;
}
