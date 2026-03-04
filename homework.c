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

