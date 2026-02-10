package security;

class Employee {
    private String name;
    private double salary;
    private final int a = 0;
    Employee(String empName, double empSalary) {
        this.name = empName;
        this.salary = empSalary;
    }
    public void setEmployeeName(String empName) {
        this.name = empName;
    }
    public void setSalary(double empSalary) {
        this.salary = empSalary;
    }
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Employee)) {
            return false;
        }
        Employee emp = (Employee) o;
        return emp.name.equals(name);   // @violation
    }

    public int hashCode() { /* ... */ }
}