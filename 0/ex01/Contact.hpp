#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		long		_number;
		std::string	_secret;

	public:
		Contact();
		~Contact();
		// SETTERS
		void		setName( std::string name );
		void		setLastName( std::string name );
		void		setNickname( std::string name );
		void		setNumber( long num );
		void		setSecret( std::string secret );
		// GETTERS
		std::string	getName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		long		getNumber(void);
		std::string	getSecret(void);
		// OTHERS
		int			isFull(void);
};

#endif
