default:
	g++ *.cpp -o test -lgmp -lgmpxx

library:
	g++ -c \
		AttributedHalfSegment2D.cpp \
		HalfSegment2D.cpp \
		Line2D.cpp \
		Number.cpp \
		Point2D.cpp \
		Region2D.cpp \
		Segment2D.cpp \
		SimplePoint2D.cpp
	ar crvs libGeometricDataStructures2D.a \
                AttributedHalfSegment2D.o \
                HalfSegment2D.o \
                Line2D.o \
                Number.o \
                Point2D.o \
                Region2D.o \
                Segment2D.o \
                SimplePoint2D.o

