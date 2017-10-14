#pragma once
#ifndef __INCREASE_SALARY_VISITOR_H
#define __INCREASE_SALARY_VISITOR_H
#include "Visitor.h"
#include "employee.h"
class IncraseSalaryVisitor : public IVisitor
{
private:
	int amount;
public:
	IncraseSalaryVisitor(int amount);
	virtual void visit(IVisitable* element);

};
#endif // __INCREASE_SALARY_VISITOR_H

