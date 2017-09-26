##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TestingSFML
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/User/Documents/Software dev 2 project"
ProjectPath            :=C:/Users/User/Documents/Software2/Project/TestingSFML
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=User
Date                   :=26/09/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TestingSFML.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)C:\Users\User\Documents\Software2\Project\TestingSFML\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\User\Documents\Software2\Project\TestingSFML\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe --std=gnu++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/random.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Satellite.cpp$(ObjectSuffix) $(IntermediateDirectory)/TestsForGame.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix): PlayerPresentation.cpp $(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/PlayerPresentation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix): PlayerPresentation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerPresentation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerPresentation.cpp$(DependSuffix) -MM PlayerPresentation.cpp

$(IntermediateDirectory)/PlayerPresentation.cpp$(PreprocessSuffix): PlayerPresentation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerPresentation.cpp$(PreprocessSuffix) PlayerPresentation.cpp

$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix): PlayerLogic.cpp $(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/PlayerLogic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix): PlayerLogic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerLogic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerLogic.cpp$(DependSuffix) -MM PlayerLogic.cpp

$(IntermediateDirectory)/PlayerLogic.cpp$(PreprocessSuffix): PlayerLogic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerLogic.cpp$(PreprocessSuffix) PlayerLogic.cpp

$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix): GameWindow.cpp $(IntermediateDirectory)/GameWindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/GameWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameWindow.cpp$(DependSuffix): GameWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameWindow.cpp$(DependSuffix) -MM GameWindow.cpp

$(IntermediateDirectory)/GameWindow.cpp$(PreprocessSuffix): GameWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameWindow.cpp$(PreprocessSuffix) GameWindow.cpp

$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix): Bullet.cpp $(IntermediateDirectory)/Bullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bullet.cpp$(DependSuffix): Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bullet.cpp$(DependSuffix) -MM Bullet.cpp

$(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix): Bullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix) Bullet.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp $(IntermediateDirectory)/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/random.cpp$(ObjectSuffix): random.cpp $(IntermediateDirectory)/random.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/random.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/random.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/random.cpp$(DependSuffix): random.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/random.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/random.cpp$(DependSuffix) -MM random.cpp

$(IntermediateDirectory)/random.cpp$(PreprocessSuffix): random.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/random.cpp$(PreprocessSuffix) random.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix): EnemyBullet.cpp $(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/EnemyBullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix): EnemyBullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyBullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyBullet.cpp$(DependSuffix) -MM EnemyBullet.cpp

$(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix): EnemyBullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyBullet.cpp$(PreprocessSuffix) EnemyBullet.cpp

$(IntermediateDirectory)/Satellite.cpp$(ObjectSuffix): Satellite.cpp $(IntermediateDirectory)/Satellite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/Satellite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Satellite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Satellite.cpp$(DependSuffix): Satellite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Satellite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Satellite.cpp$(DependSuffix) -MM Satellite.cpp

$(IntermediateDirectory)/Satellite.cpp$(PreprocessSuffix): Satellite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Satellite.cpp$(PreprocessSuffix) Satellite.cpp

$(IntermediateDirectory)/TestsForGame.cpp$(ObjectSuffix): TestsForGame.cpp $(IntermediateDirectory)/TestsForGame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/User/Documents/Software2/Project/TestingSFML/TestsForGame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestsForGame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TestsForGame.cpp$(DependSuffix): TestsForGame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TestsForGame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TestsForGame.cpp$(DependSuffix) -MM TestsForGame.cpp

$(IntermediateDirectory)/TestsForGame.cpp$(PreprocessSuffix): TestsForGame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TestsForGame.cpp$(PreprocessSuffix) TestsForGame.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


