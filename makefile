GPP				= g++

SOURCE_CPP		= src/wowbm
OUTPUT			= bin

CPPFLAGS		= -I$(SOURCE_CPP)

WOWBM_NAME		= wowbm

run: wowbm
	@$(OUTPUT)/$(WOWBM_NAME).exe

wowbm:
	@echo Compiling wowbm source...
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\wowbm.cpp 						-o $(OUTPUT)\\wowbm.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\struct\\vec\\Vector.cpp 			-o $(OUTPUT)\\Vector.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\struct\\vec\\VectorList.cpp 		-o $(OUTPUT)\\VectorList.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\struct\\vec\\VectorPair.cpp 		-o $(OUTPUT)\\VectorPair.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\struct\\exc\\Exception.cpp 		-o $(OUTPUT)\\Exception.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)\\util\\Random.cpp 					-o $(OUTPUT)\\Random.o
	@echo Building wowbm executable...
	@$(GPP) $(CPPFLAGS) $(OUTPUT)\\*.o -o $(OUTPUT)\\$(WOWBM_NAME).exe

	@del /Q $(OUTPUT)\\*.o
	@echo Done!

clean:
	@echo Cleaning up build folder...
	@del /Q $(OUTPUT)\\*
