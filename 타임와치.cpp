#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start);
void display_time(long nhour, long nmin, long nsecond);
void control_watch(void);

int main(void)
{
	display_time(0, 0, 0);
	getch();
	control_watch();
	return 0;
}
void control_watch(void)//Ű�� �Է¹޾Ƽ� ��ž��ġ���� 
{
   char key; //�Է¹��� ���� ���� 
   time_t start;//Ÿ���Լ��� start���� 
   start=time(NULL);//�ð�������� 
   time_pass(start);//time_pass�Լ��� ���ۺ��� ���� 
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 :
		time_pass(start);//���� ���۶Ǵ� ���� 
	   case 32 : 
		start=time(NULL);//�����̽��� �ʱ�ȭ 
		time_pass(start);//����� 
		break;
	   case 27 : 
		exit(0);//���� 
		break;
	}
   }while(key!=27);//esc ������ ���� 

}
void time_pass(time_t start)//���۽ð��� ����ð� ������ ���̰�� 
{
double hour, min, second;
long nhour, nmin, nsecond;
time_t now;
while(!kbhit())//Ű�� �Է��ϸ� ���� 
{
	now=time(NULL);//����ð� ���� 
	second=difftime(now, start);//�ð����� ��� �ʷκ�ȯ 
	hour= (second/3600.);//�ð����� ��ȯ 
	nhour= (long) hour;//�ð� Ÿ�Ժ�ȯ 
	min= fmod(second, 3600.)/60;//�ʸ� 3600���� ������������ ���ϱ�
	nmin= (long) min;//�� Ÿ�Ժ�ȯ 
	second= fmod(second, 60);//�ʸ� 60���γ��� ������ 
	nsecond= (long) second;//Ÿ�� 
	display_time(nhour, nmin, nsecond);//��ȯ�Ѱ����� ����Լ����־��� 
 }
}
void display_time(long nhour, long nmin, long nsecond)//��� 
{
	system("cls");//ȭ���� 
	printf("stopwatch\n\n");
	printf("%.2ld�� %.2ld�� %.2ld�� \n\n", nhour, nmin, nsecond);
	printf("Enter:(����/����), SPACE:�����, Esc:����\n");

}
