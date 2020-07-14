#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void display_rule(void);
void gotoxy(int x, int y);
void make_treasure(int tx[], int ty[]);
void display_map(int matrix[][10], int tx[], int ty[]);
void basic_map(void);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void game_control(int tx[], int ty[]);

int main(void)
{
    int tx[2], ty[2]; 
	int matrix[10][10]={0};//���� �ʱ�ȭ 
    clock_t start, end;
    double pst;
    srand(time(NULL));
	make_treasure(tx, ty);//������ġ���� 
    display_rule();
    start=clock();
	system("cls");
    game_control(tx, ty);
    end=clock();
	pst=(double)(end-start)/CLK_TCK;
	gotoxy(1, 13);
	printf("��� �ð� : %.1f ��", pst);
	gotoxy(1, 14);
	printf("��� ã�ҽ��ϴ�. ������ �����մϴ�. \n");
	getch();
	return 0;
}

void display_rule(void)//���ӱ�Ģ ���� 
{
	gotoxy(1, 1);
	printf("����ã��");
	gotoxy(1,3);
	printf("�Ʒ��� �ٵ��� ����� ���ڿ��� ������ \n");
	gotoxy(1,4);
	printf("������ �ֽ��ϴ�. \n");
	gotoxy(1,5);
	printf("ȭ��ǥ(�����)Ű�� �������� ã���ϴ�. \n");
	gotoxy(1,7);
	basic_map();
	printf("\n�ƹ�Ű�� ������ �����մϴ�. \n");
	getch();
}

void basic_map(void)//�⺻���� ��� 
{
	int i, j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("��"); //���� ��� 10x10���� 
		printf("\n");
	}
}


void make_treasure(int tx[], int ty[])//������ġ ���� 
{
	int i;
    for(i=0;i<2;i++)//��2���� ���� ���� 
    {
		do
		{
			tx[i]=rand()%11; //������ x��ǥ
			ty[i]=rand()%11; //������ y��ǥ
		}while((tx[i]<=1) || (ty[i]<=1));  
     }
}



void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void display_map(int matrix[][11], int tx[], int ty[])
{//������ ���� ���¸� ��� 
	int i, j;
	basic_map();
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if (matrix[i][j]==1)//�������� ����� 
			{
				gotoxy(2*i-1, j);
				printf("��");
			}
			else if (matrix[i][j]==2)//������ġ�ΰ��� �� 
			{
				gotoxy(2*i-1, j);
				printf("��");
			}	
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
		*x1=*x1-2;            //x��ǥ�� ���Ұ�
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //x��ǥ�� ������
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪
		break;
	default:
		return;
	}
}

void game_control(int tx[], int ty[])
{
	char key;
	int i, j, count=0;
	int x=1, y=1;
	int matrix[11][11]={0};//���� �ʱ�ȭ 
	do
	{
		gotoxy(x, y);
		printf("��");
		matrix[(x+1)/2][y]=1;//Ŀ���� �������� 1 

		for(i=0;i<2;i++)
			if (((x+1)/2==tx[i]) && (y==ty[i]))
				matrix[(x+1)/2][y]=2;//������ġ�������� 2 

		gotoxy(1, 1);
		display_map(matrix, tx, ty);//�߰�ȣ�� 

		count=0;
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if (matrix[i][j]==2)
					count=count+1;//ã������ī��Ʈ 
		gotoxy(1,12);
   		printf("ã�� ����(��)�� ���� : %d", count);
		key=getch();
		move_arrow_key(key, &x, &y, 19, 10);
	}while(count<2);
}
