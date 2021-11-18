#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main(){
    
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    // Inicio

    
    // Fim
    SetConsoleOutputCP(CPAGE_DEFAULT);
    printf("\n\n");
    return 0;
}