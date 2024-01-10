#include <stdio.h>
#include <stdlib.h>
#define SIZE 21

int get_Number();
char figoures(int);
int checkwin(int,int []);

int main(int argc, char *argv[]) {
	srand (time (NULL));
	int i=0,player[SIZE],dealer[SIZE],p=0,d=0;
	dealer[0] = get_Number();
	printf("First card of dealer is %d\n",dealer[0]);
	d++;
	player[0] = get_Number();
	printf("First card of player is %d\n",player[0]);
	p++;
	player[1] = get_Number();
	printf("Second card of player is %d\n",player[1]);
	p++;
	if(checkwin(p,player)){
		return 1;
	}
	return 0;
}

int get_Number(){
	int x;
	x = (rand() %13) + 1;
	return x;
}

char figoures(int x){
	if(x == 11){
		return 'J';
	}else if(x == 12){
		return 'Q';
	}else if(x == 13){
		return 'K';
	}else{
		return x;
	}
}

int checkwin(int p,int player[]){
			if((player[0] + player[1])== 21){
				printf("Player gets 21. Player Wins!");
				return 1;
			}
		return 0;
}
