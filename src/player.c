#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "node.h"
//#include "linkedlist.h"
//#include "textfilewriter.h"

int main(){
	
	int a,b;
	scanf("%d", &a);
	char new_data[100];
	for (int i=0;i<a;i++){
		scanf("%s", new_data);
		append(100, new_data);
	}

	scanf("%d", &b);
	for (int j=0;j<b;j++){
		int c;		
		char ch;
		scanf("%c", &ch);
		switch (ch){
			case 'add':
				char title[100];
				scanf("%s",title);
				append_left(100, title);
				break;
			case 'del':
				char title[100];
				scanf("%s",title);
				delete(title);
				break;
			case 'list':
				print();
				break;
			case 'next':
				next();
				break;
			case 'prev':
				prev();
				break;
			case 'move':
				scanf("%d", &c);
				for (int k=0;k<c;k++){
					_cur_node = _cur_node->next;
				}
				break;
			case 'play':
				printf("%s"is now playing!,_cur_node->data);
				break;
			case 'clear':
				clear();
				printf("LinkedList is cleared!");
				break;
			case 'quit':
				_cur_node = first_node;
				while(_cur_node !=NULL){
					delete_node();
				}
				printf("LinkedList is cleared!\nquit!");
				break;
			case 'load':
				char temp;
				scanf("%c",&temp);
				read_file(temp);
				break;
		}
	}
}
