#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "textfilewriter.h"
#define MAX_NAME_SIZE 20

void create_music_titles(FILE* stream){
    //표준 입력이나 파일로 부터 곡명을 입력 받아 링크드 리스트로 playlist를 생성한다
    //1.Player.c 에서 파일명 입력받고 파일로 부터 곡명을 입력받고 노드에 append
    char *name;
    clear();
    stream = fopen((const char *) stream, "r");
    Node* now = first();

    do {
        name = (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
        fgets(name,MAX_NAME_SIZE,stream);
        append(1,(char *)name);
        now = now -> next;

    } while(strcmp(name,"\0") != 0);
    free(name);
    fclose(stream);

}

void read_file(char* file_name){
    //Player.c 에서 if cmd==load 라면 1.파일에 저장된 내용을 읽음 2. 재생 목록을 생성함.


    //1. 파일명(문자열)읽고 파일명에 저장된 재생 목록 내용을 읽기
    //파일명은 Player.c에서 받고 매개변수로 넘길것.
    //Linkedlist.c 에 있는 void print_file을 이용
    FILE *fp_readfile = fopen(file_name,"r");
    char *name;
    //2. 재생 목록을 생성하기.
    //Linkedlist.c 에 있는 clear() 함수로 재생 목록 초기화 후에 append로 재생목록에 추가

    Node *now = first();
    do {
        name = (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
        fgets(name,MAX_NAME_SIZE,file_name);
        append(1,(char *)name);
        now = now -> next;
    } while(strcmp(name,"\0") != 0);

    free(name);
    fclose(fp_readfile);

    //load 함수
}

void write_file(char* file_name){
    //Player.c 에서 if cmd==save 라면
    //1.Player.c에서 파일명을 입력받고 파일은 "w"모드로 파일을 연다.
    //2.노드 돌면서 파일에 저장.


    //1. 파일명 읽고 "w"모드로 파일은 연다.
    FILE *fp_writefile = fopen(file_name,"w");

    //2.노드 돌면서 파일에 저장.
    //밑에 코드가 노드 도는건가??
    Node* now = first();
    for(int i=0; i<size(); i++) {
        fputs(now->data ,fp_writefile);
        now = now->next;
    }
    fclose(fp_writefile);

    //save 함수
}
