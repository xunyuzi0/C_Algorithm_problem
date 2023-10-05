#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[50];
    int department;
    float salary;
    struct Employee *next;
} Employee;

Employee *createNode(int id, char name[], int department, float salary) {
    Employee *newNode = (Employee *)malloc(sizeof(Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->department = department;
    newNode->salary = salary;
    newNode->next = NULL;
    return newNode;
}

void insertEmployee(Employee **head, int id, char name[], int department, float salary) {
    Employee *newNode = createNode(id, name, department, salary);
    newNode->next = *head;
    *head = newNode;
    printf("职工记录添加成功！\n");
}

void displayEmployees(Employee *head) {
    Employee *curr = head;
    printf("所有职工记录：\n");
    while (curr != NULL) {
        printf("职工编号：%d  姓名：%s  部门号：%d  工资：%f\n", curr->id, curr->name, curr->department, curr->salary);
        curr = curr->next;
    }
}

void sortByEmployeeId(Employee **head) {
    Employee *curr, *index;
    int tempId;
    char tempName[50];
    int tempDepartment;
    float tempSalary;

    if (*head == NULL) {
        return;
    }

    for (curr = *head; curr != NULL; curr = curr->next) {
        for (index = curr->next; index != NULL; index = index->next) {
            if (curr->id > index->id) {
                tempId = curr->id;
                strcpy(tempName, curr->name);
                tempDepartment = curr->department;
                tempSalary = curr->salary;

                curr->id = index->id;
                strcpy(curr->name, index->name);
                curr->department = index->department;
                curr->salary = index->salary;

                index->id = tempId;
                strcpy(index->name, tempName);
                index->department = tempDepartment;
                index->salary = tempSalary;
            }
        }
    }

    printf("按编号排序完成！\n");
}

void sortByDepartment(Employee **head) {
    Employee *curr, *index;
    int tempId;
    char tempName[50];
    int tempDepartment;
    float tempSalary;

    if (*head == NULL) {
        return;
    }

    for (curr = *head; curr != NULL; curr = curr->next) {
        for (index = curr->next; index != NULL; index = index->next) {
            if (curr->department > index->department || 
                (curr->department == index->department && curr->id > index->id)) {
                tempId = curr->id;
                strcpy(tempName, curr->name);
                tempDepartment = curr->department;
                tempSalary = curr->salary;

                curr->id = index->id;
                strcpy(curr->name, index->name);
                curr->department = index->department;
                curr->salary = index->salary;

                index->id = tempId;
                strcpy(index->name, tempName);
                index->department = tempDepartment;
                index->salary = tempSalary;
            }
        }
    }

    printf("按部门号排序完成！\n");
}

void deleteEmployee(Employee **head, int id) {
    Employee *prev = NULL;
    Employee *curr = *head;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("职工记录不存在！\n");
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    printf("职工记录删除成功！\n");
}

void saveToFile(Employee *head, char filename[]) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("打开文件失败！\n");
        return;
    }

    Employee *curr = head;
    while (curr != NULL) {
        fprintf(file, "%d,%s,%d,%.2f\n", curr->id, curr->name, curr->department, curr->salary);
        curr = curr->next;
    }

    fclose(file);
    printf("职工记录已保存到文件：%s\n", filename);
}

void freeList(Employee *head) {
    Employee *curr = head;
    Employee *temp;

    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

int main() {
    Employee *head = NULL;

    int choice;
    int id, department;
    char name[50];
    float salary;
    char filename[50];

    while (1) {
        printf("\n职工管理系统\n");
        printf("1. 增加一个职工记录\n");
        printf("2. 显示所有职工记录\n");
        printf("3. 按编号进行排序\n");
        printf("4. 按部门号进行排序\n");
        printf("5. 删除指定职工记录\n");
        printf("6. 将职工记录存储到文件\n");
        printf("0. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入职工编号：");
                scanf("%d", &id);
                printf("请输入职工姓名：");
                scanf("%s", name);
                printf("请输入部门号：");
                scanf("%d", &department);
                printf("请输入工资数：");
                scanf("%f", &salary);
                insertEmployee(&head, id, name, department, salary);
                break;
            case 2:
                displayEmployees(head);
                break;
            case 3:
                sortByEmployeeId(&head);
                break;
            case 4:
                sortByDepartment(&head);
                break;
            case 5:
                printf("请输入要删除的职工编号：");
                scanf("%d", &id);
                deleteEmployee(&head, id);
                break;
            case 6:
                printf("请输入要保存的文件名：");
                scanf("%s", filename);
                saveToFile(head, filename);
                break;
            case 0:
                freeList(head);
                exit(0);
            default:
                printf("无效的选择！\n");
        }
    }

    return 0;
}