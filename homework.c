1. 结构体数组-学生记录排序
【问题描述】

从键盘中读入最多不超过50个学生的学生信息（包括空格隔开的学号、姓名、年龄）

【输入形式】

每次键盘读入最多不超过50个学生的学生信息：

第一行为学生人数；

后面每一行为空格隔开的学生学号、姓名、年龄，其中学号和年龄是整数。

【输出形式】

分别以姓名顺序（从低到高）和年龄顺序（从低到高）将学生信息输出，每行输出一位学生的信息，其中学号占3位，姓名占6位，年龄占3位。年龄相同时按姓名从低到高排序。两种顺序的输出结果用一行空行相隔。

【输入样例】

4

1 aaa 22

45 bbb 23

54 ddd 20

110 ccc 19

【输出样例】

     1    aaa     22      

  45     bbb     23    

110     ccc     19

  54     ddd     20                                      

 

110     ccc     19      

  54     ddd     20       

    1     aaa     22      

  45     bbb     23                          

【样例说明】

从键盘输入四个学生记录，分别按姓名和年龄排序并输出。

【评分标准】

分别以姓名顺序和年龄顺序输出学生信息


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
    int id;
    char name[20];
    int age;
};

int compareByName(const void *a, const void *b) {
    struct student *s1 = (struct student*)a;
    struct student *s2 = (struct student*)b;
    return strcmp(s1->name, s2->name);
}

int compareByAge(const void *a, const void *b) {
    struct student *s1 = (struct student*)a;
    struct student *s2 = (struct student*)b;
    if(s1->age != s2->age) return s1->age - s2->age;
    return strcmp(s1->name, s2->name);
}

int main(void) {
    struct student students[50];
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
    }
    
    qsort(students, n, sizeof(struct student), compareByName);
    for(int i = 0; i < n; i++) {
        printf("%3d%6s%3d\n", students[i].id, students[i].name, students[i].age);
    }
    
    printf("\n");
    
    qsort(students, n, sizeof(struct student), compareByAge);
    for(int i = 0; i < n; i++) {
        printf("%3d%6s%3d\n", students[i].id, students[i].name, students[i].age);
    }
    
    return 0;
}

