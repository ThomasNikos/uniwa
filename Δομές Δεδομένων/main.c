#include <stdio.h>
#include <stdlib.h>

struct Student{
	int id;
	int grd;
};

int nn(struct Student first[],struct Student sec[],int n,int k,int *d);

int main(){
	int i,d=0;
	struct Student first[10];	
	struct Student sec[10];	
	for(i=0;i<10;i++){
		first[i].grd=10;
		sec[i].grd=9;
	}
	nn(first,sec,10,10,&d);
	printf("%d",first[d].grd);
	return 0;
}

int nn(struct Student first[],struct Student sec[],int n,int k,int *d){
	int i,sum=0;
	
	for(i=0;i<n;i++){
		if(first[i].grd==4,5){
			first[i].grd = 5;
		}
		if(sec[i].grd==4,5){
			sec[i].grd = 5;
		}
	}
	for(i=0;i<n;i++){
		if(first[i].grd>=5){
			sum++;
		}
		if(first[i].grd>=5){
			sum++;
		}
	}
	if(sum/(100)*(n+k)<(70/100)*(n+k))
		return 0;
	else{
		for(i=0;i<n;i++){
			if(first[i].grd==10){
				return *d=i;
			}
			if(sec[i].grd==10){
				return *d=i;
			}
		}
	}
	return 0;
}
		


	


