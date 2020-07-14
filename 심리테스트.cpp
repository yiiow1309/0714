#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
char sol[10][11];  //������� �Է� ���� ������ �迭
int main(void)
{
	intro_game();
	display_question();
	printf("\n����Ǯ�̰� ��� �������ϴ�.\n");
	printf("\n\nǮ�̸� ������ �ƹ�Ű�� �����ÿ�.");
	getch();
	display_result();
	return 0;
}

void gotoxy(int x, int y)//Ŀ�� ��ġ�̵��Լ� 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_text(int count)//���÷��� ��� 
{
	gotoxy(1,2);
	printf("���� ������ �а� ���� �Է��Ͻÿ�.\n\n");
	printf("(%d�� ����) \n\n", count+1);

}
void display_question(void)//������� 
{
	FILE *fp1;//�����Լ� 
	char chr1[82];//�迭���� 
	int line=5, count=0;//���ΰ� ī��Ʈ���� ���� 
	char *file1="�ɸ��׽�Ʈ����.txt";//���Ͽ��� 
	fp1=fopen(file1, "r");//���Ͽ��� 
	system("cls");
	while(!feof(fp1))//fp1���� ���� �����Ҷ����� �ݺ� 
	{
		fgets(chr1, 80, fp1);//fp1���Ͽ��� 80�ھ����ڸ� chr1�� �Է� 
		if (chr1[0]==10)//80�ھ�  �޴ٰ� ������(10)��������  
		{
			display_text(count);
			gotoxy(1, line);
			scanf("%s", sol[count]);
			system("cls");
			line=5;
			count++;
		}
		else//�Լ����� 
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	display_text(count);
	gotoxy(1, line);
	scanf("%s", sol[count]);
	fclose(fp1);//���ϴݴ´� 

}
void display_result(void)//����� ��� 
{
	FILE *fp2;
	char chr1[82];
	int line=5, count=0;
	char *file2="�ɸ��׽�Ʈ�ؼ�.txt";
	fp2=fopen(file2, "r");
	system("cls");
	while(!feof(fp2))
	{
		fgets(chr1, 80, fp2);
		if (chr1[0]==10)
		{
			gotoxy(1, line+1);
			printf("����� ���� : %s\n", sol[count]);
			printf("���������� �ؼ��� �ƹ�Ű�� �����ÿ�.");
			getch();
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	gotoxy(1, line+1);
	printf("����� ���� : %s\n", sol[count]);
	fclose(fp2);

}
void intro_game(void)//���� �Ұ� 
{
	system("cls");
	printf("�ɸ��׽�Ʈ ����\n\n");
	printf("���õǴ� ������ ��� ���� �ϰ���\n");
	printf("�ؼ��� ��µ˴ϴ�.\n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�. ");
	getch();

}
