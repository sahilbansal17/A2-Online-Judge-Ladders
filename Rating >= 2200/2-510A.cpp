#include <bits/stdc++.h>
using namespace std;

int main(){

	int rows, cols;
	scanf("%d %d", &rows, &cols);

	// just observing the pattern row-wise 
	// we can take row_index modulo 4 
	// and print the pattern
	// since pattern repeats after every
	// 4th row

	for(int row_index = 0; row_index < rows; row_index ++){
		int mod_4 = row_index % 4;
		switch(mod_4){
			case 0:
				for(int col_index = 0; col_index < cols; col_index ++){
					printf("#");
				}
				printf("\n");
				break;
			case 1:
				for(int col_index = 0; col_index < cols - 1; col_index ++){
					printf(".");
				}
				printf("#\n");
				break;
			case 2:
				for(int col_index = 0; col_index < cols; col_index ++){
					printf("#");
				}
				printf("\n");
				break;

			case 3:
				printf("#");
				for(int col_index = 1; col_index < cols; col_index ++){
					printf(".");
				}
				printf("\n");
		}
	}
	return 0;
}