add_library(Utilities STATIC 
	"src/Utilities.cpp" 
	"includes/Utilities.h"
)

target_include_directories(Utilities PUBLIC includes)
target_include_directories(Utilities PRIVATE src)
