#include <stdio.h> //����� �ش����� ���� 
#include <stdlib.h>//����� �ش����� ���� 
#include <conio.h>//����� �ش����� ���� 
#include <windows.h>//����� �ش����� ���� 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); //����� �Լ��� ������ ���� �����Ѵ� 
void gotoxy(int x, int y); //����� �Լ��� ������ ���� �����Ѵ� 
void draw_check01(int c, int r);//����� �Լ��� ������ ���� �����Ѵ� 
void game_control(void);//����� �Լ��� ������ ���� �����Ѵ� 

int main(void)//���α׷��� ����ɸ��εǴ�  �Լ� ���� 
{
	game_control();//�Լ���� 
	return 0;//���� �������� �ش��Լ��� ���������� ����ڴٴ� ��� 
}

void gotoxy(int x, int y)//int Ÿ�� x,y�� �Ű������� ���� �Լ� ���� 
{	//Ŀ���� ��ġ �ٲٴ� �Լ� 

   COORD Pos = {x - 1, y - 1}; //#include <windows.h>�� �ش����Ͽ��ִ� �Լ��� ����� Ŀ���� ��ġ�� �ٲ۴� 
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//#include <windows.h>�� �ش����Ͽ��ִ� �Լ��� ����� Ŀ���� ��ġ�� �ٲ۴� 
}

void draw_check01(int c, int r) //�ٵ����� �׸��� �Լ� 
{ 
    int i, j;
    unsigned char a=0xa6;//�Ϲ� ĳ���ʹ� -127~127������ �����ĳ���ʹ� ǥ���� 0~255�����Ҽ��ִ� Ư�����ڸ� ����ϱ����� ������ �����Ѵ�. 
    unsigned char b[12]; //�Ϲ� ĳ���ʹ� -127~127������ �����ĳ���ʹ� ǥ���� 0~255�����Ҽ��ִ� Ư�����ڸ� ����ϱ����� ������ �����Ѵ�. 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;//12���� ���δٸ� Ư�����ڸ� ��� 
    printf("%c%c",a, b[3]);//(��)���� ��� 
    for(i=0;i<c-1;i++)
	 printf("%c%c", a, b[8]);//(��)���� ��� 
    printf("%c%c", a, b[4]);//(��)��� 
    printf("\n");
    for(i=0;i<r-1;i++)//
    {
	printf("%c%c", a, b[7]);//(��)���� ��� 
	for(j=0;j<c-1;j++)
	   printf("%c%c", a, b[11]);//(+) ������ 
	printf("%c%c",a, b[9]);//(��)��� ��� 
	printf("\n");
    }
    printf("%c%c", a, b[6]);//(��)��� ��� 
    for(i=0;i<c-1;i++)
	printf("%c%c", a, b[10]);//(��)��� ��� 
    printf("%c%c", a, b[5]);//(���� �������ε�����)��� ��� 
    printf("\n");
     printf("\n");
      printf("\n");      
} 
void game_control(void)//�ٵ��ǿ� �ٵϵ� ǥ���Լ� �ٵ���ũ�� �Է��Լ� 
{
    int x=1, y=1;  
    char key;
    do //�ؿ� �ݺ� 
    {
	gotoxy(1,1);//ó�� Ŀ�� ��ġ�� 0,0 ���� ���� 
	draw_check01(18, 18);//�ٵ����� ũ�� ���� 
	gotoxy(x, y);//ó�� Ŀ�� ��ġ�� 0,0���� ���� 
	printf("��");//�ٵϵ� ǥ�ø� 0,0���� 
	gotoxy(1, 20);//����Ű�� �����ÿ� �ؽ�Ʈ��  1,20���� 
	printf("����Ű�� �����ÿ�.");//����Ű�� �����ÿ� �ؽ�Ʈ��  1,20���� 
	key=getch();//Ű�����Է��� �޴´� 
	if (key==27) 
		exit(0);//Ű���尪 27�Է½� ���� 
	else if (key>=72)//Ű���� ����Ű �Է½� ������ 72���� ���� 
		move_arrow_key(key, &x, &y, 37, 19); //Ű�� �Է¹����� �����̴� �Լ����ٰ� �־��ش� �ڿ� 37 19�� �ִ밪 
   }while(1);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-2;             //������������ 2�� ����
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //������������ 2�� ����
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
		break;
	default:
		return;
	}
}

