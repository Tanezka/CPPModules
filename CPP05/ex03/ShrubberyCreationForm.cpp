#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target): AForm("ShrubberyCreationForm", Target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form): target(form.target)
{
	*this = form;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	source.getName();
    return (*this);
}

void ShrubberyCreationForm::conc_execute() const
{
	std::string		file_name;
    std::ofstream	tree;

	file_name = this->getTarget().c_str();
	file_name.append("_shruberry");
    tree.open(file_name);
    if (tree.is_open())
    {
        tree << 
    "                                                     .\n"
    "                                          .         ;  \n"
    "              .             .              ;%     ;;   \n"
    "               ,           ,                :;%  %;   \n"
    "                :         ;                   :;%;'     .,   \n"
    "      ,.        %;     %;            ;        %;'    ,;\n"
    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
    "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "            `%;.     ;%;     %;'         `;%%;.%;'\n"
    "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "                `:%;.  :;bd%;          %;@%;'\n"
    "                  `@%:.  :;%.         ;@@%;'  \n" 
    "                    `@%.  `;@%.      ;@@%;     \n"    
    "                      `@%%. `@%%    ;@@%;       \n" 
    "                        ;@%. :@%%  %@@%;       \n"
    "                          %@bd%%%bd%%:;     \n"
    "                            #@%%%%%:;;\n"
    "                            %@@%%%::;\n"
    "                            %@@@%(o);  . '         \n"
    "                            %@@@o%;:(.,'         \n"
    "                        `.. %@@@o%::;         \n"
    "                           `)@@@o%::;         \n"
    "                            %@@(o)::;        \n"
    "                           .%@@@@%::;         \n"
    "                           ;%@@@@%::;.         \n" 
    "                          ;%@@@@%%:;;;. \n"
    "                      ...;%@@@@@%%:;;;;,..    \n";
    tree.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
