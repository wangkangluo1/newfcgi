#include <string> 
#include <iostream>

using namespace std;

int main()
{
    string str( "a bc abc abcd abcde" );
    string searchString( "hello" ); 
    string replaceString( "ab" );

   // assert( searchString != replaceString );

    string::size_type pos = 0;
    while ( (pos = str.find(searchString, pos)) != string::npos ) {
        str.replace( pos, searchString.size(), replaceString );
        pos++;
    }
    cout << str << endl;
    return 0;
}
