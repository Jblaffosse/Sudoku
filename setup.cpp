/* Include Standard librairies */ 
#include <iostream>
#include <vector>

using namespace std;

/* Include Specific librairies */
#include "constantes.h"
#include "sudoku_library.h"

/* Declare main function */ 
int main()
{
    /* Declare variable(s) */
    Sudoku_Grid l_grid;
    
    /* Initialize variable(s) */
    l_grid.initialize_sudoku_grid();
    
    cout << "Printing sudoku library:" << endl; 
    
    l_grid.print_sudoku_grid();
    
    /* Exit main function and return execution code */
    return 0;
}