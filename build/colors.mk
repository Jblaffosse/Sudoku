#******************************************************************************
#
#                           Suduku Application
#
#******************************************************************************

#********************************************************************************
#  Version   *    Date     *    Author   *   Modifications                      *
# *******************************************************************************
#            *             *             *                                      *
#            *             *             *                                      *
#    1.0     * 26/10/2022  * JB LAFFOSSE * First issue                          *
#            *             *             *                                      *
#            *             *             *                                      *
#********************************************************************************


#-----------------------------------------------------------------------------------------
# Keywords to color the OK, WARNING or ERRORS strings given the compilation or link status
#-----------------------------------------------------------------------------------------
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INFO_COLOR=\x1b[34;01m
MSG_COLOR=\x1b[36;1m

OK_STRING="$(OK_COLOR)[OK]$(NO_COLOR)"
ERROR_STRING="$(ERROR_COLOR)[ERRORS]$(NO_COLOR)"
WARN_STRING="$(WARN_COLOR)[WARNINGS]$(NO_COLOR)"
CLEAN_STRING="     |__INFO: Cleaning all the object files: $(OK_COLOR)[OK]$(NO_COLOR)"

#-----------------------------------------------------------------------------------------
# Commands used in this makefile (from its original path)
#-----------------------------------------------------------------------------------------
ECHO=/bin/echo -e
ECHON=/bin/echo -ne
CAT=/bin/cat
RM=/bin/rm

#-----------------------------------------------------------------------------------------
# Function used to display a Makefile header in color
#-----------------------------------------------------------------------------------------
define MyInfo
	@$(ECHO) "$(INFO_COLOR) $1 $(NO_COLOR)"
endef

define MyMsg
	@$(ECHON) "    $(MSG_COLOR) $1 $(NO_COLOR)"
endef

