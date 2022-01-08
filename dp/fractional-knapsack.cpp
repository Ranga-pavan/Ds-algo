Example:
w: 12
n: 4
Grains (weight, value): [(5, 20), (8, 20), (4, 15), (5, 8)]
Output: 42.50
Explanation: Take 5 kg of 1st grain, 3 kg of 2nd grain and 4 kg of 3rd grain

/* This is the Grain class definition


class Grain {
public:
    int weight, value;
    Grain(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};
*/
bool cmp(Grain* a,Grain* b){
	double r1=(double)a->value/(double)a->weight;
	double r2=(double)b->value/(double)b->weight;
	return r1>r2;
}
double maxSackValue(vector<Grain*> &grains, int w) {
	sort(grains.begin(),grains.end(),cmp);        //sort according to value/weight ratio
      double finalval=0.0;                      //double
	/*for(auto i:grains){
		cout<<i->weight<<" "<<i->value<<endl;
	}*/
	int n=grains.size(),currwt=0;
	for(int i=0;i<n;i++){
		if(currwt+grains[i]->weight<=w){          //current wt + added wt <= req wt then total value can accomodate 
			finalval+=grains[i]->value;
			currwt+=grains[i]->weight;
		}
		else{                                     //else part of total value will accomodate 
			int remain=w-currwt;
			finalval+=grains[i]->value*((double)remain
                             / (double)grains[i]->weight);  //part =  (remain wt /  grains[i]->wt) if  remain is 2kg but its value is 3kg then 2/3 part of value will taken
			break;                                                //all wt completed so break
		}
	}
    return finalval;
}
