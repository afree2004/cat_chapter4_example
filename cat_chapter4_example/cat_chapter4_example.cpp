// cat_chapter4_example.cpp : 定义控制台应用程序的入口点。
//测试vs的git管理功能
//
#include "stdafx.h"

#include <stdio.h>
#include <math.h>                       /* 程序中调用绝对值函数 fabs()，需包含 math.h */

/* 【例4-1】使用格里高利公式求π的近似值 */
/*  用格里高利公式计算π的近似值，精度要求：最后一项的绝对值小于0.0001  */
int ex41_calculate_pai(void)
{
	int denominator, flag;
	double item, pi;                     /* pi 用于存放累加和 */

										 /* 循环初始化 */
	flag = 1;                            /* flag 表示第 i 项的符号，初始为正 */
	denominator = 1;                     /* denominator表示第 i 项的分母，初始为1 */
	item = 1.0;                          /* item 中存放第 i 项的值，初值取 1 */
	pi = 0;                              /* 置累加和 pi 的初值为0 */

	while (fabs(item) >= 0.0001) {         /* 当|item| ≥ 0.0001时，执行循环 */
		item = flag * 1.0 / denominator; /* 计算第 i 项的值 */
		pi = pi + item;                  /* 累加第 i 项的值 */
		flag = -flag;                    /* 改变符号，为下一次循环做准备 */
		denominator = denominator + 2;   /* 分母递增2 ，为下一次循环做准备 */
	}
	pi = pi * 4;                         /* 循环计算的结果是 pi/4 */
	printf("pi = %.4f\n", pi);

	return 0;
}

/* 【例4-2】更改例3-3。从键盘输入一批学生的成绩，计算平均成绩，并统计不及格学生的人数。 */
/* 输入一批学生的成绩，以负数作为结束标志，计算平均成绩，并统计不及格学生的人数 */
int ex42_caculate_achievment(void)
{
	int count, num;					/* num 记录输入的个数，count记录不及格学生人数 */
	double grade, total;			/* 分别存放成绩、成绩之和 */

	num = 0;
	total = 0;
	count = 0;
	printf("Enter grades: ");		/* 输入提示 */
	scanf("%lf", &grade);			/* 输入第一个数据，%lf中的l是字母 */

									/* 当输入数据 grad 大于等于0时，执行循环 */
	while (grade >= 0) {
		total = total + grade;		/* 累加成绩 */
		num++;						/* 计数 */
		if (grade < 60)
			count++;
		scanf("%lf", &grade);		/* 读入一个新数据，为下次循环做准备 */
	}
	if (num != 0) {
		printf("Grade average is %.2f\n", total / num);
		printf("Number of failures is %d\n", count);
	}
	else
		printf("Grade average is 0\n");

	return 0;
}

/* 【例4-3】从键盘读入一个整数，统计该数的位数。例如，输入12534，输出5；输入-99，输出2；输入0，输出1。*/
int ex43_count_bits(void)
{
	int count, number;                  /* count 记录整数number的位数 */

	count = 0;
	printf("Enter a number:");          /* 输入提示 */
	scanf("%d", &number);
	if (number < 0) number = -number;    /* 将输入的负数转换为正数 */
	do {
		number = number / 10;           /* 整除后减少一位个位数，组成一个新数 */
		count++;                        /* 位数加1 */
	} while (number != 0);                /* 判断循环条件 */
	printf("It contains %d digits.\n", count);

	return 0;
}

/* 【例4-4-1】输入一个正整数m，判断它是否为素数。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。*/
int ex441_judge_prime(void)
{
	int i, m;

	printf("Enter a number: ");  /* 输入提示 */
	scanf("%d", &m);
	for (i = 2; i <= m / 2; i++)  /* 第9行 */
		if (m % i == 0)
			break;               /* 若m能被某个i整除，则m不是素数，提前结束循环 */
	if (i > m / 2 && m != 1)      /* 若循环正常结束，说明m不能被任何一个i整除，则m是素数 */
		printf("%d is a prime number! \n", m);
	else
		printf("No!\n");         /* 第15行 */

	return 0;
}

/* 【例4-4-2】输入一个正整数m，判断它是否为素数。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。*/
int ex442_judge_prime(void)
{
	int i, flag, m;

	flag = 1;
	printf("Enter a number: ");  /* 输入提示 */
	scanf("%d", &m);
	if (m == 1) flag = 0;
	for (i = 2; i <= m / 2; i++)
		if (m % i == 0) {
			flag = 0;
			break;               /* 若m能被某个i整除，则m不是素数，提前结束循环 */
		}

	if (flag == 1)
		printf("%d is a prime number! \n", m);
	else
		printf("No!\n");

	return 0;
}

