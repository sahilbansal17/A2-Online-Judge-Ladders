#include <bits/stdc++.h>
using namespace std;

int main(){

	int face_punched, tail_shut, paws_trampled, threatened_to_call_mom;
	scanf("%d\n%d\n%d\n%d\n", &face_punched, &tail_shut, &paws_trampled, &threatened_to_call_mom);

	int total_dragons;
	scanf("%d", &total_dragons);

	// boolean array 
	// damaged[i] tells whether i-th dragon was damaged or not
	// don't forget to initialize
	bool damaged[100002] = {false};

	int total_damaged = 0;
	for(int dragon_num = face_punched; dragon_num <= total_dragons; dragon_num += face_punched){
		if(damaged[dragon_num]){
			// if already damaged
			// please leave that dragon, don't punish him more 
			continue;
		}
		else{
			// if not already damaged
			damaged[dragon_num] = true;
			// increase the count of damaged dragons
			total_damaged ++;
		}
	}
	for(int dragon_num = tail_shut; dragon_num <= total_dragons; dragon_num += tail_shut){
		if(damaged[dragon_num]){
			// if already damaged
			// please leave that dragon, don't punish him more 
			continue;
		}
		else{
			// if not already damaged
			damaged[dragon_num] = true;
			// increase the count of damaged dragons
			total_damaged ++;
		}
	}
	for(int dragon_num = paws_trampled; dragon_num <= total_dragons; dragon_num += paws_trampled){
		if(damaged[dragon_num]){
			// if already damaged
			// please leave that dragon, don't punish him more 
			continue;
		}
		else{
			// if not already damaged
			damaged[dragon_num] = true;
			// increase the count of damaged dragons
			total_damaged ++;
		}
	}
	for(int dragon_num = threatened_to_call_mom; dragon_num <= total_dragons; dragon_num += threatened_to_call_mom){
		if(damaged[dragon_num]){
			// if already damaged
			// please leave that dragon, don't punish him more 
			continue;
		}
		else{
			// if not already damaged
			damaged[dragon_num] = true;
			// increase the count of damaged dragons
			total_damaged ++;
		}
	}

	printf("%d", total_damaged);

	// this is the worst ever implementation I've done ever
	// to make sure that I name the variables nicely
	return 0;
}