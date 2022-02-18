#include<iostream>
#include <set>

using namespace std;

int count(int data[], int idx){
	int count=0, s=0;
	set<int> mySet;
	for(int i=0; i<idx; i++){
		s=0;
		for(int j=i; j<idx; j++){
			if(data[j]==data[i]){
				s++;
			}

		}
		if(s==1){
			mySet.insert(data[i]);
			count++;
		}
	}
	return count;
}

int main(){	
	int data[] = {1,2,4,5,4,8,2,1,2,4,6,1,4,4,4,2,1,0,12}; 
	
	cout << "There are " << count(data,sizeof(data)/sizeof(int)); 
	cout << " different numbers in data.";
	
	return 0;
}
