	#include <bits/stdc++.h>

	using namespace std;

	int main() {
		int n,d;
		scanf("%d %d",&n,&d);
		int arr[n];
		int output[n];
		int count[201];
		int pre_sum[201];
		memset(count,0,sizeof(count)); 


		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
		}
		/*int x;
		ifstream inFile;

		inFile.open("input.txt");
		int i = 0;
		while (inFile >> x) {
			arr[i] = x;
	        i++;
	    }
		inFile.close();*/
		
		int notification = 0;
		int median;
		int pop_element = 0;
		bool firsttime = true;
		for(int i=d;i<n;i++) {

			memset(pre_sum,0,sizeof(pre_sum));

			if(firsttime) {
				firsttime = false;
				for(int j=i-d;j<i;j++) {
					count[arr[j]]++;
				}
			}
			else {
				count[pop_element]--;
				count[arr[i-1]]++;
			}
			
			pre_sum[0] = count[0];
			for(int j=1;j<201;j++) {
				pre_sum[j] = count[j] + pre_sum[j-1];
			}

			int a=0;
			int b=0;
			if(d%2 == 0) {

				int first = d/2;
		        int second = first+1;
		        int j = 0;

		        for(;j<201;j++){
		            if(first<=pre_sum[j]){
		                a = j;
		                break;
		            }
		        }
		        for(;j<201;j++){
		            if(second<=pre_sum[j]){
		                b = j;
		                break;
		            }
		        }
			}
			else {
				int first = d/2 + 1;
		        for(int j=0;j<201;j++){
		            if(first<=pre_sum[j]){
		                a = j;
		                break;
		            }
		        }
			}
			
			median = a + b;

			if (d % 2 == 0) {
	            if (arr[i] >= median)
	                notification++;
	        } 
	        else {
	            if (arr[i] >= 2 * median)
	                notification++;
	        }

	        pop_element = arr[i - d];
		}
		printf("%d",notification);
		return 0;
	}

	/*0 1 2 3 4 5 6 7 8

	2 3 4 2 3 6 8 4 5*/
	/*
	0 1 2 3 4
	1 2 3 4 4
	*/