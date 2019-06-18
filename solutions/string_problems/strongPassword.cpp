
#include <iostream>
#include <regex>

using namespace std;
int strongPassword(int n, string password){
    regex lower(".*[a-z]+.*");
    regex upper(".*[A-Z]+.*");
    regex digits(".*[0-9]+.*");
    regex special(".*[-!@#\\$%\\^\\&\\*\\(\\)\\+]+.*");

    int numLet = 0;
    if ( !regex_match(password, lower) )
    {    numLet++;}

    if ( !regex_match(password, upper) )
    {   numLet++;}

    if ( !regex_match(password, digits) )
    {   numLet++;}

    if ( !regex_match(password, special) )
    {   numLet++;}

    if(n<6){
        int a = 6-n;
        if(numLet>a)
           { return numLet;}
        else
        {
            return (numLet+(a-numLet));

        }
    }
    else
        {return numLet;}
}
int main()
{
    string a = "Ab$";

   cout<< strongPassword(3,a );

    return 0;
}
