/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:42:47 by jungslee          #+#    #+#             */
/*   Updated: 2024/09/26 22:34:22 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(1)
{
}

void	PhoneBook::Add()
{
	std::string	input;

	if (this->index == 9)
	{
		this->index = 1;
		this->isFull = 1;
	}

	std::getline(std::cin, input);
	this->contact[index - 1].setFirstName(input);
	std::cin.ignore();

	std::getline(std::cin, input);
	this->contact[index - 1].setLastName(input);
	std::cin.ignore();

	std::getline(std::cin, input);
	this->contact[index - 1].setNickName(input);
	std::cin.ignore();

	std::getline(std::cin, input);
	this->contact[index - 1].setPhoneNumber(input);
	std::cin.ignore();

	std::getline(std::cin, input);
	this->contact[index - 1].setDarkestSecret(input);
	std::cin.ignore();

	std::cin.clear();
	this->index++;
}

void	PhoneBook::Exit()
{
	exit(0);
}

void	PhoneBook::Search()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	int			count;
	int			chooseIndex;

	if (this->isFull == 0)
		count = this->index;
	else
		count = 8;
	for (int i = 0; i < count; i++)
	{
		firstName = this->contact[i].getFirstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 8) + ".";
		lastName = this->contact[i].getLastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 8) + ".";
		nickName = this->contact[i].getNickName();
		if (nickName.length() > 10)
			nickName = nickName.substr(0, 8) + ".";
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << firstName;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << lastName;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << nickName;
		std::cout << "|" << std::endl;
	}

	std::cin >> chooseIndex;
	while (std::cin.fail() || !(1 <= chooseIndex && chooseIndex <= 8))
	{
		std::cin.clear();
		std::cout << "올바른 인덱스를 입력해주세요." << std::endl;
		std::cin >> chooseIndex;
	}

	if (this->isFull == 0 && chooseIndex > this->index)
		std::cout << "해당 인덱스에 연락처가 입력되지 않았습니다." << std::endl;
	else
	{
		std::cout << "fist name : " << this->contact[chooseIndex - 1].getFirstName() << std::endl;
		std::cout << "last name : " << this->contact[chooseIndex - 1].getLastName() << std::endl;
		std::cout << "nickname : " << this->contact[chooseIndex - 1].getNickName() << std::endl;
		std::cout << "phone number : " << this->contact[chooseIndex - 1].getPhoneNumber() << std::endl;
		std::cout << "darkest secret : " << this->contact[chooseIndex - 1].getDarkestSecret() << std::endl;
	}
}