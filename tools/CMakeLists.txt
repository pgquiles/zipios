#
# File:
#      CMakeLists.txt
#
# Description:
#      Build Zipios++ tools.
#
# Documentation:
#      See the CMake documentation.
#
# License:
#      Zipios++ - a small C++ library that provides easy access to .zip files.
#      Copyright (C) 2000-2007  Thomas Sondergaard
#      Copyright (C) 2015  Made to Order Software Corporation
#
#      This library is free software; you can redistribute it and/or
#      modify it under the terms of the GNU Lesser General Public
#      License as published by the Free Software Foundation; either
#      version 2.1 of the License, or (at your option) any later version.
#
#      This library is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#      Lesser General Public License for more details.
#
#      You should have received a copy of the GNU Lesser General Public
#      License along with this library; if not, write to the Free Software
#      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#


###
### ZipIOS Tool
###
add_executable( zipios_tool
    zipios.cpp
)

set_target_properties( zipios_tool
    PROPERTIES OUTPUT_NAME zipios
)

target_link_libraries( zipios_tool
    zipios
)

install( TARGETS zipios_tool
    DESTINATION ${BIN_INSTALL_DIR}
)

set_property(TARGET zipios_tool
	     PROPERTY CXX_STANDARD 11)


###
### Append Zip Tool
###

add_executable( appendzip
    appendzip.cpp
)

install( TARGETS appendzip
    DESTINATION ${BIN_INSTALL_DIR}
)

set_property(TARGET appendzip
	     PROPERTY CXX_STANDARD 11)


###
### DOS Time Tool
###

add_executable( dostime
    dostime.cpp
)

target_link_libraries( dostime
    zipios
)

install( TARGETS dostime
    DESTINATION ${BIN_INSTALL_DIR}
)


set_property(TARGET dostime
	     PROPERTY CXX_STANDARD 11)

###
### zipios_example.cpp
###

add_executable( zipios_example
    zipios_example.cpp
)

target_link_libraries( zipios_example
    zipios
)

set_property(TARGET zipios_example
	     PROPERTY CXX_STANDARD 11)

# DO NOT INSTALL THIS ONE, IT IS JUST AN EXAMPLE!


# Local Variables:
# indent-tabs-mode: nil
# tab-width: 4
# End:

# vim: ts=4 sw=4 et
