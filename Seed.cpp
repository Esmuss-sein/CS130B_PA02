//Yu Yao
//PA02 for CS130B with professor Lokshtanov
//Going to Seed
//Analysis: The problem takes an input of at most 10^9 and requires to be done within 16 steps. So by two person, we can divide the trees into four parts: (0,0),(0,1),(1,0),(1,1), 4^16 > 10^9, so we should be able to make the problem to a small one that we can conquer. 
//Input: An integer n representing the number of trees.
//Output: The place of the great seedling. 
//

#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	//Declare variables and read n;
	int n,w_1,w_2,L,R;
	scanf("%d", &n);

	L = 1;
	R = n;
	//Find within 16 times.
	for(int i = 0; i < 16; i++){
		//find span (range) of possible trees.
		int span = R - L + 1;
		if(span == 2){
			printf("Q %d %d %d %d \n", L,L,R,R);
			cout.flush();
			scanf("%d %d", &w_1,&w_2);

			if(w_1 == 1){
				printf("A %d\n", L);
			}
			else{
				printf("A %d\n",R);
			}
			cout.flush();
			break;
		}//If only two trees, no need more observatiion. Break the loop and cout solution.
		else if(span == 3){
			printf("Q %d %d %d %d", L,L,L+1,L+1);
			cout.flush();
			scanf("%d %d", &w_1,&w_2);
			if(w_1 == 1){
				printf("A %d\n", L);
			}
			else if(w_2 == 1){
				printf("A %d\n", L+1);
			}
			else{
				printf("A %d\n", R);
			}
			cout.flush();
			break;
		}//Similar if span is 3. 
		else{
			int p_0 = L, p_25 = L+span/4, p_50 = L + span/2, p_75 = L + span/2+span/4, p_1 = R;//Set the points on 1/4, 1/2, 3/4, which divide the span into four equal parts. 

			printf("Q %d %d %d %d\n", p_0, p_50-1, p_25, p_75-1);
			cout.flush();

			scanf("%d %d",&w_1,&w_2);
			if(w_1 == 0 && w_2 == 0){
				L = p_75;
			}
			else if(w_1 == 0 && w_2 == 1){
				L = p_50;
				R = p_75-1;
			}
			else if(w_1 == 1 && w_2 == 0){
				R = p_50-1;
			}
			else if(w_1 == 1 && w_2 == 1){
				L = p_25;
				R = p_50-1;
			}
		}

		if(L == R){
			printf("A %d\n", L);
			cout.flush();
			break;
		}
	}
	return 0;
}



