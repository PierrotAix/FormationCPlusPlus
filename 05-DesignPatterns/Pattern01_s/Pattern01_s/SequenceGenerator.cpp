#include "stdafx.h"
#include "SequenceGenerator.h"
#include <iostream>

SequenceGenerator* SequenceGenerator::pgen=nullptr;

SequenceGenerator::SequenceGenerator(int n){
	this->n=n;
}

SequenceGenerator::SequenceGenerator(const SequenceGenerator& gen){
	pgen=gen.pgen;
	n=gen.n;
}

SequenceGenerator& SequenceGenerator::operator=(const SequenceGenerator& gen){
	pgen=gen.pgen;
	n=gen.n;
	return *this;
}


SequenceGenerator::~SequenceGenerator()
{
	if (pgen != nullptr)
	{
		delete(pgen);
	}
}

SequenceGenerator* SequenceGenerator::getInstance() {
	if(pgen==nullptr){
		pgen=new SequenceGenerator;
	}
	return pgen;
}

int SequenceGenerator::getNombre() {
	return ++n;
}
