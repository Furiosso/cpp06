#!/bin/bash

# Verifica que se proporcionen exactamente 3 argumentos: nombre de la clase, miembro1, miembro2
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <class_name>"
    exit 1
fi

CLASS_NAME="$1"
FILE_NAME="${CLASS_NAME}.cpp"

# Genera el contenido del archivo .hpp
cat << EOF > "$FILE_NAME"
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME() {}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME& src)
{
	*this = src;
}

$CLASS_NAME& $CLASS_NAME::operator=(const $CLASS_NAME& rhs)
{
	if (this != &rhs)
		return *this;
}

$CLASS_NAME::~$CLASS_NAME() {}

std::ostream&	operator<<(std::ostream& o, $CLASS_NAME const& value)
{
	o << value;
	return o;
}

EOF

echo "Generated $FILE_NAME"