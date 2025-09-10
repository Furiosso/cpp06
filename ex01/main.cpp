#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data		data;
	uintptr_t	address;

	data.id = 1;
	data.name = "Perico";
	data.surname = "de los Palotes";
	data.address = "Calle de la Piruleta 42";
	data.telephoneNumber = 123456789;

	std::cout << "Id: " << data.id << std::endl
	<< "Name: " << data.name << std::endl
	<< "Surame: " << data.surname << std::endl
	<< "Address: " << data.address << std::endl
	<< "Telephone numer: " << data.telephoneNumber << std::endl
	<< std::endl;
	
	address = Serializer::serialize(&data);
	std::cout << "address: " << address << std::endl
	<< "pointer: " << &data << std::endl
	<< std::endl;

	Data*	dptr;

	dptr = Serializer::deserialize(address);
	std::cout << "dptr: " << dptr << std::endl
	<< "address: " << address << std::endl
	<< std::endl
	<< "Id: " << dptr->id << std::endl
	<< "Name: " << dptr->name << std::endl
	<< "Surame: " << dptr->surname << std::endl
	<< "Address: " << dptr->address << std::endl
	<< "Telephone numer: " << dptr->telephoneNumber << std::endl;
}