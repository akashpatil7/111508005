#include <stdio.h>
#include <stdlib.h>

int And(int *p,int n){
	int i,opt;
	for(i = 0;i < n; i++){
		opt = (p[i] && p[i+1]);
		p[i+1] = opt;	
	}
	return p[n-1];
}

int Or(int *p,int n){
	int i,opt;
	for(i = 0;i < n; i++){
		opt = (p[i] || p[i+1]);
        	p[i+1] = opt;
	}
	return p[n-1];
}			    

int Not(int n){
	int output;
	if (n == 0)
		output = 1;
	else
		output = 0;
	return output;
}

int Nand(int *p,int n){
	return Not(And(p,n));
}

int Nor(int *p,int n){
	return Not(Or(p,n));
}

int Xor(int *p,int n){
	int i,opt,count = 0;
	for(i = 0;i < n; i++){
		if(p[i] == 1)
			count++;
	}
	if(count % 2 == 0)
		opt = 0;
	else
		opt = 1;
	return opt;
}

int Xnor(int *p,int n){
	return Not(Xor(p,n));
}

int main(){
int n,x;
int *p;
printf("Enter the number of inputs: ");
scanf("%d",&n);
p = (int *)malloc(sizeof(int) * n);
for(x = 0; x < n; x++)
	scanf("%d",&p[x]);
printf("%d\n",Xnor(p,n));
}
