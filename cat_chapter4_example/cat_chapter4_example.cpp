// cat_chapter4_example.cpp : �������̨Ӧ�ó������ڵ㡣
//����vs��git������
//
#include "stdafx.h"

#include <stdio.h>
#include <math.h>                       /* �����е��þ���ֵ���� fabs()������� math.h */

/* ����4-1��ʹ�ø��������ʽ��еĽ���ֵ */
/*  �ø��������ʽ����еĽ���ֵ������Ҫ�����һ��ľ���ֵС��0.0001  */
int ex41_calculate_pai(void)
{
	int denominator, flag;
	double item, pi;                     /* pi ���ڴ���ۼӺ� */

										 /* ѭ����ʼ�� */
	flag = 1;                            /* flag ��ʾ�� i ��ķ��ţ���ʼΪ�� */
	denominator = 1;                     /* denominator��ʾ�� i ��ķ�ĸ����ʼΪ1 */
	item = 1.0;                          /* item �д�ŵ� i ���ֵ����ֵȡ 1 */
	pi = 0;                              /* ���ۼӺ� pi �ĳ�ֵΪ0 */

	while (fabs(item) >= 0.0001) {         /* ��|item| �� 0.0001ʱ��ִ��ѭ�� */
		item = flag * 1.0 / denominator; /* ����� i ���ֵ */
		pi = pi + item;                  /* �ۼӵ� i ���ֵ */
		flag = -flag;                    /* �ı���ţ�Ϊ��һ��ѭ����׼�� */
		denominator = denominator + 2;   /* ��ĸ����2 ��Ϊ��һ��ѭ����׼�� */
	}
	pi = pi * 4;                         /* ѭ������Ľ���� pi/4 */
	printf("pi = %.4f\n", pi);

	return 0;
}

/* ����4-2��������3-3���Ӽ�������һ��ѧ���ĳɼ�������ƽ���ɼ�����ͳ�Ʋ�����ѧ���������� */
/* ����һ��ѧ���ĳɼ����Ը�����Ϊ������־������ƽ���ɼ�����ͳ�Ʋ�����ѧ�������� */
int ex42_caculate_achievment(void)
{
	int count, num;					/* num ��¼����ĸ�����count��¼������ѧ������ */
	double grade, total;			/* �ֱ��ųɼ����ɼ�֮�� */

	num = 0;
	total = 0;
	count = 0;
	printf("Enter grades: ");		/* ������ʾ */
	scanf("%lf", &grade);			/* �����һ�����ݣ�%lf�е�l����ĸ */

									/* ���������� grad ���ڵ���0ʱ��ִ��ѭ�� */
	while (grade >= 0) {
		total = total + grade;		/* �ۼӳɼ� */
		num++;						/* ���� */
		if (grade < 60)
			count++;
		scanf("%lf", &grade);		/* ����һ�������ݣ�Ϊ�´�ѭ����׼�� */
	}
	if (num != 0) {
		printf("Grade average is %.2f\n", total / num);
		printf("Number of failures is %d\n", count);
	}
	else
		printf("Grade average is 0\n");

	return 0;
}

/* ����4-3���Ӽ��̶���һ��������ͳ�Ƹ�����λ�������磬����12534�����5������-99�����2������0�����1��*/
int ex43_count_bits(void)
{
	int count, number;                  /* count ��¼����number��λ�� */

	count = 0;
	printf("Enter a number:");          /* ������ʾ */
	scanf("%d", &number);
	if (number < 0) number = -number;    /* ������ĸ���ת��Ϊ���� */
	do {
		number = number / 10;           /* ���������һλ��λ�������һ������ */
		count++;                        /* λ����1 */
	} while (number != 0);                /* �ж�ѭ������ */
	printf("It contains %d digits.\n", count);

	return 0;
}

