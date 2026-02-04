#include <stdio.h>
#include <string.h>


struct Department {
    int dept_id;
    char dept_name[50];
};

struct Employee {
    int emp_id;
    char emp_name[50];
    struct Department dept;
};


void displayEmployee(struct Employee* emp) {
    printf("\n Details \n");
    printf("Department Name: %s\n", emp->dept.dept_name);
    printf("Department ID: %d\n", emp->dept.dept_id);
    
    printf("Employee Name: %s\n", emp->emp_name);
    printf("Employee ID: %d\n", emp->emp_id);
    
   
}

int main() {

    struct Employee emp1;
    

    emp1.emp_id = 101;
    strcpy(emp1.emp_name, "David Warner");
    emp1.dept.dept_id = 1;
    strcpy(emp1.dept.dept_name, "EEE");
    

    struct Employee* emp_ptr = &emp1;
    

    displayEmployee(emp_ptr);

    struct Employee emp2;
    emp2.emp_id = 102;
    strcpy(emp2.emp_name, "Harish warner");
    emp2.dept.dept_id = 2;
    strcpy(emp2.dept.dept_name, "ECE");
    
    emp_ptr = &emp2;
    displayEmployee(emp_ptr);
    
    return 0;
}