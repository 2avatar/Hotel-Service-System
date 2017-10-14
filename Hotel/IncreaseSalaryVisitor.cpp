#include "IncreaseSalaryVisitor.h"

IncraseSalaryVisitor::IncraseSalaryVisitor(int amount) : amount(amount)
{
}

void IncraseSalaryVisitor::visit(IVisitable * element)
{
	Employee* emp = (Employee*)element;
	emp->setSalary(emp->getSalary()+amount);
}
