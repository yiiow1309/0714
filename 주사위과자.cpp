#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define cake_number 30  //������ ���� 

void intro_game(void);
void input_participant(char user_name[][8]);
void game_control(char name[][8], int condition[], int *left, int user, int *start, int *end);
void cake_display(char name[][8], int condition[], int left, int start, int end);
void gotoxy(int x, int y);

int main(void)
{
	int i, start, end, cake_left=cake_number, winner;
	int cake_condition[cake_number]={0};
	char user_name[2][8];//������ ��� ���� 
	srand(time(NULL));
   
	intro_game();
	input_participant(user_name);//2���� ������ �̸��Է� 

	start=0;
	end=cake_number-1;

	system("cls");
	game_control(user_name, cake_condition, &cake_left, 2,  &start, &end);  //user�� ���� 2�� �Ͽ� ������ �ʱ���¸� ���

	gotoxy(10, 12);
	printf("�ƹ�Ű�� ������ ���� ������ �����մϴ�. ");
	getch();
	do
	{
		for(i=0;i<2;i++)
		{
			system("cls");
			game_control(user_name, cake_condition, &cake_left, i, &start, &end);
			if (cake_left<2)
			{
				winner=i;
				break;
			}
			gotoxy(10, 12);
			printf("�ƹ�Ű�� ������ ���� ������ �����մϴ�. ");
			getch();
		}
	}while(cake_left>2);

	gotoxy(10, 12);
	printf("%s���� �̰���ϴ�. ", user_name[winner]);
	gotoxy(10, 13);
	printf("������ �����մϴ�. \n");
	return 0;
}

void intro_game(void)//���Ӽ��� 
{
	system("cls");
	printf("�ֻ����� ���ڸԱ� ���� \n\n");
	printf("�λ���� ���� �糡�� �ֻ��� ���ڸ�ŭ\n");
	printf("���ڸ� �Դ� �����Դϴ�. \n");
	printf("������ ���� ���ڸ� �Դ� ����� �̱�ϴ�. \n\n");
	printf("�ƹ�Ű�� ������ ���������ڸ�\n");
	printf("�Է��մϴ�.\n");
	getch();

}

void input_participant(char user_name[][8])//2���� ������ �̸��Է� 
{
	system("cls");
	printf("1�� �������� �̸��� �Է��ϰ� Enter>");
	scanf("%s", user_name[0]);
	printf("2�� �������� �̸��� �Է��ϰ� Enter>");
	scanf("%s", user_name[1]);
	printf("�ƹ�Ű�� ������ ������ �����մϴ�...");
	getch();

}
void game_control(char name[][8], int condition[],  int *left, int user, int *s, int *e)
{//�������� 
	int i, dice_number;
	cake_display(name, condition, *left, *s, *e);

	if (user==2)
		return;  //user�� 2�� �Ǵ� ���� main���� ���� 
	dice_number=rand()%6+1;  //�ֻ��� ���� ����
	*left-=dice_number;//left�����ͺ����� �������� ���� 
	gotoxy(10, 11);
        printf("%s���� �ֻ��� ���ڴ� %d�Դϴ�.",name[user],dice_number); 
			
	if (user==0)//�ش������ �����ڿ����� �������� ��� 
	{
		for(i=*s;i<dice_number+*s;i++)
			condition[i]=1;
		*s+=dice_number;
	}
	else//�ش������ �����ڿ����� �������� ���
	{
		for(i=*e;i>(*e-dice_number);i--)
			condition[i]=1;
		*e-=dice_number;
	}
	cake_display(name, condition, *left, *s, *e);
}
void cake_display(char name[][8], int condition[], int left, int s, int e)
{//�Ծ��ų� �����ִ� ���ڸ� ǥ�� 
	int i;
	char *eat_cake="��", *remain_cake="��";

	gotoxy(30,5);
	if (left<0)
		left=0;
	printf("���� ������ �� : %2d �� ", left);

	for(i=0;i<2;i++)
	{
		gotoxy(i*50+10, 6);
		printf("%s", name[i]);
	}

	for(i=0;i<30;i++)//�������ڴ� condition���� 1�̵Ǵ°��  
		if (condition[i]==1)
		{
			gotoxy(10+i*2, 8);
			printf("%s", eat_cake);
		}
		else//�������ڴ� condition���� 0�̵Ǵ°�� 
		{
			gotoxy(10+i*2, 8);
			printf("%s", remain_cake);
		}

	gotoxy(10, 9);
	printf("���� ���� ��: %2d", s);
	gotoxy(52, 9);
	printf("���� ���� ��: %2d", 29-e);
}

void gotoxy(int x, int y)//Ŀ����ġ ���� 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
