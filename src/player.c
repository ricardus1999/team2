#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist.h"
#include "textfilewriter.h"

void read_command(char* cmd);

int main() {
	int songNumber;
	Node* songName;
	int cmdNumber;
	char cmd[5];
	Node** musictitle = NULL;



	scanf("%d", &songNumber);
	musictitle = (Node**)malloc(sizeof(Node*) * songNumber);
	for(int i=0; i<songNumber; i++){
		musictitle[i] = (Node*)malloc(sizeof(Node) * 10);
	}
	for(int i=0; i<songNumber; i++){
		scanf("%s", songName->data);
		if(i==0){
			musictitle[i]->prev = _head;}
		else{
			musictitle[i]->prev = musictitle[i-1];}
		musictitle[i]->data = songName->data;
		if(i == songNumber-1){
			musictitle[i]->next = _tail;}
		else{
			musictitle[i]->next = musictitle[i+1];
		}
	}
	char* ms;
	int index;
	
	scanf("%d", cmdNumber);
	for(int i=0; i<cmdNumber; i++){
		scanf("%s", cmd);
		switch(read_command(cmd)){
			case 1:
				scanf("%s", ms);
				append(strlen(ms), ms);
				break;
			case 2:
				scanf("%s", ms);
				delete(ms)
				break;
			case 3:
				print();
				break;
				
			case 4:
				next();
				break;
			case 5:
				prev();
				break;
			case 6:
				scanf("%d", &index);
				insert_after(index);
				break;
			case 7:
				print();
				return 0;
				break;
			case 8:
				clear();
				break;
			case 9:
				clear();
				return 0;
				break;
			case 10:
				scanf("%s", ms);
				break;
			case 11:
				scanf("%s", ms);
				break;
		}
	}
}
				
			
void read_command(char* cmd) {
	if(!strcmp(command, "add"))        { return 1; } 
	else if(!strcmp(command, "del"))   { return 2; } 
	else if(!strcmp(command, "list"))  { return 3; }
   	else if(!strcmp(command, "next"))  { return 4; }
    	else if(!strcmp(command, "prev"))  { return 5; }
    	else if(!strcmp(command, "move"))  { return 6; } 
    	else if(!strcmp(command, "play"))  { return 7; }
    	else if(!strcmp(command, "clear")) { return 8; }
    	else if(!strcmp(command, "quit"))  { return 9; }
    	else if(!strcmp(command, "load"))  { return 10; } 
    	else return 11;
}
