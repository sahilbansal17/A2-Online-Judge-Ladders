#include <bits/stdc++.h>
using namespace std;

int main(){

	int length ;
	scanf("%d", &length);

	char to_be_checked[101];
	scanf("%s", to_be_checked);

	// a string is a pangram if it contains all the characters
	// of the alphabet (either in upper or lower case) of the language
	// atleast once 
	bool is_pangram = true;

	// make a hashtable 
	// for the count of the characters of the language
	// don't forget to initialize with "0"
	int count_character[26] = {0};

	for(int index = 0; index < length; index ++){
		char current = to_be_checked[index];
		if(current >= 'a' && current <= 'z'){
			// if in smaller case
			int char_index = current - 'a';
			count_character[char_index] ++;
		}
		else{
			// if in upper case
			int char_index = current - 'A';
			count_character[char_index] ++;
		}
	}

	// check if the hashtable has atleast one count
	// for each of the character
	// in other words
	// if atleast one character's count is zero
	// it can't be pangram, break then and there

	for(int char_index = 0; char_index < 26; char_index ++){
		if(count_character[char_index] == 0){
			is_pangram = false;
			break;
		}
	}

	if(is_pangram){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}