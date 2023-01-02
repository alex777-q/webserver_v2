#include<iostream>
#include "test.h"

int main(void){
	Person p1(1,10);
	Person p2(2,20);

	std::cout<<p1.m_id<<" "<<p1.m_age<<std::endl;
	std::cout<<p2.m_id<<" "<<p2.m_age<<std::endl;

	return 0;
}
