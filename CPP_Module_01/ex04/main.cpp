/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:41:13 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 14:36:03 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout << "You have to provide 3 arguments." << std::endl;
        return (0);
    }
    
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return (1);
    }

    std::string word;
    std::string line;
    std::string newFileContent;
    std::string searchWord = argv[2];
    std::string replaceWord = argv[3];

    while (std::getline(file, line))
    {
        std::string newLine;
        size_t pos = 0;
        while ((pos = line.find(searchWord)) != std::string::npos)
        {
            newLine = newLine + line.substr(0, pos);
            newLine = newLine + replaceWord;
            line = line.substr(pos + searchWord.length());
        }
        newLine = newLine + line;
        newFileContent = newFileContent + newLine + "\n";
    }

    std::string name = argv[1];
    std::ofstream newFile((name + ".replace").c_str());
    if (!newFile.is_open())
    {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return (1);
    }

    newFile << newFileContent;
    newFile.close();
    file.close();

    return (0);
}