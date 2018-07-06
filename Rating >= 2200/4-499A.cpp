#include <bits/stdc++.h>
using namespace std;

int main(){

	int no_of_best_moments, skip_interval;
	scanf("%d %d", &no_of_best_moments, &skip_interval);

	int start_moment, end_moment, min_minutes_must_watch = 0;
	int current_minute = 1;
	for(int moment_index = 0; moment_index < no_of_best_moments; moment_index ++){
		scanf("%d %d", &start_moment, &end_moment);

		// skip max. possible so that we can watch the current best moment
		int difference = start_moment - current_minute;
		int no_of_skips = difference/skip_interval;
		// now current minute will refer to the time at which we should start watching
		current_minute += skip_interval * no_of_skips;
		// min. we must watch to complete this best moment
		min_minutes_must_watch += end_moment - current_minute + 1;
		// update the current minute
		current_minute = end_moment + 1;
	}

	printf("%d\n", min_minutes_must_watch);

	return 0;
}