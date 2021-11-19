#include <iostream>
#include <map>
#include <vector>

int main()
{

    std::string input[2];

    std::map<std::string, std::vector<std::string> > names;
    std::map<std::string,  std::string> phoneNums;

    std::vector<std::string> phones;

    do
    {
        input[1]="";

        std::cout << "Input number&name to add, or one of the items to find: ";

        std::getline(std::cin, input[1]);

        input[0] = input[1].substr(0, input[1].find(' '));
        if(input[1].find(' ')==std::string::npos)
            input[1] = "";
        else
            input[1]=input[1].substr(input[1].find(' ')+1, input[1].length());

        if (input[1] != "")
        {
            phones = names[input[1]];
            phones.push_back(input[0]);
            names[input[1]] = phones;

            phoneNums[input[0]] = input[1];
        }
        else
        {
            std::cout << phoneNums[input[0]] << std::endl;
            for(auto it=names[input[0]].begin();it!=names[input[0]].end();it++)
                std::cout << *it << std::endl;
        }
    }
    while(input[0]!="end");

    return 0;
}
