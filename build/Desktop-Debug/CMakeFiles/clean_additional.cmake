# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/DND_GM_Helper_5E_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/DND_GM_Helper_5E_autogen.dir/ParseCache.txt"
  "DND_GM_Helper_5E_autogen"
  )
endif()
