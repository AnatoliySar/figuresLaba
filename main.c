#include "list.h"
#include "log.h"

int main()
{
	logInfo = fopen("log_info.txt", "a");
	logDebug = fopen("log_debug.txt", "a");
	setlocale(LC_ALL, "Russian");
	double a1, b1, c1;
	Triangle tri;
	char vvod;
	int buffer;	
	Stack* stack = initiate_stack();
	while (1)
	{
		printf("������� ����� ������ ������� ������������ ");
		scanf("%lf %lf %lf", &a1, &b1, &c1);	// �� ������� ������ �������� \n (enter) - ������ �������� ������. ���� ��� �� ������� �� stdin, �� ��������� scanf ������ ��� �� ����
		while ((buffer = getchar()) != EOF && buffer != '\n'); //�������� �������� ������ stdin
		if ((a1 <= 0) || (b1 <= 0) || (c1 <= 0) || (a1 + b1 <= c1) || (b1 + c1 <= a1) || (a1 + c1 <= b1)) // �������� ������ �� ����������������� � ���������� ����������� ������������
		{
			printf("��� �� �����������");
		}
		else
		{
			tri.a = a1;
			tri.b = b1;
			tri.c = c1;
			push(stack, tri); // ���������� ������������ � ����
			printf("����������� ��������\n");
			log_info("a1 = %lf, b1 = %lf, c1 = %lf", a1, b1, c1);
			log_debug("a1 = %lf, b1 = %lf, c1 = %lf, &tri = %p, buffer = %d\nStack top adress: %p", a1, b1, c1, &tri, buffer, stack[stack->curr]);
		}
		printf("������ ������ ��� ���� �����������? ");
		scanf("%c", &vvod);
		log_debug("Vvod = %c", vvod);
		while ((buffer = getchar()) != -1 && buffer != '\n');
		if (vvod != 'y')
		{
			break;
		}
	}

	printf("\n���������� �����:\n");
	int i = stack->curr;
	for (i; i > 0; i--)
	{
		tri = pop(stack);
		log_info("����������� %d: p = %lf, s = %lf.", i, perimetr(tri), ploshad(tri));
		log_debug("����������� %d: p = %lf, s = %lf.\nStack top adress: %p", i, perimetr(tri), ploshad(tri), stack[stack->curr]);
		printf("����������� %d: p = %lf, s = %lf.\n", i, perimetr(tri), ploshad(tri));
	}
	fwrite("\nLog end\n\n", 1, 12, logInfo);
	fwrite("\nLog end\n\n", 1, 12, logDebug);
	fclose(logInfo);
	fclose(logDebug);
	return 0;
}