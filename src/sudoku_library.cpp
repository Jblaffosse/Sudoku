/* Include Standard librairies */ 
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/* Include Specific librairies */
#include "constantes.h"
#include "sudoku_library.h"

/* Allow to clear the sudoku grid */
void Sudoku_Grid::clear_sudoku_grid(void)
{
    /* Declare variables */
    unsigned int column_index;
    unsigned int row_index;
    
    /* Initialize variables */
    column_index = 0U;
    row_index = 0U;
    
    for(row_index = 0U; row_index < ROW_NUMBER; row_index++)
    {
        for(column_index = 0U; column_index < COLUMN_NUMBER; column_index++)
        {
            p_grid[row_index][column_index] = 0U;
        }
    }
    
}

/* Verify if the input number is not already present inside the given vector */
unsigned int Sudoku_Grid::compute_random_number(vector<unsigned int> list_numbers)
{
    /* Declare variables */
    bool number_found;
    unsigned int index;
    unsigned int random_number;
    random_device random; /* obtain a random number from hardware */
    mt19937 seed_gen(random()); /* seed the generator */
    uniform_int_distribution<> distribution(1, 9); /* define the range */
    
    /* Initialize variables */
    number_found = false;
    index = 0U;
    random_number = 0U;
    
#ifdef DEBUG_MSG
    cout << "Try to find random number, here the list of forbidden numbers: " << endl;
    for(index = 0U; index < list_numbers.size(); index++)
    {
        cout << list_numbers.at(index) << " ";
    }
    cout << endl;
#endif /* End of debug message(s) */
    
    
    /* Until the random number is not correctly computed */
    while( (number_found == false) && (list_numbers.size() != ROW_NUMBER) )
    {
        /* Find one random number inside [1; 9] */
        random_number = (unsigned int) distribution(seed_gen);
        
        /* By default, we can say that the random number is not present */
        number_found = true;
        
        /* Parse all the values of the input vector */
        for(index = 0U; index < list_numbers.size(); index++)
        {
            /* Check if the input number is already present inside the vector */
            if(list_numbers.at(index) == random_number)
            {
                number_found = false;
            }
        }
    
    }
    
    return random_number;
}

/* Verify if the input number is not already present in the little squares of the whole grid */
void Sudoku_Grid::check_unicity_one_square(vector<unsigned int>& list_numbers, unsigned int row_min_index, unsigned int column_min_index)
{
    /* Declare variables */
    unsigned int index_row;
    unsigned int index_column;
    bool number_verification;
    
    /* Initialize variables */
    index_row = 0U;
    index_column = 0U;
    number_verification = false;
    
    /* Parse all the values of the given square */
    for(index_row = row_min_index;  index_row < row_min_index + 3U; index_row++)
    {
        
        for(index_column = column_min_index;  index_column < column_min_index + 3U; index_column++)
        {
            
            /* Verify if the number was already present inside the list */
            number_verification = check_unicity(list_numbers, p_grid[index_row][index_column]);
            
            if( (number_verification == false ) && (p_grid[index_row][index_column] != 0U) )
            {
                list_numbers.push_back(p_grid[index_row][index_column]);
            
#ifdef DEBUG_MSG
                cout << "New value found: " << p_grid[index_row][index_column] << endl;
#endif /* End of debug message(s) */
            
            }
            
        }
        
    }
    
    
}

