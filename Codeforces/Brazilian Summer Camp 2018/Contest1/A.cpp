#include <bits/stdc++.h>

using namespace std;

int a[50002], b[50002];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", a + i, b + i);
	}
	double area = 0.0;
	for(int i = 0; i < n - 1; ++i){
		area += 0.5 * (a[i] * b[i + 1] - a[i + 1] * b[i]);
	}
	printf("%.11f", area);
}