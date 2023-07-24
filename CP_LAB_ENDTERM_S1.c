#include <stdio.h>

// Given in Question.
typedef struct Person
{
    char name[30];
    int age;
} Person;

// Given in Question.
typedef struct Date
{
    int dd;
    int mm;
    int yyyy;
} Date;

// Given in Question.
struct Employee
{
    int ID;        // Unique ID of the employee
    char dept[10]; // Department of the employee
    Date joinDate; // Date of joining of the employee
    Person person; // Basic details of employee
    float salary;  // Salary of the employee
};

// Function for dislaying menu.
void Company_menu()
{
    printf("This a program for HR Menu of a Company :\n\n");
    printf("a For Add Employee.\n");
    printf("b For Display All Employees Details.\n");
    printf("c For Update Salary of Employee.\n");
    printf("d For Exit.\n\n");
}

// Searches if employee exist.
int search(struct Employee list[], int id, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (list[i].ID == id)
            return i;
    }
    return -1;
}

// Add employee details.
void addEmployee(struct Employee list[], int *num)
{
    do
    {
        printf("Enter ID : ");
        scanf("%d", &list[*num].ID);
        if (*num == 0)
        {
            break;
        }
        else if (search(list, list[*num].ID, *num) != -1)
        {
            printf("Enter Different ID, your entered ID already exist\n");
        }
    } while (search(list, list[*num].ID, *num) != -1);
    getchar();
    printf("Enter Name : ");
    scanf("%[^\n]", list[*num].person.name);
    do
    {
        printf("Enter Age : ");
        scanf("%d", &list[*num].person.age);
        if (list[*num].person.age <= 18)
            printf("Enter Correct Age.\n");
    } while (list[*num].person.age <= 18);
    getchar();
    printf("Enter Department : ");
    scanf("%[^\n]", list[*num].dept);
    do
    {
        printf("Enter Salary : ");
        scanf("%f", &list[*num].salary);
        if (list[*num].salary < 0)
            printf("Salary is always positive.\n");
    } while (list[*num].salary < 0);
    do
    {
        printf("Enter Joining Date (in [dd-mm-yyyy] format) : ");
        scanf("%d-%d-%d", &list[*num].joinDate.dd, &list[*num].joinDate.mm, &list[*num].joinDate.yyyy);
        if ((list[*num].joinDate.dd > 31 || list[*num].joinDate.dd < 1) || (list[*num].joinDate.mm > 12 || list[*num].joinDate.mm < 1) || (list[*num].joinDate.yyyy < 1900))
            printf("Enter Correct Date.\n");
    } while ((list[*num].joinDate.dd > 31 || list[*num].joinDate.dd < 1) || (list[*num].joinDate.mm > 12 || list[*num].joinDate.mm < 1) || (list[*num].joinDate.yyyy < 1900));
    printf("%s is successfully added.\n\n\n", list[*num].person.name);
    *num += 1;
}

// Function for dislaying employee records with order on highest salary.
void display(struct Employee list[], int num)
{
    int i, j;
    struct Employee temp;
    // doing linear sort here.
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (list[i].salary < list[j].salary)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    // printing details with use of for loop.
    printf("Employees Details :\n");
    for (i = 0; i < num; i++)
    {
        printf("Of %d:\n", i + 1);
        printf("Name : %s\n", list[i].person.name);
        printf("Age : %d\n", list[i].person.age);
        printf("ID : %d\n", list[i].ID);
        printf("Department : %s\n", list[i].dept);
        printf("Salary : %.2f\n", list[i].salary);
        printf("Joining Date : %d-%d-%d\n\n\n", list[i].joinDate.dd, list[i].joinDate.mm, list[i].joinDate.yyyy);
    }
}

// Function for updating the salary of given employee.
void updateSalary(struct Employee list[], int num)
{
    int id, i;
    float amount = 0;
    int percent;
    // Asking for ID from user, do-while loop terminate when correct ID is entered.
    do
    {
        printf("Enter ID : ");
        scanf("%d", &id);
        i = search(list, id, num);
        if (i == -1)
            printf("Employee with this ID don't exist, Enter Again.\n");
        else if (list[i].joinDate.yyyy >= 2018)
        {
            printf("Employee have less than 5 years of experience\n");
            i = -1;
        }
    } while (i == -1);
    printf("Enter Percentage Hike : ");
    scanf("%d", &percent);
    // Calculating increament amount
    amount = (list[i].salary) * ((percent / 100.0) + 1);
    list[i].salary = amount;
    // Displaying details.
    printf("Salary Updated Successfully.\n");
    printf("\n\nName : %s\n", list[i].person.name);
    printf("Age : %d\n", list[i].person.age);
    printf("ID : %d\n", list[i].ID);
    printf("Department : %s\n", list[i].dept);
    printf("Salary : %.2f\n", list[i].salary);
    printf("Joining Date : %d-%d-%d\n\n\n", list[i].joinDate.dd, list[i].joinDate.mm, list[i].joinDate.yyyy);
}

void main()
{
    // For storing option choosed by user.
    char option;
    int i = 0;
    // Array of Employee type struct.
    struct Employee employee[10];
    int noEmployee = 0;
    // do-while loop is used for displaying menu and terminate when option is 'd'.
    do
    {
        Company_menu();
        printf("\nEnter Your Option : ");
        if (i != 0)
            getchar();
        scanf("%c", &option);
        if (noEmployee > 10)
            break;
        switch (option)
        {
            case 'a':
                addEmployee(employee, &noEmployee);
                break;
            case 'b':
                if (noEmployee == 0)
                {
                    printf("First Add Employee.\n\n\n");
                    break;
                }
                display(employee, noEmployee);
                break;
            case 'c':
                if (noEmployee == 0)
                {
                    printf("First Add Employee.\n\n\n");
                    break;
                }
                updateSalary(employee, noEmployee);
                break;
        }
        i = 1;
    } while (option != 'd');
    // When User exit the program.
    printf("\nGood-Bye\n");
}