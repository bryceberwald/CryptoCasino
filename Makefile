default:
	g++ -std=c++11 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -lcurl lib/libcurl.a lib/libraylib.a lib/libRakNetLibStatic.a -o Savages-Online