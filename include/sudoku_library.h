#ifndef SUDOKU_LIBRARY_HEADER
#define SUDOKU_LIBRARY_HEADER


/* Declare sudoku grid class */
class Sudoku_Grid
{

private:

    /* Declare the Sudoku Grid */
    unsigned int p_grid[ROW_NUMBER][COLUMN_NUMBER];
    
    /* Allow to clear the sudoku grid */
    void clear_sudoku_grid(void);
    
    /* Find last number from a list of 8 unique numbers */
    unsigned int find_last_number(vector<unsigned int> list_numbers);
    
    /* Allow to compute one random number not present from the given list */
    unsigned int compute_random_number(vector<unsigned int> list_numbers);
    
    /* Verify if the input number is not already present in the little squares of the whole grid */
    void check_unicity_one_square(vector<unsigned int>& list_numbers, unsigned int row_min_index, unsigned int column_min_index);
    
    /* Verify if the input number is not already present in the little squares of the whole grid */
    void check_unicity_little_square(vector<unsigned int>& list_numbers, unsigned int row_index, unsigned int column_index);
    
    /* Verify if the input number is not already present inside the given vector */
    bool check_unicity(vector<unsigned int> list_numbers, unsigned int new_number);
    
    /* Declare the function which allow to find already used numbers */
    void find_impossible_numbers(vector<unsigned int>& list_numbers, unsigned int row_index, unsigned int column_index);

public:

    /*  Declare constructor for Sudoku grid */
    Sudoku_Grid(void);
    
    /*  Declare Copy constructor for Sudoku grid */
    /* void Sudoku_Grid(const Sudoku_Grid& sudoku); */
    
    /*  Declare virtual destructor */
    /* virtual ~Sudoku_Grid(); */
    
    /* Allow to properly print the sudoku grid */
    void print_sudoku_grid(void);
    
    /* Allow to initialize the Sudoku Grid with random numbers */
    void initialize_sudoku_grid(void);

};

#endif /* End of SUDOKU_LIBRARY_HEADER definition */