CXX = main.cpp
CXX += Space.hpp
CXX += Space.cpp
CXX += Player.hpp
CXX += Player.cpp
CXX += Vestibule.hpp
CXX += Vestibule.cpp
CXX += Circle1.hpp
CXX += Circle1.cpp
CXX += Circle6.hpp
CXX += Circle6.cpp
CXX += Circle7.hpp
CXX += Circle7.cpp
CXX += Circle8.hpp
CXX += Circle8.cpp
CXX += Circle9.hpp
CXX += Circle9.cpp
CXX += Hell.hpp
CXX += Hell.cpp

Inferno: main.cpp Space.hpp Space.cpp Player.hpp Player.cpp Vestibule.hpp Vestibule.cpp Circle1.hpp Circle1.cpp Circle6.hpp Circle6.cpp Circle7.hpp Circle7.cpp Circle8.hpp Circle8.cpp Circle9.hpp Circle9.cpp Hell.hpp Hell.cpp
	g++ -std=c++0x main.cpp Space.cpp Player.cpp Vestibule.cpp  Circle1.cpp Circle6.cpp Circle7.cpp Circle8.cpp Circle9.cpp Hell.cpp -o Inferno

#valgrind:
#    g++ -g -Wall -pedantic-errors main.cpp Transformer.cpp Copy.cpp Encryption.cpp #ToUpper.cpp OrderedOutput.cpp -o main ; \
#    valgrind --leak-check=yes ./main


clean:
	rm Inferno



#rm -f main *.o Copy.txt Encryption.txt ToUpper.txt OrderedOutput.txt *~