/* 【例4-5-1】改进例3-1简单的猜数游戏。输入你所猜的正整数（假定1~100内），与计算机产生的被猜数比较，若相等，显示猜中；若不等，显示与被猜数的大小关系，最多允许猜7次。 */
# include<stdlib.h>
# include<time.h>
int ex451_guess_number(void)
{
	int count = 0, flag, mynumber, yournumber;

	mynumber = 38; /* 计算机产生的被猜数 */
	flag = 0;	/* flag的值为0表示没猜中，为1表示猜中了*/
	for (count = 1; count <= 7; count++) {			/* 最多能猜7次*/
		printf("Enter your number: ");       /* 提示输入你所猜的整数 */
		scanf("%d", &yournumber);
		if (yournumber == mynumber) {     /* 若相等，显示猜中 */
			printf("Lucky You!\n");
			flag = 1;
			break;                       /* 已猜中，终止循环 */
		}
		else
			if (yournumber>mynumber)
				printf("Too big\n");
			else
				printf("Too small\n");
	}
	if (flag == 0) 	/* 超过7次还没猜中，提示游戏结束*/
		printf("Game Over!\n");

	return 0;
}

/* 【例4-5-2】改进例3-1简单的猜数游戏。输入你所猜的正整数（假定1~100内），与计算机随机产生的被猜数比较，若相等，显示猜中；若不等，显示与被猜数的大小关系，最多允许猜7次。 */
int ex452_guess_number(void)
{
	int count = 0, flag, mynumber, yournumber;
	srand(time(0));
	mynumber = rand() % 100 + 1; /* 计算机随机产生一个1~100之间的被猜数 */
	flag = 0;	/* flag的值为0表示没猜中，为1表示猜中了*/
	while (count < 7) {			/* 最多能猜7次*/
		printf("Enter your number: ");       /* 提示输入你所猜的整数 */
		scanf("%d", &yournumber);
		count++;
		if (yournumber == mynumber) {     /* 若相等，显示猜中 */
			printf("Lucky You!\n");
			flag = 1;
			break;                       /* 已猜中，终止循环 */
		}
		else
			if (yournumber>mynumber)
				printf("Too big\n");
			else
				printf("Too small\n");
	}
	if (flag == 0) 	/* 超过7次还没猜中，提示游戏结束*/
		printf("Game Over!\n");

	return 0;
}

/* 【例4-6】计算1! + 2! + 3! + … + 100!。要求定义和调用函数fact(n)计算n的阶乘。 */
/* 使用函数计算 1! + 2! + 3! + … + 100! */
double fact(int n);	/* 函数声明 */
int ex46_caculate_factorial_sum(void)
{
	int i;
	double sum;

	sum = 0;
	for (i = 1; i <= 100; i++)
		sum = sum + fact(i);						/* 调用fact(i)求i!，共重复100次 */
	printf("1! + 2! + ... + 100! = %e\n", sum);		/* 用指数形式输出结果 */

	return 0;
}
/* 定义求 n! 的函数 */
double fact(int n)
{
	int i;
	double result;                     /* 变量 result 中存放阶乘的值 */

	result = 1;                        /* 置阶乘 result 的初值为1 */
	for (i = 1; i <= n; i++)            /* 循环执行n次，计算n! */
		result = result * i;

	return  result;                    /* 把结果回送主函数 */
}

/* 【例4-7】计算1! + 2! + 3! + … + 100!。要求使用嵌套循环 */
/* 使用嵌套循环计算 1! + 2! + 3! + … + 100! */
int ex47_caculate_factorial_sum(void)
{
	int i, j;
	double item, sum;             /* 变量 item 中存放阶乘的值 */

	sum = 0;
	for (i = 1; i <= 100; i++) {    /* 外层循环执行100次，求累加和 */
		item = 1;				/* 置 item 的初值为1，以保证每次求阶乘都从1开始连乘 */
		for (j = 1; j <= i; j++)  /* 内层循环重复i次，算出item = i! */
			item = item * j;
		sum = sum + item;         /* 把 i! 累加到sum中 */
	}
	printf("1! + 2! + ... + 100! = %e\n", sum);   /* 用指数形式输出结果 */

	return 0;
}