/* ����4-4-1������һ��������m���ж����Ƿ�Ϊ��������������ֻ�ܱ�1��������������������1����������2��������*/
int ex441_judge_prime(void)
{
	int i, m;

	printf("Enter a number: ");  /* ������ʾ */
	scanf("%d", &m);
	for (i = 2; i <= m / 2; i++)  /* ��9�� */
		if (m % i == 0)
			break;               /* ��m�ܱ�ĳ��i��������m������������ǰ����ѭ�� */
	if (i > m / 2 && m != 1)      /* ��ѭ������������˵��m���ܱ��κ�һ��i��������m������ */
		printf("%d is a prime number! \n", m);
	else
		printf("No!\n");         /* ��15�� */

	return 0;
}

/* ����4-4-2������һ��������m���ж����Ƿ�Ϊ��������������ֻ�ܱ�1��������������������1����������2��������*/
int ex442_judge_prime(void)
{
	int i, flag, m;

	flag = 1;
	printf("Enter a number: ");  /* ������ʾ */
	scanf("%d", &m);
	if (m == 1) flag = 0;
	for (i = 2; i <= m / 2; i++)
		if (m % i == 0) {
			flag = 0;
			break;               /* ��m�ܱ�ĳ��i��������m������������ǰ����ѭ�� */
		}

	if (flag == 1)
		printf("%d is a prime number! \n", m);
	else
		printf("No!\n");

	return 0;
}

/* ����4-5-1���Ľ���3-1�򵥵Ĳ�����Ϸ�����������µ����������ٶ�1~100�ڣ��������������ı������Ƚϣ�����ȣ���ʾ���У������ȣ���ʾ�뱻�����Ĵ�С��ϵ����������7�Ρ� */
# include<stdlib.h>
# include<time.h>
int ex451_guess_number(void)
{
	int count = 0, flag, mynumber, yournumber;

	mynumber = 38; /* ����������ı����� */
	flag = 0;	/* flag��ֵΪ0��ʾû���У�Ϊ1��ʾ������*/
	for (count = 1; count <= 7; count++) {			/* ����ܲ�7��*/
		printf("Enter your number: ");       /* ��ʾ���������µ����� */
		scanf("%d", &yournumber);
		if (yournumber == mynumber) {     /* ����ȣ���ʾ���� */
			printf("Lucky You!\n");
			flag = 1;
			break;                       /* �Ѳ��У���ֹѭ�� */
		}
		else
			if (yournumber>mynumber)
				printf("Too big\n");
			else
				printf("Too small\n");
	}
	if (flag == 0) 	/* ����7�λ�û���У���ʾ��Ϸ����*/
		printf("Game Over!\n");

	return 0;
}

/* ����4-5-2���Ľ���3-1�򵥵Ĳ�����Ϸ�����������µ����������ٶ�1~100�ڣ�����������������ı������Ƚϣ�����ȣ���ʾ���У������ȣ���ʾ�뱻�����Ĵ�С��ϵ����������7�Ρ� */
int ex452_guess_number(void)
{
	int count = 0, flag, mynumber, yournumber;
	srand(time(0));
	mynumber = rand() % 100 + 1; /* ������������һ��1~100֮��ı����� */
	flag = 0;	/* flag��ֵΪ0��ʾû���У�Ϊ1��ʾ������*/
	while (count < 7) {			/* ����ܲ�7��*/
		printf("Enter your number: ");       /* ��ʾ���������µ����� */
		scanf("%d", &yournumber);
		count++;
		if (yournumber == mynumber) {     /* ����ȣ���ʾ���� */
			printf("Lucky You!\n");
			flag = 1;
			break;                       /* �Ѳ��У���ֹѭ�� */
		}
		else
			if (yournumber>mynumber)
				printf("Too big\n");
			else
				printf("Too small\n");
	}
	if (flag == 0) 	/* ����7�λ�û���У���ʾ��Ϸ����*/
		printf("Game Over!\n");

	return 0;
}

