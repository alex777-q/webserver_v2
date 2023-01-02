#ifndef TEST_H
#define TEST_H

class Person{
public:
	Person(int id, int age)
		:m_id(id),
		m_age(age){
		}

public:
	int m_id, m_age;
};

#endif
