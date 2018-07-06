#include <bits/stdc++.h>
using namespace std;

int fact(int n){
	if(n == 0){
		return 1;
	}
	return n * fact(n - 1);
}

int main(){

	char sent_commands[11], received_commands[11];
	scanf("%s\n%s", sent_commands, received_commands);

	int target_position, sent_index, received_index;
	target_position = sent_index = received_index = 0;

	while(sent_commands[sent_index] != '\0'){
		char current_command = sent_commands[sent_index];
		if(current_command == '+'){
			target_position ++;
		}
		else{
			target_position --;
		}
		sent_index ++;
	}

	int actual_position = 0, count_of_unrecognized_commands = 0;
	while(received_commands[received_index] != '\0'){
		char current_command = received_commands[received_index];
		if(current_command == '+'){
			actual_position ++;
		}
		else if(current_command == '-'){
			actual_position --;
		}
		else{
			count_of_unrecognized_commands ++;
		}
		received_index ++;
	}

	// sum required for the actions of unrecognized commands
	int sum_required = target_position - actual_position;

	double probability_required;

	if(abs(sum_required) > count_of_unrecognized_commands){
		probability_required = 0.0;
		printf("%.12f", probability_required);
	}
	else{
		// let x be the number of '+' commands
		// and y the number of '-' commands

		// so x + y = count_of_unrecognized_commands (let it be N)
		// and x - y = sum_required (let it be S)

		// on solving
		// x = (N + S)/2
		// y = N - (N + S)/2 
		// i.e. y = (N - S)/2

		int pos_commands = (count_of_unrecognized_commands + sum_required)/2;
		int neg_commands = (count_of_unrecognized_commands - sum_required)/2;

		// for proability, we need the favourable cases and total cases

		int total_cases = pow(2, count_of_unrecognized_commands);

		// no. of favourable cases = N choose x = N choose y (since x + y = N)
		// since the numbers are small, we can use the recursive factorial function
		int n = count_of_unrecognized_commands, x = pos_commands;
		int favourable_cases = fact(n)/(fact(n - x) * fact(x));

		probability_required = 1.0*favourable_cases/total_cases;
		printf("%.12f", probability_required);
	}
	return 0;
}