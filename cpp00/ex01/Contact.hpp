/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:43:52 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/10/18 16:23:42 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact 
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        void setFirstName(const std::string &str);
        void setLastName(const std::string &str);
        void setNickname(const std::string &str);
        void setPhoneNumber(const std::string &str);
        void setDarkestSecret(const std::string &str);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif