/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:58:07 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/21 11:19:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget("Default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return (*this);
	this->setTarget(copy.getTarget());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
	if (!this->isSigned())
		throw(IsNotSignedException());
	if (this->getGradeExec() < executor.getGradeExec())
		throw(GradeTooLowException());
	
	std::ofstream file;
	std::string filename = this->getTarget().append("_shrubbery");
	file.open(filename.c_str());
	if (!file.is_open())
		throw(ShrubberyCreationForm::OpenFailledExecption());

	file << "                                                 ***  =  -=                                         " << std::endl;
	file << "                                                =+-=-==+======                                      " << std::endl;
	file << "                          =              ++=* +=+=*=++-=-==--+===                                   " << std::endl;
	file << "                           ==  =        ==---=-==-+-=--=-=-=+-+=#++   ++ ++                         " << std::endl;
	file << "                        ==:==:==:=::::  +**==+===-=-+-==++=+--+**+++*+*=+==+  ==  +                 " << std::endl;
	file << "                     ====+==-++:==+-=+** ##=*---+=++++-==---*++*****=-+=--+++===++                  " << std::endl;
	file << "             ====     = +===:--===:+=:*#=###=*+***=+*=*==++=####**--**---=-==:==**                  " << std::endl;
	file << "          ==::==::=   +*=+=-=:::-:-+===*##*#%**++#%*%##**+#*#%#####===+--+-+=#-****                 " << std::endl;
	file << "          ::++=:-:=:+=+*==::*:-==-*=*:***+#%%%*%##**%%%%#*##%#######%%#*+*#+*#*#*++                 " << std::endl;
	file << "           ===+-+-*:++*+=*=*==**=++*=*****# %%%%%%#%###*#*#######*+-=== :##==**+++++                " << std::endl;
	file << "             =+++*#*****+#+=++++*--*****####=#=*-+*===-+**#####%#**=--:=++-*+:=+:#+++++             " << std::endl;
	file << "                    ***%#+**====***#+#%##==:=-=-=:=-:-+==+=*%%#*#**===--:----==-+++-#*##            " << std::endl;
	file << "                ==--+ *#%#*++#*+#######*#*=====---=:=+--=+::+****#*=*---=----+--++-#=#+***          " << std::endl;
	file << "           =======---=-*#**%##*###%%***#*-=:=+++:=:==-+**-*##**#*****==-=#*==-+-+-+=*#++            " << std::endl;
	file << "      -+--*--==--:==-=+-++##*%%%%%%#%%***=*+==*===-==+=##++#===##==*#***###*** *#+++#* *            " << std::endl;
	file << "      +**=+++:=-===:-+-+-+*###%%%%%%%%%###+*%%#%%%%%*%#%%%%%#==--=#==*%%*%*---**  *  #              " << std::endl;
	file << "    ++==***+=+:+:+--:+==+*#*%#%#%#%%%%%#%#%%#%#####%#%%%%#%####++*%%*##:===+-+===--*#=+=  ++++      " << std::endl;
	file << "    ++##***#+-=##==:++++**#**##%%**%%**=+#%-=-=%**==-*#####%#%%#*#**#===+-:*=+-=:::----== ##+       " << std::endl;
	file << "   +***###*#**####+**+**###*%%*%#*=-***:--++=-==+---=-:-::==%%###%####=--=--#*=:-+-+*=-+-+##+++     " << std::endl;
	file << "   +++**#**%%%+*+##*+#**#+##%*%#+%+=+-:=----:++::-=-:*===::*##%%%##%%%**+*+#++::=--*+==-#=+==+*     " << std::endl;
	file << "       #**#%####**#%######+##+:++*----#*-=:++=:=+*=-==+:--+*=##%##%%%%##+*+++##*=:*+--+#++#*+#+     " << std::endl;
	file << "          =# %% ##%%%%#**##*+*#=+-++=-+=-=+=*-=+#-##+#*++#=#---++%#%%%%%##*#++++=+=#*#=*+#=*#*+++   " << std::endl;
	file << "      ++===**=#+*%%%#%%%%***+#+-#=**::+-+*+=+#-#%##**+---+*+-#***##++++%###%##**#+++++**--*=## *++  " << std::endl;
	file << "   ++**====+=###=#=##%%%%@%*#*##+#=####***==**####*#*+++++*=-=#=*==++-*###%%%%%%%%*###%#*#*###++    " << std::endl;
	file << "  ++*==**=*=*=*=##*#*+%%%%%##**##*#####**#=***%#%#%##*+*#*#*%####+--=*#*#++%##+#########%%%#####+   " << std::endl;
	file << "    ===#**==+%++*+*#%#%%%%@@##%##*#%*###+*#%##%#*%%%%%%+**+%%%%####*%#+%*---++#%%%%%#####* #+++     " << std::endl;
	file << "      * #*####%%#*%%%#%%%%%%#*#*###%%%#%%#%%%%%%#%%%#%%%%+#%%%*#%%%%%###%+-*---++*#+###+* ## +      " << std::endl;
	file << "          **#++#%##%#%#%%%%%%%%#*##++%%%##%%%%%%%%%%%##%%%%%%#%%%%%%#####+##++=++*###++             " << std::endl;
	file << "               **#####**######*##*##++*#%%%#%%%%%%%%%%%@%%#%%%%%###**###*#***++      +              " << std::endl;
	file << "                    #  * ** ********  *    %%%%%%%%%%%%@%%%%%++++**+#*#       +                     " << std::endl;
	file << "                            *    ++          %%%%%%##%%%%%%  == =                                   " << std::endl;
	file << "                                              %%%%%%%%%%%%                                          " << std::endl;
	file << "                                               %%%%#%%%%%#                                          " << std::endl;
	file << "                                                %%##%#%%%#                                          " << std::endl;
	file << "                                                ###%##%%%#                                          " << std::endl;
	file << "                                                *###*#%#%#                                          " << std::endl;
	file << "                                               *####*#%#%#                                          " << std::endl;
	file << "                                               *#*###%%#%%#                                         " << std::endl;
	file << "                                              *#*#*###%%%#%                                         " << std::endl;
	file << "                                          **##*#%%###%%%%%###*                                      " << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::OpenFailledExecption::what() const throw()
{
	return ("Error: Failled to open file.");
}