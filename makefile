GPP				= g++
PYINS			= pyinstaller

SOURCE_CPP		= src/wowbm
SOURCE_PY		= src/wowplot
OUTPUT			= bin

CPPFLAGS		= -I$(SOURCE_CPP)
DBGFLAGS		= -D DEBUG
PYFLAGS			= --onefile --specpath $(OUTPUT) --workpath $(OUTPUT) --name $(WOWPLOT_NAME) --log-level WARN

WOWBM_NAME		= wowbm
WOWPLOT_NAME	= wowplot

run: wowbm
	@$(OUTPUT)/$(WOWBM_NAME).exe
	@$(OUTPUT)/

debug: wowbm-debug
	@$(OUTPUT)/$(WOWBM_NAME)_debug.exe

wowbm:
	@echo Compiling wowbm source...
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/wowbm.cpp 										-o $(OUTPUT)/wowbm.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/struct/vec/Vector.cpp 							-o $(OUTPUT)/Vector.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/struct/vec/VectorList.cpp 						-o $(OUTPUT)/VectorList.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/struct/vec/VectorPair.cpp 						-o $(OUTPUT)/VectorPair.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/struct/exc/Exception.cpp 						-o $(OUTPUT)/Exception.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/util/Random.cpp 								-o $(OUTPUT)/Random.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_CPP)/util/Timer.cpp 								-o $(OUTPUT)/Timer.o
	@echo Building wowbm executable...
	@$(GPP) $(CPPFLAGS) $(OUTPUT)/*.o -o $(OUTPUT)/$(WOWBM_NAME).exe

	@del /Q $(OUTPUT)\\*.o
	@echo Done!

wowbm-debug:
	@echo Compiling wowbm source with debug option...
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/wowbm.cpp 							-o $(OUTPUT)/wowbm.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/struct/vec/Vector.cpp 				-o $(OUTPUT)/Vector.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/struct/vec/VectorList.cpp 			-o $(OUTPUT)/VectorList.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/struct/vec/VectorPair.cpp 			-o $(OUTPUT)/VectorPair.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/struct/exc/Exception.cpp 			-o $(OUTPUT)/Exception.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/util/Random.cpp 					-o $(OUTPUT)/Random.o
	@$(GPP) $(CPPFLAGS) $(DBGFLAGS) -c $(SOURCE_CPP)/util/Timer.cpp 					-o $(OUTPUT)/Timer.o
	@echo Building wowbm executable...
	@$(GPP) $(CPPFLAGS) $(OUTPUT)/*.o -o $(OUTPUT)/$(WOWBM_NAME)_debug.exe

	@del /Q $(OUTPUT)\\*.o
	@echo Done!

wowplot:
	@echo Building wowplot executable...
	@$(PYINS) $(PYFLAGS) $(SOURCE_PY)/$(WOWPLOT_NAME).py								--distpath $(OUTPUT)
	@echo Done!

clean:
	@echo Cleaning up build folder...
	@del /Q $(OUTPUT)\\*