/* ����4-6������1! + 2! + 3! + �� + 100!��Ҫ����͵��ú���fact(n)����n�Ľ׳ˡ� */
/* ʹ�ú������� 1! + 2! + 3! + �� + 100! */
double fact(int n);	/* �������� */
int ex46_caculate_factorial_sum(void)
{
	int i;
	double sum;

	sum = 0;
	for (i = 1; i <= 100; i++)
		sum = sum + fact(i);						/* ����fact(i)��i!�����ظ�100�� */
	printf("1! + 2! + ... + 100! = %e\n", sum);		/* ��ָ����ʽ������ */

	return 0;
}
/* ������ n! �ĺ��� */
double fact(int n)
{
	int i;
	double result;                     /* ���� result �д�Ž׳˵�ֵ */

	result = 1;                        /* �ý׳� result �ĳ�ֵΪ1 */
	for (i = 1; i <= n; i++)            /* ѭ��ִ��n�Σ�����n! */
		result = result * i;

	return  result;                    /* �ѽ������������ */
}

/* ����4-7������1! + 2! + 3! + �� + 100!��Ҫ��ʹ��Ƕ��ѭ�� */
/* ʹ��Ƕ��ѭ������ 1! + 2! + 3! + �� + 100! */
int ex47_caculate_factorial_sum(void)
{
	int i, j;
	double item, sum;             /* ���� item �д�Ž׳˵�ֵ */

	sum = 0;
	for (i = 1; i <= 100; i++) {    /* ���ѭ��ִ��100�Σ����ۼӺ� */
		item = 1;				/* �� item �ĳ�ֵΪ1���Ա�֤ÿ����׳˶���1��ʼ���� */
		for (j = 1; j <= i; j++)  /* �ڲ�ѭ���ظ�i�Σ����item = i! */
			item = item * j;
		sum = sum + item;         /* �� i! �ۼӵ�sum�� */
	}
	printf("1! + 2! + ... + 100! = %e\n", sum);   /* ��ָ����ʽ������ */

	return 0;
}

/* ����4-8-1������ֵ���⡣����һ��ѧ���ĳɼ����ҳ���߷� */
/*  �������n���ɼ���ѡ����߷֣���for���ʵ��  */
int ex481_caculate_max(void)
{
	int i, mark, max, n;            /* max�з���߷� */

	printf("Enter n: ");            /* ������ʾ */
	scanf("%d", &n);                /* �������ݸ��� */
	printf("Enter %d marks: ", n);  /* ��ʾ����n���ɼ� */
	scanf("%d", &mark);             /* �����һ���ɼ� */
	max = mark;          	        /* �����һ���ɼ�����߷� */
	for (i = 1; i < n; i++) {        /* �����Ѿ�����һ������ѭ��ִ��n-1�� */
		scanf("%d", &mark); 	    /* ������һ���ɼ� */
		if (max < mark)      	    /* ����óɼ�����߷ָ� */
			max = mark;      	    /* �ټ���óɼ�Ϊ��߷� */
	}
	printf("Max = %d\n", max);

	return 0;
}

/* ����4-8-2������ֵ���⡣����һ��ѧ���ĳɼ����ҳ���߷֡� */
/* �������һ���Ը��������ĳɼ���ѡ����߷֣���while���ʵ�� */
int ex482_caculate_max(void)
{
	int mark, max;            	         /* max�з���߷� */

	printf("Enter marks:");    	         /* ������ʾ */
	scanf("%d", &mark);     	         /* �����һ���ɼ� */
	max = mark;            	             /* �����һ���ɼ�����߷� */
										 /*  ������ĳɼ� mark ���ڵ���0ʱ��ִ��ѭ�� */
	while (mark >= 0) {
		if (max < mark)      	         /* �������ĳɼ�����߷ָ� */
			max = mark;     	         /* �ټ���óɼ�Ϊ��߷� */
		scanf("%d", &mark); 	         /* ������һ���ɼ� */
	};
	printf("Max = %d\n", max);

	return 0;
}

