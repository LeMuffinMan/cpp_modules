/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:45:58 by oelleaum          #+#    #+#             */
/*   Updated: 2025/07/24 17:47:33 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> // toupper

void lowercase_to_uppercase(char *str)
{
  for (int i = 0; str[i]; i++)
    str[i] = toupper(str[i]);
}

int main (int argc, char *argv[])
{
  const char* default_str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

  if (argc == 1)
    std::cout << default_str << std::endl;
  else 
  {
    for (int i = 1; i < argc; ++i)
    {
      lowercase_to_uppercase(argv[i]);
      std::cout << argv[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
