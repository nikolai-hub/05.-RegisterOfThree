
#include "Register.h"
#include <cstdlib>


Register::Register(size_t numCompanies) : companiesArray(new Company[numCompanies]), numAdded(0) {}

void Register::add(const Company& c) {
	companiesArray[numAdded] = c;
	numAdded++;
}

Company Register::get(int companyId)const {
	for (size_t i = 0; i < numAdded; i++)
	{
		if (companiesArray[i].getId() == companyId)
		{
			return companiesArray[i];
		}
	}
	return Company();
}

Register::~Register() {
	delete[] companiesArray;
}


Register& Register::operator=(const Register& other) {
	if (this != &other)
	{
		Company* companiesCopy = new Company[other.numAdded];
		for (size_t i = 0; i < other.numAdded; i++)
		{
			companiesCopy[i] = other.companiesArray[i];
		}

		if (companiesArray!=nullptr)
		{
			delete[] companiesArray;
		}
		companiesArray = companiesCopy;
		numAdded = other.numAdded;
	}

	return *this;
}

Register::Register(const Register& other) {
	Company* companiesCopy = new Company[other.numAdded];

	for (size_t i = 0; i < other.numAdded; i++)
	{
		companiesCopy[i] = other.companiesArray[i];
	}
	companiesArray = companiesCopy;
	numAdded = other.numAdded;
}