#include <cstdlib>
#include <iostream>
#include "complexityrecorder.h"
#include "complexitytimer.h"
using namespace std;

void sort(int arr[], int length);

int main() {
	timer t; 
	int sorted[10] = {0,1,2,3,4,5,6,7,8,9};
	int nearlySorted[10] = {1,0,2,3,4,5,6,7,8,9};
	int unsorted[10] = { 5,1,3,2,9,0,7,4,6,8};
	int veryUnsorted[10] = {9,8,7,6,5,4,3,2,1,0};
	int *test[4] = { sorted,nearlySorted,unsorted,veryUnsorted };
	vector<recorder<timer>> stats(4);
	for(int k = 0; k < 1000; k++){
		t.restart();
		for (int l = 0; l < 1000; l++) {
			sort(test[k], 10);
		}
		t.stop();
		stats[k].record(t);
	}
	return 0;
}

void sort(int arr[], int length) {
	for (int i = 0, j = 0; i < length; j = ++i) {
		int curr,next;
			while (j != 0 && arr[j-1] > arr[j]) {
				int curr = arr[j];
				arr[j] = arr[j - 1];
				arr[j-- - 1] = curr;
		}
	}
}
