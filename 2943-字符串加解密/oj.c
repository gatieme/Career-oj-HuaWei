#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


//  对字符串进行加密
void Encrypt (char *aucPassword, char *aucResult);


//  对字符串进行解密
void unEncrypt (char *result, char *password);


int main( )
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);


    char sourceone[100], resultone[100], sourcetwo[100], resulttwo[100];  
      
    scanf("%s %s", sourceone, sourcetwo);
    //printf("%s %s\n", sourceone, sourcetwo);
    Encrypt(sourceone, resultone);        
    unEncrypt (sourcetwo, resulttwo);  
      
    puts(resultone);  
    puts(resulttwo);  


    return 0;
}




char EncryptChar(char *ch)
{
    char temp = *ch;
    if(temp >= '0' && temp <= '9')
    {
        *ch = (((temp + 1) > '9') ? (temp + 1) : '0');
    }
    else if(temp >= 'A' && temp <= 'Z')
    {
        *ch = ((temp == 'Z') ? 'a' : tolower(temp + 1));
    }
    else if(temp >= 'a' && temp <= 'z')
    {
        *ch = ((temp == 'z') ? 'A' : toupper(temp + 1));
    }

    return *ch;
}


char DecryptChar(char *ch)
{
    char temp = *ch;
    if (temp >= 'A' && temp <= 'Z')
    {  
        *ch = tolower((temp == 'A') ? 'Z' : (temp - 1));
    }
    else if (temp >= 'a' && temp <= 'z' )
    {
        *ch = toupper((temp == 'a') ? 'z' : (temp - 1));
    }
    else if (temp >= '0' &&temp <= '9')
    {
        *ch = ((temp == '0') ? '9' : (temp - 1));
    }  

    return *ch;
}

void Encrypt (char *aucPassword, char *aucResult)
{
    int length = strlen(aucPassword);
    strcpy(aucResult, aucPassword);
    aucResult[length] = '\0';

    int i = 0;
    while(aucResult[i] != '\0')
    {
    	//printf("%c", aucResult[i]);
        EncryptChar(&aucResult[i]);
    	//printf(" -=> %c\n", aucResult[i]);
        i++;
    }
    //printf("%s\n", aucResult);
}
void unEncrypt (char *result, char *password)
{
    int length = strlen(result);
    strcpy(password, result);
    password[length] = '\0';
    
    int i = 0;
    while(password[i] != '\0')
    {
    	//printf("%c", password[i]);
        DecryptChar(&password[i]);
	//printf(" -=> %c", password[i]);
        i++;
    }
    //printf("%s\n", password);
}
