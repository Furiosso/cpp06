#!/bin/bash

# Verifica que se proporcionen exactamente 3 argumentos: nombre de la clase, miembro1, miembro2
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <class_name>"
    exit 1
fi

CLASS_NAME="$1"
HEADER_GUARD="${CLASS_NAME^^}_HPP" # Convierte el nombre de la clase a mayúsculas para el include guard
FILE_NAME="${CLASS_NAME}.hpp"

# Genera el contenido del archivo .hpp
cat << EOF > "$FILE_NAME"
#ifndef $HEADER_GUARD
# define $HEADER_GUARD

# include <string>
# include <iostream>

class	$CLASS_NAME
{
	private:
	protected:
	public:
		$CLASS_NAME();
		$CLASS_NAME(const $CLASS_NAME& src);
		$CLASS_NAME& operator=(const $CLASS_NAME& rhs);
		~$CLASS_NAME();
};

std::ostream&	operator<<(std::ostream& o, $CLASS_NAME const& value);

#endif
EOF

echo "Generated $FILE_NAME"