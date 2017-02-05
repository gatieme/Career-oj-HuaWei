#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

#include <fstream>

using namespace std;

//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG

string NumberToEnglishString(long int number);

int main( )
{
    ifstream fin("in.txt");
    streambuf *cinbackup = cin.rdbuf(fin.rdbuf());
    //ofstream fout("out.txt");
    //streambuf *coutbackup = cout.rdbuf(fout.rdbuf());

    long int number;
	while(cin >>number)
    {
        debug <<number <<" = ";
	    cout <<NumberToEnglishString(number) <<endl;
        // system("PAUSE");
    }

    return 0;
}


string numStringB20[21] =       /* blew 20  */
{
    "zero", "one", "two",  "three", "four",                     /*  0~4  */
    "five", "six", "seven", "eight", "nine",                    /*  5~9  */
    "ten", "eleven", "twelve", "thirteen", "fourteen",          /* 10~14 */
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen",  /* 15~19 */
    "error",                                                    /* 20    */
};

string numStringZ10[] =
{
    "error", "error",
    "twenty", "thirty", "forty", "fifty", "sixty",              /* 20~60 */
	"seventy", "eighty", "ninety",                              /* 70~90 */
    "error",
};

string NumberToEnglishString(long int number)
{
	debug <<"number  = " <<number <<endl;
    if(number < 0)
	{
		return "error";
	}
    else if(number < 20)
	{
	   return numStringB20[number];
    }
    else if(number < 100)       //  21-99
	{
		if (number % 10 == 0)   //  20,30,40,...90的输出k
		{
            return numStringZ10[number / 10];
		}
		else
		{
			return  NumberToEnglishString(number / 10 * 10) + ' '
                  + NumberToEnglishString(number % 10);
		}

	}
    else if(number < 1000)  //100-999
	{
		if(number % 100 == 0)
		{
			return NumberToEnglishString(number / 100 ) + " hundred";

		}
		else
		{
			return  NumberToEnglishString(number / 100) + " hundred and "
                  + NumberToEnglishString(number % 100);
		}
	}
    else if(number < 1000000)  //1000-999999   百万以下
	{
		if(number % 1000 == 0)
		{
			return NumberToEnglishString(number / 1000) + " thousand";

		}
		else
		{
			return NumberToEnglishString(number / 1000) + " thousand "
                + NumberToEnglishString(number % 1000);
		}
	}
    else if(number < 1000000000)   //十亿以下
	{
		if(number % 1000000 == 0)
		{
			return NumberToEnglishString(number / 1000000) + " million";
		}
		else
		{
			return   NumberToEnglishString(number / 1000000) + " million "
                   + NumberToEnglishString(number % 1000000);
		}
	}
    else if (number < 9999999999)  //十亿到99亿
	{
		if(number % 1000000000 == 0)
		{
			return NumberToEnglishString(number / 1000000000) + " billion";
		}
		else
		{
			return  NumberToEnglishString(number / 1000000000) + " billion "
                  + NumberToEnglishString(number % 1000000000);
		}
	}
    else if (number > 9999999999)
	{
		return "error";
	}
    return "error";
}
