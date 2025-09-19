/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:39:52 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/17 15:57:56 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if(argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < argc; i++)
      for(int j = 0; argv[i][j]; j++)
            std::cout << (char)std::toupper(argv[i][j]);
    std::cout << std::endl;
}
