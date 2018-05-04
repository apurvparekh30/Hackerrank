int findMinGates(vector < int > arrivals, vector < int > departures, int flights) {
    sort(arrivals.begin(),arrivals.end());
    sort(departures.begin(),departures.end());
    int i=1;
    int j=0;
    int gatesNeed=1;
    int result=1;
    while(arrivals[i]<flights && departures[j]<flights){
        if(arrivals[i]<=departures[j]){
            gatesNeed++;
            i++;
            if(result<gatesNeed){
                result=gatesNeed;
            }
        }
        else{
            gatesNeed--;
            j++;
        }
    }
    return result;
}