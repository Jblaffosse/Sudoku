#ifndef CONSTANTES_HEADER
#define CONSTANTES_HEADER

/* Define constant(s) used by the Sudoku library */

/* Print log message, used for debug */
/* #define DEBUG_MSG 1 */

/* Row and column sizes */
#define ROW_NUMBER ((unsigned int) 9U)
#define COLUMN_NUMBER ((unsigned int) 9U)

/* Define little square indexes */
/* Here the notation of the squares: */
/* 11 12 13 */
/* 21 22 23 */
/* 31 32 33 */
#define SQUARE11_ROW_MIN ((unsigned int) 0U)
#define SQUARE11_ROW_MAX ((unsigned int) 3U)
#define SQUARE11_COLUMN_MIN ((unsigned int) 0U)
#define SQUARE11_COLUMN_MAX ((unsigned int) 3U)

#define SQUARE12_ROW_MIN ((unsigned int) 0U)
#define SQUARE12_ROW_MAX ((unsigned int) 3U)
#define SQUARE12_COLUMN_MIN ((unsigned int) 3U)
#define SQUARE12_COLUMN_MAX ((unsigned int) 6U)

#define SQUARE13_ROW_MIN ((unsigned int) 0U)
#define SQUARE13_ROW_MAX ((unsigned int) 3U)
#define SQUARE13_COLUMN_MIN ((unsigned int) 6U)
#define SQUARE13_COLUMN_MAX ((unsigned int) 9U)

#define SQUARE21_ROW_MIN ((unsigned int) 3U)
#define SQUARE21_ROW_MAX ((unsigned int) 6U)
#define SQUARE21_COLUMN_MIN ((unsigned int) 0U)
#define SQUARE21_COLUMN_MAX ((unsigned int) 3U)

#define SQUARE22_ROW_MIN ((unsigned int) 3U)
#define SQUARE22_ROW_MAX ((unsigned int) 6U)
#define SQUARE22_COLUMN_MIN ((unsigned int) 3U)
#define SQUARE22_COLUMN_MAX ((unsigned int) 6U)

#define SQUARE23_ROW_MIN ((unsigned int) 3U)
#define SQUARE23_ROW_MAX ((unsigned int) 6U)
#define SQUARE23_COLUMN_MIN ((unsigned int) 6U)
#define SQUARE23_COLUMN_MAX ((unsigned int) 9U)

#define SQUARE31_ROW_MIN ((unsigned int) 6U)
#define SQUARE31_ROW_MAX ((unsigned int) 9U)
#define SQUARE31_COLUMN_MIN ((unsigned int) 0U)
#define SQUARE31_COLUMN_MAX ((unsigned int) 3U)

#define SQUARE32_ROW_MIN ((unsigned int) 6U)
#define SQUARE32_ROW_MAX ((unsigned int) 9U)
#define SQUARE32_COLUMN_MIN ((unsigned int) 3U)
#define SQUARE32_COLUMN_MAX ((unsigned int) 6U)

#define SQUARE33_ROW_MIN ((unsigned int) 6U)
#define SQUARE33_ROW_MAX ((unsigned int) 9U)
#define SQUARE33_COLUMN_MIN ((unsigned int) 6U)
#define SQUARE33_COLUMN_MAX ((unsigned int) 9U)

#endif /* End of CONSTANTES_HEADER definition */