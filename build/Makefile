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
# Include colorization rules
#-----------------------------------------------------------------------------------------
include ./colors.mk

#-----------------------------------------------------------------------------------------
# Include general rules linked to compiler and linker executable and associated option
#-----------------------------------------------------------------------------------------
include ./rules.mk

#-----------------------------------------------------------------------------------------
# Header includes
#-----------------------------------------------------------------------------------------
EXT_INCLUDES := -I ../include
#INT_INCLUDES=	-I../include\

#-----------------------------------------------------------------------------------------
# External Libraries
#-----------------------------------------------------------------------------------------
LIB_INCLUDE=

#-----------------------------------------------------------------------------------------
# Executable linked to the process
#-----------------------------------------------------------------------------------------
EXEC=sudoku

#-----------------------------------------------------------------------------------------
# Library to build
#-----------------------------------------------------------------------------------------
LIBNM=

#-----------------------------------------------------------------------------------------
# Executable linked to the process
#-----------------------------------------------------------------------------------------
LIBS=

#-----------------------------------------------------------------------------------------
# Extra-flags for the Compiler
#-----------------------------------------------------------------------------------------
CEXFLAGS=
LDEXFLAGS=


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------------------------------------------
# Header to display for each target
#-----------------------------------------------------------------------------------------
default:
	$(call MyInfo,*********************************************************************************)
	$(call MyInfo,**** System:                      Sudoku Application                         ****)
	$(call MyInfo,*********************************************************************************)

#-----------------------------------------------------------------------------------------
# Target used to build the executable, object and library
#-----------------------------------------------------------------------------------------
all: exec

#-----------------------------------------------------------------------------------------
# Target used to build the executable
#-----------------------------------------------------------------------------------------
exec: $(OBJ)
ifneq ($(EXEC),)
	$(call MyMsg,|__INFO: Building the executable: $(EXEC))
	@$(LD) $(LDEXFLAGS) $^ -o $(EXEC) $(LDFLAGS) $(LIB_INCLUDE) $(LIBS) 2>temp.log  || touch temp.errors
	@if test -e temp.errors;\
	then $(ECHO) $(ERROR_STRING) && $(CAT) temp.log;\
	elif test -s temp.log;\
	then $(ECHO) $(WARN_STRING) && $(CAT) temp.log;\
	else $(ECHO) $(OK_STRING);\
	fi;
	@$(RM) -f temp.errors temp.log
	$(call MyMsg,|__INFO: Executable $(EXEC) correctly generated, move it...)
	@$(MV) $(EXEC) ..
	@$(ECHO) $(OK_STRING)
else
#-----------------------------------------------------------------------------------------
# Target used to build a library
#-----------------------------------------------------------------------------------------
	$(call MyMsg,|__INFO: Building the library: $(LIBNM) ...)
	@$(AR) $(ARFLAGS) $(LIBNM) $(LIBS) $(LIB_INCLUDE) $^ 2>temp.log || touch temp.errors
	@$(RANLIB) $(LIBNM) 2>>temp.log || touch temp.errors
	@if test -e temp.errors;\
	then $(ECHO) $(ERROR_STRING) && $(CAT) temp.log;\
	elif test -s temp.log;\
	then $(ECHO) $(WARN_STRING) && $(CAT) temp.log;\
	else $(ECHO) $(OK_STRING);\
	fi;
	@$(RM) -f temp.errors temp.log
endif

#-----------------------------------------------------------------------------------------
# Target used to build each object file associated to a C file
#-----------------------------------------------------------------------------------------
%.o: %.cpp
	$(call MyMsg,|__INFO: Compiling object file: $^ ...)
#	g++ -c -o $@ $< -I../include
	@$(CC) $(CFLAGS) $(CEXFLAGS) -c $< $(EXT_INCLUDES) $(INT_INCLUDES) -o $@ 2>temp.log || touch temp.errors
	@if test -e temp.errors;\
	then $(ECHO) $(ERROR_STRING) && $(CAT) temp.log;\
	elif test -s temp.log;\
	then $(ECHO) $(WARN_STRING) && $(CAT) temp.log;\
	else $(ECHO) $(OK_STRING);\
	fi;
	@$(RM) -f temp.errors temp.log

#-----------------------------------------------------------------------------------------
# Target to consider always out-of-date
#-----------------------------------------------------------------------------------------
.PHONY: clean mrproper all

#-----------------------------------------------------------------------------------------
# Target used to remove object file(s) only
#-----------------------------------------------------------------------------------------
clean:	default mrproper
	$(call MyMsg,|__INFO: Cleaning all the object files:)
	@$(ECHO) $(OK_STRING)
	@find .. -name '*.o' -exec rm {} \; &2>/dev/null

#-----------------------------------------------------------------------------------------
# Target used to remove executable and object file(s)
#-----------------------------------------------------------------------------------------
mrproper:
ifneq ($(EXEC),)
	$(call MyMsg,|__INFO: Cleaning the executable: $(EXEC))
	@rm -rf $(EXEC) &2>/dev/null
else
	$(call MyMsg,|__INFO: Cleaning the executable: $(LIBNM))
	@rm -rf $(LIBNM) &2>/dev/null
endif
	@printf "\n"
