SRCS = main.cpp Matrix.cpp mtx_io.cpp BasicStrategy.cpp EigenSumStrategy.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = g++
CXXFLAGS = -fopenmp -I/prj/prjad/fcabral/eigen-3.4.0/
LDFLAGS =
TARGET = Blaol

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

