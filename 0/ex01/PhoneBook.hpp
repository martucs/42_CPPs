#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <sstream>

class PhoneBook
{
	private:
		Contact	_contact[8];
	public:
		PhoneBook();
		~PhoneBook();
		int		index;
		
		// GETTER
		Contact	GetContact(int index);
		// OTHERS
		int		PrintBook();
		int		FillContact();
		void	CopyContact(Contact tmp, Contact *real);
};

#endif
