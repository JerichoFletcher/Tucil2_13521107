GPP				= g++
PYINS			= pyinstaller

SOURCE_CPP		= src/wowbm
SOURCE_PY		= src/wowplot
OUTPUT			= bin

CPPFLAGS		= -I$(SOURCE_CPP)
DBGFLAGS		= -D DEBUG
PYFLAGS			= --onefile --specpath $(OUTPUT) --workpath $(OUTPUT) --name $(WOWPLOT_NAME) --log-level WARN

WOWBM_NAME		= wowbm
WOWBMDBG_NAME	= $(WOWBM_NAME)_debug
WOWPLOT_NAME	= wowplot

run:
	@$(OUTPUT)/$(WOWBM_NAME).exe
	@echo Plotting...
	@$(OUTPUT)/$(WOWPLOT_NAME).exe

debug:
	@$(OUTPUT)/$(WOWBMDBG_NAME).exe
	@echo Plotting...
	@$(OUTPUT)/$(WOWPLOT_NAME).exe

build-all: wowbm wowplot
build-debug: wowbm-debug wowplot

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
	@$(GPP) $(CPPFLAGS) $(OUTPUT)/*.o -o $(OUTPUT)/$(WOWBMDBG_NAME).exe

	@del /Q $(OUTPUT)\\*.o
	@echo Done!

wowplot:
	@echo Building wowplot executable...
	@$(PYINS) $(PYFLAGS) $(SOURCE_PY)/$(WOWPLOT_NAME).py								--distpath $(OUTPUT)
	@echo Done!

clean:
	@echo Cleaning up build folder...
ifeq ($(OS),Windows_NT)
	@rmdir /s /q $(OUTPUT)
else
	@rm -rf $(OUTPUT)
endif
	@mkdir $(OUTPUT)