/* ����4-9���������⡣����һ��������������������������磬����12345�����54321��*/
/* �������һ�������� */
int ex49_caculate_backward_order(void)
{
	int x;

	printf("Enter x: ");           /* ������ʾ */
	scanf("%d", &x);
	while (x != 0) {
		printf("%d ", x % 10);
		x = x / 10;
	}

	return 0;
}

/* ����4-10���������⡣��100���ڵ�ȫ��������ÿ�����10������������ֻ�ܱ�1��������������������1����������2�������� */
/* ʹ��Ƕ��ѭ����100���ڵ�ȫ������ */
int ex410_caculate_prime(void)
{
	int count, i, m, n;

	count = 0;                      /* count��¼�����ĸ��������ڿ��������ʽ */
	for (m = 2; m <= 100; m++) {
		n = sqrt(m);
		for (i = 2; i <= n; i++)
			if (m % i == 0)
				break;
		if (i > n) {              /* ���m������ */
			printf("%6d", m);       /* ���m */
			count++;                /* �ۼ��Ѿ�������������� */
			if (count % 10 == 0)     /* ���count��10�ı��������� */
				printf("\n");
		}
	}
	printf("\n");

	return 0;
}

/* ����4-11���Ʋ������������⡣����Ʋ�������Fibonacci�����е�ǰ10�1��1��2��3��5��8��13��21��34��55�� */
/* ����Ʋ��������У�1��1��2��3��5��8������ǰ10�� */
int ex411_caculate_fibonacci(void)
{
	int i, x1, x2, x;            /* x1��x2���δ���ǰ���x��ʾ���һ�� */

	x1 = 1;                      /* ͷ�����1 */
	x2 = 1;
	printf("%6d%6d", x1, x2);   /* �����ͷ���� */
	for (i = 1; i <= 8; i++) {     /* ѭ�������8�� */
		x = x1 + x2;             /* �������� */
		printf("%6d", x);
		x1 = x2;                 /* ����x1��x2��Ϊ��һ�μ�������x��׼��*/
		x2 = x;
	}
	printf("\n");

	return 0;
}

/* ����4-12-1������㷨�����й��ŵ��������⣩ĳ������Ҫ����ש�飬��֪����һ�˰�3�飬Ů��һ�˰�2�飬С�����˰�1�顣�ж����ְᷨ��45�����ð�45��ש�� */
/* 45�����ð�45��ש������汾1 */
int ex4121_caculate_himmer(void)
{
	int child, men, women;

	for (men = 0; men <= 45; men++)
		for (women = 0; women <= 45; women++)
			for (child = 0; child <= 45; child++)
				if (men + women + child == 45 && men * 3 + women * 2 + child*0.5 == 45)
					printf("men=%d,women=%d,child=%d\n", men, women, child);

	return 0;
}

/* ����4-12-2������㷨�����й��ŵ��������⣩ĳ������Ҫ����ש�飬��֪����һ�˰�3�飬Ů��һ�˰�2�飬С�����˰�1�顣�ж����ְᷨ��45�����ð�45��ש�� */
/* 45�����ð�45��ש������汾2 */
int ex4122_caculate_himmer(void)
{
	int child, women, men;

	for (men = 0; men <= 15; men++)
		for (women = 0; women <= 22; women++) {
			child = 45 - women - men;
			if (men * 3 + women * 2 + child * 0.5 == 45)
				printf("men=%d,women=%d,child=%d\n", men, women, child);
		}

	return 0;
}

int main(void)
{
	ex41_calculate_pai();
	//ex42_caculate_achievment();
	//ex43_count_bits();
	//ex441_judge_prime();
	//ex442_judge_prime();
	//ex451_guess_number();
	//ex452_guess_number();
	//ex46_caculate_factorial_sum();
	//ex47_caculate_factorial_sum();
	//ex47_caculate_factorial_sum();
	//ex481_caculate_max();
	//ex482_caculate_max();
	//ex49_caculate_backward_order();
	//ex410_caculate_prime();
	//ex411_caculate_fibonacci();
	//ex4121_caculate_himmer();
	//ex4122_caculate_himmer();
	return 0;
}