/* 【例4-8-1】求最值问题。输入一批学生的成绩，找出最高分 */
/*  从输入的n个成绩中选出最高分，用for语句实现  */
int ex481_caculate_max(void)
{
	int i, mark, max, n;            /* max中放最高分 */

	printf("Enter n: ");            /* 输入提示 */
	scanf("%d", &n);                /* 输入数据个数 */
	printf("Enter %d marks: ", n);  /* 提示输入n个成绩 */
	scanf("%d", &mark);             /* 读入第一个成绩 */
	max = mark;          	        /* 假设第一个成绩是最高分 */
	for (i = 1; i < n; i++) {        /* 由于已经读了一个数，循环执行n-1次 */
		scanf("%d", &mark); 	    /* 读入下一个成绩 */
		if (max < mark)      	    /* 如果该成绩比最高分高 */
			max = mark;      	    /* 再假设该成绩为最高分 */
	}
	printf("Max = %d\n", max);

	return 0;
}

/* 【例4-8-2】求最值问题。输入一批学生的成绩，找出最高分。 */
/* 从输入的一批以负数结束的成绩中选出最高分，用while语句实现 */
int ex482_caculate_max(void)
{
	int mark, max;            	         /* max中放最高分 */

	printf("Enter marks:");    	         /* 输入提示 */
	scanf("%d", &mark);     	         /* 读入第一个成绩 */
	max = mark;            	             /* 假设第一个成绩是最高分 */
										 /*  当输入的成绩 mark 大于等于0时，执行循环 */
	while (mark >= 0) {
		if (max < mark)      	         /* 如果读入的成绩比最高分高 */
			max = mark;     	         /* 再假设该成绩为最高分 */
		scanf("%d", &mark); 	         /* 读入下一个成绩 */
	};
	printf("Max = %d\n", max);

	return 0;
}

/* 【例4-9】逆序问题。输入一个正整数，将其逆序输出。例如，输入12345，输出54321。*/
/* 逆序输出一个正整数 */
int ex49_caculate_backward_order(void)
{
	int x;

	printf("Enter x: ");           /* 输入提示 */
	scanf("%d", &x);
	while (x != 0) {
		printf("%d ", x % 10);
		x = x / 10;
	}

	return 0;
}

/* 【例4-10】素数问题。求100以内的全部素数，每行输出10个。素数就是只能被1和自身整除的正整数，1不是素数，2是素数。 */
/* 使用嵌套循环求100以内的全部素数 */
int ex410_caculate_prime(void)
{
	int count, i, m, n;

	count = 0;                      /* count记录素数的个数，用于控制输出格式 */
	for (m = 2; m <= 100; m++) {
		n = sqrt(m);
		for (i = 2; i <= n; i++)
			if (m % i == 0)
				break;
		if (i > n) {              /* 如果m是素数 */
			printf("%6d", m);       /* 输出m */
			count++;                /* 累加已经输出的素数个数 */
			if (count % 10 == 0)     /* 如果count是10的倍数，换行 */
				printf("\n");
		}
	}
	printf("\n");

	return 0;
}

/* 【例4-11】菲波那契数列问题。输出菲波那契（Fibonacci）序列的前10项：1，1，2，3，5，8，13，21，34，55。 */
/* 输出菲波那契序列：1，1，2，3，5，8，…的前10项 */
int ex411_caculate_fibonacci(void)
{
	int i, x1, x2, x;            /* x1和x2依次代表前两项，x表示其后一项 */

	x1 = 1;                      /* 头两项都是1 */
	x2 = 1;
	printf("%6d%6d", x1, x2);   /* 先输出头两项 */
	for (i = 1; i <= 8; i++) {     /* 循环输出后8项 */
		x = x1 + x2;             /* 计算新项 */
		printf("%6d", x);
		x1 = x2;                 /* 更新x1和x2，为下一次计算新项x作准备*/
		x2 = x;
	}
	printf("\n");

	return 0;
}

/* 【例4-12-1】穷举算法。（中国古典算术问题）某工地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬1块。有多少种搬法用45人正好搬45块砖？ */
/* 45人正好搬45块砖，程序版本1 */
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

/* 【例4-12-2】穷举算法。（中国古典算术问题）某工地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬1块。有多少种搬法用45人正好搬45块砖？ */
/* 45人正好搬45块砖，程序版本2 */
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

