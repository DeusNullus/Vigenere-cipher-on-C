#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void cyphr(char x[],char k[]);
int alp_to_ind(char x);
void decyph(char x[],char k[]);
char cyphrated[100];
char decyphh[100];
int main(int n,char*v[]){
		int cypher = 0;
		int decypher = 0;
		if(strcmp(v[1],"cyph")==0&&v[2]!=NULL){
			cypher = 1;
		}else if(strcmp(v[1],"decyph")==0&&v[2]!=NULL){
			decypher = 1;
		}else{
			printf("You must enter cyph or decyph as a flag to programm and word with you wannt to operate\n");
		}
		printf("Enter your secret key\n");
		int x = strlen(v[2]);
		char scn[x];
		scanf("%s",scn);
		if(cypher==1){
			char* str= v[2];
			cyphr(str,scn);
			int lenn = strlen(cyphrated);
			printf("Your cyphred word is \n");
			for(int i = 0;i<lenn;i++){
				printf("%c\n", cyphrated[i]);
			}
		}
		if(decypher==1){
			char* str = v[2];
			decyph(str,scn);
			int lenn = strlen(decyphh);
			printf("Your decyphrated word is\n");
			for(int i = 0;i<lenn;i++){
				printf("%c\n", decyphh[i]);
			}
		}

		return 0;
}
void cyphr(char x[],char k[]){
	char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int lenx = strlen(x);
	int lenk = strlen(k);
	for(int i = 0;strlen(k)<lenx;i++){
		k[lenk+i]=k[i];
	}
	lenx = strlen(x);
	lenk = strlen(k);
	//char cyphred[lenx];
	for(int i = 0;i<lenx;i++){
		int ind_x = alp_to_ind(x[i]);
		int ind_k = alp_to_ind(k[i]);
		int ind = ind_x+ind_k;
		cyphrated[i]=alp[ind];
	}
}

void decyph(char x[],char k[]){
	char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int strx = strlen(x);
	int strk = strlen(k);
	for(int i = 0;strlen(k)<strx;i++){
		k[strk+i]=k[i];
	}
	int lenk = strlen(k);
	int lenx = strlen(x);
	int text[lenx];
	int key[lenk];
	for(int i = 0;i<lenx;i++){
		text[i]= alp_to_ind(x[i]);
		key[i]=alp_to_ind(k[i]);
	}
	for(int i = 0;i<lenx;i++){
		int ind=text[i]-key[i];
		decyphh[i]=alp[ind];
	}

}

int alp_to_ind(char x){
	char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int ind;
	for(int i = 0;i<26;i++){
		if(x == alp[i]){
			ind = i;
			i = 26;
		}
	}
	return ind;
}
