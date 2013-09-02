#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "common.h"
#include "AbstractBase.h"
#include "DataIO.h"


template <typename T>
class ArrayStack : public AbstractBase
{
public:
	ArrayStack()
	{
		SetClassType(DATA_STRUCT);
		SetTitle("Data Struct: Stack Implemented By Array");
		m_nSize = 10;
		try
		{
			m_pArray = new int[10];
		}
		catch(...)
		{
			TRACE("new failure!");
		}
		m_nTop = -1;
	}
	ArrayStack(int nSize);
	~ArrayStack(void);
	int GetStackSize(void) const;
	void Description(void) const;
	bool Push(const T nData);
	T Pop();
	bool IsEmpty();
	T Top();
	void Test();
private:
	int m_nSize;
	T* m_pArray;
	int m_nTop;
};

#endif