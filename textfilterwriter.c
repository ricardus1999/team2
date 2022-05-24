#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "textfilewriter.h"
#define MAX_NAME_SIZE 20

void create_music_titles(FILE* stream){
    //표준 입력이나 파일로 부터 곡명을 입력 받아 링크드 리스트로 playlist를 생성한다
    //1.Player.c 에서 파일명 입력받고 파일로 부터 곡명을 입력받고 노드에 append
    clear();
    stream = fopen((const char *) stream, "r");
    Node* now = first();
    for(int i=0; i<size(); i++) {
        char *new_data= (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
        fgets(new_data,MAX_NAME_SIZE,stream);
        append(1,(char *)new_data); //이러면 playlist 생성되나?
        now = now->next; // 이러면 노드를 도나?
    }

    fclose(stream);
}

void read_file(char* file_name){
    //Player.c 에서 if cmd==load 라면 1.파일에 저장된 내용을 읽음 2. 재생 목록을 생성함.


    //1. 파일명(문자열)읽고 파일명에 저장된 재생 목록 내용을 읽기
    //파일명은 Player.c에서 받고 매개변수로 넘길것.
    //Linkedlist.c 에 있는 void print_file을 이용
    FILE *fp_readfile = fopen(file_name,"r");
    print_file(fp_readfile);


    //2. 재생 목록을 생성하기.
    //Linkedlist.c 에 있는 clear() 함수로 재생 목록 초기화 후에 append로 재생목록에 추가

    //size()가 size()안에서 파일안에 있는 노래 수를 카운트하나??
    //append에서 노래명 입력?? -> read_file 안에서 받아야할듯
    //append에서 size()만큼 new_data를 입력하나?
    //아니면 size()만큼 read_file에서 루프를 돌아야하나?
    clear();
    char *new_data= (char *)malloc(sizeof(char) * MAX_NAME_SIZE);
    fgets(new_data,MAX_NAME_SIZE,fp_readfile);
    append(size(),(char *)new_data);
    fclose(fp_readfile);

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

}
