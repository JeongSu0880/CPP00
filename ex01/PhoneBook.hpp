/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:01:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/09/26 21:54:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact 	contact[8];
		int			index;
		int			isFull;

	public:
		PhoneBook();
		~PhoneBook();
		void		Add();
		void		Search();
		void		Exit();
};

#endif