/* Verify if the input number is not already present in the little square */
void Sudoku_Grid::check_unicity_little_square(vector<unsigned int>& list_numbers, unsigned int row_index, unsigned int column_index)
{
    
    
    /* Verify in which square the value is located: */
    if(row_index < SQUARE11_ROW_MAX) /* First row */
    {
        /* Verify in which column the square is located: */
        if(column_index < SQUARE11_COLUMN_MAX) /* First column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE11_ROW_MIN, SQUARE11_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE12_COLUMN_MIN) && ( column_index < SQUARE12_COLUMN_MAX) ) /* Second column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE12_ROW_MIN, SQUARE12_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE13_COLUMN_MIN) && ( column_index < SQUARE13_COLUMN_MAX) ) /* Third column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE13_ROW_MIN, SQUARE13_COLUMN_MIN);
            
        }
        else
        {
            cout << "Error while locating the value inside the grid (first row)..." << endl;
        }
        
    }
    else if ( (row_index >= SQUARE21_ROW_MIN) && ( row_index < SQUARE21_ROW_MAX) ) /* Second row */
    {
        
        /* Verify in which column the square is located: */
        if(column_index < SQUARE21_COLUMN_MAX) /* First column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE21_ROW_MIN, SQUARE21_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE22_COLUMN_MIN) && ( column_index < SQUARE12_COLUMN_MAX) ) /* Second column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE22_ROW_MIN, SQUARE22_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE23_COLUMN_MIN) && ( column_index < SQUARE13_COLUMN_MAX) ) /* Third column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE23_ROW_MIN, SQUARE23_COLUMN_MIN);
            
        }
        else
        {
            cout << "Error while locating the value inside the grid (second row)..." << endl;
        }
        
    }
    else if ( (row_index >= SQUARE31_ROW_MIN) && ( row_index < SQUARE31_ROW_MAX) ) /* Third row */
    {
        
        /* Verify in which column the square is located: */
        if(column_index < SQUARE31_COLUMN_MAX) /* First column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE31_ROW_MIN, SQUARE31_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE32_COLUMN_MIN) && ( column_index < SQUARE32_COLUMN_MAX) ) /* Second column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE32_ROW_MIN, SQUARE32_COLUMN_MIN);
            
        }
        else if ( (column_index >= SQUARE33_COLUMN_MIN) && ( column_index < SQUARE33_COLUMN_MAX) ) /* Third column */
        {
            
            /* Parse all the values of the given little square in order to verify all the existing numbers */
            check_unicity_one_square(list_numbers, SQUARE33_ROW_MIN, SQUARE33_COLUMN_MIN);
            
        }
        else
        {
            cout << "Error while locating the value inside the grid (third row)..." << endl;
        }
        
    }
    else
    {
        cout << "Error while locating the value inside the grid ..." << endl;
    }
    
}

/* Verify if the input number is not already present inside the given vector */
bool Sudoku_Grid::check_unicity(vector<unsigned int> list_numbers, unsigned int new_number)
{
    /* Declare variables */
    bool present;
    unsigned int index;
    
    /* Initialize variables */
    present = false;
    index = 0U;
    
    /* Parse all the values of the input vector */
    for(index = 0U; index < list_numbers.size(); index++)
    {
        /* Check if the input number is already present inside the vector */
        if(list_numbers.at(index) == new_number)
        {
            present = true;
        }
    }
    
    return present;
}

/* Declare the function which allow to find already used numbers */
void Sudoku_Grid::find_impossible_numbers(vector<unsigned int>& list_numbers, unsigned int row_index, unsigned int column_index)
{
    /* Declare variables */
    unsigned int index;
    bool number_verification;
    unsigned int vector_size;
    
    /* Initialize variables */
    index = 0U;
    number_verification = false;
    vector_size = 0U;
    
#ifdef DEBUG_MSG
    cout << "Find impossible numbers at (" << row_index << ", " << column_index << ")" << endl;
#endif /* End of debug message(s) */
    
    /* Clear all the values of the vector */
    vector_size = list_numbers.size();
    for(index = 0U; index < vector_size; index++)
    {
        list_numbers[index] = 0U;
    }
    list_numbers.clear();
    
    /* Parse all the numbers in the given row */
    for(index = 0U; index < ROW_NUMBER; index++)
    {
    
#ifdef DEBUG_MSG
        cout << "Find impossible value for row: " << index << endl;
#endif /* End of debug message(s) */
    
        /* Verify if the number was already present inside the list */
        number_verification = check_unicity(list_numbers, p_grid[index][column_index]);
        
        if( (number_verification == false ) && (p_grid[index][column_index] != 0U) )
        {
            list_numbers.push_back(p_grid[index][column_index]);
            
#ifdef DEBUG_MSG
            cout << "New value found: " << p_grid[index][column_index] << endl;
#endif /* End of debug message(s) */
        }
    }
    
    /* Parse all the numbers in the given column */
    for(index = 0U; index < COLUMN_NUMBER; index++)
    {
    
#ifdef DEBUG_MSG
        cout << "Find impossible value for column: " << index << endl;
#endif /* End of debug message(s) */
        
        /* Verify if the number was already present inside the list */
        number_verification = check_unicity(list_numbers, p_grid[row_index][index]);
        
        if( (number_verification == false ) && (p_grid[row_index][index] != 0U) )
        {
            list_numbers.push_back(p_grid[row_index][index]);
            
#ifdef DEBUG_MSG
            cout << "New value found: " << p_grid[row_index][index] << endl;
#endif /* End of debug message(s) */
        }
    }
    
    /* Parse all the numbers present inside the little square */
    check_unicity_little_square(list_numbers, row_index, column_index);
    
    
}


/*  Declare constructor for Sudoku grid */
Sudoku_Grid::Sudoku_Grid(void)
{
    
    /* Clear the sudoku grid */
    clear_sudoku_grid();
    
}

/* Allow to properly print the sudoku grid */
void Sudoku_Grid::print_sudoku_grid(void)
{
    
    /* Declare variables */
    unsigned int column_index;
    unsigned int row_index;
    
    /* Initialize variables */
    column_index = 0U;
    row_index = 0U;
    
    for(row_index = 0U; row_index < ROW_NUMBER; row_index++)
    {
        if ( (row_index % 3) == 0)
        {
            cout << "- - - - - - - - - - - - -" << endl;
        }
        
        for(column_index = 0U; column_index < COLUMN_NUMBER; column_index++)
        {
            if ( (column_index % 3) == 0)
            {
                cout << "| ";
            }
            
            cout << p_grid[row_index][column_index] << " ";
        }
        
        cout << "|" << endl;
    }
    
    cout << "- - - - - - - - - - - - -" << endl;
}

/* Allow to initialize the Sudoku Grid with random numbers */
void Sudoku_Grid::initialize_sudoku_grid(void)
{
    
    /* Declare variables */
    unsigned int column_index;
    unsigned int row_index;
    unsigned int random_number;
    vector<unsigned int> list_impossible_numbers;
    bool sudoko_finish;
    
    /* Initialize variables */
    column_index = 0U;
    row_index = 0U;
    random_number = 0U;
    sudoko_finish = false;
    
#ifdef DEBUG_MSG
    unsigned int computation;
    computation = 0U;
#endif /* End of debug message(s) */
    
    do
    {
        
        /* Clear variables before computing grid numbers */
        sudoko_finish = true;
        clear_sudoku_grid();
        
#ifdef DEBUG_MSG
        computation++;
        cout << "Start computing ... (" << computation << ")" << endl;
#endif /* End of debug message(s) */
    
        /* Parse all the rows */
        for(row_index = 0U; row_index < ROW_NUMBER; row_index++)
        {
            /* Parse all the columns */
            for(column_index = 0U; column_index < COLUMN_NUMBER; column_index++)
            {
                /* For the given position inside the grid, find the list of impossible values */
                find_impossible_numbers(list_impossible_numbers, row_index, column_index);
                
                /* Compute the random number */
                random_number = compute_random_number(list_impossible_numbers);
                
                /* Check if the random value was correctly computed */
                if ( random_number == 0U )
                {
                    sudoko_finish = false;
                    
#ifdef DEBUG_MSG
                    cout << "Error found..." << endl;
#endif /* End of debug message(s) */
                }
                
#ifdef DEBUG_MSG
                cout << "Random number found: " << random_number << endl << "##############" << endl;
#endif /* End of debug message(s) */
                
                /* Affect the random number */
                p_grid[row_index][column_index] = random_number;
            }
            
        }
        
    } 
    while( sudoko_finish == false );
    
}