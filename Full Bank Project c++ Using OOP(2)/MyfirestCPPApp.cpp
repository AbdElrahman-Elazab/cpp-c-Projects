#include <iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
#include<iomanip>

using namespace std;

int main(){
   
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }
    system("pause>0");
    return 0;
    
}