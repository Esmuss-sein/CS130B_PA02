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

	int n,w_1,w_2,L,R;
	scanf("%d", &n);

	L = 1;
	R = n;

	for(int i = 0; i < 16; i++){
		int span = R - L + 1;
		int p_0 = L, p_25 = L+span/4, p_50 = L + span/2, p_75 = L + 3*span/4, p_1 = R;
		
		printf("Q %d %d %d %d\n", p_0, p_50-1, p_25, p_75 - 1);
		cout.flush();
		
		scanf("%d,%d",&w1,&w2);
		if(w_1 == 0 && w_2 == 0){
			L = p_75;
		}
		else if(w_1 == 0 && w_2 == 1){
			L = p_50;
			R = p_75;
		}
		else if(w_1 == 1 && w_2 == 0){
			R = p_50;
		}
		else{
			L = p_25;
			R = p_50;
		}

		if(L == R){
			printf("A %d\n", L);
			cout.flash();
			break;
		}

		L = max (1, L-1);
		R = min (R+1, n);
	}
	return 0;
}



