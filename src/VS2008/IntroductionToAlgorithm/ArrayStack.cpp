#include "ArrayStack.h"

ArrayStack::ArrayStack(int nSize)
{
	SetClassType(DATA_STRUCT);
	SetTitle("Data Struct: Stack Implemented By Array");
	m_nSize = nSize;
	m_nTop = 0;
	try
	{
		m_pArray = new int[nSize];
	}
	catch(...)
	{
		TRACE("new failure!");
	}
}

ArrayStack::~ArrayStack(void)
{
	if(m_pArray)
		delete[] m_pArray;
	m_nSize = 0;
	m_nTop = -1;
}

void ArrayStack::Description(void) const
{
	cout<<STAR_STRING<<endl;
	cout<<"DESCRIPTION:"<<endl;
	cout<<"Referenced From:"<<endl;
	cout<<"http://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Abstract_definition"<<endl;
	cout<<"In computer science, a stack is a particular kind of abstract"<<endl;
	cout<<"data type or collection in which the principal operations"<<endl;
	cout<<"on the collection are the addition of an entity to the collection,"<<endl;
	cout<<"known as push and removal of an entity, known as pop.The relation"<<endl;
	cout<<"between the push and pop operations is such that the stack is a "<<endl;
	cout<<"Last-In-First-Out (LIFO) data structure. In a LIFO data structure,"<<endl;
	cout<<"the last element added to the structure must be the first one to be"<<endl;
	cout<<"removed. This is equivalent to the requirement that, considered as"<<endl;
	cout<<"a linear data structure, or more abstractly a sequential collection,"<<endl;
	cout<<"the push and pop operations occur only at one end of the structure,"<<endl;
	cout<<"referred to as the top of the stack. Often a peek or top operation is"<<endl;
	cout<<"also implemented, returning the value of the top element without"<<endl;
	cout<<" removing it."<<endl;
	cout<<"THE USEFUL CHINESE URL IS:http://zh.wikipedia.org/wiki/%E5%A0%86%E6%A0%88"<<endl;
	cout<<STAR_STRING<<endl;
	cout<<endl;
}

void ArrayStack::Push(const int nData)
{
	if(m_nTop == m_nSize - 1)
	{
		TRACE("the stack is full!");
		return;
	}
	else
	{
		cout<<"Push Data:"<<nData<<endl;
		++m_nTop;
		m_pArray[m_nTop] = nData;
	}
}

int ArrayStack::Pop()
{
	if(m_nTop == -1)
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
	else
	{
		--m_nTop;
		cout<<"Pop Data:"<<m_pArray[m_nTop+1]<<endl;
		return m_pArray[m_nTop+1];
	}
}

bool ArrayStack::IsEmpty()
{
	return (m_nTop == -1);
}

int ArrayStack::Top()
{
	if(m_nTop == -1)
	{
		TRACE("the stack is empty!");
		return ERROR_EMPTY;
	}
	else
	{
		cout<<"Return Top Data:"<<m_pArray[m_nTop]<<endl;
		return m_pArray[m_nTop];
	}
}

int ArrayStack::GetStackSize(void) const
{
	return m_nSize;
}

void ArrayStack::Test()
{
	DataIO dataIO(INT);
	cout<<endl<<TEST_BEGIN_STRING<<endl;
	cout<<"Let's See The Test of ArrayStack"<<endl;
	int * pData = (int*)dataIO.GetDataFromStdIO(1);
	unsigned int nDataByte = dataIO.GetDataByte();
	for(unsigned int i=0;i<nDataByte;i++)
	{
		Push(pData[i]);
	}
	for(unsigned int i=0;i<nDataByte;i++)
	{
		int nData = Pop();
	}
	Pop();
	cout<<TEST_END_STRING<<endl<<endl;
}