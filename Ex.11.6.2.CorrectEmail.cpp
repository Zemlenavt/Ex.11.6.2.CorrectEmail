#include <iostream>

bool validFirstPart (char c)
{
    std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.!#$%&'*+-/=?^_`{|}~";

    for (int i = 0; i < validChars.length(); i++)
    {
        if (c == validChars[i])
        {
            return true;
        }
    }
    return false;
}

bool validSecondPart (char c)
{
    std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";

    for (int i = 0; i < validChars.length(); i++)
    {
        if (c == validChars[i])
        {
            return true;
        }
    }
    return false;
}

std::string getFirstPart (std::string email)
{
    std::string firstPart = "";
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        if (!validFirstPart (email[i]))
        {
            return "";
        }
        firstPart += email[i];
    }
    if (firstPart.length() < 1 || firstPart.length() > 64)
    {
        return "";
    }
    if (firstPart[0] == '.' || firstPart[firstPart.length()-1] == '.')
    {
        return "";
    }
    for (int i=0; i < firstPart.length() - 1; i++)
    {
        if (firstPart[i] == '.' && firstPart[i+1] == '.')
        {
            return "";
        }
    }
    return firstPart;
}

std::string getSecondPart (std::string email)
{
    std::string secondPart = "";
    bool findSecondPart = false;
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] != '@' && !findSecondPart)
        {
            continue;
        }
        else if (email[i] == '@')
        {
            if (findSecondPart)
            {
                return "";
            }
            else
            {
                findSecondPart = true;
                continue;
            }
            
        }

        if (!findSecondPart || !validSecondPart (email[i]))
        {
            return "";
        }
        secondPart += email[i];
    }
    if (secondPart.length() < 1 || secondPart.length() > 63)
    {
        return "";
    }
    if (secondPart[0] == '.' || secondPart[secondPart.length()-1] == '.')
    {
        return "";
    }
    for (int i=0; i < secondPart.length() - 1; i++)
    {
        if (secondPart[i] == '.' && secondPart[i+1] == '.')
        {
            return "";
        }
    }
    return secondPart;
}

bool validEmail (std::string email)
{
    std::string firstPart = getFirstPart(email);
    std::string secondPart = getSecondPart(email);
    if (firstPart == "" || secondPart == "")
    {
        return false;
    }
    return true;
}




int main()
{
    std::string email;
    std::cout << "Input Email: ";
    std::cin >> email;
    if (validEmail(email))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
} 