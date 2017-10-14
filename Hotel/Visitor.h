#pragma once
#ifndef __VISITOR_H
#define __VISITOR_H

class IVisitable;

class IVisitor
{
public:
	virtual void visit(IVisitable* element) = 0;
};

class IVisitable
{
public:
	virtual void accept(IVisitor* visitor) = 0;
};

#endif // __VISITOR_H
