/* 
 * File:   main.cpp
 * Author: javavirys
 *
 * Created on 7 декабря 2015 г., 22:18
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

#include <windows.h>


char *arrCommand[]= {
    "COMPUTERSYSTEM",
    "BIOS",
    "CPU",
    "MEMORYCHIP",
    "SYSTEMSLOT",
    "OS",
    "SOUNDDEV",
    "STARTUP",
    "PROCESS"
};

/*
 * 
 */
int main(int argc, char** argv) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hConsole != INVALID_HANDLE_VALUE)
    {
        COORD  size;
        size.X = 2000;//ширина 2000
        size.Y = 2000;//высота 2000
        SetConsoleScreenBufferSize(hConsole,size);//задать размер буфера экрана
    }
    
    cout<<"WMICInformation"<<endl;
    cout<<"Vendor:\t javavirys"<<endl;
    if(hConsole != INVALID_HANDLE_VALUE)
            SetConsoleTextAttribute(hConsole,2);//зелёный цвет
    cout<<"Web:\t http://java-virys.narod.ru"<<endl<<endl;
    if(hConsole != INVALID_HANDLE_VALUE)
            SetConsoleTextAttribute(hConsole,7);//стандартный цвет
    
    char buf[255];//буфер для строковых манипуляций
    for(int i=0;i<(int)(sizeof(arrCommand)/4);i++)
    {   
        sprintf(buf,"=============%s=============",arrCommand[i]);
        if(hConsole != INVALID_HANDLE_VALUE)
            SetConsoleTextAttribute(hConsole,3);//зелёный цвет
        cout<<buf<<endl;
        sprintf(buf,"wmic %s",arrCommand[i]);
        if(hConsole != INVALID_HANDLE_VALUE)
            SetConsoleTextAttribute(hConsole,7);//стандартный цвет
        system(buf);
        system("pause");//пауза после каждого пункта
        cout<<endl;
    }
    
    return 0;
}

